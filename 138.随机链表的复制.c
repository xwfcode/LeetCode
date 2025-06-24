/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
//1.复制链表结点，依次插入原链表中
//2.开始给random赋值
//3，拆开链表，注意恢复原链表
struct Node* copyRandomList(struct Node* head) {
	if(head == NULL)
    {
        return NULL;
    }
    struct Node* cur = head;
    while(cur != NULL)
    {
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->val = cur->val;
        new->next = cur->next;
        cur->next = new;
        cur = new->next;
    }
    cur = head;
    while(cur != NULL)
    {
        if(cur->random == NULL)
        {
            cur->next->random = NULL;
        }
        else
        {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }
    cur = head->next;
    struct Node* newhead = head->next;
    struct Node* copy = head->next;
    struct Node* orig = head;
    while(copy != NULL)
    {
        orig->next = copy->next;
        orig = copy->next;
        copy->next = (orig != NULL) ? orig->next : NULL;
        copy = (orig != NULL) ? orig->next : NULL;
    }
    return newhead;
}