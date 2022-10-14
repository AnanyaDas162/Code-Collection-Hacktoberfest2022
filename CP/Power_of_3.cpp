//power of 3 
//  Ankur Shukla (Leetcode)

#include <iostream>
bool isPowerOfThree(int n) {
        if(n==0 ){
             return false;
         }
        
        else if(n==1 ){
            return true;
        }
       
        
        
        return (n%3==0) and isPowerOfThree(n/3);
    }



int main() {
    
     // call function as per requirement 

    return 0;
}
