// Book Reading

// Given two friends Ram and Raj, and N number of books which they are going to read. 
// They cannot read the same book at the same time. For each book, you are given the time in minutes it takes to
// read from beginning to end. Write a program to find the minimum total time it takes to read all the books for both of them combined.


#include<iostream>
#include<climits>
using namespace std;
#define ll long long int


int main(){
    int n;
    cin>>n;
    
    ll a[n];
    ll totalTimeTakenByOne = 0;
    ll MaxTimeForOneBook = LLONG_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        totalTimeTakenByOne += a[i];
        if(a[i] > MaxTimeForOneBook){
            MaxTimeForOneBook = a[i];
        }
    }
    if(MaxTimeForOneBook > totalTimeTakenByOne - MaxTimeForOneBook){
        // It means that, when the one person is reading the latgest book the
        // other can read all the remaining books and when secondone is reading
        // the largest book, the firstone will already have finished reading all the books.
        // so intotal 2*MaxTimeForOneBook is the minimum time when both will be done reading
        // all the books in this case.
        cout<< 2*MaxTimeForOneBook;
    }
    else{
        // If the above case is not happening then minimum time to finish reading
        // all the books will be the sum of all the times.
        cout<< totalTimeTakenByOne;
    }
}
