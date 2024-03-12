#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0, head);
        int prefix = 0;
        unordered_map<int, ListNode*> prefixToNode;
        prefixToNode[0] = &dummy;

        for (; head; head = head->next) {
            prefix += head->val;
            prefixToNode[prefix] = head;
        }

        prefix = 0;

        for (head = &dummy; head; head = head->next) {
            prefix += head->val;
            head->next = prefixToNode[prefix]->next;
        }

        return dummy.next;
    }
};

int main() {
    // Example usage
    Solution solution;
    
    // Create your linked list here
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);
    
    ListNode* result = solution.removeZeroSumSublists(head);

    // Print the result
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
