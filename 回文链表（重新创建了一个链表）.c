/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//思路先给链表倒置一下，然后再一一对比
bool isPalindrome(struct ListNode* head){
    struct ListNode* nummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    nummy->val = 0;
    nummy->next = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = head;
    if(head == NULL)
        return NULL;
    struct ListNode* copynummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    copynummy->val = 0;
    copynummy->next = NULL;
    struct ListNode* copycur = head;
    struct ListNode* copytail = copynummy;
    while(copycur != NULL)
    {
        struct ListNode* copynode= (struct ListNode*)malloc(sizeof(struct ListNode));
        copynode->val = copycur->val;
        copynode->next = NULL;
        copytail->next = copynode;
        copytail = copynode;
        copycur = copycur->next;
    }
    struct ListNode* copyhead = copynummy->next;

    while(cur != NULL)
    {
        next = next->next;
        cur->next = nummy->next;
        nummy->next = cur;
        
        cur = next;
    }
    struct ListNode* newhead = nummy->next;
    while(copyhead != NULL)
    {
        if(copyhead->val == newhead->val)
        {
            copyhead = copyhead->next;
            newhead = newhead->next;
        }
        else
        {
            return 0;
        }
    }
    return 1;
    
}