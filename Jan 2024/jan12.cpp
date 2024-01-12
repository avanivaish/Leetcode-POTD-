#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count = 0;
        transform(s.begin(), s.end(), s.begin(), :: tolower);
        string a = s.substr(0,n/2);
        string b = s.substr(n/2);
        for(char c : a){
            if(c == 'a' || c == 'e'|| c == 'i' || c == 'o' || c == 'u'){
                count++;
            }
        }
        for(char c : b){
            if(c == 'a' || c == 'e'|| c == 'i' || c == 'o' || c == 'u'){
                count--;
            }
        }
        if(count==0) return true;
        else return false;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Test cases
    string test1 = "book";
    string test2 = "textbook";
    string test3 = "MerryChristmas";
    
    // Check if halves are alike for each test case
    bool result1 = solution.halvesAreAlike(test1);
    bool result2 = solution.halvesAreAlike(test2);
    bool result3 = solution.halvesAreAlike(test3);

    // Display results
    cout << "Test Case 1: " << (result1 ? "true" : "false") << endl;
    cout << "Test Case 2: " << (result2 ? "true" : "false") << endl;
    cout << "Test Case 3: " << (result3 ? "true" : "false") << endl;

    return 0;
}
