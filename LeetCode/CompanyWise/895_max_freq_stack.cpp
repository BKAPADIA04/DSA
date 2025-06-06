class FreqStack {
public:

    int maxFreq;
    unordered_map<int,int>freqMap;
    unordered_map<int,stack<int>>freqStack;

    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freqMap[val]++;
        if(maxFreq < freqMap[val]) maxFreq = freqMap[val];
        freqStack[freqMap[val]].push(val);
    }
    
    int pop() {
        int ans = freqStack[maxFreq].top();
        freqMap[ans]--;
        if(freqMap[ans] == 0) freqMap.erase(ans);
        freqStack[maxFreq].pop();
        if(freqStack[maxFreq].size() == 0) {
            freqStack.erase(maxFreq);
            maxFreq--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
