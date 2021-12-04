// A peak in an array is a position that is greater than or equal to its adjacent elements
#include<iostream>
using namespace std;
typedef long long int ll;

ll computePeak1DArray(ll a[],int i, int n){
    int temp = i + (n - i)/2;
    if(i==n-1){
        return a[i];
    }
    else if(a[temp] > a[temp + 1] && a[temp] > a[temp - 1] ){
        return a[temp];
    }
    else if(a[temp + 1] > a[temp]){
        return computePeak1DArray(a,temp,n);
    }
    else{
        return computePeak1DArray(a,i,temp);
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    ll arr[n];
    int start = 0;
    
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        arr[i] = temp;
    }
    cout<<computePeak1DArray(arr,start,n);
    return 0;
}
