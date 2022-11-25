//#include"Queue.h"
//
//// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
//BTNode* BuyBTNode(BTDataType x)
//{
//	BTNode* ret = (BTNode*)malloc(sizeof(BTNode));
//	if (!ret)
//		exit(EXIT_FAILURE);
//	ret->val = x;
//	ret->left = NULL;
//	ret->right = NULL;
//	return ret;
//}
//BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
//{
//	if (a[*pi]=='#')
//	{
//		*pi += 1;
//		return NULL;
//	}
//	BTNode* root = BuyBTNode(a[*pi]);
//	*pi += 1;
//	root->left=BinaryTreeCreate(a, pi);//构建左子树；
//	root->right=BinaryTreeCreate(a,pi);//构建右子树
//	return root;
//}
//// 前序销毁二叉树
//void PrevDestroy(BTNode* root)
//{
//	if (root == NULL)
//		return;
//	BTNode* Left = root->left;//
//	BTNode* Right = root->right;//需要提前保存避免找不到左右子树
//	free(root);
//	PrevDestroy(Left);//销毁左子树
//	PrevDestroy(Right);//销毁右子树
//}
////利用中序销毁二叉树
//void InDestroy(BTNode* root)
//{
//	if (root == NULL)
//		return;
//	BTNode* Left = root->left;//
//	BTNode* Right = root->right;//需要提前保存避免找不到左右子树
//	InDestroy(Left);//先销毁左子树
//	free(root);
//	InDestroy(Right);//在销毁右子树
//}
////利用后序销毁二叉树
//void PostDestroy(BTNode* root)
//{
//	if (root == NULL)
//		return;
//	BTNode* Left = root->left;//
//	BTNode* Right = root->right;//
//	PostDestroy(Right);//先销毁右子树
//	PostDestroy(Left);//在销毁左子树
//	free(root);
//}
//void BinaryTreeDestory(BTNode** root)
//{
//	BTNode* head = *root;
//	InDestroy(head);
//	*root = NULL;
//}
//// 二叉树节点个数
//int BinaryTreeSize(BTNode* root)
//{
//	return root ? (1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right)) : 0;
//}
//
//// 二叉树叶子节点个数
//int BinaryTreeLeafSize(BTNode* root)
//{
//	if (!root)
//		return 0;
//	if (root->left == root->right && root->left == NULL)
//		return 1;
//	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->left);
//}
//// 二叉树第k层节点个数
//int BinaryTreeLevelKSize(BTNode* root, int k)
//{
//	if (!root)
//		return 0;
//	if (1 == k)
//		return 1;
//	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
//}
//// 二叉树查找值为x的节点
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
//{
//	if (!root)
//		return NULL;
//	if (root->val == x)
//		return root;
//	BTNode* key = NULL;
//	if ((key = BinaryTreeFind(root->left, x)))
//		return key;
//	return BinaryTreeFind(root->right,x);
//}
//// 二叉树前序遍历 
//void BinaryTreePrevOrder(BTNode* root)
//{
//	if (!root)
//	{
//    printf("NULL ");
//	return;
//	}
//	printf("%c ",root->val);
//	BinaryTreePrevOrder(root->left);
//	BinaryTreePrevOrder(root->right);
//}
//// 二叉树中序遍历
//void BinaryTreeInOrder(BTNode* root)
//{
//	if (!root)
//	{
//		printf("NULL ");
//		return;
//	}
//	BinaryTreeInOrder(root->left);
//	printf("%c ",root->val);
//	BinaryTreeInOrder(root->right);
//}
//// 二叉树后序遍历
//void BinaryTreePostOrder(BTNode* root)
//{
//	if (!root)
//	{
//		printf("NULL ");
//		return;
//	}
//	BinaryTreePostOrder(root->left);
//	BinaryTreePostOrder(root->right);
//	printf("%c ", root->val);
//
//}
//// 层序遍历
//void BinaryTreeLevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q,root);
//	while (QueueEmpty(&q)==false)
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		printf("%c ",front->val);
//		if (front->left)
//			QueuePush(&q,front->left);
//		if (front->right)
//			QueuePush(&q,front->right);
//	}
//	QueueDestroy(&q);
//}
//// 判断二叉树是否是完全二叉树
//bool BinaryTreeComplete(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q,root);
//	while (1)
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		if (front)
//		{
//			QueuePush(&q,front->left);
//			QueuePush(&q,front->right);
//		}
//		else
//		{
//			while (QueueEmpty(&q) == false)
//			{
//				if (QueueFront(&q))
//					return false;
//				else
//					QueuePop(&q);
//			}
//			return true;
//		}
//	}
//}
//void test1()
//{
//	char ch[] = {"ABD##E#H##CF##G##"};
//	int len = sizeof(ch)/sizeof(char);
//	int i = 0;
//	BTNode*root=BinaryTreeCreate(ch,&i);
//	BinaryTreeLevelOrder(root);
//	printf("\n");
//	BinaryTreePrevOrder(root);
//	printf("\n");
//	BinaryTreeInOrder(root);
//	printf("\n");
//	BinaryTreePostOrder(root);
//	printf("\n");
//	/*printf("BinaryTreeSize:%d\n", BinaryTreeSize(root));
//	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(root));
//	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root,4));
//	printf("BinaryTreeFind:%p\n", BinaryTreeFind(root,'H'));
//	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(root));*/
//	BinaryTreeDestory(&root);
//}
//void test2()
//{
//	//手动创建一颗二叉树
//	BTNode* n1 = BuyBTNode(1);
//	BTNode* n2 = BuyBTNode(2);
//	BTNode* n3 = BuyBTNode(3);
//	BTNode* n4 = BuyBTNode(4);
//	BTNode* n5 = BuyBTNode(5);
//	BTNode* n6 = BuyBTNode(6);
//	n1->left = n2;
//	n1->right = n4;
//	n2->left = n3;
//	n4->left = n5;
//	n4->right = n6;
//	//该二叉树的根节点为n1
//	BinaryTreePrevOrder(n1);
//	printf("\n");
//	BinaryTreeInOrder(n1);
//	printf("\n");
//	BinaryTreePostOrder(n1);
//	printf("\n");
//	BinaryTreeLevelOrder(n1);
//
//}
//int main()
//{
//	test1();
//	//test2();
//	return;
//}