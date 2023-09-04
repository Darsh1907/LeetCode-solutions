/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false; // If the list is empty or has only one node, there can't be a cycle.
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      // Move the slow pointer by one step.
        fast = fast->next->next; // Move the fast pointer by two steps.

        if (slow == fast) {
            return true; // If they meet, there is a cycle.
        }
    }

    return false; // If fast reaches the end of the list, there is no cycle.
}