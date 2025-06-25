/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL)
    {
        return NULL;
    }
    //设置一个空的头结点
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    dummyHead->val = 0;
    //设置一个遍历链表的结点
    struct ListNode* cur = head->next;
    //设置一个后续的结点（用于迭代）
    //struct ListNode* next = head->next;
    //设置一个顺序链表的头结点
    struct ListNode* newHead = head;
    newHead->next = NULL;//要进行断开，否则会死循环
    //开始循环
    while(cur != NULL)
    {
        // 保存下一个要处理的节点
        struct ListNode* next = cur->next;
        //next = next->next;
        if(cur->val >= newHead->val)
        {
            struct ListNode* newcur = newHead;
            while((newcur->next != NULL) && (newcur->next->val < cur->val))
            {
                newcur = newcur->next;
            }
            cur->next = newcur->next;
            newcur->next = cur;
        }
        else
        {
            cur->next = dummyHead->next;
            dummyHead->next = cur;
            newHead = dummyHead->next;
        }
        cur = next;
    }
    struct ListNode* result = dummyHead->next;
    free(dummyHead);
    return result;
}