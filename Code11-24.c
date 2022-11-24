////#include <stdio.h>
////#include<stdlib.h>
////#include<string.h>
//#include"Queue.h"
//BTNode* BuyNode(char a)
//{
//    BTNode* ret = (BTNode*)malloc(sizeof(BTNode));
//    if (!ret)
//        exit(-1);
//    ret->val = a;
//    ret->right = ret->left = NULL;
//    return ret;
//}
//BTNode* CreatBinTree(char* nums, int* i)
//{
//    if (nums[*i] == '#'||nums[*i]=='\0')
//    {
//        *i = *i + 1;
//        return NULL;
//    }
//    BTNode* root = BuyNode(nums[*i]);
//    *i = *i + 1;
//    BTNode* left = CreatBinTree(nums, i);
//    BTNode* right = CreatBinTree(nums, i);
//    root->left = left;
//    root->right = right;
//    return root;
//}
////void InOrder(BTNode* root)
////{
////    if (!root)
////        return;
////    InOrder(root->left);
////    printf("%c ", root->val);
////    InOrder(root->right);
////
////}
//void Destroy(BTNode* root)
//{
//    if (!root)
//        return;
//    free(root->left);
//    free(root->right);
//    free(root);
//}
////int main() {
////
////    char arr[101];
////    gets(arr);
////    int i = 0;
////    BTNode* root = CreatBinTree(arr, &i);
////    InOrder(root);
////    Destroy(root);
////    return 0;
////}
//void LevelOrder(BTNode* root)
//{
//    Queue q;
//    QueueInit(&q);
//    QueuePush(&q,root);
//    while (false==QueueEmpty(&q))
//    {
//        BTNode* front = QueueFront(&q);
//        QueuePop(&q);
//        printf("%c ",front->val);
//        if (front->left)
//        {
//            QueuePush(&q,front->left);
//        }
//        if (front->right)
//        {
//            QueuePush(&q,front->right);
//        }
//    }
//    QueueDestroy(&q);
//}
//void test11()
//{
//    char arr[] = { "abc##de#g##f###"};
//    int i = 0;
//    BTNode* root = CreatBinTree(arr,&i);
//    LevelOrder(root);
//    Destroy(root);
//}
//bool BinaryTreeComplete(BTNode* root)
//{
//    Queue q;
//    QueueInit(&q);
//    QueuePush(&q, root);
//    while (1)
//    {
//        BTNode* front = QueueFront(&q);
//        QueuePop(&q);
//        if (NULL == front)
//        {
//            while (QueueEmpty(&q)==false)
//            {
//                if (QueueFront(&q) == NULL)
//                    QueuePop(&q);
//                else
//                {
//                    QueueDestroy(&q);
//                    return false;
//                }
//            }
//            QueueDestroy(&q);
//            return true;
//        }
//        else
//        {
//            QueuePush(&q, front->left);
//            QueuePush(&q, front->right);
//        }
//    }
//}
//
//    void test2()
//      {
//    char arr[] = { "ab##d##" };
//    int i = 0;
//    BTNode* root = CreatBinTree(arr, &i);
//    bool ret=BinaryTreeComplete(root);
//    if (ret)
//        printf("true\n");
//    else
//        printf("false\n");
//    Destroy(root);
//}
//int main()
//{
//    test2();
//    return 0;
//}
//bool isUnivalTree(struct TreeNode* root) {
//    if (!root)
//        return true;
//    if (root->left && root->left->val != root->val)
//        return false;
//    if (root->right && root->right->val != root->val)
//        return false;
//    return isUnivalTree(root->left) && isUnivalTree(root->right);
//}