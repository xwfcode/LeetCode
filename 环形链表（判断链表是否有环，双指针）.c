/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //类似于操场跑圈，一快一慢总会套圈
bool hasCycle(struct ListNode *head) {
    if((head == NULL) || (head->next == NULL))
    {
        return false;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while((fast != NULL) && (fast->next != NULL))
    {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}