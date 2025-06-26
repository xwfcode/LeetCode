


typedef struct {
    //_a用指针说明他是一个动态数组，如果是静态的话就得这样子定义int _a[100]
    int* _a; //一个指向整数数组的指针，将在队列初始化时通过malloc分配内存
    int _front;
    int _rear;
    int _k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    //这一步分配的是循环队列结构本身的内存
    //分配的大小是sizeof(MyCircularQueue),即结构体的大小
    //这个结构体包含三个成员:int* _a,int _front;int _rear;
    //此时的p是指向一个可以存储这三个成员的内存块，这个时候的_a只是一个啥也没有指向的指针
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    //开辟一个空间大小为这么多的内存，让指针_a指向
    //这一步分配是用于存储队列元素的数组内存
    q->_a = (int *)malloc((k+1) * sizeof(int));//多开一个的原因是，循环队列有一个位置不能存放数据
    q->_front = 0;
    q->_rear = 0;
    q->_k = k;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if((obj->_rear + 1)%(obj->_k + 1) == (obj->_front))
        return false;
    obj->_a[obj->_rear] = value;
    obj->_rear = (obj->_rear + 1) % (obj->_k + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->_front ==  obj->_rear)
        return false;
    obj->_front = (obj->_front + 1) % (obj->_k + 1);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->_front ==  obj->_rear)
        return -1;
    else
    {
     return(obj->_a[obj->_front]);
    }
       
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->_front ==  obj->_rear)
        return -1;
    else
        return(obj->_a[(obj->_rear-1 + (obj->_k + 1)) % (obj->_k + 1)]);
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->_front ==  obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return(obj->_rear + 1)%(obj->_k + 1) == (obj->_front);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/












MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->_a = (int*)malloc(sizeof(int) * k);  // 分配k个整数的空间
    obj->_front = 0;
    obj->_rear = 0;
    return obj;
}
两次内存分配的原因

这段代码中确实有两次内存分配，它们的目的不同：

第一次分配 (MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue)))：
这一步分配的是循环队列结构体本身的内存
分配的大小是 sizeof(MyCircularQueue)，即结构体的大小
这个结构体包含三个成员：int* _a、int _front、int _rear
此时，obj 指向一个可以存储这三个成员的内存块

第二次分配 (obj->_a = (int*)malloc(sizeof(int) * k))：
这一步分配的是用于存储队列元素的数组内存
分配的大小是 sizeof(int) * k，即k个整数的空间
这个数组将用来存储队列中的实际元素
此时，obj->_a 指向一个可以存储k个整数的内存块

第一次分配 (obj):
+-------------------+
| _a    | 指针      | --+
+-------------------+   |
| _front| 0         |   |
+-------------------+   |
| _rear | 0         |   |
+-------------------+   |
                        |
第二次分配 (obj->_a):   |
                        v
                    +---+---+---+---+---+
                    | 0 | 0 | 0 | 0 | 0 | ... (k个整数空间)
                    +---+---+---+---+---+