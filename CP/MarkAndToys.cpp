#include <bits/stdc++.h>

using namespace std;

using namespace std;
int main(){
    
    int num, money,i,sum=0;
    cin >> num >> money;
    
    int cost[num];
    for (i=0;i<num;i++)
        cin>>cost[i];
    
    sort(cost,cost+num);
    i=0;
    
    while(cost[i]<money){
        sum=sum+cost[i];
        if(sum>money) break;
        i++;    
    }
    
    cout << i;
    return 0;
}