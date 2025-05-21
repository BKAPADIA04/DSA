class Solution {
public:

    void check(int n, int k, int counter,vector<int>&answer,int &temp) {
        if(counter == n) {
            answer.push_back(temp);
            return;
        }
        
        for(int i = 0;i <= 9;i++) {
            if(counter == 0) {
                if(i != 0) {
                    temp = i;
                    check(n,k,counter+1,answer,temp);
                    temp = 0;
                }
            }
            else {
                int lastDigit = temp % 10;
                if(abs(i - lastDigit) == k) {
                    temp = temp * 10 + i;
                    check(n,k,counter+1,answer,temp);
                    temp = temp/10;
                }
            }
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        int temp = 0;
        vector<int>answer;
        check(n,k,0,answer,temp);
        return answer;
    }
};
