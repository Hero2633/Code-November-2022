//#include<stdio.h>
//#include<time.h>
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void PrintfArr(int* nums, int len)
//{
//	for (int i = 0; i < len; i++)
//		printf("%d ",nums[i]);
//}
//void AdjustDown(int* nums, int top, int end)
//{
//	int parent = top;
//	int child = 2 * parent + 1;
//	while (child < end)
//	{
//		if (child + 1 < end && nums[child + 1] > nums[child])
//			child++;
//		if (nums[parent] < nums[child])
//		{
//			Swap(nums + parent, nums + child);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else
//			break;
//	}
//}
//void test1()
//{
//	int arr[] = {9,15,30,11,12,29,23};
//	int len = sizeof(arr)/sizeof(int);
//	AdjustDown(arr, 0, len);
//	PrintfArr(arr,len);
//}
//void test2()
//{
//	int arr[] = {20,11,1,22,0,19,75,8,31};
//	int len = sizeof(arr) / sizeof(int);
//	//利用向下调整算法建立大堆，时间复杂度O(N)
//	for (int top = (len - 2) / 2; top >= 0; top--)
//	{
//		AdjustDown(arr,top,len);
//	}
//	PrintfArr(arr,len);
//}
//void AdjustUp(int* nums, int end)
//{
//	int child = end - 1;
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (nums[child] > nums[parent])
//		{
//			Swap(nums + parent, nums + child);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//			break;
//	}
//}
//void test3()
//{
//	int arr[] = { 20,11,1,22,0,19,75,8,31 };
//	int len = sizeof(arr) / sizeof(int);
//	//利用向上调整算法建堆，时间复杂度O（NlogN）
//	for (int i = 0; i < len; i++)
//	{
//		AdjustUp(arr,i+1);
//	}
//	PrintfArr(arr, len);
//}
//void HeapSort1(int* nums, int len)//利用向下调整算法
//{
//	for (int top = (len - 2) / 2; top >= 0; top--)
//	{
//		AdjustDown(nums,top,len);
//	}
//	int size = len;
//	while (size > 1)
//	{
//		Swap(nums,nums+size-1);
//		size--;
//		AdjustDown(nums,0,size);
//	}
//}
//void HeapSort2(int* nums, int len)
//{
//	for (int i = 0; i < len; i++)
//		AdjustUp(nums,i+1);
//	int size = len;
//	while (size > 1)
//	{
//		Swap(nums, nums + size - 1);
//		size--;
//		AdjustDown(nums, 0, size);
//	}
//}
//#include<stdlib.h>
//#define SIZE 400000000
//void test4()
//{
//	int* tmp = (int*)malloc(sizeof(int) * SIZE);
//	if (!tmp)
//		exit(-1);
//	for (int i = 0; i < SIZE; i++)
//		tmp[i] = rand() % 1000;
//	clock_t left1 = clock();
//	HeapSort2(tmp, SIZE);
//
//	clock_t right1 = clock();
//
//	clock_t left2 = clock();
//	HeapSort1(tmp, SIZE);
//
//	clock_t right2 = clock();
//	printf("向上调整算法:%.6fs\n", (float)(right1 - left1) / CLOCKS_PER_SEC);
//	printf("向下调整算法:%.6fs\n",(float)(right2-left2)/CLOCKS_PER_SEC);
//}
//int main()
//{
//	srand((size_t)time(NULL));
//	//test1();
//	//test2();
//	//test3();
//	test4();
//	return 0;
////}
//#include<iostream>
//#include<string>
