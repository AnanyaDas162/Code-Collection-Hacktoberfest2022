class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int cnt = 1; // this will keep track of duplicate element    atmost 2.
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] == nums[i])
            {
                if (cnt == 2) // cnt already 2 then..
                {
                    int index = i; // keeping track of curr index
                    while (i < nums.size() && nums[i - 1] == nums[i])
                        i++;                                            // increament till we reach to non-duplicate element.
                    nums.erase(nums.begin() + index, nums.begin() + i); // removing all the duplicate from nums from index to i.
                    i = index - 1;
                    cnt = 1; // making cnt again 1.
                }
                else
                    ++cnt;
            }
            else
                cnt = 1; // if nums[i]!=nums[i-1] then update cnt to 1.
        }
        return nums.size(); // returning size after erasing duplicate from nums.
    }
};