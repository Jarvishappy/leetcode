#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;


class Solution {
public:
    /**
     * 思路：
     * 将x转成字符串s，然后用2个指针从s的中间开始，分别向头和尾前进，
     * 比较每一个字符是否相等。注意s的长度可能为奇数或偶数。
     *
     */
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        stringstream ss;
        ss << x;
        string str;
        ss >> str;

        bool result = false;
        // check length of str is odd or even
        int n = str.length();
        int i, j;
        if (n == 1) {
            return true;
        }

        if (n % 2 == 0) {
            i = (n/2) - 1;
            j = (n/2);
        }
        else {
            i = (n/2) - 1;
            j = (n/2) + 1;
        }

        // check if is palindrome
        for (; i >= 0 && j < n; i--, j++) {
            result = str[i] == str[j];
            // 如果遇到一个不相同的就没必要继续比较下去了
            if (!result) {
                return result;
            }
        }

        return result;
    }
};


int main(int argc, char *argv[]) {
    Solution sol;
    int d;
    while (true) {
        printf("enter e number:\n");
        scanf("%d", &d);
        bool ret = sol.isPalindrome(d);
        if (ret) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
