//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* prev = NULL;
//    struct ListNode* cur = head;
//    struct ListNode* next = NULL;
//    while (cur)
//    {
//        next = cur->next;
//        cur->next = prev;
//        prev = cur;
//        cur = next;
//    }
//    return prev;
//}
//bool hasCycle(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast)//说明带环
//            return true;
//    }
//    return false;
//}
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* curA = headA;
//    struct ListNode* curB = headB;
//    int lenA = 0;
//    int lenB = 0;
//    while (curA->next)
//    {
//        curA = curA->next;
//        lenA++;
//    }
//    while (curB->next)
//    {
//        curB = curB->next;
//        lenB++;
//    }
//    if (curB != curA)
//        return NULL;
//    struct ListNode* LongList = headA;
//    struct ListNode* ShortList = headB;
//    if (lenB > lenA)
//    {
//        LongList = headB;
//        ShortList = headA;
//    }
//    int gap = abs(lenB - lenA);
//    while (gap--)
//    {
//        LongList = LongList->next;
//    }
//    while (LongList)
//    {
//        if (LongList == ShortList)
//            break;
//        LongList = LongList->next;
//        ShortList = ShortList->next;
//    }
//    return ShortList;
//}
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast)//说明带环
//        {
//            //核心部分
//            struct ListNode* plist = head;
//            struct ListNode* meet = slow->next;
//            slow->next = NULL;
//            return getIntersectionNode(plist, meet);
//        }
//    }
//    return NULL;//链表无环
//}