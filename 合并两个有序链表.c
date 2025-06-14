/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* cur1 = list1;
    struct ListNode* cur2 = list2;
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->val = 0;dummy->next = NULL;
    struct ListNode* cur = dummy;
    while(cur1 && cur2)
    {
        if(cur1->val <= cur2->val)
        {
            cur->next = cur1;
            cur1 = cur1->next;
            cur = cur->next;
        }
        else
        {
            cur->next = cur2;
            cur2 = cur2->next;
            cur = cur->next;
        }
    }
    if(cur1 == NULL)
	cur->next = cur2;
    else
	cur->next = cur1;
    struct ListNode* head = dummy->next;
    free(dummy);
    return head;
}