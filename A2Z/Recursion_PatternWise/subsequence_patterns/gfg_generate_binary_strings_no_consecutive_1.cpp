#include <bits/stdc++.h>
using namespace std;

void print(vector<string>temp) {
    for(string str:temp) cout << str << endl;
}


vector<string> generate(string s,int i,int n) {
    if(i == n) { return {s}; }

    vector<string> result;
    if(s[i-1] == '1') {
        s = s + "0";
        vector<string>temp = generate(s,i+1,n);
        result.insert(result.end(), temp.begin(), temp.end());
    }
    else {
        s = s + "0";
        vector<string>temp = generate(s,i+1,n);
        result.insert(result.end(), temp.begin(), temp.end());
        s[i] = '1';
        temp = generate(s,i+1,n);
        result.insert(result.end(), temp.begin(), temp.end());
    }
    return result;
}


vector<string> generateBinaryStrings(int num){
    vector<string>ans;
    string str = "1";
    ans = generate(str,1,num);

    str = "0";
    vector<string>temp = generate(str,1,num);
    ans.insert(ans.end(),temp.begin(),temp.end());
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<string>ans = generateBinaryStrings(3);
    for(string s:ans) { cout << s << endl;}
}