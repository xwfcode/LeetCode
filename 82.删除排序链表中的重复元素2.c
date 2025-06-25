/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL)
    {
        return head;
    }
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    dummyHead->val = 0;
    struct ListNode* prev = dummyHead;
    struct ListNode* cur = head;
    struct ListNode* next = head->next;
    while(next != NULL)
    {
        if(cur->val != next->val)
        {
            prev->next = cur;
            prev = cur;
            cur = next;
            next = next->next;
        }
        else
        {
            while(cur->val == next->val)
            {
                next = next->next;
                if(next ==NULL)//处理到了最后的元素（特殊考虑）
                {
                    prev->next = next;
                    cur = next;
                    return dummyHead->next;
                }
            }
            //还没有处理到最后的元素，正常执行
            prev->next = next;
            cur = next;
            next = next->next;
        }
    }
    return dummyHead->next;
}