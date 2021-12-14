// Find Kth Largest Element

// Given an array A of N integers, write an efficient program to 
// find the Kth largest element in A. Note: All integers are unique


#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long int
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    
    vector<ll> v;
    for(int i = 0;i<n;i++){
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    ll kthMax;
    make_heap(v.begin(), v.end());
    while(k > 0){
        pop_heap(v.begin(),v.end());
        kthMax = v.back();
        v.pop_back();
        k--;
    }
    cout<<kthMax;
}
