#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 思路：
     * 相当于26进制嘛
     */
    int titleToNumber(string s) {
        if (s.empty())
            return 0;

        int sum = 0,
            mul = 1,
            len = s.length() - 1;
        while (len--) {
            mul *= 26;
        }

        for (int i = 0, len = s.length(); i < len; ++i) {
            sum += (s[i] - 'A' + 1) * mul;
            mul /= 26;
        }

        return sum;
    }
};

int main(int argc, char *argv[])
{
    while (true) {
        printf("enter a title\n");
        string s;
        cin >> s;
        Solution sol;
        printf("result: %d\n", sol.titleToNumber(s));
    }

    return 0;
}
