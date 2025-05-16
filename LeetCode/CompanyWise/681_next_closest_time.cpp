#include <bits/stdc++.h>
using namespace std;

set<char>digits;
int minDifference;
string answer;
int originalMinutes;

bool isValid(string temp) {
  int hrs = stoi(temp.substr(0,2));
  int min = stoi(temp.substr(3));
  
  return hrs >= 0 && hrs <= 23 && min >= 0 && min <= 59;
}

void check(string &temp) {
  if(temp.size() == 4) {
    if(isValid(temp)) {
      int minutes = stoi(temp.substr(0,2)) * 60 + stoi(temp.substr(3));
      if(minutes > originalMinutes && minutes - originalMinutes < minDifference) {
        minDifference = minutes - originalMinutes;
        answer = temp.substr(0,2) + ":" + temp.substr(3);
      }
    }
    return;
  }
  
  for(char ch : digits) {
    temp.push_back(ch);
    check(temp);
    temp.pop_back();
  }
  return;
}

string nextClosestTime(string str) {
  originalMinutes = stoi(str.substr(0,2)) * 60 + stoi(str.substr(3));
  minDifference = INT_MAX;
  
  char minDigit = '9';
  for(char ch:str) {  
      if(ch == ':') continue;
      minDigit = min(minDigit, ch);
      digits.insert(ch);
  }
  
  string temp = "";
  check(temp);
  
  if(answer.size() == 0) {
    return string(2,minDigit) + ":" + string(2,minDigit);
  }
  return answer;
}

int main() {
    string str;
    cin >> str;
    string answer = nextClosestTime(str);
    cout << answer << endl;
    return 0;
}
