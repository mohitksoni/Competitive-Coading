// We need to sort the given array based on it's number of occurrences in decreasing order 
// and if the occurrence of two elements are same than sort them in decreasing order.

// Input Array n = 10, [2 1 1 3 5 5 4 1 1 3]
// Output Array [1 1 1 1 5 5 3 3 4 2]


#include <iostream>
#include<map>
#include<algorithm>
#define ll long long int
using namespace std;

map<ll, int> m;
bool compare(ll &a, ll &b){
    if(m[a] == m[b]){
        return a > b;
    }
    else{
        return m[a] > m[b];
    }
}

int main() {
    int n;
    cin>>n;
    
    ll a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    sort(a, a+n, compare);
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
