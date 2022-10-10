//https://www.codechef.com/JULY221C/problems/KNIGHT2
//#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
    
int main() {
    int t;
    cin >> t;
    while (t--){
        int p, q, r, s;
        cin >> p >> q >> r >> s;

        int x, y;
        x=(p+q) & 1;
        y=(r+s) & 1;

        if(x==y)
            cout << "YES" << endl;
        
        else
            cout << "NO" << endl;
        
    }
return 0;
}