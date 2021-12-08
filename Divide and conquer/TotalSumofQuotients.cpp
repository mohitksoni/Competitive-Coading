// Total Sum of Quotients
// Given an array A of integers and an integer S. Write an efficient program to find the minimum X such
// that when X divides all the elements in A, the total sum of the quotients doesn't exceed S. Consider
// Integer division while dividing elements of the array.Note: X should be a positive number and the total
// sum of quotients can be equal to S.


#include<iostream>
#include<climits>
#include<vector>
typedef long long int ll;
// #define ll long long int
using namespace std;

ll SumOfQuotients(vector<ll> v1, int n,ll s){
    ll maximum = LLONG_MIN;
    for(int i=0;i<n;i++){
        maximum = max(maximum, v1[i]);
    }
    
    // binary search between k = 1 and maximum + 1
    ll low = 1, high = maximum + 1;
    ll sol = high;
    while(low <= high){
        ll mid = low + (high - low)/2;
        ll sum = 0;
        for(int i = 0;i<n;i++){
            sum += v1[i]/mid;
        }
        if(sum > s){
            low = mid + 1;
        }
        else{
            sol = min(sol,mid);
            high = mid - 1;
        }
    }
    return sol;
}


int main(){
    int n;
    cin>>n;
    ll s;
    cin>>s;
    vector<ll> v;
     
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    cout<<SumOfQuotients(v,n,s);
    return 0;
}
