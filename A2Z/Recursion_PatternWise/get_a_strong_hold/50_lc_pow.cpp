#include <bits/stdc++.h>
using namespace std;

// double myPow(double x, int n) {

//     if(n < 0) return 1/myPow(x,abs(n));

//     if(n == 1) return x;

//     return x * myPow(x,n - 1);    
// }

double myPow(double x, int n) {
    if(n == 0) return 1; 
    if(n == 1) return x;
    if(n == -1) return 1/x;
    double check = myPow(x,n/2);
    double answer = check * check;
    if(n % 2 == 1) answer = answer * x;
    else if(n % 2 == -1) answer = answer * (1/x);
    return answer;
}

double myPow_(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
}

int main() {
    cout << myPow(1,-2147483648) << endl;
    cout << myPow_(1,-2147483648) << endl;
    cout << myPow(2,-3) << endl;
    cout << myPow_(2,-3) << endl;
    cout << INT_MIN << " " << INT_MAX << endl;
}