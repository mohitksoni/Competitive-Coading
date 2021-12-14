// Maximize Profit

// Given an array 'rows[]' of N integers where 'rows[i]' represents the number of empty seats present in the 'ith' row.
// There are M people willing to buy tickets, each seat costs equal to the number of empty seats present in that row.
// Write an efficient program to maximize the profit by selling tickets to M people.

                //___Edge_Case___

                //____INPUT______
                // n = 4, m = 40
                // 1 2 3 4

                //____OUTPUT_____
                // 20
                
#include<iostream>
#include<queue>
#define ll long long int
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    
    priority_queue<ll> q;
    
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        q.push(temp);
    }
    ll sum = 0;
    while(m != 0 && q.empty() != 1){
        ll x = q.top();
        sum += x;
        q.pop();
        x--;
        if(x>0){
            q.push(x);
        }
        m--;
    }
    cout<<sum;
}
