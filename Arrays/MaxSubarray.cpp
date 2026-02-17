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

#include <bits/stdc++.h>
using namespace std;

/*
    This code prints the maximum sum subarray itself (NOT the length).
*/

void printMaxSubarray(int arr[], int n) {
    
    long long sum = 0, maxi = LLONG_MIN;
    int start = 0;        // temporary start
    int ansStart = -1;    // final subarray start
    int ansEnd = -1;      // final subarray end

    for (int i = 0; i < n; i++) {
        
        if (sum == 0) {
            start = i;    // potential new subarray start
        }

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "Maximum Sum: " << maxi << endl;
    cout << "Subarray: ";

    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printMaxSubarray(arr, n);

    return 0;
}

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

