// how to compare the character of strings from different arrays 
// suppose 2 arrays of strings are there --> and u want to compare the 1st character of 1st String from 1st array --to  1st character of 1st String from 2nd array 
//here is the approach

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (int i = 0; i < queries.size(); i++) {

            for (int j = 0; j < dictionary.size(); j++) {

                int diff = 0;

                for (int k = 0; k < queries[i].size(); k++) {
                    if (queries[i][k] != dictionary[j][k]) diff++; //
                    if (diff > 2) break;
                }

                if (diff <= 2) {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

// Main Logic --> queries[i][k] != dictionary[j][k] -------> it means -> Compare the k-th character of the i-th string in queries with the k-th character of the j-th string in dictionary
