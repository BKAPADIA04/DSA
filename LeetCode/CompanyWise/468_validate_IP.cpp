class Solution {
public:

    string validateIPv4(string IP) {
        IP.push_back('.');
        stringstream ss(IP);
        string word; int count = 0;
        while(getline(ss,word,'.')) {
            if(word.size() == 0 || word.size() > 3) return "Neither";
            if(word[0] == '0' && word.size() > 1) return "Neither";
            for(char ch : word) {
                if(!isdigit(ch)) return "Neither";
            }
            if(stoi(word) > 255) return "Neither";
            count++;
        }
        return (count == 4 && ss.eof()) ? "IPv4" : "Neither";
    }

    string validateIPv6(string IP) {
        IP.push_back(':');
        stringstream ss(IP);
        string word; int count = 0;
        while(getline(ss,word,':')) {
            if(word.size() == 0 || word.size() > 4) return "Neither";
            for(char ch : word) {
                if(!isdigit(ch) && !isalpha(ch)) return "Neither";
                if(ch >= 'A' && ch <= 'Z' && ch > 'F') return "Neither";
                if(ch >= 'a' && ch <= 'z' && ch > 'f') return "Neither";
            }
            count++;
        }
        return (count == 8 && ss.eof()) ? "IPv6" : "Neither";
    }

    string validIPAddress(string IP) {
        return (count(begin(IP), end(IP), '.') == 3)
                   ? validateIPv4(IP)
                   : (count(begin(IP), end(IP), ':') == 7 ? validateIPv6(IP)
                                                          : "Neither");
    }
};
