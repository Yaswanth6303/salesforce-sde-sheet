#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
     * Method 1: Brute Force
     * TC: O(n^3)
     * SC: O(1)
     */
    int maxSubarraySumBrute(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;

                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }

                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }

    /*
     * Method 2: Better Approach
     * TC: O(n^2)
     * SC: O(1)
     */
    int maxSubarraySumBetter(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }

    /*
     * Method 3: Optimal Approach (Kadane's Algorithm)
     * TC: O(n)
     * SC: O(1)
     */
    int maxSubarraySumOptimal(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;
            maxSum = max(maxSum, currentSum);

            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Brute Force: "
         << sol.maxSubarraySumBrute(nums) << endl;

    cout << "Better Approach: "
         << sol.maxSubarraySumBetter(nums) << endl;

    cout << "Optimal (Kadane's Algorithm): "
         << sol.maxSubarraySumOptimal(nums) << endl;

    return 0;
}
