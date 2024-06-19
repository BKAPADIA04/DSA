#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    string temp = s;
    int check = temp.find_first_not_of(' ');
    temp.erase(0,check);

    int minus = 0;
    if(temp[0] == '-' || temp[0] == '+') {
        if(temp[0] == '-') minus = 1;
        temp = temp.substr(1);
    }

    if(temp.find_first_not_of("0123456789") != string::npos)
        temp.erase(temp.find_first_not_of("0123456789"));

    temp.erase(0,temp.find_first_of("123456789"));
    int n = temp.size();

    int ans = 0;
    for(int i = n - 1; i >= 0;i--) {
        if((ans + ((temp[i] - 48) * pow(10,(n-i-1))) > INT_MAX)) {
            if(minus) return INT_MIN;
            else return INT_MAX;
        }
        ans += ((temp[i] - 48) * pow(10,(n-i-1))); 
    }
    return minus ? ((-1)  * ans) : ans;
}


// or
int myAtoi_(string s) {
    if (s.empty()) return 0;

    int idx=0;
    bool isNegative = false;
    const long max_val = pow(2, 31)-1;
    const long min_val = -pow(2, 31);

    while (s[idx] == ' ') idx++;

    if (s[idx] == '-') {
        isNegative = true;
        idx++;
    } else if (s[idx] == '+') {
        isNegative = false;
        idx++;
    }

    long number = 0;
    while (isdigit(s[idx])) {
        number = number * 10 + (s[idx] - '0');
        if (!isNegative && number > max_val) return max_val;
        if (isNegative && -number < min_val) return min_val;
        idx++;
    }

    if (isNegative) {
        return (number < pow(2, 31)) ? -number : -pow(2, 31);
    } else {
        return (number < pow(2, 31)-1) ? number : pow(2, 31)-1;
    }
}

int main() {
    cout << myAtoi("-+12") << endl;
    cout << myAtoi_("-+12") << endl;
}