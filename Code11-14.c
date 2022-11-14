//typedef struct {
//    int* nums;
//    int front;
//    int rear;
//    int k;//必须把这个带着，不然后期无法判满和循环
//} MyCircularQueue;
//
//void myCircularQueueFree(MyCircularQueue* obj);
//MyCircularQueue* myCircularQueueCreate(int k);
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
//bool myCircularQueueDeQueue(MyCircularQueue* obj);
//int myCircularQueueFront(MyCircularQueue* obj);
//int myCircularQueueRear(MyCircularQueue* obj);
//bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//bool myCircularQueueIsFull(MyCircularQueue* obj);
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//
//    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    q->nums = (int*)malloc(sizeof(int) * (k + 1));//实际开k+1个空间
//    q->front = 0;
//    q->rear = 0;
//    q->k = k;
//    return q;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* q, int value) {
//    assert(q);//好习惯
//    if (myCircularQueueIsFull(q))//如果队列已满，则返回false，表示插入失败；
//        return false;
//    else
//    {
//        q->nums[q->rear] = value;
//        q->rear++;
//        q->rear = (q->rear == q->k + 1) ? 0 : q->rear;//判断rear指针是否越界
//    }
//    return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* q) {
//    assert(q);
//    if (myCircularQueueIsEmpty(q))//如果队列为空就会删除失败
//        return false;
//    else
//    {
//        q->front++;
//        q->front = (q->front == q->k + 1) ? 0 : q->front;//判断一下front是否越界
//    }
//    return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* q) {
//    assert(q);
//    if (myCircularQueueIsEmpty(q))//判空
//        return -1;
//    return q->nums[q->front];
//}
//
//int myCircularQueueRear(MyCircularQueue* q) {
//    assert(q);
//    if (myCircularQueueIsEmpty(q))//判空
//        return -1;
//    int index = (q->rear) ? q->rear - 1 : q->k;
//    return q->nums[index];
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* q) {
//    assert(q);
//    return ((q->front == q->rear));
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* q) {
//    assert(q);
//    return ((q->rear + 1) % (q->k + 1) == q->front);
//}
//
//void myCircularQueueFree(MyCircularQueue* q) {
//    assert(q);
//    free(q->nums);
//    free(q);
//}
// 链式结构：表示队列 
//typedef int QDataType;
//typedef struct QListNode
//{
//    struct QListNode* next;
//    QDataType val;
//}QNode;
//
//// 队列的结构 
//typedef struct Queue
//{
//    QNode* front;
//    QNode* rear;
//    int size;
//}Queue;
//
////初始化队列
//void QueueInit(Queue* q);
////销毁队列
//void QueueDestroy(Queue* q);
////入队列
//void QueuePush(Queue* q, QDataType x);
////出队列
//void QueuePop(Queue* q);
////获取队头元素
//QDataType QueueFront(Queue* q);
////获取队尾元素
//QDataType QueueBack(Queue* q);
////获取队列元素个数
//size_t QueueSize(Queue* q);
////队列判空
//bool QueueEmpty(Queue* q);
////初始化队列
//void QueueInit(Queue* q)
//{
//    assert(q);
//    q->front = NULL;
//    q->rear = NULL;
//    q->size = 0;
//}
////销毁队列
//void QueueDestroy(Queue* q)
//{
//    assert(q);
//    QNode* cur = q->front;
//    while (cur)
//    {
//        QNode* next = cur->next;
//        free(cur);
//        cur = next;
//    }
//    q->front = NULL;
//    q->rear = NULL;
//    q->size = 0;
//}
//
////开辟新节点
//static QNode* BuyQNode(QDataType x)
//{
//    QNode* NewNode = (QNode*)malloc(sizeof(QNode));
//    if (!NewNode)
//    {
//        printf("malloc fail!\n");
//        exit(EXIT_FAILURE);
//    }
//    NewNode->next = NULL;
//    NewNode->val = x;
//    return NewNode;
//}
////入队列
//void QueuePush(Queue* q, QDataType x)
//{
//    assert(q);
//    QNode* NewNode = BuyQNode(x);
//    if (q->rear == NULL)
//    {
//        q->front = q->rear = NewNode;
//    }
//    else
//    {
//        q->rear->next = NewNode;
//        q->rear = NewNode;
//    }
//    q->size++;
//}
////出队列
//void QueuePop(Queue* q)
//{
//    assert(q);
//    assert(QueueEmpty(q) == false);//判空
//    QNode* next = q->front->next;
//    free(q->front);
//    q->front = next;
//    if (q->front == NULL)//删除节点过后front指针指向NULL，表示无节点可删
//        q->rear = q->front;
//    q->size--;
//}
////队列判空
//bool QueueEmpty(Queue* q)
//{
//    assert(q);
//    return (q->front == q->rear && q->front == NULL);
//}
////获取队头元素
//QDataType QueueFront(Queue* q)
//{
//    assert(q);
//    assert(!QueueEmpty(q));
//    return q->front->val;
//}
////获取队尾元素
//QDataType QueueBack(Queue* q)
//{
//    assert(q);
//    assert(!QueueEmpty(q));
//    return q->rear->val;
//}
////获取队列元素个数
//size_t QueueSize(Queue* q)
//{
//    assert(q);
//    QNode* cur = q->front;
//
//    return q->size;
//}
//
//
//typedef struct {
//    Queue q1;
//    Queue q2;//我们得需两个队列才能完成模拟操作
//} MyStack;
//
//bool myStackEmpty(MyStack* obj);
//MyStack* myStackCreate() {
//    //该结构体用于控制两个队列，并且完成结构体的创建和初始化工作
//    MyStack* NewStack = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&NewStack->q1);
//    QueueInit(&NewStack->q2);//完成对于两个队列的初始化工作
//    //也就相当于完成了对于这个结构体的初始化工作
//    return NewStack;//由于该结构体是在堆上开辟的不会随着改函数栈帧的销毁而销毁
//    //只有当我们手动去销毁时，才会被销毁；
//}
//
//void myStackPush(MyStack* obj, int x) {
//    //完成入栈操作
//    assert(obj);//养成一个好的代码习惯，反之用户乱穿null指针
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;//我们需要对不为空的队列完成插入操作，为此我们得需要知道那个是非空队；
//    //假设q2是非空队，但是假设是会出错的啊，这就需要我们纠正
//    if (QueueEmpty(&obj->q2))//如果q2是空队，则纠正错误
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    //到这里我们只需完成队非空队列的插入操作
//    QueuePush(nonempty, x);
//}
//
//int myStackPop(MyStack* obj) {
//    //出栈操作
//    assert(obj);//好习惯
//    assert(myStackEmpty(obj) == false);//当栈为空的时候就不需要在删除了
//    //老样子先判断那个队列是非空
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if (QueueEmpty(&obj->q2))
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    //将非空队列的元素（除队尾外）全部搬运到空队;
//    while (QueueSize(nonempty) > 1)
//    {
//        QueuePush(empty, QueueFront(nonempty));
//        QueuePop(nonempty);
//    }
//    int top = QueueFront(nonempty);
//    QueuePop(nonempty);//完成出栈操作
//    return top;
//}
//
//int myStackTop(MyStack* obj) {
//    //获取栈顶元素
//    assert(obj);
//    assert(myStackEmpty(obj) == false);//当栈为空的时候就不要在进行此操作了
//    //老样子先判断那个队列是非空
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if (QueueEmpty(&obj->q2))
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    //非空队列的队尾就相当于栈顶
//    int top = QueueBack(nonempty);
//    return top;
//}
//
//bool myStackEmpty(MyStack* obj) {
//    assert(obj);
//    return (QueueEmpty(&obj->q1) && (QueueEmpty(&obj->q2)));//只有两个队列都为空，整个栈才为空;
//}
//
//void myStackFree(MyStack* obj) {
//    assert(obj);
//    QueueDestroy(&obj->q1);
//    QueueDestroy(&obj->q2);
//    free(obj);//注意这里不要一上来就释放obj，这样会造成内存泄漏，因为obj之开辟存放q1和q2的空间没有开辟具体的队列空间，对于具体的队列空间是通过q1、q2去完成的，为此我们需要先释放队列，在释放存储队列的结构体（obj）；
//}
//typedef int DataType;
//typedef struct Stack
//{
//    DataType* nums;
//    int capcity;
//    int top;
//}ST;
////初始化栈
//void InitStack(ST* ps);
////销毁栈
//void DestroyStack(ST* ps);
////入栈
//void StackPush(ST* ps, DataType x);
////出栈
//void StackPop(ST* ps);
////判断栈是否为NULL
//bool StackEmpty(ST* ps);
////统计栈的元素
//size_t StackSize(ST* ps);
////获取栈顶元素个数
//DataType StackTop(ST* ps);
////初始化栈
//void InitStack(ST* ps)
//{
//    assert(ps);//防止乱传
//    ps->capcity = 0;
//    ps->top = 0;
//    ps->nums = NULL;
//}
////销毁栈
//void DestroyStack(ST* ps)
//{
//    assert(ps);
//    ps->capcity = 0;
//    ps->top = 0;
//    free(ps->nums);
//}
////检查扩容，不提供给用户，由程序自己完成
//static void Check_Capcity(ST* ps)
//{
//    assert(ps);
//    if (ps->capcity == ps->top)//需要扩容
//    {
//        int len = (ps->capcity == 0) ? 4 : ps->capcity * 2;
//        DataType* tmp = (DataType*)realloc(ps->nums, len * sizeof(DataType));
//        if (!tmp)
//        {
//            printf("realloc fail!\n");
//            exit(EXIT_FAILURE);
//        }
//        ps->nums = tmp;
//        ps->capcity = len;
//    }
//}
////入栈
//void StackPush(ST* ps, DataType x)
//{
//    assert(ps);
//    Check_Capcity(ps);
//    ps->nums[ps->top] = x;
//    ps->top++;
//}
////出栈
//void StackPop(ST* ps)
//{
//    assert(ps);
//    assert(!StackEmpty(ps));//判空
//    ps->top--;
//}
////判断栈是否为NULL
//bool StackEmpty(ST* ps)
//{
//    assert(ps);
//    return !ps->top;
//}
////统计栈的元素
//size_t StackSize(ST* ps)
//{
//    assert(ps);
//    return ps->top;
//}
////获取栈顶元素
//DataType StackTop(ST* ps)
//{
//    assert(ps);
//    assert(!StackEmpty(ps));//栈不为空，我们才有元素获取;
//    return ps->nums[ps->top - 1];
//}
//
//
//typedef struct {
//    ST PushSt;//这个栈专门用来插入数据（入栈）
//    ST PopSt;//这个栈专门用来删除数据  (出栈)
//} MyQueue;
//
//bool myQueueEmpty(MyQueue* obj);
//MyQueue* myQueueCreate() {
//    //创建结构体
//    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
//    InitStack(&q->PushSt);
//    InitStack(&q->PopSt);//初始化两个栈
//    return q;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//    //入队
//    assert(obj);//好习惯
//    //我们只需要在PushSt栈里面插入数据
//    StackPush(&obj->PushSt, x);
//}
//
//int myQueuePop(MyQueue* obj) {
//    //出队
//    assert(obj);
//    assert(myQueueEmpty(obj) == false);//判空
//    //只需要对PopSt栈进行操作即可
//    //当然如果PopSt栈里面没有元素了，我们就需要将PushSt里面的元素全部倒过来
//    /*if(StackEmpty(&obj->PopSt))
//    {
//        while(StackEmpty(&obj->PushSt)==false)
//        {
//            StackPush(&obj->PopSt,StackTop(&obj->PushSt));
//            StackPop(&obj->PushSt);
//        }
//    }
//    int top=StackTop(&obj->PopSt);
//    StackPop(&obj->PopSt);
//    return top;*/
//    //代码复用
//    int top = myQueuePeek(obj);
//    StackPop(&obj->PopSt);
//    return top;
//}
//
//int myQueuePeek(MyQueue* obj) {
//    assert(obj);
//    assert(myQueueEmpty(obj) == false);
//    //当然如果PopSt栈里面没有元素了，我们就需要将PushSt里面的元素全部倒过来
//    if (StackEmpty(&obj->PopSt))
//    {
//        while (StackEmpty(&obj->PushSt) == false)
//        {
//            StackPush(&obj->PopSt, StackTop(&obj->PushSt));
//            StackPop(&obj->PushSt);
//        }
//    }
//    //PopSt的栈顶元素就是队头元素
//    int top = StackTop(&obj->PopSt);
//    return top;
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//    assert(obj);
//    return ((StackEmpty(&obj->PopSt)) && (StackEmpty(&obj->PushSt)));//两个栈同时为空队列才为空
//}
//
//void myQueueFree(MyQueue* obj) {
//    assert(obj);
//    DestroyStack(&obj->PopSt);
//    DestroyStack(&obj->PushSt);
//    free(obj);//与前一道题一样，必选先释放所开辟的栈，在释放当前结构体，否则会照成内存泄漏；
//}
