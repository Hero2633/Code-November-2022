//int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
//    int i = 0;
//    int Lmul = 1;
//    int Rmul = 1;
//    int* answer = (int*)malloc(sizeof(int) * numsSize);
//    while (i < numsSize)
//    {
//        if (i == 0)//特殊处理;
//        {
//            Lmul = 1;
//            answer[i] = Lmul;
//        }
//        else
//        {
//            Lmul = Lmul * nums[i - 1];
//            answer[i] = Lmul;
//        }
//        i++;
//    }
//    i--;
//    while (i >= 0)
//    {
//        if (i == numsSize - 1)
//        {
//            Rmul = 1;
//            answer[i] = answer[i] * Rmul;
//        }
//        else
//        {
//            Rmul = Rmul * nums[i + 1];
//            answer[i] = answer[i] * Rmul;
//        }
//        i--;
//    }
//    *returnSize = numsSize;
//    return answer;
//}
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//    int* tmp = (int*)calloc(numsSize, sizeof(int));
//    int* ret = (int*)malloc(sizeof(int) * numsSize);
//    int i = 0;
//    while (i < numsSize)
//    {
//        tmp[nums[i] - 1] = nums[i];
//        i++;
//    }
//    int k = 0;
//    for (int j = 0; j < numsSize; j++)
//    {
//        if (tmp[j] == 0)
//            ret[k++] = j + 1;
//    }
//    free(tmp);
//    *returnSize = k;
//    return ret;
//}
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//    int* ret = (int*)malloc(sizeof(int) * numsSize);
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[abs(nums[i]) - 1] > 0)//开始标记
//        {
//            nums[abs(nums[i]) - 1] *= -1;
//        }
//    }
//    int k = 0;
//    i = 0;
//    while (i < numsSize)
//    {
//        if (nums[i] > 0)
//            ret[k++] = i + 1;
//        i++;
//    }
//    *returnSize = k;
//    return ret;
//}
//#define WEIGHT 1000
//int SoldierNum(int* nums, int left, int right)
//{
//    if (left > right)
//    {
//        return 0;
//    }
//    int mid = (right - left) / 2 + left;
//    if (nums[mid] == 1)
//        return SoldierNum(nums, mid + 1, right) + mid + 1 - left;
//    else
//        return SoldierNum(nums, left, mid - 1);
//}
//int cmp(const void* p1, const void* p2)
//{
//    return *(int*)p1 - *(int*)p2;
//}
//int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
//    int NewFight[matSize];
//    *returnSize = k;
//    for (int i = 0; i < matSize; i++)
//    {
//        NewFight[i] = SoldierNum(mat[i], 0, *matColSize - 1) * WEIGHT + i;//获取新的战斗力
//    }
//    qsort(NewFight, matSize, sizeof(int), cmp);
//    int* ret = malloc(sizeof(int) * k);
//    for (int i = 0; i < k; i++)
//        ret[i] = NewFight[i] % WEIGHT;
//    return ret;
//}
//#include<limits.h>
//int reverse(int x) {
//    int num = 0;
//    int prevsum = 0;
//    int cursum = 0;
//    int MAX_ = INT_MAX / 10;
//    int MIN_ = INT_MIN / 10;
//    while (x)
//    {
//        num = x % 10;
//        prevsum = cursum;
//        //开始提前检验一下这次cursum会不会溢出
//        if ((prevsum > MAX_) || (prevsum == MAX_ && num > 7))//正数发生溢出条件
//            return 0;
//        else if (prevsum < MIN_ || (prevsum == MIN_ && num < -8))//负数发生溢出条件
//            return 0;
//        else//未发生溢出
//            cursum = prevsum * 10 + num;
//        x /= 10;
//    }
//    return cursum;
//}
//int main()
//{
//    reverse(123);
//    return 0;
//}