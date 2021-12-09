// sorting array using quick sort
// Last element of the array is considered as pivot

#include<iostream>
#define ll long long int
using namespace std;

int partition(ll a[], int start, int end){
    ll pivot = a[end];
    int i = start - 1;
    int j = start;
    while(j<end){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
        j++;
    }
    i++;
    swap(a[i], a[end]);
    return i;
}

void quicksort(ll a[], int start, int end){
    if(start<end){
        int pivot = partition(a, start, end);
        quicksort(a,start, pivot-1);
        quicksort(a, pivot + 1, end);
    }
}

int main(){
    int n;
    cin>>n;
    ll a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    quicksort(a, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
