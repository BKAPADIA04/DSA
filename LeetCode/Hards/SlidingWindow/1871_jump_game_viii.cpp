class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        bool ans = false;
        deque<int>dq;
        dq.push_back(0);

        for(int i = 1;i < n;i++) {
            while(!dq.empty() && dq.front() < i - maxJump) {
                dq.pop_front();
            }

            if(s[i] == '1') continue;

            bool temp = false;
            if(!dq.empty() && dq.front() + minJump <= i && dq.front() + maxJump >= i) {
                temp = true;
                if(i == (n-1)) return true;
            }
            
            if(temp) dq.push_back(i);
        }
        return false;
    }
};
