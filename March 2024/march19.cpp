#include <iostream>
#include <vector>
#include <algorithm>
#include <range/v3/algorithm/count.hpp>
#include <range/v3/algorithm/max.hpp>

using namespace std;
using namespace ranges;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();

        vector<int> count(26);

        for (const char task : tasks)
            ++count[task - 'A'];

        const int maxFreq = max(count);
        // Put the most frequent task in the slot first.
        const int maxFreqTaskOccupy = (maxFreq - 1) * (n + 1);
        // Get the number of tasks with the same frequency as `maxFreq`, we'll
        // append them after `maxFreqTaskOccupy`.
        const int nMaxFreq = count(count, maxFreq);
        // max(
        //   the most frequent task is frequent enough to force some idle slots,
        //   the most frequent task is not frequent enough to force idle slots
        // )
        return max(maxFreqTaskOccupy + nMaxFreq, static_cast<int>(tasks.size()));
    }
};

int main() {
    // Example usage:
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << "Minimum intervals required: " << sol.leastInterval(tasks, n) << endl;
    return 0;
}
