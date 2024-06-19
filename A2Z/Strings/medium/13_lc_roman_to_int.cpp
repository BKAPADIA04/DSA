#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    int n = s.size();
    int answer = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'M') {
            if((i - 1 >= 0) && s[i-1] == 'C') { answer += 900;i--;}
            else answer += 1000;
        }
        else if(s[i] == 'D') {
            if((i - 1 >= 0) && s[i-1] == 'C') { answer += 400;i--;}
            else answer += 500;
        }
        else if(s[i] == 'C') {
            if((i - 1 >= 0) && s[i-1] == 'X') { answer += 90;i--;}
            else answer += 100;
        }
        else if(s[i] == 'L') {
            if((i - 1 >= 0) && s[i-1] == 'X') { answer += 40;i--;}
            else answer += 50;
        }
        else if(s[i] == 'X') {
            if((i - 1 >= 0) && s[i-1] == 'I') { answer += 9;i--;}
            else answer += 10;
        }
        else if(s[i] == 'V') {
            if((i - 1 >= 0) && s[i-1] == 'I') { answer += 4;i--;}
            else answer += 5;
        }
        else if(s[i] == 'I') answer += 1;

    }
    return answer;
}


// or

int romanToInt_(string s) {
        int a=0;
        vector<int>res(128);
        res['I']=1;
        res['V']=5;
        res['X']=10;
        res['L']=50;
        res['C']=100;
        res['D']=500;
        res['M']=1000;
        
        for(int i=0;i+1<s.length();i++)
            if(res[s[i]]< res[s[i+1]])
            a-=res[s[i]];
            else 
            a+=res[s[i]];
            return a+res[s.back()];
    }

int main() {
    cout << romanToInt("LXXX") << endl;
    cout << romanToInt_("LXXX") << endl;
}