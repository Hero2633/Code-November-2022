#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    int len = nums1Size + nums2Size;
//    int* tmp = (int*)malloc(sizeof(int) * len);
//    while (i < nums1Size && j < nums2Size)
//    {
//        if (nums1[i] < nums2[j])
//            tmp[k++] = nums1[i++];
//        else
//            tmp[k++] = nums2[j++];
//    }
//    while (i < nums1Size)
//        tmp[k++] = nums1[i++];
//    while (j < nums2Size)
//        tmp[k++] = nums2[j++];
//    if (len % 2)
//    {
//        double ret = 1.0 * tmp[len / 2];
//        free(tmp);
//        return ret;
//    }
//    int index1 = len / 2 - 1;
//    int index2 = index1 + 1;
//    double ret = (tmp[index1] + tmp[index2]) / 2.0;
//    free(tmp);
//    return ret;
//}
//bool isPalindrome(int x) {
//    if ((x >= 0 && x <= 9))//单个数一定是
//        return true;
//    if (x < 0 || x % 10 == 0)//首先整十倍数和负数一定不是
//        return false;
//    int tmp = 0;
//    while (x > tmp)
//    {
//        tmp = tmp * 10 + x % 10;
//        x /= 10;
//    }
//    if (x == tmp)
//        return true;
//    else if (tmp / 10 == x)
//        return true;
//    return false;
//}
//bool isPalindrome(int x) {
//    char tmp[10] = { 0 };
//    int k = 0;
//    if (x < 0)
//        return false;
//    while (x)//将数字转换为字符串
//    {
//        tmp[k++] = x % 10 + '0';
//        x /= 10;
//    }
//    int left = 0;
//    int right = k - 1;
//    while (left < right && tmp[right] == tmp[left])
//    {
//        left++;
//        right--;
//    }
//    if (left < right)
//        return false;
//
//    return true;
//}
//int Min(int a, int b)
//{
//    return a > b ? b : a;
//}
//int maxArea(int* height, int heightSize) {
//    int left = 0;
//    int right = heightSize - 1;
//    int s = (right - left) * Min(height[left], height[right]);
//    while (left < right)
//    {
//        int NewS = Min(height[left], height[right]) * abs(left - right);
//        if (s < NewS)
//            s = NewS;
//        if (height[left] < height[right])//移动矮指针
//            left++;
//        else
//            right--;
//    }
//    return s;
//}

//int search_bin(int* nums, int left, int right, int target)
//{
//    while (left <= right)
//    {
//        int mid = (right - left) / 2 + left;
//        if (nums[mid] > target)
//            right--;
//        else if (nums[mid] < target)
//            left++;
//        else
//            return mid;
//    }
//    return -1;
//}
//void search_part(int* nums, int left, int right, int target, int* ret)
//{
//    if (left>=right)
//    {
//        *ret = search_bin(nums,left,right,target);
//        return;
//    }
//    int mid = (right - left) / 2 + left;
//    if (nums[mid] < nums[right])
//    {
//        *ret = search_bin(nums, mid, right, target);
//        if (*ret == -1)//说明有序区间没找到
//            search_part(nums, left, mid - 1, target, ret);
//    }
//    else if (nums[mid] > nums[right])
//    {
//        *ret = search_bin(nums, left, mid, target);
//        if (*ret == -1)
//            search_part(nums, mid + 1, right, target, ret);
//    }
//    else
//    {
//        right--;
//        search_part(nums, left, right, target, ret);
//    }
//}
//int search(int* nums, int numsSize, int target) {
//    int ret = -1;
//    search_part(nums, 0, numsSize - 1, target, &ret);
//    return ret;
//}
//int main()
//{
//    int arr[] = { 4,5,6,7,0,1,2 };
//    int len = sizeof(arr) / sizeof(arr[0]);
//    search(arr,len,0);
//    return 0;
//}