class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        if(nums.empty())
            return res;
        
        int n = nums.size();
        
        // Approach requires sorting and 2-pointer approach
        
        // Step1 -> sorting
        sort(nums.begin(),nums.end());
        
        
        // Step2 -> 2-pointer 
        for(int i=0; i<n; i++)
        {
            long long int target3 = target - nums[i];
            
            for(int j=i+1; j<n; j++)
            {
                long long int target2 = target3 - nums[j];
                
                int front = j+1;
                int back = n-1;
                
                while(front<back)
                {
                    // remaining elements to be found for quad sum
                    int two_sum = nums[front] + nums[back];
                    
                    if(two_sum < target2)
                        front++;
                    else if(two_sum > target2)
                        back--;
                    
                    else
                    {
                        // if two_sum == target2
                        vector<int> quad(4,0);
                        // quad.push_back(nums[i]);
                        // quad.push_back(nums[j]);
                        // quad.push_back(nums[front]);
                        // quad.push_back(nums[back]);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        
                        
                        res.push_back(quad);
                        
                        // Processing the duplicates of number 3
                        while(front < back && nums[front] == quad[2]) 
                            front++;
                        
                        // Processing the duplicates of number 4
                        while(front < back && nums[back] == quad[3]) 
                            back--;
                    }
                    
                }
                // Processing the duplicates of number 2
                    while(j + 1 < n && nums[j + 1] == nums[j]) 
                        j++;
            }
            // Processing the duplicates of number 2
                    while(i + 1 < n && nums[i + 1] == nums[i]) 
                        i++;
        }
        
        return res;
    }
};

int main(){
  vector<int> arr = {1,2,4,7,0};
  int target = 8;
  vector<vector<int>> ans = fourSum(arr,target);
  cout<<ans<<endl;
}
