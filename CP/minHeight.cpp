//https://www.codechef.com/submit/MINHEIGHT

#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int X, H;
        cin>>X>>H;
        if(X>=H){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}