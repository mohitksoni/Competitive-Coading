// Minimum Lecture Halls

// Given an array A of N lecture time intervals consisting of start time and end time.
// Considering the fact that no two lectures happen simultaneously, Write an efficient
// program to find the minimum number of lecture halls needed that will result in 
// conducting all lectures.
  
// Note: If an interval's end time matches another interval's start time, then the intervals are not considered as overlapping.
// Input

// First line contains a single integer N
// N lines follow, each line contains two space separated integers representing the start time and the end time of an interval respectively
// Output

// Print a single integer based on the above context.
// Constraints

// 1 <= N <= 10^5
// 0 <= start time, end time <= 1000
// start time < end time
// Sample Input 1
//   3
//   0 10
//   8 12
//   13 15
// Sample Output 1
//   2


#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> &a, pair<int,int> &b){
    return a.first < b.first;
}
int main(){
    int n;
    cin>>n;
    
    pair<int,int> a[n];
    priority_queue<int ,vector<int>, greater<int>> q;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    
    sort(a, a+n,compare);
    q.push(a[0].second);
    for(int i = 1;i<n;i++){
        if(a[i].first >= q.top()){
            q.pop();
        }
        q.push(a[i].second);
    }
    cout<<q.size();
}
