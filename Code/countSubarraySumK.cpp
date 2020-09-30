// this requires o(n2) time compkexity
// #include <bits/stdc++.h>
// using namespace std;
// int findSubarray(int arr[], int k, int n)
// {
//     int c = 0;
//     int arr2[n+1];
//     arr2[0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         arr2[i] = arr2[i - 1] + arr[i-1];
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         cout<<arr2[i]<<" ";
//     }
//     cout<<endl;
//     for (int i = 0; i < n; i++)
//     {
//         // if(arr[i]==k){
//         //     c++;
//         // }
//         for(int j = i+1 ;j<=n;j++){
//             if((arr2[j]-arr2[i])==k){
//                 c++;
//                 cout<<arr2[j]-arr2[i]<<endl;
//             }
//             else{
//                 cout<<arr2[j]-arr2[i]<<endl;
//             }
//         }
//     }
//     return c;
// }
// int main()
// {
//     int arr[] = {10, 2, -2, -20, 10};
//     int k = -10;
//     int n = 5;
//     int ans;
//     ans = findSubarray(arr, k, n);
//     cout << "ans : -"<<ans;
//     return 0;
// }
// ##################################################################################################################
// but this requires o(n) only
// The idea behind this approach is as follows: If the cumulative sum(repreesnted by sum[i]sum[i] for sum upto i^{th}
// ith index) upto two indices is the same, the sum of the elements lying in between those indices is zero. Extending
// the same thought further, if the cumulative sum upto two indices, say ii and jj is at a difference of kk i.e.
// if sum[i] - sum[j] = ksum[i]−sum[j]=k, the sum of elements lying between indices ii and jj is kk.
// Based on these thoughts, we make use of a hashmap mapmap which is used to store the cumulative sum upto all the
// indices possible along with the number of times the same sum occurs. We store the data in the form: (sum_i, no.
// of occurences of sum_i)(sum i,no.ofoccurencesofsum i). We traverse over the array numsnums and keep on finding the
// cumulative sum. Every time we encounter a new sum, we make a new entry in the hashmap corresponding to that sum.
// If the same sum occurs again, we increment the count corresponding to that sum in the hashmap. Further, for every
// sum encountered, we also determine the number of times the sum sum-ksum−k has occured already, since it will
// determine the number of times a subarray with sum kk has occured upto the current index. We increment the count
// count by the same amount.

#include <bits/stdc++.h>
using namespace std;

int findSubarray(int arr[], int k, int n)
{
    int c = 0;
    unordered_map<int, int> prevSum;
    int currsum = 0;

    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum == k)
            c++;
        if (prevSum.find(currsum - k) != prevSum.end())
            c += (prevSum[currsum - k]);
        prevSum[currsum]++;
    }
    return c;
}

int main()
{
    int arr[] = {10, 2, -2, -20, 10};
    int k = -10;
    int n = 5;
    int ans;
    ans = findSubarray(arr, k, n);
    cout << "ans : -" << ans;
    return 0;
}


