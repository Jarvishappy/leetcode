#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if (x < 0) {
            isNeg = true;
            x = abs(x);
        }

        int reversed = 0;
        // reverse
        while (x > 0) {
            int p = x / 10;
            int digit = x - p * 10;
            /* 这是原来的想法，后来发现根本不需要事先知道x有多少位
             *
             * reversed += digit * (int) pow(10, n); */
            if (reversed <= 214748364) {
                reversed = reversed * 10 + digit;
            } else {
                return 0;
            }

            x = p;
        }

        return isNeg ? -reversed : reversed;
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
