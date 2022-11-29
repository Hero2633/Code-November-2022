////int Depth(struct TreeNode* root)
////{
////    if (!root)
////        return 0;
////    int lh = Depth(root->left);
////    int rh = Depth(root->right);
////    return 1 + (lh > rh ? lh : rh);
////}
////bool isBalanced(struct TreeNode* root) {
////    if (!root)
////        return true;
////    int lh = Depth(root->left);
////    int rh = Depth(root->right);
////    if (abs(lh - rh) > 1)
////        return false;
////    return isBalanced(root->left) && isBalanced(root->right);
////}
//#include<stdio.h>
//#include<stdlib.h>
//struct Node
//{
//    int val;
//    int Frequent;
//};
//void Swap(struct Node* a, struct Node* b)
//{
//    struct Node tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void ShellSort(int* nums, int len)
//{
//    int gap = len;
//    while (gap > 1)
//    {
//        gap = gap / 3 + 1;
//        for (int j = 0; j < gap; j++)
//        {
//            for (int i = j; i < len - gap; i += gap)
//            {
//                int end = i;
//                int key = nums[end + gap];
//                while (end >= 0)
//                {
//                    if (key >= nums[end])
//                        break;
//                    else
//                    {
//                        nums[end + gap] = nums[end];
//                        end -= gap;
//                    }
//                }
//
//                nums[end + gap] = key;
//            }
//        }
//    }
//}
//
//void AdjustDown(struct Node* tmp, int top, int end)
//{
//    int parent = top;
//    int child = 2 * top + 1;
//    while (child < end)
//    {
//        if (child + 1 < end && tmp[child + 1].Frequent < tmp[child].Frequent)
//            child++;
//        if (tmp[parent].Frequent <= tmp[child].Frequent)
//        {
//            break;
//        }
//        else
//        {
//            Swap(tmp + parent, tmp + child);
//            parent = child;
//            child = 2 * parent + 1;
//        }
//    }
//}
//
//void Topk(struct Node* tmp, int k, int len)
//{
//    for (int i = (k - 2) / 2; i >= 0; i--)
//        AdjustDown(tmp, i, k);
//    for (int i = k; i < len; i++)
//    {
//        if (tmp[0].Frequent < tmp[i].Frequent)
//            Swap(tmp, (tmp + i));
//        AdjustDown(tmp,0,k);
//    }
//}
//int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
//    //1、先排序
//    ShellSort(nums, numsSize);
//    //2、遍历
//    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node) * numsSize);
//    int keyi = 0;
//    int cur = 0;
//    int j = 0;
//    while (keyi != numsSize)
//    {
//        while (cur < numsSize && nums[cur] == nums[keyi])
//            cur++;
//        tmp[j].val = nums[keyi];
//        tmp[j].Frequent = cur - keyi;
//        keyi = cur;
//        j++;
//    }
//    //3、tokd对结构体排序
//    Topk(tmp, k, j);
//    int* ret = (int*)malloc(sizeof(int) * k);
//    *returnSize = k;
//    for (int i = 0; i < k; i++)
//        ret[i] = tmp[i].val;
//    free(tmp);
//    return ret;
//
//}
//int main()
//{
//    int tmp[] = { 5,2,5,3,5,3,1,1,3 };
//    int ret = 0;
//    topKFrequent(tmp,9,2,&ret);
//    return 0;
//}
//void Swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void QuickSort(int* nums, int left, int right)
//{
//    if (left >= right)
//        return;
//    int keyi = left;
//    int begin = left;
//    int end = right;
//    while (left < right)
//    {
//        while (left < right && nums[right] <= nums[keyi])
//            right--;
//        while (left < right && nums[left] >= nums[keyi])
//            left++;
//        Swap(nums + left, nums + right);
//    }
//    Swap(nums + right, nums + keyi);
//    QuickSort(nums, begin, left - 1);
//    QuickSort(nums, right + 1, end);
//}
//int Deduplication(int* nums, int len)
//{
//    int cur = 0;
//    int keyi = 0;
//    while (cur < len)
//    {
//        if (nums[cur] == nums[keyi])
//            cur++;
//        else
//        {
//            keyi++;
//            nums[keyi] = nums[cur];
//        }
//    }
//    return keyi + 1;
//}
//int thirdMax(int* nums, int numsSize) {
//    QuickSort(nums, 0, numsSize - 1);
//    int len = Deduplication(nums, numsSize);
//    printf("%d ", len);
//    return len < 3 ? nums[len - 1] : nums[2];
//}