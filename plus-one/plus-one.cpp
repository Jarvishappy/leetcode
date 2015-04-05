#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 0;
        for (vector<int>::reverse_iterator i = digits.rbegin(); i != digits.rend(); ++i) {
            if (i == digits.rbegin())
                *i += 1;
            else
                *i += carry;

            carry = *i / 10;
            *i = *i % 10;
        }

        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};

void printVec(vector<int> &v) {
    for (auto e : v) {
        printf("%d ", e);
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    vector<int> v = {9,9};
    Solution sol;
    v = sol.plusOne(v);

    printVec(v);
    return 0;
}
