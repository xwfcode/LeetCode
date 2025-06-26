 #include <stdlib.h>
 #include <stdbool.h>


// 队列结点定义
typedef struct QueueNode {
    int val;
    struct QueueNode* next;//指向下一个结点
} QueueNode;

// 队列结构定义
typedef struct {
    QueueNode* front;  // 队头
    QueueNode* rear;   // 队尾
    int size;          // 当前元素数量
} Queue;

//栈结构定义
typedef struct {
    Queue *queue1;//第一个指向队列的指针
    Queue *queue2;//第二个指向队列的指针
} MyStack;

//创建栈
MyStack* myStackCreate() {
    //给栈开辟一个空间，这个时候这个栈就包含了，两个队列
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));//栈的名字就叫obj

    //初始化queue1
    obj->queue1 = (Queue*)malloc(sizeof(Queue));
    obj->queue1->rear = NULL;
    obj->queue1->front = NULL;
    obj->queue1->size = 0;

    //初始化queue2
    obj->queue2 = (Queue*)malloc(sizeof(Queue));
    obj->queue2->rear = NULL;
    obj->queue2->front = NULL;
    obj->queue2->size = 0;

    return obj;
}

//入栈操作
void myStackPush(MyStack* obj, int x) {
    //确定使用哪个队列（使用非空队列，如果都为空则使用queue2）
    Queue* q = (obj->queue1->front != NULL) ? obj->queue1 : obj->queue2;

    //创建新结点
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->val = x;
    newnode->next = NULL;

    //将新结点添加到队列尾部
    if(q->rear == NULL){
        q->rear = newnode;
        q->front = newnode;
    }
    else{
        q->rear->next = newnode;
        q->rear = newnode;
    }
    q->size++;
}

//出栈操作
int myStackPop(MyStack* obj) {
    //确定非空队列和空队列(一定不会存在均为非空队列的情况)
    Queue* nonEmptyQ = (obj->queue1->front != NULL) ? obj->queue1 : obj->queue2;
    Queue* emptyQ = (obj->queue1->front != NULL) ? obj->queue2 : obj->queue1;

    //如果两个队列均为空，则返回错误值
    if(nonEmptyQ->front == NULL){
        return -1;
    }

    //将非空队列中除了最后一个结点之外的所有结点移动到空队列中
    while(nonEmptyQ->rear != nonEmptyQ->front){

        //从非空队列中取出头结点
        QueueNode* node = nonEmptyQ->front;
        nonEmptyQ->front = nonEmptyQ->front->next;
        nonEmptyQ->size--;

        //将结点添加到空队列
        if(emptyQ->rear == NULL)
        {
            emptyQ->rear = node;
            emptyQ->front = node;
        }
        else{
            emptyQ->rear->next = node;
            emptyQ->rear = node;
        }
        node->next = NULL;
        emptyQ->size++;
    }

    //获取最后一个元素的值（栈顶元素的值）
    int val = nonEmptyQ->front->val;

    //释放最后一个结点(也可以直接free(nonEmptyQ->front),然后再设置为NULL)
    QueueNode* lastNode = nonEmptyQ->front;
    free(lastNode);

    //重置非空队列为空
    nonEmptyQ->front = NULL;
    nonEmptyQ->rear = NULL;
    nonEmptyQ->size = 0;

    return val;
}

//获取栈顶元素(基本上和出栈差不多)
int myStackTop(MyStack* obj) {
    //确定非空队列和空队列
    Queue* nonEmptyQ = (obj->queue1->front != NULL) ? obj->queue1 : obj->queue2;
    Queue* emptyQ = (obj->queue1->front != NULL) ? obj->queue2 : obj->queue1;

    //如果都是空队列则返回错误值
    if(nonEmptyQ->front == NULL){
        return -1;
    }

    //将非空队列中除了最后一个元素其余的都挪到空队列中
    while(nonEmptyQ->front != nonEmptyQ->rear){
        //从非空队列取出头结点
        QueueNode* node = nonEmptyQ->front;
        nonEmptyQ->front = nonEmptyQ->front->next;
        nonEmptyQ->size--;

        //将结点添加到空队列
        if(emptyQ->front == NULL){
            emptyQ->front = node;
            emptyQ->rear = node;
        }
        else{
            emptyQ->rear->next = node;
            emptyQ->rear = node;
        }
        node->next = NULL;//从老的链表断开
        emptyQ->size++;
    }
    //获取最后一个结点的值（栈顶元素）
    int val = nonEmptyQ->front->val;

    //将最后一个元素移入emptyQ
    QueueNode* lastnode = nonEmptyQ->front;

    if(emptyQ->rear == NULL){
        emptyQ->front = lastnode;
        emptyQ->rear = lastnode;
    }
    else{
        emptyQ->rear->next = lastnode;
        emptyQ->rear = lastnode;
    }
    lastnode->next = NULL;
    emptyQ->size++;

    //重置非空队列为空
    nonEmptyQ->rear = NULL;
    nonEmptyQ->front = NULL;
    nonEmptyQ->size = 0;

    return val; 
}

//判断栈是否为空
bool myStackEmpty(MyStack* obj) {
    return (obj->queue1->rear==NULL) && (obj->queue2->rear== NULL);
}


//释放栈
void myStackFree(MyStack* obj) {
    //释放queue1所有结点
    QueueNode* cur = obj->queue1->front;
    while(cur != NULL){
        QueueNode* next = cur->next;
        free(cur);
        cur = next;
    }

    //释放queue1所有结点
    cur = obj->queue2->front;
    while(cur != NULL){
        QueueNode* next = cur->next;
        free(cur);
        cur = next;
    }

    // 释放队列和栈结构
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
    
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/