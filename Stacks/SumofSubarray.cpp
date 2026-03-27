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
// --------------------------------------------------------------------Finding SUM OF SUBARRAY MINIMUM using STACKS------------------------------------------------------------------

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        
        //previous smaller or equal element ka logic
        int n = arr.size();
        vector <int> pse(n);//pse vector of size n
        stack <int> st;
        
        for(int i=0; i<arr.size();i++){
            
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top(); //this will store index of pse
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop(); //clear the stack before pushing anything
        
    //--------------------- next smaller index ---------------------
    
        vector <int> nse(n);//nse vector of size n
        // stack <int> st; mo need of redeclaration
        
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                nse[i] = n; //if there is no nse then store nth index ( IMPORTANT)
            }
            else{
                nse[i] = st.top(); //this will store index of pse
            }
            st.push(i);
        }
        
         
        long long total = 0; //(just in case if array is too big)
        for(int i=0; i<arr.size(); i++){
            long long left = i - pse[i]; //left me next ps or equal element se curr element index minus
            long long right = nse[i] - i;//right me next smaller element se curr element minus
            
            total = total + (left * right) * arr[i]; //(MAIN LOGIC )
        }
        return total;
    }
};


/* O(n) We can find SUM OF SUBARRAY MINIMUM using STACKS 

For a subarray minimum we need to find how many times each element is a minimum 
for example for an array [1, 2, 3] 1 is mimimum for 3 subarrays : 2 is minimum for 2 subarrays: 3 is mimimum for 1 subarray : --> so total sum of subarray minimum is 1*3+ 2*2 + 3*1 = 10

  1. we need to find next smaller element and previous smaller element for every element 
  2. till next smaller element and previous smaller element all the element which lies in between. THE ELEMENT will be MINIMUM for them so we can store its' count
  3. And how many elements are in between can be calculated by = NSE[index] - Element[index] * Element[index] - PSE[index] = total elements in between(for which this element is minimum)
  4. If there is no NSE then assign Next Smaller Element(NSE) to Nth index. & If there is no PSE then PSE = -1;
  5. Important thing to remember if we don't want duplicate --> while searching NSE keep index of element which is only smaller remove/pop =(equal) element also
                                                                while searching pse keep index of element which is either smaller or equal to  // this will avoid duplicate subarrays 

  TIME COMPLEXITY WILL BE AROUND O(5n) = almost equal to O(n)
  SPACE COMPLEXITY WILL BE AROUND O(5n) = almost equal to O(n)
  
*/

//TO calculate  ----------------------------------------------------------SUM OF SUBARRAY RANGES -----------------------------------------------------------------

//THIS is the brute force approach
class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        
        int sum =0;
        for(int i=0; i<arr.size(); i++){
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int j=i; j<arr.size(); j++){
                maxi = max(maxi, arr[j]);
                mini = min(mini, arr[j]);
                sum = sum + (maxi - mini);
            }
        }
        return sum;
    }
};

/*for optimal approach

  1. find sum of subarray minimum 
  2. find sum of subarray maximum

  3. Then return SumOfSubarray Maximum - SumOfSubarray Minimum 

  TIME COMPLEXITY will be O95n) + O(5n) = O(10n) which is as good as O(n):
*/
