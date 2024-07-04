#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* newCurr = dummyNode;
        ListNode* curr = head;

        while(1){
            int sum = 0;
            while(curr->next != NULL && curr->next->val != 0){
                curr = curr->next;
                sum += curr->val;
            }
            newCurr->next = new ListNode(sum);
            newCurr = newCurr->next;
            curr = curr->next;
            if(curr->next == NULL) break;
        }
        ListNode* newHead = dummyNode->next;
        delete(dummyNode);
        return newHead;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Create the linked list: 0 -> 1 -> 3 -> 0 -> 2 -> 5 -> 0
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(0);

    Solution sol;
    ListNode* result = sol.mergeNodes(head);

    // Print the result
    printList(result);

    // Free the allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
