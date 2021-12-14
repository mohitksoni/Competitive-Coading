// Sort String by Frequency

// Given a string S with lowercase alphabets of N length, write an efficient program to sort S by the frequency of its characters.
// Note: If two characters' frequency matches, the character with higher ASCII value must precede the one with lower ASCII value.

// Input

// First line contains a single integer T. T testcases follow.
// The only line of input for a testcase is a string S.

// Output

// For every testcase in T, print sorted S based on the above context in a newline.
// Constraints

// 1 <= T <= 50
// 1 <= N <= 3*10^5
// S does not contain spaces


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct structure{
    string s;
    int count;
}struc;

bool compare(struc &a, struc &b){
    if(a.count != b.count){
        return a.count>b.count;
    }
    return (a.s)[0] > (b.s)[0];
}

void SortAndPrint(string s){
    vector<struc> v;
    string s1 = "";
    int count1 = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] == s[i+1]){
            count1++;
            s1 += s[i];
        }
        else{
            count1++;
            s1 += s[i];
            struc p;
            p.s = s1;
            p.count = count1;
            v.push_back(p);
            s1 = "";
            count1 = 0;
        }
    }
    sort(v.begin(),v.end(),compare);
    auto itr = v.begin();
    while(itr != v.end()){
        cout<<(*itr).s;
        itr++;
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t != 0){
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        SortAndPrint(s);
        t--;
    }
}
