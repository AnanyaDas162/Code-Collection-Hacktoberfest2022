#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    
    int n, t, temp;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    cin >> t;
    
    while (t--){
        cin >> temp;
        cout << distance(upper_bound(v.begin(), v.end(), temp), v.end())+1 << '\n';
    }
}