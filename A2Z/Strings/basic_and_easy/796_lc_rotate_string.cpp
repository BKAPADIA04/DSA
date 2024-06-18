#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    int s_size = s.size();
    int g_size = goal.size();
    if(s_size != g_size) return false;

    string temp = s + s;
    return temp.find(goal) != string::npos;

    // This compares the result of find with a special value called string::npos. npos (not found position) is a constant defined within the <string> library and represents a value that indicates the substring was not found. So, this part checks if the result is not equal to npos.
}

int main() {
    cout << rotateString("aabcd","abcda") << endl;
}
