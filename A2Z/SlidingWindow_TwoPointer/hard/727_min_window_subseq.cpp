string minWindow(string s, string t)
{
	// Write your Code here
	int n = s.size();
	int m = t.size();

	int start = -1;
	int minLength = n;
	int end = -1;
	int j = 0;
	string answer = "";
	for(int i = 0;i < n;i++) {
		if(s[i] == t[j]) {
			j++;
			if(j >= m) {
				end = i + 1;
				j--;
				while(j >= 0) {
					if(s[i] == t[j]) {
						j--;
					}
					i--;
				}
			j++; i++;
			if(end - i < minLength) {
				minLength = end - i;
				answer = s.substr(i,minLength);
			}
		}
	}
	}
	return answer;
}
