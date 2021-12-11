// Longest Subsequence

// Given two arrays A and B with the same length, write an efficient program to find
// the length of the longest subsequence of array A, whose sum is greater than or equal
// to the corresponding subsequence of array B. Corresponding subsequence means indices
// chosen in both of the arrays must be the same. Note: Subsequences need not be continuous.

#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;

bool compare(ll &a, ll &b){
    return a>b;
}

int main(){
    int n;
    cin>>n;
    
    ll a[n],b[n],c[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    
    for(int i=0;i<n;i++){
        c[i] = a[i] - b[i];
    }
    
    sort(c, c+n, compare);
    int result = 0;
    ll sum = 0;
    int flag = 0;
    for(int i=0;i<n;i++){
        sum+= c[i];
        if(sum >= 0){
            flag = 1;
            result = i;
        }
    }
    if(flag == 0){
        cout<<result;
    }
    else
    {
        cout<<result + 1;
    }
}
