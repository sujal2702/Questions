#include<iostream> 
using namespace std;

char toLowerCase(char ch) {
    if(ch >='a' && ch <='z')
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(char a[], int n) {
    int s = 0;
    int e = n-1;

    while(s<=e) {
        if(toLowerCase( a[s] ) != toLowerCase( a[e] ) )
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

void reverse(char name[], int n) {
    int s=0;
    int e = n-1;

    while(s<e) {
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }

    return count;
}

char getMaxOccCharacter(string s) {

    int arr[26] = {0};


    //create an array of count of characters
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        //lowercase means if(ch>=a && ch<=z) ch - 'a' else uppercase then ch - 'A'
        int number = 0;
        number = ch - 'a'; //because b - 'a' = 1 (FROM CHAR TO INT) and in next step we increase the count of 1 ex arr[1]++;
        arr[number]++;   
    }

    //find maximum occ character
    int maxi = -1, ans = 0;
    for(int i=0;i<26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }
    

    return 'a'+ans;  //dekho i to arr[26] me se kisi ek position pe hoga to usko as a string return krne k liye 
                    // (ans + 'a') jiska mtlb INT + INT(ASCII of a) isse lowercase of a k respect me store krega 
                    //MTLB if ans = 0 then 0+97(which is ASCII of a) there if will return a if ans = 2 then 97+2 which is 'c' it will return 'c'

}

int main( ) {
 
    char name[20];

    cout << "Enter your name " << endl;
    cin >> name;
    //name[2] = '\0';

    cout << "Your name is ";
    cout << name << endl;
    int len = getLength(name);
    cout << " Length: " << len << endl;

    reverse(name, len);
    cout << "Your name is ";
    cout << name << endl;

    cout <<" Palindrome or Not: " << checkPalindrome(name, len) << endl;

    cout << " CHARACTER is " << toLowerCase('b') << endl;
    cout << " CHARACTER is " << toLowerCase('C') << endl;
    

   string s;
   cin >> s;

    cout << getMaxOccCharacter(s) << endl;

    return 0;
}
