/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //去对比头插法
struct ListNode* reverseList(struct ListNode* head) {
   struct ListNode* prev = NULL;//反转后链表的头节点
   struct ListNode* cur = head;//正在进行反转的结点
   while(cur != NULL)
   {
   struct ListNode* next = cur->next;//下一个将要进行反转的结点（还未进行反转链表的头节点）
    cur->next = prev;//第一次循环的时候（第一个进行反转的结点就是反转后的尾结点）指向空。
    prev = cur;
    cur = next;
   }
   return prev;
}