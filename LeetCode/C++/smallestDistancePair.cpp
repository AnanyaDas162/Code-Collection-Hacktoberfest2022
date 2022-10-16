class compare{
    public:
        bool operator()(vector<int> &v1, vector<int> &v2){
            return abs(v1[0]-v1[1]) < abs(v2[0]-v2[1]);
        }
};
class Solution {
public:
    int smallestDistancePair(vector<int>& arr, int k) {
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
                    if(abs(arr[i]-arr[j]) < abs(pq.top()[0]-pq.top()[1]))
                    {
                        pq.pop();
                        pq.push(v);
                    }
                }
            }
        }

        return abs(pq.top()[0]-pq.top()[1]);
    }
};
