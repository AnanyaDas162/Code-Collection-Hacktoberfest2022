class Solution {
public:
    string getHint(string &secret, string &guess) {
        int c = 0, b = 0, i = 0, n = secret.length();
        unordered_map<char,char> mp;
        for(i = 0; i < n; i++){
            if(secret[i]==guess[i]){
                b++;
                guess[i] = '#';
            }else{
                mp[secret[i]]++;
            }
        }
        for(auto &i: guess){
            if(i != '#' && mp.count(i) && mp[i]>0){
                c++;
            }
            mp[i]--;
        }
        return to_string(b)+'A'+to_string(c)+'B';
    }
};
