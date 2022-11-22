#include<stdio.h>
//void Swap(int*a,int*b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void PrintfArr(int* nums, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ",nums[i]);
//	}
//}
//void AdjustDown(int* nums, int top, int len)
//{
//	int parent = top;
//	int child = 2 * parent + 1;
//	while (child < len)
//	{
//		if (child + 1 < len && nums[child + 1] < nums[child])
//			child++;
//		if (nums[parent] <= nums[child])//说明符合条件
//			break;
//		else
//		{
//			Swap(nums+parent,nums+child);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//	}
//}
//void HeapSort1(int* nums, int len)
//{
//	//1、建堆(向下调整算法)
//	for (int top = (len - 2) / 2; top >= 0; top--)
//		AdjustDown(nums,top,len);
//	//2、开始选数排序
//	int size = len;
//	while (size > 1)
//	{
//		Swap(nums,nums+size-1);
//		size--;
//		AdjustDown(nums,0,size);
//	}
//}
//void test1()
//{
//	int nums[] = { 20,11,28,9,3,12,54,32,-3,42,-5 };
//	int len = sizeof(nums)/sizeof(int);
//	HeapSort1(nums,len);
//	PrintfArr(nums,len);
//}
//void AdjustUp(int* nums, int end)
//{
//	int child = end;
//	int parent = (end - 1) / 2;
//	while (child > 0)
//	{
//		if (nums[child] >= nums[parent])//是小堆没问题
//			break;
//		else
//		{
//			Swap(nums+child,nums+parent);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//	}
//}
//void HeapSort2(int* nums, int len)
//{
//	//1、利用向上调整算法建堆
//	for (int i = 0; i < len; i++)
//		AdjustUp(nums,i);
//	//2、开始选数排序
//	int size = len;
//	while (size > 1)
//	{
//		Swap(nums,nums+size-1);
//		size--;
//		AdjustDown(nums,0,size);
//	}
//}
//void test2()
//{
//	int nums[] = { 20,11,28,9,3,12,54,32,-3,42,-5 };
//	int len = sizeof(nums) / sizeof(int);
//	HeapSort2(nums, len);
//	PrintfArr(nums, len);
//}
//void Swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void AdjustDown(int* nums, int top, int end)
//{
//    int parent = top;
//    int child = (2 * parent) + 1;
//    while (child < end)
//    {
//        if (child + 1 < end && nums[child + 1] > nums[child])
//            child++;
//        if (nums[parent] >= nums[child])
//            break;
//        else
//        {
//            Swap(nums + parent, nums + child);
//            parent = child;
//            child = 2 * parent + 1;
//        }
//    }
//}
//int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
//    *returnSize = k;
//    //1、前k个数建大堆
//    for (int i = (k - 2) / 2; i >= 0; --i)
//        AdjustDown(arr, i, k);
//    for (int j = k; j < arrSize; j++)
//    {
//        if (arr[j] < arr[0])
//        {
//            Swap(arr, arr + j);
//            AdjustDown(arr, 0, k);
//        }
//    }
//    return arr;
//}
//int main()
//{
//	test1();
//	printf("\n");;
//	test2();
//	return 0;
//}
//
//int Dig_pit(int* nums, int left, int right)
//{
//    int pit = left;
//    int key = nums[pit];
//    while (left < right)
//    {
//        while (left < right && nums[right] <= key)
//            right--;
//        nums[pit] = nums[right];
//        pit = right;
//        while (left < right && nums[left] > key)
//            left++;
//        nums[pit] = nums[left];
//        pit = left;
//    }
//    nums[left] = key;
//    return right;
//}
//
//int findKthLargest(int* nums, int numsSize, int k) {
//    int index = 0;
//    int left = 0;
//    int right = numsSize - 1;
//    while (((index = Dig_pit(nums, left, right)) + 1) != k)
//    {
//        if (index + 1 < k)
//            left = index + 1;
//        else if (index + 1 > k)
//            right = index - 1;
//    }
//    return nums[index];
//}
//int main()
//{
//    int arr[] = {3,2,1,5,6,4};
//    findKthLargest(arr,6,2);
//    return 0;
//}