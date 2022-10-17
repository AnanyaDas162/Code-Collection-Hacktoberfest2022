/*
Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.

 

Example 1:

Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
*/



class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c){
      int i,j,k,count=0;
      for(i=0;i<(arr.length)-2;i++){
        for(j=i+1;j<(arr.length)-1;j++){
          if(Math.abs(arr[i]-arr[j]) <=a){
            for(k=j+1;k<arr.length;k++){
             if(Math.abs(arr[j]-arr[k]) <=b && Math.abs(arr[i]-arr[k]) <=c)
                  count++;
            }
          }
        }
      }
      return count;
    }
}

//time complexity : O(n^3)
//space complexity :o(1)
