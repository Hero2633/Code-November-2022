////struct TreeNode* invertTree(struct TreeNode* root) {
////	if (!root)
////		return NULL;
////	struct TreeNode* tmp = root->left;
////	root->left = root->right;
////	root->right = tmp;
////	invertTree(root->left);
////	invertTree(root->right);	
////	return root;
////}
////bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
////    if (!p && !q)
////        return true;
////    else if (!p || !q)
////        return false;
////    if (p->val != q->val)
////        return false;
////    if (isSameTree(p->left, q->left) == false)
////        return false;
////    if (isSameTree(p->right, q->right) == false)
////        return false;
////    return true;
////}
////
////
////bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
////    if (!root)
////        return false;
////    if (isSameTree(root, subRoot))
////        return true;
////    if (isSubtree(root->left, subRoot))
////        return true;
////    if (isSubtree(root->right, subRoot))
////        return true;
////    return false;
////}
//int DigKey(int* nums, int left, int right)
//{
//    int key = nums[left];
//    int pig = left;
//    while (left < right)
//    {
//        while (left < right && nums[right] >= key)
//            right--;
//        nums[pig] = nums[right];
//        pig = right;
//        while (left < right && nums[left] < key)
//            left++;
//        nums[pig] = nums[left];
//        pig = left;
//    }
//    nums[left] = key;
//    return right;
//}
//int getKthMagicNumber(int* nums, int left, int right, int k) {
//
//    int index = -1;
//    while ((index = DigKey(nums, left, right)) + 1 != k)
//    {
//        if (index + 1 > k)
//            right = index - 1;
//        else
//            left = index + 1;
//    }
//    return index;
//}
//int* smallestK(int* arr, int arrSize, int k, int* returnSize) {
//    *returnSize = k;
//    if (!k)
//    {
//        printf("1");
//        return arr;
//    }
//    getKthMagicNumber(arr, 0, arrSize - 1, k);
//    return arr;
//}
////int main()
////{
////    smallestK();
////    return 0;
////}
//#include"Queue.h"
//int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
//    int** ret = (int**)malloc(sizeof(int*) * 1000);
//    int* col = (int*)malloc(sizeof(int) * 1000);
//    int step = 0;
//    int size = 0;
//    int r = -1;
//    int c = 0;
//    Queue q;
//    int* tmp = NULL;
//    QueueInit(&q);
//    QueuePush(&q, root);
//    while (false == QueueEmpty(&q))
//    {
//        if (size)
//        {
//            size--;
//            struct TreeNode* front = QueueFront(&q);
//            QueuePop(&q);
//            ret[r][c++] = front->val-'0';
//            if (front->left)
//                QueuePush(&q, front->left);
//            if (front->right)
//                QueuePush(&q, front->right);
//        }
//        else
//        {
//            step++;
//            size = QueueSize(&q);
//            tmp = (int*)malloc(sizeof(int) * size);
//            r++;
//            ret[r] = tmp;
//            c = 0;
//            col[r] = size;
//        
//        }
//    }
//    QueueDestroy(&q);
//    *returnSize = step;
//    *returnColumnSizes = col;
//    return ret;
//}
//// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
//BTNode* BuyBTNode(BTDataType x)
//{
//    BTNode* ret = (BTNode*)malloc(sizeof(BTNode));
//    if (!ret)
//        exit(EXIT_FAILURE);
//    ret->val = x;
//    ret->left = NULL;
//    ret->right = NULL;
//    return ret;
//}
//BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
//{
//    if (a[*pi] == '#')
//    {
//        *pi += 1;
//        return NULL;
//    }
//    BTNode* root = BuyBTNode(a[*pi]);
//    *pi += 1;
//    root->left = BinaryTreeCreate(a, pi);//构建左子树；
//    root->right = BinaryTreeCreate(a, pi);//构建右子树
//    return root;
//}
//#include<string.h>
//int main()
//{
//    char arr[] = {"39##21##7##"};
//    int len = strlen(arr);
//    int i = 0;
//    BTNode*root=BinaryTreeCreate(arr,&i);
//    int* col = NULL;
//    int row = 0;
//    levelOrder(root,&row,&col);
//    return 0;
//}