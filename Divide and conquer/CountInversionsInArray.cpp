// Count Inversions in the Array
// Given an array A of integers, write a program to find the number of inversions in A.
// Two elements A[i] and A[j] form a inversion if A[i] > A[j] and i < j.

// Done this problem using the concept of merge sort


#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
ll count = 0;

void combine(ll v[], int start, int mid,int end){
    int i=0,j=0,k=0;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    vector<ll> vLeft,vRight;
    for(int x = 0;x<n1;x++){
        vLeft.push_back(v[start + x]);
    }
    for(int x = 0;x<n2;x++){
        vRight.push_back(v[mid + 1 + x]);
    }
    
    while(i<n1 && j<n2){
        if(vLeft[i] <= vRight[j]){
            v[start + k] = vLeft[i];
            k++;i++;
        }
        else if(vLeft[i] > vRight[j]){
            v[start + k] = vRight[j];
            j++;k++;
            count+=(mid-i+1-start);
        }
    }
    while(i<n1){
        v[start + k] = vLeft[i];
        k++;i++;
    }
    while(j<n2){
        v[start + k] = vRight[j];
        k++;j++;
    }
}

void countInversion(ll v[], int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;
        countInversion(v, start, mid);
        countInversion(v, mid + 1, end);
        combine(v, start, mid, end);
    }
}

int main(){
    int n;
    cin>>n;
    ll v[n];
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    countInversion(v, 0, n-1);
    cout<<count;
    return 0;
}


// Explaination of combine function
// I find the number of inversions in the left part, right part, and the inversions that overlap in the left part and right part while sorting the array.
// As I am sorting the array using merge sort, I get the left subarray and right subarray in sorted order (non-decreasing) into compare function (merge step).
// If the ith element in the left subarray is greater than the jth element in the right subarray, then all the elements of the left subarray in the range [i+1, mid]
// are also greater than this jth element. So, while merging, if left[i] > right[j], I add (mid-i+1-start) to count.
