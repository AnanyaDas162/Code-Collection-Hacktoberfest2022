class Solution 
{
    public String getPermutation(int n, int k) 
    {
      ArrayList number = new ArrayList<>();
      String ans="";
      int fact=1;
      for(int i=1;i<n;i++)
      {
        fact = fact*i;
        number.add(i);
      }
      number.add(n);//we do not n as we have to calculate factorial for n-1 numbers as there 1 digit is already placed at its position
      k=k-1;//as we are using 0 bit indexing(starting from 0 rather than 1)
      while(true)
      {
          ans=ans+number.get(k/fact);// k/fact is the digits that is required to be placed according to given k
          number.remove(k/fact);
          if(number.size()==0)//no digits left to place them in the places.
              break;

          k = k%fact;//
          fact=fact/number.size();// as number.size()has decreased by 1 we require factorial of 1 less number of digits like if there fact was 6 that meant there were three digits for permutation so when we select either the three then there will remain two digits for further proceedings so 2! = 2  (so 6/3=2 therefore 3 is the size of new number arrayList and there is first place that is already occupied. )
      }
    return ans;
    }
}
