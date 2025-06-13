/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == NULL)
        {
            return slow;
        }
    }
    return slow;
}