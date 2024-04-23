#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

const int MAX_INT = 0x3f3f3f;
const int MAX_LEN = 1000000;

int nums[MAX_LEN];
int len;

void up(int k)
{
    if (k <= 1)
    {
        return;
    }
    if (nums[k] < nums[k / 2])
    {
        swap(nums[k], nums[k / 2]);
        up(k / 2);
    }
}

void down(int k)
{
    int j = k;
    if (2 * k <= len && nums[j] > nums[2 * k])
    {
        j = 2 * k;
    }
    if (2 * k + 1 <= len && nums[j] > nums[2 * k + 1])
    {
        j = 2 * k + 1;
    }
    if (j != k)
    {
        swap(nums[j], nums[k]);
        down(j);
    }
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
    int k = 10000;
    len = 0;
    vector<int> t = gen_random_ids(k);
    for (int i = 0; i < t.size(); i++)
    {
        len++;
        nums[len] = t[i];
        up(len);
    }
    sort(t.begin(), t.end());

    for (int i = 0; i < t.size(); i++)
    {
        swap(nums[1], nums[len]);
        len--;
        down(1);       
    }
    len = k;
    for (int i = 0; i < k; i++) {
        if (t[i] != nums[len - i]) {
            cout << "error" << endl;
            return 0;
        } 
    }
    cout << "success" << endl;
    return 0;
}
