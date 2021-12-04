// Longest Common Prefix
// Given an array A of strings, write an efficient program to find the longest common prefix present in all strings.


#include<iostream>
#include<string>
using namespace std;

string compare_prefix_of_twos(string left_string,string right_string)
{
    string compare="";
    int n1=left_string.length();
    int n2=right_string.length();
    int i,j,k;
    for(i=0,j=0;i<n1 && j<n2;i++,j++)
    {
        if(left_string[i]==right_string[j])
        compare.push_back(left_string[i]);
        else
        break;
    }
    return compare;
}

string get_prefix(string a[],int low,int high)
{
    if(low == high)
    return a[low];
    
    else
    {
        int mid=(low+high)/2;
        string left_string=get_prefix(a,low,mid);
        string right_string=get_prefix(a,mid+1,high);
        return compare_prefix_of_twos(left_string,right_string);
    }
}
int main()
{
    int n;
    cin>>n;
    string a[n];
    getchar();
    int i,j,k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    string s=get_prefix(a,0,n-1);
    if(s=="")
    cout<<"-1";
    else
    cout<<s;
    
}
