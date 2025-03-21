#define ll long long
class ATM {
public:

    vector<int>nums;
    vector<int>money;

    ATM() {
        nums.resize(5);
        money.push_back(20); money.push_back(50); money.push_back(100); money.push_back(200); money.push_back(500);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0;i < banknotesCount.size();i++) {
            nums[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int>temp = nums;
        ll temp_amount = amount;
        vector<int>ans(5,0);
        for(int i = 4;i >= 0;i--) {
            if(nums[i]) {
                if((ll)nums[i] * money[i] > (ll)temp_amount) {
                    int req = temp_amount/money[i];
                    temp_amount -= money[i] * req;
                    ans[i] += req;
                    nums[i] -= req;
                }
                else {
                    temp_amount -= (ll)nums[i] * money[i];
                    ans[i] += nums[i];
                    nums[i] = 0;
                }
            }
        }
        if(temp_amount == 0) return ans;
        nums = temp;
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
