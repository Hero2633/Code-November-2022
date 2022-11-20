//#include<stdio.h>
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void AdjustDown(int* nums, int top, int len)
//{
//	int parent = top;
//	int child = (2 * parent) + 1;
//	while (child < len)
//	{
//		if (child + 1 < len && nums[child + 1] < nums[child])
//			child++;
//		if (nums[child] < nums[parent])
//		{
//			Swap(nums + child, nums + parent);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else
//			break;
//	}
//}
//#pragma warning (disable:4996)
//#include<time.h>
//#include<stdlib.h>
//void test1()
//{
//	srand((size_t)time(NULL));
//	FILE* fin = fopen("date.txt","w");
//	if (fin == NULL)
//	{
//		exit(-1);
//	}
//	int n = 10;
//	int k = 3;
//	printf(">:");
//	scanf("%d%d",&n,&k);
//	for (int i = 0; i < n; i++)
//	{
//		fprintf(fin,"%d\n",rand()%100000);
//	}
//	fclose(fin);
//	//开始读取数据
//	FILE* fout = fopen("date.txt","r");
//	if (fout == NULL)
//		exit(-1);
//	int* tmp = (int*)malloc(sizeof(int) * k);
//	if (tmp == NULL)
//		exit(-1);
//	for (int i = 0; i < k; i++)
//		fscanf(fout,"%d",tmp+i);
//	//前k个元素建立一个小堆
//	for (int top = (k - 2) / 2; top >= 0; top--)
//	{
//		AdjustDown(tmp,top,k);
//	}
//	int val = 0;
//	while (fscanf(fout, "%d", &val) != EOF)
//	{
//		if (val > tmp[0])
//		{
//			tmp[0] = val;
//			AdjustDown(tmp,0,k);
//		}
//	}
//	for (int i = 0; i < k; i++)
//		printf("%d\n",tmp[i]);
//	fclose(fout);
//	free(tmp);
//}
//typedef struct BTNode
//{
//	int val;
//	struct BTNode* left;
//	struct BTNode* right;
//}BTNode;
//int TreeSize(BTNode* root)
//{
//	return root?(1 + TreeSize(root->left) + TreeSize(root->right)):0;
//}
//// 叶子节点
//int TreeLeafSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	if (root->left == NULL && root->right == NULL)
//		return 1;
//	return TreeLeafSize(root->left)+TreeLeafSize(root->right);
//}
//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	int HL = TreeHeight(root->left);
//	int HR = TreeHeight(root->right);
//	return 1 + HL > HR ? HL : HR;
//}
//BTNode* CreatNode(int x)
//{
//	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
//	if (NewNode == NULL)
//		exit(-1);
//	NewNode->left = NULL;
//	NewNode->right = NULL;
//	NewNode->val = x;
//	return NewNode;
//}
////前序遍历
//void PreOrder(BTNode* root)
//{
//	if (!root)
//	{
//		printf("NULL ");
//		return;
//	}
//	printf("%d ",root->val);
//	PreOrder(root->left);
//	PreOrder(root->right);
//}
////中序遍历
//void InOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	InOrder(root->left);
//	printf("%d ",root->val);
//	InOrder(root->right);
//}
////后序遍历
//void PostOrder(BTNode* root)
//{
//	if (!root)
//	{
//		printf("NULL ");
//		return;
//	}
//	PostOrder(root->left);
//	PostOrder(root->right);
//	printf("%d ",root->val);
//}
////查找底K层的节点数
//int BinaryTreeLevelKSize(BTNode* root, int k)
//{
//	if (root == NULL)
//		return 0;
//	if (k == 1)
//		return 1;
//	return BinaryTreeLevelKSize(root->left,k-1) + BinaryTreeLevelKSize(root->right,k-1);
//}
//// 二叉树查找值为x的节点
//BTNode* BinaryTreeFind(BTNode* root, int x)
//{
//	if (root == NULL)
//		return NULL;
//	if (root->val == x)
//		return root;
//	else
//	{
//		BTNode* ret = BinaryTreeFind(root->left,x);
//		if (ret)
//			return ret;
//		else
//		{
//			ret = BinaryTreeFind(root->right,x);
//			if (ret)
//				return ret;
//			else
//				return NULL;
//		}
//	}
//}
//void test2()
//{
//	BTNode* n1 = CreatNode(1);
//	BTNode* n2 = CreatNode(2);
//	BTNode* n3 = CreatNode(3);
//	BTNode* n4 = CreatNode(4);
//	BTNode* n5 = CreatNode(5);
//	BTNode* n6 = CreatNode(6);
//	//BTNode* n1 = CreatNode(1);
//	n1->left = n2;
//	n1->right = n4;
//	n2->left = n3;
//	n4->left = n5;
//	n4->right = n6;
//	PreOrder(n1);
//	putchar('\n');
//	InOrder(n1);
//	putchar('\n');
//	PostOrder(n1);
//	putchar('\n');
//	printf("BinaryTreeLevelKSize:%d\n",BinaryTreeLevelKSize(n1,0));
//	BTNode* ret = BinaryTreeFind(n1,1);
//	if (ret)
//		printf("找到啦!:%d\n",ret->val);
//	else
//		printf("NULL\n");
//}
//	void Printf(int* nums, int len)
//	{
//		for (int i = 0; i < len; i++)
//			printf("%d ",nums[i]);
//	}
//	void HeapSort(int* nums, int len)
//	{
//		//1、建堆//升序==》大堆；降序==》小堆
//		for (int i = (len-2)/2; i>=0; i--)
//			AdjustDown(nums,i,len);
//		//2、选数排序
//		int size = len;
//		while (size > 1)
//		{
//			Swap(nums,nums+size-1);
//			size--;
//			AdjustDown(nums,0,size);
//		}
//	}
//	void test3()
//	{
//		int arr[] = { 20,1,12,22,34,67,82,-1,-35,-49,43,9 };
//		int len = sizeof(arr) / sizeof(int);
//		HeapSort(arr,len);
//		Printf(arr,len);
//	}
//	//bool isUnivalTree(struct TreeNode* root) {
//	//	if (!root)
//	//		return true;
//	//	if (root->left)
//	//	{
//	//		if (root->val != root->left->val || !isUnivalTree(root->left))
//	//			return false;
//	//	}
//	//	if (root->right)
//	//	{
//	//		if (root->val != root->right->val || !isUnivalTree(root->right))
//	//			return false;
//	//	}
//	//	return true;
//
//	//}
//	//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//	//	if (p == q && p == NULL)
//	//		return true;
//	//	else if (!p || !q)
//	//		return false;
//	//	if (p->val != q->val)
//	//		return false;
//	//	bool ret = isSameTree(p->left, q->left);
//	//	if (ret)
//	//	{
//	//		ret = isSameTree(p->right, q->right);
//	//		if (ret)
//	//			return true;
//	//	}
//	//	return false;
//	//}
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}