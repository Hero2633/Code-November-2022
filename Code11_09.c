//int SearchStep(struct Node* head, struct Node* random)
//{
//    if (random == NULL)
//        return -1;
//    struct Node* cur = head;
//    int step = 0;
//    while (cur)
//    {
//        if (cur == random)
//            break;
//        else
//        {
//            step++;
//            cur = cur->next;
//        }
//    }
//    return step;
//}
//struct Node* CopyRandom(struct Node* head, int step)
//{
//    struct Node* cur = head;
//    while (step--)
//        cur = cur->next;
//    return cur;
//}
//struct Node* copyRandomList(struct Node* head) {
//    struct Node* CopyHead = NULL;
//    struct Node* cur = head;
//    struct Node* copy = NULL;
//    struct Node* tail = NULL;
//    while (cur)
//    {
//        copy = (struct Node*)malloc(sizeof(struct Node));
//        copy->val = cur->val;
//        if (CopyHead == NULL)
//        {
//            CopyHead = tail = copy;
//            tail->next = NULL;
//        }
//        else
//        {
//            tail->next = copy;
//            tail = copy;
//            tail->next = NULL;
//        }
//        cur = cur->next;
//    }
//    cur = head;
//    copy = CopyHead;
//    while (cur)
//    {
//        struct Node* random = cur->random;
//        int step = SearchStep(head, random);
//        if (step == -1)
//        {
//            copy->random = NULL;
//        }
//        else
//        {
//            struct Node* copyrandom = CopyRandom(CopyHead, step);
//            copy->random = copyrandom;
//        }
//        cur = cur->next;
//        copy = copy->next;
//    }
//    return CopyHead;
//}
//struct Node* copyRandomList(struct Node* head) {
//    struct Node* cur = head;
//    struct Node* next = NULL;
//    struct Node* copy = NULL;
//    while (cur)
//    {
//        next = cur->next;
//        copy = (struct Node*)malloc(sizeof(struct Node));
//        copy->val = cur->val;
//        copy->next = next;
//        cur->next = copy;
//        cur = next;
//    }
//    cur = head;
//    while (cur)
//    {
//        copy = cur->next;
//        if (cur->random == NULL)
//        {
//            copy->random = NULL;
//        }
//        else
//        {
//            copy->random = cur->random->next;
//        }
//        cur = copy->next;
//    }
//    cur = head;
//    struct Node* CopyHead = NULL;
//    struct Node* CopyTail = NULL;
//    while (cur)
//    {
//        copy = cur->next;
//        next = copy->next;
//        cur->next = next;
//        if (CopyHead == NULL)
//        {
//            CopyHead = CopyTail = copy;
//            CopyTail->next = NULL;
//        }
//        else
//        {
//            CopyTail->next = copy;
//            CopyTail = copy;
//            CopyTail->next = NULL;
//        }
//        cur = next;
//    }
//    return CopyHead;
//}\
//struct ListNode *detectCycle(struct ListNode *head) {
//struct ListNode* slow = head;
//struct ListNode* fast = head;
//while (fast && fast->next)
//{
//    slow = slow->next;
//    fast = fast->next->next;
//    if (slow == fast)
//    {
//        struct ListNode* meet = slow;
//        struct ListNode* plist = head;
//        while (plist != meet)
//        {
//            plist = plist->next;
//            meet = meet->next;
//        }
//        return meet;
//    }
//}
//return NULL;
//}