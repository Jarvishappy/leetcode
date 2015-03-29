#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAX_LENGTH 10


class Solution {
public:
    int reverse(int x) {
        const string s1 = "2147483647";
        const string s2 = "2147483648";

        bool isNeg = x < 0;
        x = abs(x);
        // decide the length of number x
        stringstream ss;
        ss << x;
        int n = ss.str().size();
        int result;

        string digits;
        // get each digit of number x
        int d = 0;
        int multiple = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            multiple = (int) pow(10, i);
            d = x / multiple;
            x -= d * multiple;
            digits.append(to_string(d));
            if (digits.size() > MAX_LENGTH)
                return 0;
        }

        reverseStr(digits);
        // 判断溢出
        if (digits.length() == s1.length())
        {
            if (!isNeg)
            {
                if (digits.compare(s1) > 0)
                    return 0;
            }
            else
            {
                if (digits.compare(s2) > 0)
                    return 0;
            }
        }

        ss.str("");
        ss.clear();
        ss << digits;
        ss >> result;

        return isNeg ? -result : result;
    }

    void reverseStr(string &s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            swap(s[i++], s[j--]);
        }
    }

};
