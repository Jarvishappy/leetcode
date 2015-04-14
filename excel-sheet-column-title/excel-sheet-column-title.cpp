#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static const string table;
    /**
     * 思路：
     * 26的整数倍需要注意，因为这个不是真正的26进制，26进制应该是0~25，
     * 而改计数法是1~26。如果是0~25，那么table就应该是[A...Z]，1~26相当于
     * 右移了一位，变成了[ZABC...Y]
     */
    string convertToTitle(int n) {
        string ret;
        int mod;
        while (n > 0) {
            mod = n % 26;
            ret.insert(0, 1, Solution::table[mod]);
            n /= 26;
            if (mod == 0)
                n -= 1;
        }

        return ret;
    }

};

const string Solution::table = "ZABCDEFGHIJKLMNOPQRSTUVWXY";

int main(int argc, char *argv[])
{
    Solution sol;
    int n;
    while (true) {
        printf("enter a num: ");
        cin >> n;
        cout << "result: " << sol.convertToTitle(n) << endl;
    }
    return 0;
}
