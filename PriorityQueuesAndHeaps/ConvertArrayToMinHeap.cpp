// Convert Array to Min Heap

// Given an array A of N integers, write a program to convert A into min-heap.
// Note: Try solving without using in-built STL functions of heaps.
// Do not sort the array; a sorted array output is not evaluated as the right answer.

#include<algorithm>
#include<iostream>
#include<array>
#define ll long long int
using namespace std;

void min_heakify(ll a[], int i, int length){
    int left = 2*i;
    int right = 2*i + 1;
    
    int smallest;
    if(left <= length && a[left] < a[i]){
        smallest = left;
    }
    else{
        smallest = i;
    }
    if(right <= length && a[right] < a[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(a[smallest], a[i]);
        min_heakify(a, smallest, length);
    }
}

void ConvertMinHeap(ll a[], int n){
    for(int i = n/2;i>=1;i--){
        min_heakify(a, i, n);
    }
}

int main(){
    int n;
    cin>>n;
    
    ll a[n + 1];
    for(int i = 1;i<n + 1;i++){
        cin>>a[i];
    }
    ConvertMinHeap(a,n);
    for(int i = 1;i<n + 1;i++){
        cout<<a[i]<<" ";
    }
}
