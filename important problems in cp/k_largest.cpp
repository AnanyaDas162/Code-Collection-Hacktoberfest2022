#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    priority_queue<int,vector<int>> maxh;
    int k=3;
    vector<int> nums = {7,4,3,8,10,9};
    for(int i=0;i<nums.size();i++){
        maxh.push(nums[i]);
        if(maxh.size()>k)
            maxh.pop();
    }
    cout<<k<<"th smallest "<<maxh.top();
    return 0;
}