#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    /**
     * 思路：
     * 将x反转，然后比较x与反转后的整数是否相等
     *
     */
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        return x == reverse(x);
    }

    int reverse(int x) {
        int reversed = 0;
        while (x > 0) {
            int p = x / 10;
            int digit = x - p * 10;
            if (reversed <= 214748364) {
                reversed = reversed * 10 + digit;
            } else {
                return 0;
            }
            x = p;
        }

        return reversed;
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

