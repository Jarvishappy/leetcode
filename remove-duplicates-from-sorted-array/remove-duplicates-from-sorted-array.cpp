#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 思路：
     * 最开始想到的是把后面的元素全部都copy到前面，这样是可以实现的，但是时间复杂度高。
     * 后来发现其实根本不需要copy，用2个指针，1个记录目标位置，另一个寻找不重复的元素，
     * 只要把不重复的元素复制到目标位置就好了，数组的大小即最后指向目标位置的指针减去
     * (数组头指针的地址 + 1)
     *
     */
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }

        int *p = A, *q = A + 1;

        for (int i = 1; i < n; ++i, q++) {
            if (*q != *p) {
                *(p + 1) = *q;
                p = p + 1;
            }
        }

        return p - A + 1;
    }

};

void printArray(int a[], const int n) {
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    Solution sol;
    int A[] = {1,1,2};
    int n = sizeof(A) / sizeof(int);
    n = sol.removeDuplicates(A, n);
    printf("n: %d\n", n);
    printArray(A, n);

    return 0;
}
