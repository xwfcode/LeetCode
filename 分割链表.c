/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode* cur = head->next;
    struct ListNode* tail = head;
    if(head->next == NULL)
    {
        return head;
    }
    while(cur != NULL)
    {
        if(cur->val >= x)
        {
            tail->next=cur;
            tail = tail->next;
        }
        else
        {
            tail->next = cur->next;
            cur->next = head;
            head = cur;
            cur = tail;
        }
        cur = cur->next;
    }
    return head;
}