#include <iostream>
#include <cmath>
using namespace std;
 
void rook() {
    int n, k;
    cin >> n >> k;
 
    if(k > ceil((float)n/2)){
        cout << "-1\n";
        return;
    }
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
 
            if(i==j && i%2==0 && k>0){
                cout << "R";
                k--;
            }
            else
                cout << ".";
        }
        cout << "\n";
    }
}
 
int main(){
    int t;
    cin >> t;
    
    while(t--)
        rook();
    
    return 0;
}