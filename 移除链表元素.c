/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while(cur != NULL)
    {
        if(cur->val == val)
        {
            if(cur == head)
            {
                head = cur->next;
                free(cur);
                cur = head;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;

}