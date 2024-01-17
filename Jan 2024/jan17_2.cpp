#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

class Solution {
public:
    int k = 1000;
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2 * k + 1);
        
        // Count occurrences of each element in the vector
        for (int el : arr) {
            freq[el + k]++;
        }

        // Sort the frequency array
        sort(freq.begin(), freq.end());

        // Check for unique occurrences
        for (int i = 0; i < 2 * k; i++) {
            if (freq[i] != 0 && freq[i] == freq[i + 1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> exampleVector = {1, 2, 2, 3, 3, 3};

    if (solution.uniqueOccurrences(exampleVector)) {
        cout << "Occurrences are unique." << endl;
    } else {
        cout << "Occurrences are not unique." << endl;
    }

    return 0;
}
