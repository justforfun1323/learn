#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

const int MAX_INT = 100;
const int MAX_LEN = 1000000;
int nums[MAX_LEN];
int len;

void quick_sort(int nums[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int target = nums[(l + r) / 2];
    int i = l - 1;
    int j = r + 1;
    while (i < j)
    {
        i++;
        while (nums[i] < target)
        {
            i++;
        }
        j--;
        while (nums[j] > target)
        {
            j--;
        }
        if (i < j)
            swap(nums[i], nums[j]);
    }
    /* 
    划分边界就是： 每一个循环开始时候保证 nums[0...i-1]均为≤target 的元素， nums[j+1,...]均为>= target 的元素。
    为什么以 l,j 作为左半部分？而不是[l, i - 1]
    case1: 假定 nums[i-j]均≥targt. nums[4,5]，
    此时 i 会卡在 4位置不懂，j 会走到 4 位置。此时 i,j 均指向 4. 划分后左半部分[0,-1][0,1]陷入死循环
    */
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
}

vector<int> gen_random_ids(int k)
{
    vector<int> data(k, 0);
    for (int i = 0; i < k; i++)
    {
        data[i] = rand() % MAX_INT;
    }
    return data;
}

int main()
{
    srand((unsigned)time(NULL));
    int k = 100000;
    vector<int> data = gen_random_ids(k);
    len = k;
    vector<int> origin_data = vector<int>(data.begin(), data.end());
    for (int i = 0; i < data.size(); i++)
    {
        nums[i] = data[i];
    }
    sort(data.begin(), data.end());
    quick_sort(nums, 0, len - 1);
    for (int i = 0; i < data.size(); i++)
    {
        if (nums[i] != data[i])
        {
            cout << "error" << endl;
            return 0;
        }
    }
    cout << "success" << endl;
    return 0;
}