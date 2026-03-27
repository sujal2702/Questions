//To find Sum of Subarray Minimum 
//--------------------------->>BRUTE FORCE APPROACH------------------------------- T.C.O(n^2)
class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            int mini = INT_MAX;
            for(int j=i; j<arr.size(); j++){ //Iterate through every possible subarray combination and store min & add it in sum.
                mini = min(mini , arr[j]);
                sum = sum + mini;
            }
        }
        return sum;
    }
};
