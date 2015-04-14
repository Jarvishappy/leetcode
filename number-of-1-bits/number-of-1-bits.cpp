#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        const uint32_t mask = 1;
        int count = n & mask;

        for (int i = 1; i < 32; ++i) {
            n = n >> 1;
            if ((n & mask) == 1) {
                count++;
            }
        }

        return count;
    }
};


int main(int argc, char *argv[])
{
    Solution sol;

    uint32_t n;
    while (true) {
        printf("enter a num\n");
        scanf("%d", &n);
        printf("result: %d\n", sol.hammingWeight(n));
    }

    printf("done\n");
    return 0;
}
