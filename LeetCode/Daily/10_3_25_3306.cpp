#define ll long long
class Solution {
public:
    ll check(string word, int k) {
        ll n = word.size();
        unordered_map<char,ll>freq;
        ll conso_count = 0; 
        ll answer = 0ll;
        ll left = 0ll; ll right = 0ll;
        while(right < n) {
            if(word[right] == 'a' || word[right] == 'e' || word[right] == 'i' || word[right] == 'o' || word[right] == 'u') {
                freq[word[right]]++;
            }
            else conso_count++;

            while(conso_count >= k && freq.size() == 5) {
                answer += n - right;
                if(word[left] == 'a' || word[left] == 'e' || word[left] == 'i' || word[left] == 'o' || word[left] == 'u') {
                    freq[word[left]]--;
                    if(freq[word[left]] == 0) freq.erase(word[left]);
                }
                else conso_count--;
                left++;
            }
            
            right++;
        }
        return answer;
    }

    long long countOfSubstrings(string word, int k) {
        return check(word,k) - check(word,k+1);
    }
};

