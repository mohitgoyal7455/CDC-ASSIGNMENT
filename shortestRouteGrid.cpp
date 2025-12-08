#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findTripletsWithSumLimit(vector<int>& nums, int targetSum)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n - 2; i++)
    {
        int start = i + 1;     
        int end = n - 1;       

        while (start < end)
        {
            int total = nums[i] + nums[start] + nums[end];

            if (total > targetSum)
            {
                end--;
            }
            else
            {
                for (int k = end; k > start; k--)
                {
                    cout << "(" << nums[i] << ", "
                         << nums[start] << ", "
                         << nums[k] << ") ";
                }

                start++;
            }
        }
    }
}

int main()
{
    vector<int> arr = {2, 7, 4, 9, 5, 1, 3};

    int target = 10;

    findTripletsWithSumLimit(arr, target);

    return 0;
}
