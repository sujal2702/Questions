// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

//1 BRUTE FORCE APPROACH 

 int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;

            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                ans = max(ans, sum);
            }
        }

        return ans;

//OPTIMAL APPROACH -------> //KADANE'S ALGORITHM

// THIS IS KADANE'S ALGORITHM

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];

        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
            maxi = max(maxi, sum);

            //main part to include
            if(sum<0) 
            sum = 0;
        }
        return maxi;

    }
};


