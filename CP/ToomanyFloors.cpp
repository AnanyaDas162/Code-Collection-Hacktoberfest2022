//https://www.codechef.com/LTIME109C/problems/FLOORS
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
    cin >> t;
    while (t--){
        int x, y;
        cin >> x >> y;
        int fx, fy, diff;
        fx=(x+9)/10;
        fy=(y+9)/10;
        diff=abs(fx-fy);
        cout << diff << endl;
    }
return 0;
}