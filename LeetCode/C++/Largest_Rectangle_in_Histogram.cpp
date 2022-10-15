class Solution
{
public:
    vector<int> leftindex(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    vector<int> rightindex(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n);
        left = leftindex(heights, n);
        vector<int> right(n);
        right = rightindex(heights, n);
        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (right[i] == -1)
            {
                right[i] = n;
            }
            int b = right[i] - left[i] - 1;
            int newarea = l * b;
            area = max(area, newarea);
        }
        return area;
    }
};