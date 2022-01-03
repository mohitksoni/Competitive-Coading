// Total Number of Subarrays Divisible by K

// Given an array A of N integers, and an integer K. Write an efficient
// program to find the count of subarrays whose sum is exactly divisible
// by K.

// Input

// First line contains a single integet T. T testcases follow.
// First line of a testcase contains two space separated integers N and
// K.
// Second line of a testcase contains N space separated integers of A.
// Output

// For each testcase in T, print the output in a new line.
// Output contains a single integer based on the above context.

// Constraints

// 1 <= T <= 5
// 1 <= N <= 10^5
// -10^9 <= A[i] <= 10^9
// 1 <= K <= largest element of A

// Sample Input
// 1
// 5 2
// 1 2 4 3 -4

// Sample Output
// 6

#include<iostream>
#include<map>
#define ll long long int
using namespace std;

ll Subarray(ll a[], ll k,ll n){
    map<int,int> map;
    int count = 0;
    ll sum = 0;
    map[sum%k]++;
    for(int i = 0;i < n;i++){
        sum += a[i];
        if(sum%k >= 0){
            if(map.find(sum%k) != map.end()){
                count += map[sum%k];
                map[sum%k] ++;
            }
            else{
                map[sum%k] ++;
            }
        }
        else{
            if(map.find(sum%k + k) != map.end()){
                count += map[sum%k + k];
                map[sum%k + k] ++;
            }
            else{
                map[sum%k + k] ++;
            }
        }
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    
    while(t!= 0){
        ll n,k;
        cin>>n>>k;
        
        ll a[n];
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        cout<<Subarray(a,k,n)<<endl;;
        t--;
    }
}
