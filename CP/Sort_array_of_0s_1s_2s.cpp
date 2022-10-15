#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void sort012(int a[], int n){
        int one = 1;
        int two = 2;
        int zero = 0;

        for (int j = 0; j < n; j++){
            if (a[j] == 0){
                zero++;
            }
            else if (a[j] == 1){
                one++;
            }
            else{
                two++;
            }
        }
        for (int j = 0; j < n; j++){
            if (zero > 0){
                a[j] = 0;
                zero--;
            }
            else if (one > 1){
                a[j] = 1;
                one--;
            }
            else{
                a[j] = 2;
                two--;
            }
        }
    }
};

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Solution ob;
    ob.sort012(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}