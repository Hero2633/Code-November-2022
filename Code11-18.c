//#include<stdio.h>
//void PrintfArr(int*nums,int len)
//{
//	for (int i = 0; i < len; i++)
//		printf("%d ",nums[i]);
//}
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
////void AdjustDown(int* nums, int top, int len);
////void HeapCreat(int* nums, int len)
////{
////	for (int parent = (len - 1 - 1) / 2; parent >= 0; parent--)
////	{
////		AdjustDown(nums,parent,len);
////	}
////}
////
////void AdjustDown(int* nums, int top,int len)
////{
////	int parent = top;
////	int child = 2 * parent + 1;//�������������������д��
////	while (child < len)
////	{
////		//��֤����
////		if (child+1<len&&nums[child + 1] > nums[child])
////			child++;
////		if (nums[child] > nums[parent])//���Ǵ��
////		{		//�������׺����������
////			Swap(nums + parent, nums + child);
////			//�����������ӽڵ�
////			parent = child;
////			//���¼��㸸�׵ĺ���
////			child = 2 * parent + 1;
////		}
////		else//�Ǵ�ѣ�����Ҫ�����µ�����
////			break;
////	}
////}
////void HeapSort(int* nums, int len)
////{
////    //1������
////	HeapCreat(nums,len);
////	//2����ʼѡ��
////	int size = len;
////	while (size > 1)
////	{
////		//�����Ѷ���Ԫ�غͶѶ�β��Ԫ��
////		Swap(nums,nums+size-1);
////		//�ѵ�Ԫ�ظ�����1
////		size--;
////		//ִ�����µ����㷨
////		AdjustDown(nums,0,size);
////	}
////}
////void test1()
////{
////	int arr[] = {62,16,13,17,41,22,30,19,28,15};
////	int len = sizeof(arr) / sizeof(int);
////	HeapSort(arr,len);
////	PrintfArr(arr,len);
////}
////int main()
////{   
////	test1();
////	return 0;
////}
//void AdjustUp(int* nums, int end)
//{
//	int child = end - 1;
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (nums[child] < nums[parent])
//		{
//			Swap(nums + child, nums + parent);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//			break;
//	}
//}
//void test1()
//{
//	int arr[] = { 70,56,30,25,15,10,100 };
//	int len = sizeof(arr) / sizeof(int);
//	AdjustUp(arr,len);
//	//Swap(arr,arr+len-1)
//	PrintfArr(arr,len);
//}
//void AdjustDown(int* nums, int top, int len)
//{
//	int parent = top;
//	int child = 2 * parent + 1;
//	while(child < len)
//	{
//		if (child+1<len && nums[child + 1] < nums[child])
//			child++;
//		if (nums[parent] <= nums[child])
//			break;
//		else
//		{
//			Swap(nums+parent,nums+child);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//	}
//}
//void test2()
//{
//	int arr[] = {0,56,70,25,15,10,30};
//	int len = sizeof(arr) / sizeof(int);
//	AdjustDown(arr,0,len);
//	PrintfArr(arr,len);
//}
//void HeapSort(int* nums, int len)
//{
//	int size = len;/*
//	int top = (len - 1 - 1) / 2;
//	for (top; top >= 0; top--)
//	{
//		AdjustDown(nums, top, size);
//	}*/
//	//���ϵ����㷨������
//	for (int i = 0; i < len; i++)
//	{
//		AdjustUp(nums,i+1);
//	}
//	while (size > 1)
//	{
//		Swap(nums, nums + size - 1);
//		size--;
//		AdjustDown(nums, 0, size);
//	}
//}
//void test3()
//{
//	int nums[] = {62,16,13,17,41,22,30,19,28,15};
//	int len = sizeof(nums) / sizeof(int);;
//	HeapSort(nums,len);
//	PrintfArr(nums,len);
//}
//void PrintTopK(int* a, int n, int k)
//{
//	// 1. ����--��a��ǰk��Ԫ�ؽ���
//	for (int top = (k - 1 - 1) / 2; top >= 0; top--)
//	{
//		AdjustDown(a,top,k);
//	}
//	// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ��������������滻
//	for (int i = k; i < n; i++)
//	{
//		if (a[0] < a[i])
//		{
//			Swap(a,a+i);
//			AdjustDown(a,0,k);
//		}
//	}
//	PrintfArr(a,k);
//}
//void test4()
//{
//	int nums[] = { 62,16,13,17,41,22,30,19,28,15 };
//	int len = sizeof(nums) / sizeof(int);;
//	PrintTopK(nums,len,len);
//}
//int main()
//{
//	test3();
//	return 0;
//}