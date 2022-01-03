// Group Shifted Strings

// Given a string, we can "shift" each of its letter to its successive letter,
// for example: "abc" -> "bcd". We can keep shifting which forms the
// sequence: "abc" -> "bcd" -> ... -> "xyz" ->"abc".

// Given N strings, find how many types of shifting sequences are there
// for different lengths of strings.

// Input

// First line contains single integer N, followed by N strings separated
// by space.
// Output

// If l1, l2, l3 ... are lengths of given strings in the increasing order. Print
// the number of different shifting sequences for each length in the
// above order separated by space.

// Explanation

// Given 6 strings "a", "f", "abc", "bcd", "dmp", "abcd". Here, lengths of
// strings in increasing order are 1,3,4.
// For length 1, we have "a", "f", which come under one shifting
// sequence.
// For length 3, we have "abc", "bcd", "dmp" of which "abc" and "bcd"
// are of same shifting sequence, and "dmp" is of different shifting
// sequence. So, 2 different types.
// For length 4, There is only one string "abcd".
// So the output will be "1 2 1".

// Constraints

// 1 <= N <= 10^5
// 1 <= length of each string <= 10^4
// 1<= Number of different length strings <= 10

// Sample Input 1
// 9 a c az ba lm abc bcd xyz aflm
// Sample Output 1
// 1 2 1 1

// Sample Input 2
// 4 abd zac fgi wxz
// Sample Output 2
// 1

#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

string convert(string s){
    char c = s[0];
    string numeric = "0 ";
    for(int i = 1;i < s.length();i++){
        if(s[i] - c >= 0){
            numeric += to_string(s[i] - c);
            numeric += " ";
            c = s[i];
        }
        else{
            numeric += to_string(26 + s[i] - c);
            numeric += " ";
            c = s[i];
        }
    }
    return numeric;
}
int main(){
    int n;
    cin>>n;
    
    vector<string> v;
    for(int i = 0;i<n;i++){
        string sample;
        cin>>sample;
        v.push_back(sample);
    }
    map<string,string> m2;
    map<int,int> m1;
    
    for(int i = 0;i<n;i++){
        if(v[i].length() == 1){
            m1[1] = 1;
        }
        else{
            m2[convert(v[i])] = v[i];
        }
    }
    auto itr = m2.begin();
    while(itr != m2.end()){
        m1[(itr->second).length()]++;
        itr++;
    }
    auto itr1 = m1.begin();
    while(itr1 != m1.end()){
        cout<<(itr1 -> second)<<" ";
        itr1++;
    }
}
