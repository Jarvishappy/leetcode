#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int num = abs(x);
        int rev = 0;

        // num must be positive
        while (num > 0) {
            /* 这是原来的想法，后来发现根本不需要事先知道x有多少位
             *
             * rev += digit * (int) pow(10, n); */
            if (rev <= 214748364) {
                rev = rev * 10 + num % 10;
            } else {
                return 0;
            }
            num /= 10;
        }

        return x < 0 ? -rev : rev;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int d;
    while (true) {
        printf("enter a num: ");
        scanf("%d", &d);
        printf("return: %d\n", sol.reverse(d));
    }
    return 0;
}
