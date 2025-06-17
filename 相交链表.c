/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //判断是否存在空链表
    if((headA==NULL) || (headB ==NULL))
    {
        return NULL;
    }
    struct ListNode* curA = headA , * curB = headB;
    int lengthA = 0,lengthB = 0;
    //求链表A的长度
    while(curA)
    {
        lengthA++;
        curA = curA->next;
    }
    //求链表B的长度
    while(curB)
    {
        lengthB++;
        curB = curB->next;
    }
    //求出链表A和B的差值
    int n = (lengthA > lengthB) ? (lengthA - lengthB) : (lengthB - lengthA);
    //确保链表A和链表B在相对同一个位置出发
     struct ListNode* startA;
     struct ListNode* startB;
    if(lengthA > lengthB)
    {
        startA = headA;
        for(n;n>0;n--)
        {
            startA = startA->next;
        }
        startB = headB; 
    }
    else
    {
        startB = headB;
        for(n;n>0;n--)
        {
            startB = startB->next;
        }
        startA = headA;
    }
    while(startA != NULL)
    {
        if((startA) == (startB))
            return startA;
        else
        {
            startA = startA->next;
            startB = startB->next;
        }
    }
    return NULL;

}