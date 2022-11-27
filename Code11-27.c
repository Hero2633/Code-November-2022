//#include<stdio.h>
//#include<stdlib.h>
//void Swap(int* a, int* b)
//{
//	int tmo = *a;
//	*a = *b;
//	*b = tmo;
//}
//void PrintfArr(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//		printf("%d ", arr[i]);
//}
//void Quick(int* nums, int left, int right)
//{
//	if (left >= right)
//		return;
//	int begin = left;
//	int end = right;
//	int key = left;
//	while (left < right)
//	{
//		while (left < right && nums[right] >= nums[key])
//			right--;
//		while (left < right && nums[left] <= nums[key])
//			left++;
//		Swap(nums+left,nums+right);
//	}
//	Swap(nums+left,nums+key);
//	Quick(nums, begin, left - 1);
//	Quick(nums,right+1,end);
//}
//void QuickSort(int* nums, int len)
//{
//	Quick(nums,0,len-1);
//}
//void QuickSortTest()
//{
//	int arr[] = { 9,1,2,5,7,4,8,6,3,5 };
//	int len = sizeof(arr) / sizeof(int);
//	QuickSort(arr,len);
//	PrintfArr(arr,len);
//}
//void InsertSort(int* nums, int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		int end=i;
//		int key = nums[end + 1];
//		while (end >= 0)
//		{
//			if (key >= nums[end])//排升序
//				break;
//			else
//			{
//				nums[end + 1] = nums[end];
//				end--;
//			}
//		}
//		nums[end + 1] = key;
//	}
//}
//void ShellSort(int* nums, int len)
//{
//	int gap = len;
//	while (gap>1)
//	{
//		gap /= 2;
//			for (int i = 0; i < len - gap; i +=1)
//			{
//				int end = i;
//				int key = nums[end + gap];
//				while (end >= 0)
//				{
//					if (key >= nums[end])
//						break;
//					else
//					{
//						nums[end + gap] = nums[end];
//						end -= gap;
//					}
//				}
//				nums[end + gap] = key;
//			}
//	}
//}
//void AdjustDown(int* nums, int top, int len)
//{
//	int parent = top;
//	int child = 2 * top + 1;
//	while (child < len)
//	{
//		if (child + 1 < len && nums[child + 1] > nums[child])
//			child++;
//		if (nums[parent] >= nums[child])
//			break;
//		else
//		{
//			Swap(nums+parent,nums+child);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//	}
//}
//void HeapSort(int* nums, int len)
//{
//	//1、建大堆
//	for (int top = (len - 2) / 2; top >= 0; top--)
//		AdjustDown(nums,top,len);
//	
//	//2、选数排序
//	int size = len;
//	while (size > 1)
//	{
//		Swap(nums,nums+size-1);
//		size--;
//		AdjustDown(nums,0,size);
//	}
//}
//void SelectSort(int* nums, int len)
//{
//	int left = 0;
//	int right = len - 1;
//	int maxi = left;
//	int mini = left;
//	while (left < right)
//	{
//		maxi = left;
//		mini = left;
//		for (int i = left; i <= right; i++)
//		{
//			if (nums[i] > nums[maxi])
//				maxi = i;
//			if (nums[i] < nums[mini])
//				mini = i;
//		}
//		if (maxi == left)
//			maxi = mini;
//		Swap(nums+left,nums+mini);
//		Swap(nums+right,nums+maxi);
//		left++;
//		right--;
//	}
//}
//void BubbleSort(int* nums, int len)
//{
//	for (int j = 0; j < len-1; j++)
//	{
//		for (int i = 0; i < len - 1-j; i++)
//		{
//			if (nums[i + 1] < nums[i])
//				Swap(nums + i, nums + i + 1);
//		}
//	}
//}
//void Merge(int* nums, int left, int right,int*tmp)
//{
//	if (left >= right)
//		return;
//	int mid = ((right - left)>> 1) + left;
//	Merge(nums, left, mid, tmp);
//	Merge(nums,mid+1,right,tmp);
//	int begin1 = left;
//	int end1 = mid;
//	int begin2 = mid + 1;
//	int end2 = right;
//	int j = 0;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (nums[begin1] < nums[begin2])
//		{
//			tmp[j++] = nums[begin1];
//			begin1++;
//		}
//		else
//		{
//			tmp[j++] = nums[begin2];
//			begin2++;
//		}
//	}
//	    while (begin1 <= end1)
//		tmp[j++] = nums[begin1++];
//		while (begin2 <= end2)
//		tmp[j++] = nums[begin2++];
//		int k = left;
//		for (int i = 0; i < j; i++)
//			nums[k++] = tmp[i];
//	
//}
//void MergeSort(int* nums, int len)
//{
//	int* tmp = (int*)calloc(len, sizeof(int));
//	Merge(nums, 0, len - 1,tmp);
//	free(tmp);
//}
//void InsertSortTest()
//{
//	int nums[] = {9,1,2,5,7,4,8,6,3,5};
//	int len = sizeof(nums) / sizeof(int);
//	InsertSort(nums,len);
//	PrintfArr(nums,len);
//}
//void ShellSortTest()
//{
//	int nums[] = { 9,1,2,5,7,4,8,6,3,5 };
//	int len = sizeof(nums) / sizeof(int);
//	ShellSort(nums,len);
//	PrintfArr(nums,len);
//}
//void HeapSortTest()
//{
//	int nums[] = { 9,1,2,5,7,4,8,6,3,5 };
//	int len = sizeof(nums) / sizeof(int);
//	HeapSort(nums,len);
//	PrintfArr(nums,len);
//}
//void SelectSortTest()
//{
//	int nums[] = { 9,1,2,5,7,4,8,6,3,5 };
//	int len = sizeof(nums) / sizeof(int);
//	SelectSort(nums,len);
//	PrintfArr(nums,len);
//}
//void BubbleSortTest()
//{
//	int nums[] = { 9,1,2,5,7,4,8,6,3,5 };
//	int len = sizeof(nums) / sizeof(int);
//	BubbleSort(nums,len);
//	PrintfArr(nums,len);
//}
//void MergeSortTest()
//{
//	int nums[] = { 9,1,2,5,7,4,8,6,3,5 };
//	int len = sizeof(nums) / sizeof(int);
//	MergeSort(nums,len);
//	PrintfArr(nums,len);
//}
//void TestOP()
//{
//	srand(time(0));
//	const int N = 1000000;
//	int* a1 = (int*)malloc(sizeof(int) * N);
//	int* a2 = (int*)malloc(sizeof(int) * N);
//	int* a3 = (int*)malloc(sizeof(int) * N);
//	int* a4 = (int*)malloc(sizeof(int) * N);
//	int* a5 = (int*)malloc(sizeof(int) * N);
//	int* a6 = (int*)malloc(sizeof(int) * N);
//	for (int i = 0; i < N; ++i)
//	{
//		a1[i] = rand();
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
//	}
//	int begin1 = clock();
//	InsertSort(a1, N);
//	int end1 = clock();
//	int begin2 = clock();
//	ShellSort(a2, N);
//	int end2 = clock();
//	int begin3 = clock();
//	SelectSort(a3, N);
//	int end3 = clock();
//	int begin4 = clock();
//	HeapSort(a4, N);
//	int end4 = clock();
//	int begin5 = clock();
//	QuickSort(a5, 0, N - 1);
//	int end5 = clock();
//	int begin6 = clock();
//	MergeSort(a6, N);
//	int end6 = clock();
//	printf("InsertSort:%d\n", end1 - begin1);
//	printf("ShellSort:%d\n", end2 - begin2);
//	printf("SelectSort:%d\n", end3 - begin3);
//	printf("HeapSort:%d\n", end4 - begin4);
//	printf("QuickSort:%d\n", end5 - begin5);
//	printf("MergeSort:%d\n", end6 - begin6);
//	free(a1);
//	free(a2);
//	free(a3);
//	free(a4);
//	free(a5);
//	free(a6);
//}
//int main()
//{
//	QuickSortTest();
//	//InsertSortTest();
//	//ShellSortTest();
//	//HeapSortTest();
//	//SelectSortTest();
//	//BubbleSortTest();
//	//MergeSortTest();
//	//TestOP();
//	return 0;
//}