class Solution
{
    public String largestPalindromic(String num)
    {
        int i,j;
        StringBuilder lPal=new StringBuilder();
        StringBuilder rPal=new StringBuilder();
        String tempRes="";
        Map<Integer, Integer> map=new HashMap<>();
        for(i=0;i<=9;i++)
            map.put(i,0);
        for(i=0;i<=num.length()-1;i++)
            map.put(Character.getNumericValue(num.charAt(i)),map.get(Character.getNumericValue(num.charAt(i)))+1);
        for(i=9;i>=0;i--)
        {
            for(j=1;j<=map.get(i)/2;j++)
            {
                lPal.append(i);
                rPal.insert(0,i);
            }
            map.put(i,map.get(i)%2);
        }
        for(i=9;i>=0;i--)
            if(map.get(i)==1)
            {
                tempRes=lPal.toString()+i+rPal.toString();
                break;
            }
        if(tempRes.length()==0)
            tempRes=lPal.toString()+rPal.toString();
        StringBuilder res=new StringBuilder(tempRes);
        while(res.length()>0 && res.charAt(0)=='0')
        {
            res.deleteCharAt(0);
            if(res.length()>0)
                res.deleteCharAt(res.length()-1);
        }
        if(res.length()==0)
            res.append(0);
        
        return res.toString();
    }
}
