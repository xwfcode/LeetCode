/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//先找到中间节点，然后给中间节点后面的进行逆置
bool isPalindrome(struct ListNode* head){
    //找中间节点
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* slowslow = NULL;//用于找到前面一半的最后一个结点
    while((fast != NULL) && (fast->next != NULL))
    {
        slowslow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* mid = slow;//已经找到了中间节点mid
    struct ListNode* tail = slowslow;//前面一半的最后一个结点(中间结点的前一个)
    //判断链表的结点是奇数个还是偶数个，如果fast为空就是偶数个
    struct ListNode* lasthead;//后半截链表的头节点
    if(fast == NULL)
    {
        tail->next = NULL;
        lasthead = mid;
    }
    else
    {
        lasthead = mid->next;
        mid->next = NULL;
    }
    //开始设置并初始化哑结点
    struct ListNode* nummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    nummy->val = 0;
    nummy->next = NULL;
    //开始逆置后半截结点
    struct ListNode* lastcur = lasthead;
    struct ListNode* copylastcur = lasthead;
    while(lastcur != NULL)
    {
        copylastcur = copylastcur->next;
        lastcur->next = nummy->next;
        nummy->next = lastcur;
        lastcur = copylastcur;
    }
    lasthead = nummy->next;
    while(lasthead != NULL)
    {
        if(lasthead->val == head->val)
        {
            lasthead = lasthead->next;
            head = head->next;
        }
        else{
            return 0;
        }
    }
    return 1;
    
}