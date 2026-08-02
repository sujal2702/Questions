//BitMasking to print all Subset of bits

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();      // Number of elements

        int subsett = 1 << n;     // Total subsets = 2^n

        vector<vector<int>> ans;  // Stores all subsets

        // Generate every bitmask from 0 to 2^n - 1
        for (int num = 0; num < subsett; num++) {

            vector<int> list;     // Current subset

            // Check every bit
            for (int i = 0; i < n; i++) {

                // If ith bit is set, include nums[i]
                if (num & (1 << i)) {
                    list.push_back(nums[i]);
                }
            }

            ans.push_back(list);
        }

        return ans;
    }
};
