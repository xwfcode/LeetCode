/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //思路1：逆置一下链表，删除逆置后的第n个节点，然后再重新进行逆置,待删除结点为第一个结点需要特殊考虑(在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 next 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。
 //思路2：使用双指针（类似于快慢指针），先让快指针走n+1步，再让快慢指针同时走，当快指针走到NULL时，慢指针所指向的结点，就是待删除结点的前一个结点。待删除结点为第一个结点需要特殊考虑

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy =(struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->val = 0;dummy->next=head;
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode* slow = dummy;
    struct ListNode* fast = head;
    for(int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;

}