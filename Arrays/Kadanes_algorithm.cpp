#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    int64_t mmax=INT32_MIN, curr=0;
    for(int i=0;i<n;i++)
    {
        curr=curr+arr[i];
        if(curr>mmax) mmax=curr;
        if(curr<0) curr=0;
    }
    return max(mmax, int64_t(0));
}
