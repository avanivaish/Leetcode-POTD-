#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        // Count occurrences of each element in the vector
        for (auto i : arr) {
            freq[i]++;
        }
        
        unordered_set<int> freqSet;
        
        // Check for unique occurrences using a set
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            freqSet.insert(it->second);
        }

        
        // Return true if the number of unique occurrences is equal to the total number of distinct elements
        return freq.size() == freqSet.size();
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
