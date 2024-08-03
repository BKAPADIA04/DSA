#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int n = bills.size();
    int five = 0; int ten = 0;
    for(int i = 0;i < n;i++) {
        if(bills[i] == 5) five++;
        else if(bills[i] == 10) {
            ten += 1;
            if(five) {
                five -= 1;
            }
            else return false;
        }
        else {
            if(five && ten) {
                five -= 1;
                ten -= 1;
            }
            else if(five >= 3) {
                five -= 3;
            }
            else return false;
        }
    }
    return true;
}

int main() {
    vector<int>bills = {5,5,10,10,20};
    cout << lemonadeChange(bills) << endl;
}