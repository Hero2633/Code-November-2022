//int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//    int i = 0;
//    int j = 0;
//    int index = 0;
//    int* ret = (int*)malloc(sizeof(int) * nums1Size);
//    for (i = 0; i < nums1Size; i++)
//    {
//        for (j = 0; j < nums2Size; j++)
//        {
//            if (nums1[i] == nums2[j])
//            {
//                for (int k = j + 1; k < nums2Size; k++)
//                {
//                    if (nums2[k] > nums1[i])
//                    {
//                        ret[index++] = nums2[k];
//                        goto flag;
//                    }
//                }
//                ret[index++] = -1;
//                goto flag;
//            }
//        }
//    flag:
//    }
//    *returnSize = index;
//    return ret;
//}
//#include"Queue.h"
//int Step(int* nums, int len)
//{
//	int max = nums[0];
//	for (int i = 0; i < len; i++)
//		max = max < nums[i] ? nums[i] : max;
//	int count = 0;
//	while (max)
//	{
//		count++;
//		max /= 10;
//	}
//	return count;
//}
//void CardinalitySort(int* nums, int len)
//{
//	int step = Step(nums,len);
//	Queue Q[10] = { 0 };
//	//对桶进行初始化
//	for (int i = 0; i < 10; i++)
//		QueueInit(Q + i);
//	int x = 1;
//	for (int k = 0; k < step; k++)
//	{
//		for (int i = 0; i < len; i++)
//		{
//			int tmp = nums[i];
//			tmp /= x;
//			//进入桶
//			QueuePush(Q+tmp%10,nums[i]);
//		}
//		//开始往回拷贝
//		int j = 0;
//		for (int i = 0; i < 10; i++)
//		{
//			//对每个桶都这样操作
//			while (QueueEmpty(Q + i) == false)
//			{
//				nums[j++] = QueueFront(Q+i);
//				QueuePop(Q+i);
//			}
//		}
//		x *= 10;
//	}
//	for (int i = 0; i < 10; i++)
//		QueueDestroy(Q+i);
//}
//void Printf(int* nums, int len)
//{
//	for (int i = 0; i < len; i++)
//		printf("%d ",nums[i]);
//}
//void test1()
//{
//	int arr[] = {27,49,38,55,97,76,13};
//	int len = sizeof(arr) / sizeof(int);
//	CardinalitySort(arr,len);
//		Printf(arr,len);
//}
//int main()
//{
//	test1();
//	return 0;
//}
//void deleteNode(struct ListNode* node) {
//    struct ListNode* next = node->next;
//    *node = *next;
//    free(next);
//}
//struct ListNode* oddEvenList(struct ListNode* head) {
//    struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* tail1 = head1;
//    struct ListNode* tail2 = head2;
//    tail1->next = NULL;
//    tail2->next = NULL;
//    struct ListNode* cur = head;
//    int index = 1;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        if (index % 2)
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
//        index++;
//        cur = next;
//    }
//    tail1->next = head2->next;
//    struct ListNode* phead = head1->next;
//    free(head1);
//    free(head2);
//    return phead;
//}