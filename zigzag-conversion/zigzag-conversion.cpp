#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 思路：
     * 经过分析，发现Z字顶点的间距为nRows - 1，
     * 第一行和最后一行的顶点间距都为2 * nRows - 2。
     * 处于同一行的字母，跟在它们之间的顶点的距离总是相等的。
     *
     */
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }

        string ret;
        vector<int> vets;
        int len = s.length();
        if (len == 0 || nRows == 0) {
            return ret;
        }

        if (nRows >= len) {
            return s;
        }

        for (int i = 0; i < len; i += nRows - 1) {
            vets.push_back(i);
        }

        // remove first vertex
        vets.erase(vets.begin());

        // first line
        for (int i = 0; i < len; i += 2 * nRows - 2) {
            ret.push_back(s[i]);
        }

        int d = 0;
        int p = 0;
        for (int i = 1; i < nRows; ++i) {
            p = i;
            ret.push_back(s[p]);
            for (auto v : vets) {
                // calculate distance between s[v] and s[p]
                d = v - p;
                if (v + d >= len) {
                    break;
                }
                if (d != 0) {
                    ret.push_back(s[v + d]);
                }
                p = v + d;
            }
        }

        return ret;
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    cout << sol.convert("", 2) << endl;
    cout << sol.convert("PAYPALISHIRING", 1) << endl;
    cout << sol.convert("PAYPALISHIRING", 2) << endl;
    cout << sol.convert("PAYPALISHIRING", 3) << endl;
    cout << sol.convert("PAYPALISHIRING", 4) << endl;
    cout << sol.convert("PAYPALISHIRING", 5) << endl;

    cout << sol.convert("PAYPALISHIRING", 10) << endl;
    cout << sol.convert("PAYPALISHIRING", 11) << endl;
    cout << sol.convert("PAYPALISHIRING", 12) << endl;
    cout << sol.convert("PAYPALISHIRING", 13) << endl;

    return 0;
}
