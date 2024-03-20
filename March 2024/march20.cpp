#include <iostream>

using namespace std;

// Define the ListNode structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Your Solution class
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* nodeBeforeA = list1;
        for (int i = 0; i < a - 1; ++i)
            nodeBeforeA = nodeBeforeA->next;

        ListNode* nodeB = nodeBeforeA->next;
        for (int i = 0; i < b - a; ++i)
            nodeB = nodeB->next;

        nodeBeforeA->next = list2;
        ListNode* lastNodeInList2 = list2;

        while (lastNodeInList2->next != nullptr)
            lastNodeInList2 = lastNodeInList2->next;

        lastNodeInList2->next = nodeB->next;
        nodeB->next = nullptr;
        return list1;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list1: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode* list1 = new ListNode(0);
    ListNode* current = list1;
    for (int i = 1; i <= 5; ++i) {
        current->next = new ListNode(i);
        current = current->next;
    }

    // Create list2: 100 -> 101 -> 102 -> nullptr
    ListNode* list2 = new ListNode(100);
    current = list2;
    for (int i = 1; i <= 2; ++i) {
        current->next = new ListNode(100 + i);
        current = current->next;
    }

    cout << "Before merging:" << endl;
    cout << "List1: ";
    printList(list1);
    cout << "List2: ";
    printList(list2);

    Solution solution;
    // Merge list2 into list1 starting from index 2 to 4
    list1 = solution.mergeInBetween(list1, 2, 4, list2);

    cout << "After merging:" << endl;
    cout << "List1: ";
    printList(list1);

    // Deallocate memory
    while (list1 != nullptr) {
        ListNode* temp = list1;
        list1 = list1->next;
        delete temp;
    }
    while (list2 != nullptr) {
        ListNode* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}
