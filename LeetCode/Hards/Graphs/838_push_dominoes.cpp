class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        queue<int>q;
        vector<int>time(n,-1);
        vector<vector<char>> forces(n);

        string answer(n,'.');

        for(int i = 0;i < n;i++) {
            if(dominoes[i] == '.') continue;
            q.push(i);
            time[i] = 0;
            forces[i].push_back(dominoes[i]);
        }

        while(!q.empty()) {
            int index = q.front(); q.pop();
            if(forces[index].size() == 1) {
                answer[index] = forces[index][0];

                int adjacentIndex = forces[index][0] == 'L' ? index - 1 : index + 1;
                if(adjacentIndex < 0 || adjacentIndex >= n) continue;

                int currTime = time[index];
                if(time[adjacentIndex] == -1) {
                    q.push(adjacentIndex);
                    time[adjacentIndex] = currTime + 1;
                    forces[adjacentIndex].push_back(forces[index][0]);
                }
                else if(time[adjacentIndex] == currTime + 1) {
                    forces[adjacentIndex].push_back(forces[index][0]);
                }
            }
        }

        return answer;
    }
};

/*class Solution {
public:
    string pushDominoes(string dominoes) {
        int i=0,j=0;
        int n = dominoes.size();
        while(i<n){
            if(dominoes[i]!='.') i++;
            else{
                int j=i;
                while(j<n && dominoes[j] == '.') j++;
                int end = j;
                j--;
                char left,right;
                if(i==0) left = 'L';
                else if(i>0) left = dominoes[i-1];
                if(j==n-1) right = 'R';
                else if(j<n-1) right = dominoes[j+1];
                while(i<j){
                    if(left == 'L' && right == 'R'){
                        break;
                    } else if(left!='L' && right != 'R'){
                        if(i>=0 && i<n) dominoes[i] = 'R';
                        if(j>=0 && j<n) dominoes[j] = 'L';
                        i++;
                        j--;
                    }else if(left == 'L' && right == 'L'){
                        while(j>=0 && j>=i) {
                            dominoes[j] = 'L';
                            j--;
                        }
                        break;
                    }else if(left == 'R' && right == 'R'){
                        while(i<=j && i<n) {
                            dominoes[i] = 'R';
                            i++;
                        }
                        break;
                    }
                }
                if(left == 'L' && right == 'L') dominoes[i] = 'L';
                if(left == 'R' && right == 'R') dominoes[i] = 'R';
                i= end;
            }
        }
        return dominoes;
    }
};*/
