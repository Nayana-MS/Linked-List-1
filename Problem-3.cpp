

142. Linked List Cycle II

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

TC O(n)
SC O(1)


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool flag = false;
        if(head == NULL) {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while ((fast!= NULL)  && (fast->next!= NULL)) {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast) {
                    flag = true;
                    break;
                }
        }
        if(!flag) return NULL;
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;

    }
};
