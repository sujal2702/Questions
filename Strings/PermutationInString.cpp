#include<iostream>
using namespace std;

class Solution {
public:

    // Yeh function dono frequency arrays compare karta hai
    bool isFreqSame(int freq1[], int freq2[]) {
        
        // 0 se 25 tak (a-z)
        for(int i = 0; i < 26; i++) {
            
            // agar kisi bhi index par mismatch mila
            if(freq1[i] != freq2[i]) {
                return false;   // permutation nahi hai
            }
        }
        
        // agar saare 26 match ho gaye
        return true;
    }


    bool checkInclusion(string s1, string s2) {

        // s1 ka frequency array bana rahe hain
        int freq[26] = {0};

        for(int i = 0; i < s1.length(); i++) {
            
            // character ka index nikal ke count badha diya
            freq[s1[i] - 'a']++;
        }

        // window ka size fix kar diya
        int windSize = s1.length();


        // s2 ke har index se window start karenge
        for(int i = 0; i < s2.length(); i++) {

            int windIdx = 0;   // window ke andar kitne character add hue
            int Idx = i;       // s2 ka actual pointer

            // har nayi window ke liye fresh frequency array
            int windFreq[26] = {0};

            // jab tak window ka size complete na ho
            // aur string ke bahar na chale jaye
            while(windIdx < windSize && Idx < s2.length()) {

                // current character ka count badhao
                windFreq[s2[Idx] - 'a']++;

                windIdx++;  // window ke andar 1 character add hua
                Idx++;      // next character par jao
            }

            // dono frequency arrays compare karo
            if(isFreqSame(freq, windFreq)) {
                return true;   // permutation mil gaya
            }
        }

        // agar kahin bhi match nahi mila
        return false;
    }
};
