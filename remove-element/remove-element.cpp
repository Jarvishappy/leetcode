#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n == 0) {
            return 0;
        }
        int *p = A, *q = A;
        bool found = false;

        for (; q < A + n; q++) {
            // 先找第一个出现的位置
            if (!found && *q == elem) {
                p = q - 1;
                found = true;
            }
            // 之后就只复制不等于elem的元素到p的指向
            else if (found && *q != elem) {
                *(p + 1) = *q;
                p = p + 1;
            }
        }

        int len = 0;
        if (found) {
            len = p - A + 1;
        } else {
            len = n;
        }

        return len;
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
    int A[] = {4, 5};
    int n = sizeof(A) / sizeof(int);
    int elem = 4;

    n = sol.removeElement(A, n, elem);
    printf("n: %d\n", n);
    printArray(A, n);

    return 0;
}
