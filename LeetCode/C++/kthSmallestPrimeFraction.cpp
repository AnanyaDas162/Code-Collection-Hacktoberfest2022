class compare{
    public:
        bool operator()(vector<int> &v1, vector<int> &v2){
            return (double)v1[0]/(double)v1[1] < (double)v2[0]/(double)v2[1];
        }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                vector<int> v;
                v.push_back(arr[i]);
                v.push_back(arr[j]);
                if(pq.size() < k){
                    pq.push(v);
                }else{
                    if((double)arr[i]/(double)arr[j] < (double)pq.top()[0]/(double)pq.top()[1])
                    {
                        pq.pop();
                        pq.push(v);
                    }
                }
            }
        }

        return pq.top();
    }
};
