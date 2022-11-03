#include<stdio.h>
//int main()
//{
//	printf("hell Win10!\n");
//	return 0;
//}
//#include<stdio.h>
//void tian(int arr[], int i)
//{
//	int m = 0;
//	for (m = 0; m < i; m++)
//	{
//		int n = 0;
//		for (n = 0; n < i-m-1; n++)
//		{
//			if (arr[n] > arr[n + 1])
//			{
//				int num = arr[n];
//				arr[n] = arr[n + 1];
//				arr[n + 1] = num;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 2,3,4,62,9,45,75,26,95 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int m = 0;
//	tian(arr, sz);
//	for (m = 0; m < sz; m++)
//	{
//		printf("%d ", arr[m]);
//	}
//	return 0;
//
//}
//#include<stdio.h>
//
//void tian(int arr[], int i)
//
//{
//
//	int m = 0;
//
//	for (m = 0; m < i; m++)
//
//	{
//
//		int n = 0;
//
//		for (n = m; n < i; n++)
//
//		{
//
//			if (arr[n] > arr[n + 1])
//
//			{
//
//				int num = arr[n];
//
//				arr[n] = arr[n + 1];
//
//				arr[n + 1] = num;
//
//			}
//
//		}
//
//	}
//
//}
//
//int main()
//
//{
//
//	int arr[] = { 2,3,4,62,9,45,75,26,95 };
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int m = 0;
//
//	tian(arr, sz);
//
//	for (m = 0; m < sz; m++);
//
//	{
//
//		printf("%d ", arr[m]);
//
//	}
//
//	return 0;
//
//}
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* Newhead = NULL;
//    struct ListNode* tail = NULL;
//    struct ListNode* cur = head;
//    struct ListNode* next = NULL;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            next = cur->next;
//            free(cur);
//            cur = next;
//        }
//        else
//        {
//            if (tail == NULL)
//            {
//                next = cur->next;
//                Newhead = tail = cur;
//                tail->next = NULL;
//                cur = next;
//            }
//            else
//            {
//                next = cur->next;
//                tail->next = cur;
//                tail = cur;
//                tail->next = NULL;
//                cur = next;
//            }
//        }
//    }
//    return Newhead;
//}
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* Newhead = NULL;
//    struct ListNode* tail = NULL;
//    struct ListNode* l1 = list1;
//    struct ListNode* l2 = list2;
//    struct ListNode* next = NULL;
//    while (l1 && l2)
//    {
//        if (l1->val > l2->val)
//        {
//            if (tail == NULL)
//            {
//                next = l2->next;
//                Newhead = tail = l2;
//                tail->next = NULL;
//                l2 = next;
//            }
//            else
//            {
//                next = l2->next;
//                tail->next = l2;
//                tail = l2;
//                tail->next = NULL;
//                l2 = next;
//            }
//        }
//        else
//        {
//            if (tail == NULL)
//            {
//                next = l1->next;
//                Newhead = tail = l1;
//                tail->next = NULL;
//                l1 = next;
//            }
//            else
//            {
//                next = l1->next;
//                tail->next = l1;
//                tail = l1;
//                tail->next = NULL;
//                l1 = next;
//            }
//        }
//    }
//    if (l1)
//    {
//        if (tail == NULL)
//            Newhead = l1;
//        else
//            tail->next = l1;
//    }
//    if (l2)
//    {
//        if (tail == NULL)
//            Newhead = l2;
//        else
//            tail->next = l2;
//    }
//    return Newhead;
//}
//时间复杂度：O（N）
//空间复杂度：O（1）
//带哨兵位
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* l1 = list1;
//    struct ListNode* l2 = list2;
//    struct ListNode tmp;
//    struct ListNode* DummyHead = &tmp;
//    DummyHead->next = NULL;
//    struct ListNode* tail = DummyHead;
//    struct ListNode* next = NULL;
//    while (l1 && l2)
//    {
//        if (l1->val > l2->val)
//        {
//            next = l2->next;
//            tail->next = l2;
//            tail = l2;
//            tail->next = NULL;
//            l2 = next;
//        }
//        else
//        {
//            next = l1->next;
//            tail->next = l1;
//            tail = l1;
//            tail->next = NULL;
//            l1 = next;
//        }
//    }
//    if (l1)
//        tail->next = l1;
//    if (l2)
//        tail->next = l2;
//    return DummyHead->next;
//}