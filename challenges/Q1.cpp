/*
Max till i

Problem: Given an array a[] of size n. For every i from 0 to n-1 output max(a[0],a[1],...,a[i])

*/
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int mx = INT_MIN;

    for(int i=0;i<n;i++)
    {
        /*
        int maximum = INT32_MIN;
        for(int j=0;j<=i;j++)
        {
            if (arr[j]>maximum)
            {
                maximum = arr[j];
            }
        }
        cout<<maximum<<endl;
        */
       int mx = max(mx,arr[i]);
       cout<<mx<<endl;
    }

    return 0;
}
