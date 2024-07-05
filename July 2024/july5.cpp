#include <iostream>
#include <vector>
#include <climits>

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, INT_MIN};
        ListNode* cur = head;
        int prevCriticalIndex = -1, firstCriticalIndex = -1, prevNode = cur->val;
        int id = 0;
        cur = cur->next;
        while (cur->next != NULL) {
            id++;
            int curNode = cur->val, nextNode = cur->next->val;
            if ((prevNode < curNode && curNode > nextNode) || (prevNode > curNode && curNode < nextNode)) {
                if (firstCriticalIndex == -1) {
                    firstCriticalIndex = id;
                    prevCriticalIndex = id;
                } else {
                    ans[0] = min(ans[0], id - prevCriticalIndex);
                    ans[1] = max(ans[0], id - firstCriticalIndex);
                    prevCriticalIndex = id;
                }
            }
            prevNode = curNode;
            cur = cur->next;
        }
        vector<int> defaultAns = {-1, -1};
        return (ans[0] == INT_MAX) ? defaultAns : ans;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Creating a linked list: 1 -> 3 -> 2 -> 4 -> 5 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    vector<int> result = solution.nodesBetweenCriticalPoints(head);

    cout << "Min distance between critical points: " << result[0] << endl;
    cout << "Max distance between critical points: " << result[1] << endl;

    // Freeing the allocated memory for the linked list
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
