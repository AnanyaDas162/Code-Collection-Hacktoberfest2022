class Solution
{
    public String sortString(String str)
    {
        char tempArr[]=str.toCharArray();
        Arrays.sort(tempArr);
        
        return new String(tempArr);
    }
    
    public List<List<String>> groupAnagrams(String[] strs)
    {
        int i;
        String[] strsCpy=strs.clone();
        Map<String, List<String>> map=new HashMap<>();
        List<List<String>> res=new ArrayList<>();
        for(i=0;i<=strsCpy.length-1;i++)
            strsCpy[i]=sortString(strsCpy[i]);
        for(i=0;i<=strsCpy.length-1;i++)
            if(map.containsKey(strsCpy[i]))
                map.get(strsCpy[i]).add(strs[i]);
            else
            {
                List<String> tempLst=new ArrayList<String>();
                tempLst.add(strs[i]);
                map.put(strsCpy[i],tempLst);
            }
        for(Map.Entry<String, List<String>> entry: map.entrySet())
            res.add(entry.getValue());
        
        return res;
    }
}
