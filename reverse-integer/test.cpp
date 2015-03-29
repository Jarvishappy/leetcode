#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAX_LENGTH 10

string s1 = "2147483647";
string s2 = "2147483648";

void reverse(string &s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        swap(s[i++], s[j--]);
    }

}

int foo(int x)
{
    bool isNeg = x < 0;
    x = abs(x);
    // decide the length of number x
    stringstream ss;
    ss << x;
    string ret = ss.str();
    int n = ret.size();
    int result;

    string res;
    // get each digit of number x
    int d = 0;
    int multiple = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        multiple = (int) pow(10, i);
        d = x / multiple;
        x -= d * multiple;
        res.append(to_string(d));
        if (res.size() > MAX_LENGTH)
            return 0;
    }

    reverse(res);
    // 判断溢出
    if (res.length() == s1.length()) {
        if (!isNeg) {
            if (res.compare(s1) > 0)
                return 0;
        } else {
            if (res.compare(s2) > 0)
                return 0;
        }
    }

    ss.str("");
    ss.clear();
    ss << res;
    ss >> result;

    return isNeg ? -result : result;
}


int main(int argc, char *argv[])
{
    int x;
    scanf("%d", &x); 
    cout << "after: " << foo(x) << endl; 

    return 0;
}

