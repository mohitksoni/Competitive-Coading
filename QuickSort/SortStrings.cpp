// Sort Strings

// Given an array A of N strings, Write a program to sort strings in A by
// comparing the characters in dictionary order from last of every string.
// Note: A can have duplicate strings.


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string &s1, string &s2){
    // string a = s1,b = s2;
    // reverse(a.begin(), a.end());
    // reverse(b.begin(), b.end());
    // return a < b;
    
    // ----****-----OR-----****-----
    string a = "",b = "";
    for(int i = s1.length() - 1; i>=0;i--){
        a += s1[i];
    }
    for(int i = s2.length() - 1; i>=0;i--){
        b += s2[i];
    }
    return a < b;
}

int main(){
    int n;
    cin>>n;
    
    string arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr, arr + n, compare);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
