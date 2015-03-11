#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

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
                m.insert(make_pair(numbers[i], i));
            }
            else
            {
                dupm.insert(make_pair(numbers[i], i));
            }
        }


        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < length; i++)
        {
            int to_find = target - numbers[i];
            if (binary_search(numbers.begin(), numbers.end(), to_find))
            {
                // get index of the element
                int idx1 = m[numbers[i]];
                int idx2 = m[to_find];
                if (idx1 < idx2)
                {
                    result.push_back(idx1 + 1);
                    result.push_back(idx2 + 1);
                }
                else
                {
                    result.push_back(idx2 + 1);
                    result.push_back(idx1 + 1);
                }
                break;
            }
        }

        return result;
    }
};

