// Squares of Character Counts

// Given a string S with lower-case alphabets of N length and an integer K.
// Write an efficient program to find the sum of squares of the count of
// every unique character in S after removing any K characters from it.
// Note: You need to remove K characters in such a way that the sum should
// be the minimum. S does not contain spaces.


#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
bool IND(int i,int j)
{
    return i>j;
}

int main()
{
    string s;
    getline(cin,s);
    sort(s.begin(),s.end());
    vector<int> v1;
    v1.push_back(0);
    long long int k;
    cin>>k;

    long long int i,sum=1;
    long long int n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            sum+=1;
        }
        else
        {
            v1.push_back(sum);
            sum=1;
        }
    }
    auto itr=v1.begin()+1;
    make_heap(itr,v1.end());
    priority_queue<int>q(itr,v1.end());
    while(k>0)
    {
        int temp=q.top();
        temp--;
        q.pop();
        q.push(temp);
        k--;
    }
    long long int sum_1=0;
    while(q.empty()!=1)
    {
        sum_1+=pow(q.top(),2);
        q.pop();
    }
    cout<<sum_1;
}
