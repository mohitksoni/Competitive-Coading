// Arrange Numbers to Form the Largest Number
// Given an array A of numbers. Arrange A in a way that 
// forms the largest single number when its elements are combined.


#include<iostream>
#include<string>
#include<algorithm>
#define ll long long int
using namespace std;

bool compare(string &s1, string &s2){
    string S1 = s1 + s2;
    string S2 = s2 + s1;
    return S1 > S2;
}
int main(){
    int n;
    cin>>n;
    
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    
    sort(s, s + n, compare);
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
}
