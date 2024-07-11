#include <bits/stdc++.h>
using namespace std;

void bitManipulation(int num, int i) {
    int get_ith_bit = (num & (1 << (i-1))) != 0;
    int set_ith_bit = (num | (1 << (i-1)));
    int clear_ith_bit = (num & (~(1 << (i-1))));

    cout << get_ith_bit << " " << set_ith_bit << " " << clear_ith_bit << endl;
}

int main() {
    bitManipulation(70, 3);
    bitManipulation(678883006,16);
}