/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur = head;
    if(head == NULL)
    {
        return head;
    }
    struct ListNode* next = head->next;
    while(next != NULL)
    {
        if(cur->val == next->val)
        {
            cur->next = next->next;
            next = cur->next;
        }
        else
        {
            cur = next;
            next = next->next;
        }
    }
    return head;
}