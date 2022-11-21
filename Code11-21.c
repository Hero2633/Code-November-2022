//#include"Heap.h"
//void test1()
//{
//	Hp hp;
//	HeapInit(&hp);
//	int arr[] = { 20,1,11,29,38,40,2,4,0,53 };
//	int len = sizeof(arr) / sizeof(int);
//	//1、建堆
//	for (int i = 0; i < len; i++)
//	{
//		HeapPush(&hp,arr[i]);
//	}
//	int j = len-1;
//	//2、选取堆顶元素返回元素组
//	while (HeapEmpty(&hp) == false)
//	{
//		arr[j--] = HeapTop(&hp);
//		HeapPop(&hp);
//	}
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	HeapDestroy(&hp);
//}
//void Swap(int *a,int*b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void AdjustUp1(int *nums,int len)
//{
//	int child = len - 1;
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (nums[child] > nums[parent])
//		{
//			Swap(nums + child, nums + parent);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//			break;
//	}
//}
//void test2()
//{
//	int arr[] = { 20,1,11,29,38,40,2,4,0,53 };
//	int len = sizeof(arr) / sizeof(int);
//	//1、利用向下调整算法建堆：
//	for (int i = 0; i < len; i++)
//	{
//		AdjustUp1(arr,i+1);
//	}
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void AdjustDown1(int* nums, int top, int end)
//{
//	int parent = top;
//	int child = 2 * parent + 1;
//	while (child < end)
//	{
//		if (child + 1 < end && nums[child + 1] > nums[child])
//			child++;
//		if (nums[child] > nums[parent])
//		{
//			Swap(nums + child, nums + parent);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else
//			break;
//	}
//}
//void test3()
//{
//	int arr[] = { 20,1,11,29,38,40,2,4,0,53 };
//	int len = sizeof(arr) / sizeof(int);
//	//1、利用向下调整算法建堆：
//	for (int i =(len-1-1)/2; i>=0; i--)
//	{
//		AdjustDown1(arr, i,len);
//	}
//	//2、开始选数排序
//	int size = len;
//	while (size > 1)
//	{
//		Swap(arr,arr+size-1);
//		size--;
//		AdjustDown1(arr,0,size);
//	}
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}
//void AdjustDown(int* nums, int top, int end)//向下调整算法
//{
//	int parent = top;
//	int child = 2 * parent + 1;
//	while (child < end)
//	{
//		if (child + 1 < end && nums[child + 1] > nums[child])
//			child++;
//		if (nums[parent] < nums[child])
//		{
//			int tmp = nums[parent];
//			nums[parent] = nums[child];
//			nums[child] = tmp;
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else
//			break;
//	}
//}
//int* smallestK(int* arr, int arrSize, int k, int* returnSize) {
//	for (int top = (k - 1 - 1) / 2; top >= 0; top--)//1、前k个元素先建堆
//		AdjustDown(arr, top, k);
//	for (int j = k; j < arrSize; j++)
//	{
//		if (arr[j] < arr[0])//开始验证假设
//		{
//			int rmp = arr[0];
//			arr[0] = arr[j];
//			arr[j] = rmp;
//			AdjustDown(arr, 0, k);
//		}
//	}
//	*returnSize = k;
//	return arr;
//}
//#include<stdbool.h>
//bool is_BigRoot(int* nums, int top, int len)
//{
//	if (top >= len)
//		return true;
//	bool L = is_BigRoot(nums, 2 * top + 1, len);
//	bool R = is_BigRoot(nums,2*top+2,len);
//	if (L && R)
//	{
//		int child = 2 * top + 1;
//		if (child < len)
//		{
//			if (child + 1 < len && nums[child + 1] > nums[child])
//				child++;
//			return nums[top] >= nums[child] ? true : false;
//		}
//		else
//			return true;
//	}
//	return false;
//}
//
//int main()
//{
//	int arr[] = { 0,5 };
//	int len = sizeof(arr) / sizeof(int);
//	bool ret = is_BigRoot(arr,0,len);
//	if (ret)
//		printf("Yes!\n");
//	return 0;
//}
//#include"Stack.h"
//void test5()
//{
//	int arr[] = {7,6,1,3,2,5,4};
//	int N = 7;
//	int M = 5;
//	ST Container;
//	ST bottle;
//	InitStack(&Container);
//	InitStack(&bottle);
//	int step = 1;
//	int i = 0;
//	while (1)
//	{
//		while (StackEmpty(&Container) == false && (StackTop(&Container) == step))
//		{
//			StackPush(&bottle,step++);
//			StackPop(&Container);
//		}
//		if(i<N&&arr[i]==step)
//		{
//			StackPush(&bottle,step++);
//			i++;
//		}
//		else
//		{
//			if (StackSize(&Container) == M)
//			{
//				printf("NO\n");
//				return 0;
//			}
//			else
//				StackPush(&Container,arr[i]);
//			i++;
//		}
//	}
//
//}
//int main()
//{
//	test5();
//	return 0;
//}
