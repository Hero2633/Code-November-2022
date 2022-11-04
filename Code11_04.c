#pragma warning (disable:4996)
#include<stdio.h>
//struct Student
//{
//	char Id[20];
//	float grade;
//};
//void SelectionSort(struct Student* nums, int len)
//{
//	int index = 0;
//	struct Student min = nums[0];
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < len-1; i++)
//	{
//		index = i;
//		min = nums[i];
//		for (j = i; j < len; j++)
//		{
//			if (nums[j].grade > min.grade)
//			{
//				index = j;
//				min = nums[j];
//			}
//		}
//		struct Student tmp = nums[i];
//		nums[i] = min;
//		nums[index] = tmp;
//	}
//}
//int main()
//{
//	struct Student class[50] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//	for (int j = 0; j < n; j++)
//	{
//		scanf("%s", (class + j)->Id);
//		scanf("%f",&((class+j)->grade));
//	}
//	int len = n;
//	SelectionSort(class,len);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%s %f\n",class[i].Id,class[i].grade);
//	}
//	return 0;
//}
//不带哨兵位
//时间复杂度：O（N）
//空间复杂度的：O（1）
//struct ListNode* partition(struct ListNode* head, int x) {
//    struct ListNode* Newhead1 = NULL;//链接小于x的
//    struct ListNode* tail1 = NULL;
//    struct ListNode* Newhead2 = NULL;//链接大于等于x的
//    struct ListNode* tail2 = NULL;
//    struct ListNode* cur = head;
//    struct ListNode* next = NULL;
//    while (cur)
//    {
//        next = cur->next;
//        if (cur->val < x)
//        {
//            if (tail1 == NULL)//一个节点都还没链接
//            {
//                Newhead1 = tail1 = cur;
//            }
//            else
//            {
//                tail1->next = cur;
//                tail1 = cur;
//            }
//            tail1->next = NULL;
//        }
//        else
//        {
//            if (tail2 == NULL)//一个节点都还没链接
//            {
//                Newhead2 = tail2 = cur;
//            }
//            else
//            {
//                tail2->next = cur;
//                tail2 = cur;
//            }
//            tail2->next = NULL;
//        }
//        cur = next;
//    }
//    if (tail1 == NULL)
//        Newhead1 = tail1 = Newhead2;
//    else
//        tail1->next = Newhead2;
//    return Newhead1;
//}
//struct ListNode* partition(struct ListNode* head, int x) {
//    struct ListNode* dummyhead1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* tail1 = dummyhead1;
//    tail1->next = NULL;
//    struct ListNode* dummyhead2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* tail2 = dummyhead2;
//    tail2->next = NULL;
//    struct ListNode* cur = head;
//    struct ListNode* next = NULL;
//    while (cur)
//    {
//        next = cur->next;
//        if (cur->val < x)
//        {
//            tail1->next = cur;
//            tail1 = cur;
//            tail1->next = NULL;
//        }
//        else
//        {
//            tail2->next = cur;
//            tail2 = cur;
//            tail2->next = NULL;
//        }
//        cur = next;
//    }
//    tail1->next = dummyhead2->next;
//    struct ListNode* plist = dummyhead1->next;
//    free(dummyhead2);
//    free(dummyhead1);
//    return plist;
//}
//struct ListNode* reverse_List(struct ListNode* head)
//{
//    struct ListNode* plist = NULL;
//    struct ListNode* next = head;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        next = cur->next;
//        cur->next = plist;
//        plist = cur;
//        cur = next;
//    }
//    return plist;
//}
//bool isPalindrome(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    struct ListNode* Newhead1 = head;
//    //1、找中间节点
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    //找到中间节点了，反转slow~NULL部分;
//    struct ListNode* Newhead2 = reverse_List(slow);
//    //反转完毕，开始比较Newhead1链表和Newhead2链表,当Newhead2等于NULL==>true
//    while (Newhead2)
//    {
//        if (Newhead2->val == Newhead1->val)
//        {
//            Newhead1 = Newhead1->next;
//            Newhead2 = Newhead2->next;
//        }
//        else
//            return false;
//    }
//    return true;
//}
//size_t CountList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    int len = 0;
//    while (cur)
//    {
//        len++;
//        cur = cur->next;
//    }
//    return len;
//}
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* cur1 = headA;
//    struct ListNode* cur2 = headB;
//    int len1 = CountList(headA);
//    int len2 = CountList(headB);
//    int k = 0;
//    if (len2 > len1)
//    {
//        k = len2 - len1;
//        while (k--)
//            cur2 = cur2->next;
//    }
//    else
//    {
//        k = len1 - len2;
//        while (k--)
//            cur1 = cur1->next;
//    }
//    while (cur2)
//    {
//        if (cur1 != cur2)
//        {
//            cur1 = cur1->next;
//            cur2 = cur2->next;
//        }
//        else
//            return cur1;
//    }
//    return NULL;
//}
//#include<stdlib.h>
//
//struct ListNode {
//	int val;
//	struct ListNode* next;
//
//};
//struct ListNode* CreatList(int* nums, int len)
//{
//	struct ListNode* dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (dummyhead == NULL)
//		exit(-1);
//	struct ListNode* tail = dummyhead;
//	tail->next = NULL;
//	for (int i = 0; i < len; i++)
//	{
//		struct ListNode* NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//		if (NewNode == NULL)
//			exit(-1);
//		NewNode->next = NULL;
//		NewNode->val = nums[i];
//		tail->next = NewNode;
//		tail = NewNode;
//	}
//	struct ListNode* plist = dummyhead->next;
//	free(dummyhead);
//	return plist;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int len = sizeof(arr) / sizeof(int);
//	struct ListNode* head = CreatList(arr, len);
//	while (head)
//	{
//		printf("%d->", head->val);
//		head = head->next;
//	}
//	printf("NULL\n");
//	return 0;
//}
