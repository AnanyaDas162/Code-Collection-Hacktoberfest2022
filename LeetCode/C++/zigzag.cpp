class Solution {
public:
    string convert(string s, int n) 
    {
        if(n==1) return s;
       vector<string>v(n,"");
       int idx=0;
       int counter=0;
       bool flag=true;   //true->uper se neeche   
       while(idx<s.length())
       {
          if(idx<s.length() and flag==true)
          {
            while(idx<s.length() and counter<=(v.size()-1))
            {
               v[counter].push_back(s[idx]);
               idx++;
               counter++;
            }
            if(idx>=s.length()) break;
              
            if(counter>=v.size()) counter=v.size()-2;
              
            flag=!flag;
          }
          else if(idx<s.length() and flag==false)
          {
            while(idx<s.length() and counter>=0)
            {
               v[counter].push_back(s[idx]);
               idx++;
               counter--;	
            }
            if(idx>=s.length()) break;
              
            if(counter<=0) counter=counter+2;
              
            flag=!flag;
          }
       }

       string ans="";
       for(int i=0;i<v.size();i++)
       {
         ans=ans+v[i];
       }
       return ans;
    }
};
