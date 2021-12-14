// Convert Min Heap to Max Heap

// Given an array A of N integers representing min heap, write a program to convert A into max heap.
// Note: Try solving without using in-built STL functions of heaps. Do not sort the array; a sorted
// array output is not evaluated as the right answer.


#include<algorithm>
#include<iostream>
#include<array>
#define ll long long int
using namespace std;

void max_heakify(ll a[], int i, int length){
    int left = 2*i;
    int right = 2*i + 1;
    
    int largest;
    if(left <= length && a[left] > a[i]){
        largest = left;
    }
    else{
        largest = i;
    }
    if(right <= length && a[right] > a[largest]){
        largest = right;
    }
    if(largest != i){
        swap(a[largest], a[i]);
        max_heakify(a, largest, length);
    }
}

void ConvertMinHeapToMaxHeap(ll a[], int n){
    for(int i = n/2;i>=1;i--){
        max_heakify(a, i, n);
    }
}

int main(){
    int n;
    cin>>n;
    
    ll a[n + 1];
    for(int i = 1;i<n + 1;i++){
        cin>>a[i];
    }
    ConvertMinHeapToMaxHeap(a,n);
    for(int i = 1;i<n + 1;i++){
        cout<<a[i]<<" ";
    }
}
