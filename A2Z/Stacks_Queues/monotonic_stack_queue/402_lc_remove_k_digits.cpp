#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    if(num.size() == k) return "0";
    stack<char>st;
    for(int i = 0;i < num.size();i++) {
        while(!st.empty() && (st.top() > num[i]) && k > 0) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while(k > 0) {
        st.pop();
        k--;
    }

    string temp = "";
    while(!st.empty())  {
        temp += st.top();
        st.pop();
    }
    reverse(temp.begin(),temp.end());
    int j = 0;
    while(j < temp.size() && (temp[j] == '0')) j++;
    temp = temp.substr(j);
    if(temp == "") return "0";
    return temp;
}

int main() {
    cout << removeKdigits("1432219",3) << endl;
    cout << removeKdigits("10200",1) << endl;
    cout << removeKdigits("9123",2) << endl;
}