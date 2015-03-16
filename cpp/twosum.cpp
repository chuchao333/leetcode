#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int>> numWithIndex(numbers.size());
        for (int i = 0; i < numbers.size(); ++i) {
            numWithIndex[i] = make_pair(numbers[i], i);
        }

        sort(begin(numWithIndex), end(numWithIndex),
             [] (pair<int, int> a, pair<int, int> b) {
                 return a.first < b.first; });

        int low = 0, high = numWithIndex.size() - 1;
        while (low < high) {
            auto s = numWithIndex[low].first + numWithIndex[high].first;
            if (s == target)
                break;

            if (s < target)
                ++low;
            else
                --high;

        }

        int idx1 = numWithIndex[low].second+1;
        int idx2 = numWithIndex[high].second+1;

        return { min(idx1, idx2), max(idx1, idx2) };
    }
};
