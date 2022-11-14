//typedef struct {
//    int* nums;
//    int front;
//    int rear;
//    int k;//�����������ţ���Ȼ�����޷�������ѭ��
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
//    q->nums = (int*)malloc(sizeof(int) * (k + 1));//ʵ�ʿ�k+1���ռ�
//    q->front = 0;
//    q->rear = 0;
//    q->k = k;
//    return q;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* q, int value) {
//    assert(q);//��ϰ��
//    if (myCircularQueueIsFull(q))//��������������򷵻�false����ʾ����ʧ�ܣ�
//        return false;
//    else
//    {
//        q->nums[q->rear] = value;
//        q->rear++;
//        q->rear = (q->rear == q->k + 1) ? 0 : q->rear;//�ж�rearָ���Ƿ�Խ��
//    }
//    return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* q) {
//    assert(q);
//    if (myCircularQueueIsEmpty(q))//�������Ϊ�վͻ�ɾ��ʧ��
//        return false;
//    else
//    {
//        q->front++;
//        q->front = (q->front == q->k + 1) ? 0 : q->front;//�ж�һ��front�Ƿ�Խ��
//    }
//    return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* q) {
//    assert(q);
//    if (myCircularQueueIsEmpty(q))//�п�
//        return -1;
//    return q->nums[q->front];
//}
//
//int myCircularQueueRear(MyCircularQueue* q) {
//    assert(q);
//    if (myCircularQueueIsEmpty(q))//�п�
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
// ��ʽ�ṹ����ʾ���� 
//typedef int QDataType;
//typedef struct QListNode
//{
//    struct QListNode* next;
//    QDataType val;
//}QNode;
//
//// ���еĽṹ 
//typedef struct Queue
//{
//    QNode* front;
//    QNode* rear;
//    int size;
//}Queue;
//
////��ʼ������
//void QueueInit(Queue* q);
////���ٶ���
//void QueueDestroy(Queue* q);
////�����
//void QueuePush(Queue* q, QDataType x);
////������
//void QueuePop(Queue* q);
////��ȡ��ͷԪ��
//QDataType QueueFront(Queue* q);
////��ȡ��βԪ��
//QDataType QueueBack(Queue* q);
////��ȡ����Ԫ�ظ���
//size_t QueueSize(Queue* q);
////�����п�
//bool QueueEmpty(Queue* q);
////��ʼ������
//void QueueInit(Queue* q)
//{
//    assert(q);
//    q->front = NULL;
//    q->rear = NULL;
//    q->size = 0;
//}
////���ٶ���
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
////�����½ڵ�
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
////�����
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
////������
//void QueuePop(Queue* q)
//{
//    assert(q);
//    assert(QueueEmpty(q) == false);//�п�
//    QNode* next = q->front->next;
//    free(q->front);
//    q->front = next;
//    if (q->front == NULL)//ɾ���ڵ����frontָ��ָ��NULL����ʾ�޽ڵ��ɾ
//        q->rear = q->front;
//    q->size--;
//}
////�����п�
//bool QueueEmpty(Queue* q)
//{
//    assert(q);
//    return (q->front == q->rear && q->front == NULL);
//}
////��ȡ��ͷԪ��
//QDataType QueueFront(Queue* q)
//{
//    assert(q);
//    assert(!QueueEmpty(q));
//    return q->front->val;
//}
////��ȡ��βԪ��
//QDataType QueueBack(Queue* q)
//{
//    assert(q);
//    assert(!QueueEmpty(q));
//    return q->rear->val;
//}
////��ȡ����Ԫ�ظ���
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
//    Queue q2;//���ǵ����������в������ģ�����
//} MyStack;
//
//bool myStackEmpty(MyStack* obj);
//MyStack* myStackCreate() {
//    //�ýṹ�����ڿ����������У�������ɽṹ��Ĵ����ͳ�ʼ������
//    MyStack* NewStack = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&NewStack->q1);
//    QueueInit(&NewStack->q2);//��ɶ����������еĳ�ʼ������
//    //Ҳ���൱������˶�������ṹ��ĳ�ʼ������
//    return NewStack;//���ڸýṹ�����ڶ��Ͽ��ٵĲ������Ÿĺ���ջ֡�����ٶ�����
//    //ֻ�е������ֶ�ȥ����ʱ���Żᱻ���٣�
//}
//
//void myStackPush(MyStack* obj, int x) {
//    //�����ջ����
//    assert(obj);//����һ���õĴ���ϰ�ߣ���֮�û��Ҵ�nullָ��
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;//������Ҫ�Բ�Ϊ�յĶ�����ɲ��������Ϊ�����ǵ���Ҫ֪���Ǹ��Ƿǿնӣ�
//    //����q2�Ƿǿնӣ����Ǽ����ǻ����İ��������Ҫ���Ǿ���
//    if (QueueEmpty(&obj->q2))//���q2�ǿնӣ����������
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    //����������ֻ����ɶӷǿն��еĲ������
//    QueuePush(nonempty, x);
//}
//
//int myStackPop(MyStack* obj) {
//    //��ջ����
//    assert(obj);//��ϰ��
//    assert(myStackEmpty(obj) == false);//��ջΪ�յ�ʱ��Ͳ���Ҫ��ɾ����
//    //���������ж��Ǹ������Ƿǿ�
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if (QueueEmpty(&obj->q2))
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    //���ǿն��е�Ԫ�أ�����β�⣩ȫ�����˵��ն�;
//    while (QueueSize(nonempty) > 1)
//    {
//        QueuePush(empty, QueueFront(nonempty));
//        QueuePop(nonempty);
//    }
//    int top = QueueFront(nonempty);
//    QueuePop(nonempty);//��ɳ�ջ����
//    return top;
//}
//
//int myStackTop(MyStack* obj) {
//    //��ȡջ��Ԫ��
//    assert(obj);
//    assert(myStackEmpty(obj) == false);//��ջΪ�յ�ʱ��Ͳ�Ҫ�ڽ��д˲�����
//    //���������ж��Ǹ������Ƿǿ�
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if (QueueEmpty(&obj->q2))
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//    //�ǿն��еĶ�β���൱��ջ��
//    int top = QueueBack(nonempty);
//    return top;
//}
//
//bool myStackEmpty(MyStack* obj) {
//    assert(obj);
//    return (QueueEmpty(&obj->q1) && (QueueEmpty(&obj->q2)));//ֻ���������ж�Ϊ�գ�����ջ��Ϊ��;
//}
//
//void myStackFree(MyStack* obj) {
//    assert(obj);
//    QueueDestroy(&obj->q1);
//    QueueDestroy(&obj->q2);
//    free(obj);//ע�����ﲻҪһ�������ͷ�obj������������ڴ�й©����Ϊobj֮���ٴ��q1��q2�Ŀռ�û�п��پ���Ķ��пռ䣬���ھ���Ķ��пռ���ͨ��q1��q2ȥ��ɵģ�Ϊ��������Ҫ���ͷŶ��У����ͷŴ洢���еĽṹ�壨obj����
//}
//typedef int DataType;
//typedef struct Stack
//{
//    DataType* nums;
//    int capcity;
//    int top;
//}ST;
////��ʼ��ջ
//void InitStack(ST* ps);
////����ջ
//void DestroyStack(ST* ps);
////��ջ
//void StackPush(ST* ps, DataType x);
////��ջ
//void StackPop(ST* ps);
////�ж�ջ�Ƿ�ΪNULL
//bool StackEmpty(ST* ps);
////ͳ��ջ��Ԫ��
//size_t StackSize(ST* ps);
////��ȡջ��Ԫ�ظ���
//DataType StackTop(ST* ps);
////��ʼ��ջ
//void InitStack(ST* ps)
//{
//    assert(ps);//��ֹ�Ҵ�
//    ps->capcity = 0;
//    ps->top = 0;
//    ps->nums = NULL;
//}
////����ջ
//void DestroyStack(ST* ps)
//{
//    assert(ps);
//    ps->capcity = 0;
//    ps->top = 0;
//    free(ps->nums);
//}
////������ݣ����ṩ���û����ɳ����Լ����
//static void Check_Capcity(ST* ps)
//{
//    assert(ps);
//    if (ps->capcity == ps->top)//��Ҫ����
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
////��ջ
//void StackPush(ST* ps, DataType x)
//{
//    assert(ps);
//    Check_Capcity(ps);
//    ps->nums[ps->top] = x;
//    ps->top++;
//}
////��ջ
//void StackPop(ST* ps)
//{
//    assert(ps);
//    assert(!StackEmpty(ps));//�п�
//    ps->top--;
//}
////�ж�ջ�Ƿ�ΪNULL
//bool StackEmpty(ST* ps)
//{
//    assert(ps);
//    return !ps->top;
//}
////ͳ��ջ��Ԫ��
//size_t StackSize(ST* ps)
//{
//    assert(ps);
//    return ps->top;
//}
////��ȡջ��Ԫ��
//DataType StackTop(ST* ps)
//{
//    assert(ps);
//    assert(!StackEmpty(ps));//ջ��Ϊ�գ����ǲ���Ԫ�ػ�ȡ;
//    return ps->nums[ps->top - 1];
//}
//
//
//typedef struct {
//    ST PushSt;//���ջר�������������ݣ���ջ��
//    ST PopSt;//���ջר������ɾ������  (��ջ)
//} MyQueue;
//
//bool myQueueEmpty(MyQueue* obj);
//MyQueue* myQueueCreate() {
//    //�����ṹ��
//    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
//    InitStack(&q->PushSt);
//    InitStack(&q->PopSt);//��ʼ������ջ
//    return q;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//    //���
//    assert(obj);//��ϰ��
//    //����ֻ��Ҫ��PushStջ�����������
//    StackPush(&obj->PushSt, x);
//}
//
//int myQueuePop(MyQueue* obj) {
//    //����
//    assert(obj);
//    assert(myQueueEmpty(obj) == false);//�п�
//    //ֻ��Ҫ��PopStջ���в�������
//    //��Ȼ���PopStջ����û��Ԫ���ˣ����Ǿ���Ҫ��PushSt�����Ԫ��ȫ��������
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
//    //���븴��
//    int top = myQueuePeek(obj);
//    StackPop(&obj->PopSt);
//    return top;
//}
//
//int myQueuePeek(MyQueue* obj) {
//    assert(obj);
//    assert(myQueueEmpty(obj) == false);
//    //��Ȼ���PopStջ����û��Ԫ���ˣ����Ǿ���Ҫ��PushSt�����Ԫ��ȫ��������
//    if (StackEmpty(&obj->PopSt))
//    {
//        while (StackEmpty(&obj->PushSt) == false)
//        {
//            StackPush(&obj->PopSt, StackTop(&obj->PushSt));
//            StackPop(&obj->PushSt);
//        }
//    }
//    //PopSt��ջ��Ԫ�ؾ��Ƕ�ͷԪ��
//    int top = StackTop(&obj->PopSt);
//    return top;
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//    assert(obj);
//    return ((StackEmpty(&obj->PopSt)) && (StackEmpty(&obj->PushSt)));//����ջͬʱΪ�ն��в�Ϊ��
//}
//
//void myQueueFree(MyQueue* obj) {
//    assert(obj);
//    DestroyStack(&obj->PopSt);
//    DestroyStack(&obj->PushSt);
//    free(obj);//��ǰһ����һ������ѡ���ͷ������ٵ�ջ�����ͷŵ�ǰ�ṹ�壬������ճ��ڴ�й©��
//}
