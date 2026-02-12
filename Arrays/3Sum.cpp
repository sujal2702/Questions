// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

//Function to Solve 3sum problem 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<vector<int>> ans;
       int n = nums.size();
       for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;   // ye case MAT bhoolna
         int j = i+1;
         int k = n-1;
         while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++;    //qki already sorted array h aur hame value badhana h isliye
            }
            else if(sum > 0){
                k--;
            }
            else{
                //yaha aa gaye mtlb sum == 0 h
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1]) j++;
                while(j<k && nums[k] == nums[k+1]) k--;

            }
         } 
       }
       return ans;
    }
};
