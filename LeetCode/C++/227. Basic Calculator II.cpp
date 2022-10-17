// Given a string s which represents an expression, evaluate this expression and return its value. 

// The integer division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> stk; 
        
        long long int ans = 0, curr = 0;
        char sign = '+'; //to store the previously encountered sign
        
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])) curr = curr*10 + (s[i]-'0'); //keep forming the number, until you encounter an operator
            
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                
                if(sign == '+') stk.push(curr); //'Cause it has to added to the ans
            
                else if(sign == '-') stk.push(curr*(-1)); //'Cause it has to be subtracted from ans
                
                else if(sign == '*'){
                    int num = stk.top(); stk.pop();  //Pop the top of the stack
                    stk.push(num*curr); //Multiply it with the current value & push the result into stack
                }
                
                else if(sign == '/'){
                    int num = stk.top();stk.pop(); 
                    stk.push(num/curr);  //Divide it with curr value & push it into the stack
                }
                
                curr = 0; 
                sign = s[i]; 
            }
            
        }
        
        while(stk.size()){
            ans += stk.top(); stk.pop();
        }
            
        return ans;    
    }
};
