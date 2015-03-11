#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        map<int, int> m;
        map<int, int> dupm;
        int length = numbers.size();
        for (int i = 0; i < length; i++)
        {
            if (0 == m.count(numbers[i]))
            {
                m.insert(make_pair(numbers[i], i + 1));
            }
            else
            {
                dupm.insert(make_pair(numbers[i], i + 1));
            }
        }

        for (auto n : numbers) {
            int idx1 = m[n];
            int idx2 = 0;

            auto ret = m.find(target - n);
            if (ret == m.end())
            {
                continue;
            }
            else
            {
                // check if the found number is n itself
                if (n == ret->first && 0 == dupm.count(n))
                    continue;
            }

            // if n is duplicate in numbers, get index from the other map
            if (0 != dupm[ret->first])
            {
                idx2 = dupm[ret->first];
            }
            else
            {
                idx2 = ret->second;
            }

            if (idx1 < idx2)
            {
                result.push_back(idx1);
                result.push_back(idx2);
            }
            else
            {
                result.push_back(idx2);
                result.push_back(idx1);
            }
            break;
        }

        return result;
    }
};

