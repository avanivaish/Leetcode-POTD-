#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxLength(std::vector<std::string>& arr) {
        std::vector<int> masks;

        for (const std::string& s : arr) {
            const int mask = getMask(s);
            if (mask != -1)
                masks.push_back(mask);
        }

        return dfs(masks, 0, /*used=*/0);
    }

private:
    int dfs(const std::vector<int>& masks, int s, int used) {
        int res = __builtin_popcount(used);
        for (int i = s; i < masks.size(); ++i)
            if ((used & masks[i]) == 0)
                res = std::max(res, dfs(masks, i + 1, used | masks[i]));
        return res;
    }

    int getMask(const std::string& s) {
        int mask = 0;
        for (const char c : s) {
            const int i = c - 'a';
            if ((mask & (1 << i)) != 0)
                return -1;
            mask |= 1 << i;
        }
        return mask;
    }
};

int main() {
    Solution solution;
    vector<string> input = {"abc", "def", "ghi"};

    int result = solution.maxLength(input);

    cout << "Maximum Length: " << result<< endl;

    return 0;
}
