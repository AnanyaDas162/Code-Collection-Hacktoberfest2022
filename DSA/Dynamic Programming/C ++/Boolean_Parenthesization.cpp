/* Evaluate Expression to True Boolean Parenthesization */
/* I/P : "T|F&T^F", O/P : 5. Count the no. of ways we can parenthesize the exp.*/
/*Add brackets in the expression in such a way that after evaluation the output is true.
e.g = ((T|F)&(T^F)) or ((T)|(F&T^F))...... */

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int mcm(string s, int i, int j, bool isTrue)
{
    if(i > j)
        return false;
    if(i == j){
        if(isTrue == true)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    int ans = 0;
    for(int k=i+1; k<=j-1; k=k+2){
        int lT = mcm(s, i, k-1, true);
        int lF = mcm(s, i, k-1, false);
        int rT = mcm(s, k+1, j, true);
        int rF = mcm(s, k+1, j, false);

        if(s[k] == '&'){
            if(isTrue == true)
                ans += lT*rT;
            else
                ans += lF*rT + lT*rF + lF*rF;
        }
        else if(s[k] == '|'){
            if(isTrue == true)
                ans += lT*rT + lT*rF + lF*rT;
            else
                ans += lF*rF;
        }
        else if(s[k] == '^'){
            if(isTrue == true)
                ans += lF*rT + lT*rF;
            else
                ans += lT*rT + lF*rF;
        }
    }
    return ans;
}

int mcm_m(string s, int i, int j, bool isTrue)
{
    if(i > j)
        return false;
    if(i == j){
        if(isTrue == true)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if(mp.find(temp) != mp.end())
        return mp[temp];

    int ans = 0;
    for(int k=i+1; k<=j-1; k=k+2){
        int lT = mcm(s, i, k-1, true);
        int lF = mcm(s, i, k-1, false);
        int rT = mcm(s, k+1, j, true);
        int rF = mcm(s, k+1, j, false);

        if(s[k] == '&'){
            if(isTrue == true)
                ans += lT*rT;
            else
                ans += lF*rT + lT*rF + lF*rF;
        }
        else if(s[k] == '|'){
            if(isTrue == true)
                ans += lT*rT + lT*rF + lF*rT;
            else
                ans += lF*rF;
        }
        else if(s[k] == '^'){
            if(isTrue == true)
                ans += lF*rT + lT*rF;
            else
                ans += lT*rT + lF*rF;
        }
    }
    return mp[temp] = ans;
}

int main()
{
    string s = "T|F&T^F";
    int i = 0, j = s.size()-1;
    bool isTrue = true;

    cout << mcm(s, i, j, isTrue) << "\n";

    mp.clear();
    cout << mcm_m(s, i, j, isTrue) << "\n";

    return 0;
}
