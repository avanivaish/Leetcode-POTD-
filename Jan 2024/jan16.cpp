#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> idxMap;
    RandomizedSet() {}
    bool insert(int val) {
        if(idxMap.find(val)!=idxMap.end()) return false;
        nums.push_back(val);
        idxMap[val]=nums.size()-1;
        return true;
    }
    bool remove(int val) {
        if(idxMap.find(val)==idxMap.end()) return false;
        int last = nums.back();
        idxMap[last]=idxMap[val];
        nums[idxMap[last]]=last;
        nums.pop_back();
        idxMap.erase(val);
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    // Create a RandomizedSet object
    RandomizedSet* obj = new RandomizedSet();

    // Insert elements
    bool param_1 = obj->insert(1);
    bool param_2 = obj->insert(2);
    bool param_3 = obj->insert(3);

    // Display whether insertion was successful
    cout << "Insertion 1: " << (param_1 ? "true" : "false") << endl;
    cout << "Insertion 2: " << (param_2 ? "true" : "false") << endl;
    cout << "Insertion 3: " << (param_3 ? "true" : "false") << endl;

    // Attempt to insert a duplicate element
    bool param_4 = obj->insert(2);
    cout << "Insertion 2 (duplicate): " << (param_4 ? "true" : "false") << endl;

    // Remove an element
    bool param_5 = obj->remove(2);
    cout << "Removal 2: " << (param_5 ? "true" : "false") << endl;

    // Attempt to remove a non-existent element
    bool param_6 = obj->remove(4);
    cout << "Removal 4: " << (param_6 ? "true" : "false") << endl;

    // Get a random element
    int param_7 = obj->getRandom();
    cout << "Random Element: " << param_7 << endl;

    // Clean up the allocated memory
    delete obj;

    return 0;
}
