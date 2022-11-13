//
//typedef struct {
//    Queue q1;
//    Queue q2;
//} MyStack;
//
//bool myStackEmpty(MyStack* obj);
//MyStack* myStackCreate() {
//    MyStack* NewStack = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&NewStack->q1);
//    QueueInit(&NewStack->q2);
//    return NewStack;
//}
//
//void myStackPush(MyStack* obj, int x) {
//    assert(obj);
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if (QueueEmpty(&obj->q1) == false)
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    QueuePush(nonempty, x);
//}
//
//int myStackPop(MyStack* obj) {
//    assert(obj);
//    assert(myStackEmpty(obj) == false);
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if (QueueEmpty(&obj->q1) == false)
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    while (QueueSize(nonempty) > 1)
//    {
//        QueuePush(empty, QueueFront(nonempty));
//        QueuePop(nonempty);
//    }
//    int top = QueueFront(nonempty);
//    QueuePop(nonempty);
//    return top;
//}
//
//int myStackTop(MyStack* obj) {
//    assert(obj);
//    assert(myStackEmpty(obj) == false);
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if (QueueEmpty(&obj->q1) == false)
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    return QueueBack(nonempty);
//}
//
//bool myStackEmpty(MyStack* obj) {
//    assert(obj);
//    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//    QueueDestroy(&obj->q1);
//    QueueDestroy(&obj->q2);
//    free(obj);
//}
//bool myQueueEmpty(MyQueue* obj);
//MyQueue* myQueueCreate() {
//    MyQueue* NewQueue = (MyQueue*)malloc(sizeof(MyQueue));
//    InitStack(&NewQueue->pushst);
//    InitStack(&NewQueue->popst);
//    return NewQueue;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//    assert(obj);
//    StackPush(&obj->pushst, x);
//}
//
//int myQueuePop(MyQueue* obj) {
//    assert(obj);
//    assert(myQueueEmpty(obj) == false);
//    int top = myQueuePeek(obj);
//    StackPop(&obj->popst);
//    return top;
//}
//
//int myQueuePeek(MyQueue* obj) {
//    assert(obj);
//    assert(myQueueEmpty(obj) == false);
//    if (StackEmpty(&obj->popst))
//    {
//        while (!StackEmpty(&obj->pushst))
//        {
//            StackPush(&obj->popst, StackTop(&obj->pushst));
//            StackPop(&obj->pushst);
//        }
//    }
//    return StackTop(&obj->popst);
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//    assert(obj);
//    return StackEmpty(&obj->popst) && StackEmpty(&obj->pushst);
//}
//
//void myQueueFree(MyQueue* obj) {
//    assert(obj);
//    DestroyStack(&obj->popst);
//    DestroyStack(&obj->pushst);
//    free(obj);
//}