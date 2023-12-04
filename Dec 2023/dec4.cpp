#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char ans = -1;
        for(int i=2; i<num.size(); i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                ans = max(ans, num[i]);
            }
        }
        return (ans==-1) ? "" : string(3,ans);
    }
};

int main() {
    Solution solution;
    string a = "6777133339";
    string b = "2300019";
    string c = "42352338";

    string result = solution.largestGoodInteger(a);
    
    if (result.empty()) {
        cout << "No such character found." << endl;
    } else {
        cout << "Largest good integer: " << result << endl;
    }

    return 0;
}
