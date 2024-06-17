#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    int n = num.size();
    // string temp = num;
    // while(temp.size() != 0) {
    //     int t_size = temp.size();
    //     // char *ch = (char *)malloc(sizeof(char));
    //     // *ch = temp[t_size - 1];
    //     // cout << atoi(ch) << endl;
    //     // cout << stoi(ch) << endl;
    //     char ch =  temp[t_size - 1];
    //     int number = int(ch) - 48;
    //     if(number % 2 == 1) {
    //         return num.substr(0,t_size);
    //     }
    //     temp = temp.substr(0,t_size-1);
    // }       
    for (int i = n - 1; i >= 0; --i) {
        int digit = num[i] - '0';
        if (digit % 2 == 1) {
            return num.substr(0, i + 1);
        }
    }      
    return "";
}

int main() {
    cout << largestOddNumber("123456") << endl;
}