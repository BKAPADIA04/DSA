#include <bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(long long int Arr[], long long int N)  
{
    vector<long long int> answer;
    long long int xorr = 0;
    for(int i = 0;i < N;i++) {
        xorr = xorr ^ Arr[i];
    }

    // Rightmost Set Bit which is also the differentiating bit (first differentiating bit from right)
    long long int right_most_set_diff = xorr & (~(xorr-1));
    long long int ith_bit = log2(right_most_set_diff);

    long long int first = 0,second = 0;

    for(int i = 0;i < N;i++) {
        if(Arr[i] & (1 << ith_bit)) {
            first = first ^ Arr[i];
        }
        else {
            second = second ^ Arr[i];
        }
    }

    first = first ^ xorr;
    second = second ^ xorr;

    if(first > second) {
        answer.push_back(first);
        answer.push_back(second);
    }
    else {
        answer.push_back(second);
        answer.push_back(first);
    }

    return answer;
}

int main() {
    int N = 8;
    // long long int Arr[] = {4, 2, 4, 5, 2, 3, 3, 1};

    long long int Arr[] = {1 ,7 ,5 ,7, 5 ,4 ,7, 4};

    vector<long long int> answer = twoOddNum(Arr,N);
    cout << answer[0] << " " << answer[1] << endl;
}