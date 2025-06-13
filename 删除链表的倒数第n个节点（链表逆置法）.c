/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //思路1：逆置一下链表，删除逆置后的第n个节点，然后再重新进行逆置,待删除结点为第一个结点需要特殊考虑(在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 next 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。
 //思路2：遍历出节点个数，然后求出倒数第n个节点是正数的哪个节点，然后再进行删除
 //思路3：使用双指针（类似于快慢指针），先让快指针走n+1步，再让快慢指针同时走，当快指针走到NULL时，慢指针所指向的结点，就是待删除结点的前一个结点。待删除结点为第一个结点需要特殊考虑

struct ListNode* reverseList(struct ListNode* head);
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    head = reverseList(head);
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    int i = 1;
    while((cur != NULL) && (i != n))
    {   
        prev = cur;
        cur = cur->next;
        i++;
    }
    if(cur == NULL)
    {
        return NULL;
    }
    else if(prev == NULL)
    {
        head = cur->next;
        free(cur);
    }
    else 
    {
        prev->next = cur->next;
        free(cur);
    }

    head = reverseList(head);
    return head;

}

//反转链表函数
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while(cur != NULL)
    {
        struct ListNode* curnext = cur->next;
        cur->next = prev;
        prev = cur;
        cur = curnext;
    }
    return prev;
}