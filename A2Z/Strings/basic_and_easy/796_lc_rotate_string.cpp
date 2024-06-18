#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    int s_size = s.size();
    int g_size = goal.size();
    if(s_size != g_size) return false;

    char ch = s[0]; int rotation = 0;
    for(int i = 0;i < g_size;i++) {
        if(goal[i] == ch) {
            rotation = i;break;
        }
    }     

    string temp = goal;
    reverse(temp.begin(),temp.begin() + rotation);
    reverse(temp.begin()+rotation,temp.end());
    reverse(temp.begin(),temp.end());

    if(s == temp) {
        return true;
    }
    return false;
}

int main() {
    cout << rotateString("aabcd","abcda") << endl;
}
