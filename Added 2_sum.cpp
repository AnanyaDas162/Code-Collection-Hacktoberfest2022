#include <stdio.h>
 
// Naive method to find a pair in an array with a given sum
void findPair(int nums[], int n, int target)
{
    // consider each element except the last
    for (int i = 0; i < n - 1; i++)
    {
        // start from the i'th element until the last element
        for (int j = i + 1; j < n; j++)
        {
            // if the desired sum is found, print it
            if (nums[i] + nums[j] == target)
            {
                printf("Pair found (%d, %d)\n", nums[i], nums[j]);
                return;
            }
        }
    }
 
    // we reach here if the pair is not found
    printf("Pair not found");
}
 
int main(void)
{
    int nums[] = { 8, 7, 2, 5, 3, 1 };
    int target = 10;
 
    int n = sizeof(nums)/sizeof(nums[0]);
 
    findPair(nums, n, target);
 
    return 0;
}
