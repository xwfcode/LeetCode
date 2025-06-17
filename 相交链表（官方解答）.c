/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //思路：创建两个指针curA和curB，初始时分别指向两个链表的头结点；然后两个指针一起往后走，
 //如果curA走到空了，就让curA移动到headB的头结点；如果curB走到空了，就让curB移动到headA的头结点
 //当两个指针分别都走完一趟后，就和之前的一样了
 //设链表A的长度为a+c,链表B的长度为b+c;最后走的路都是a+b+c;最后的路是一起走的
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //判断是否存在空链表
    if((headA==NULL) || (headB ==NULL))
    {
        return NULL;
    }
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    while(curA != curB)
    {
        curA = curA == NULL ? headB : curA->next;
        curB = curB == NULL ? headA : curB->next;
    }
    return curA;
}