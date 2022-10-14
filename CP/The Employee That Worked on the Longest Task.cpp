//Leetcode 2432
//Problem link
//https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/

class Solution {
public:
    int hardestWorker(int nn, vector<vector<int>>& logs) {
        int n = logs.size();
        int maxi = logs[0][1];
        int id = logs[0][0];
        int temp = logs[0][1];
        for(int i=1;i<n;i++){
            int j = logs[i][1] - temp;
            temp = logs[i][1];
            if(j==maxi){
                if(logs[i][0]<id)
                    id=logs[i][0];
            }
            else if(j>maxi){
                maxi = j;
                id=logs[i][0];
            }
        }
        return id;
    }
};