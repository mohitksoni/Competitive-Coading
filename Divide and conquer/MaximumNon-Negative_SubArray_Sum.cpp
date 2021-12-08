// Maximum Non-Negative SubArray Sum

// Given an array A of integers, write an efficient program to find the maximum sum sub-array consisting of only non-negative numbers.
// Note: Maximum sum sub-array is defined in terms of the sum of the elements in the sub-array. The sub-array should be contiguous,
// i.e., a sub-array created by choosing the second and fourth element by skipping the third element is invalid.
// A contains at least 1 non-negative number.

//first Method (Divide and Conquer)

#include<iostream>
using namespace std;
#include<climits>
typedef long long int ll;

ll combine(ll a[],int start, int mid, int end){
    ll sum = 0;
    ll n1 = 0;
    ll n2 = 0;
    
    for(int i = mid;i>=start;i--){
        if(a[i] >= 0){
            sum += a[i];
        }
        else{
            break;
        }
        if(sum>n1){
            n1 = sum;
        }
    }
    sum = 0;
    for(int i = mid+1;i<=end;i++){
        if(a[i] >= 0){
            sum += a[i];
        }
        else{
            break;
        }
        if(sum>n2){
            n2 = sum;
        }
    }
    return (n1+n2);
}

ll maxSumSubarray(ll a[], int start, int end)
{
    int mid = (start + end)/2;
    if(start == end && a[end] >= 0){
        return a[start];
    }
    else if(start == end && a[end] < 0){
        return 0;
    }
    else{
        ll left = maxSumSubarray(a,start,mid);
        ll right = maxSumSubarray(a,mid+1,end);
        ll comb = combine(a,start, mid, end);
        
        //cout<<left<<" "<<right<<" "<<comb<<endl;
        if(left>=comb && left>=right)
        return left;
        else if(right>=comb && right>=left)
        return right;
        else
        return comb;
    }
}

int main(){
    
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<maxSumSubarray(a,0,n-1);
    return 0;
}



//first Method (Brute force)

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    long long int max=0;
    long long int maxs=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            max+=a[i];
        }
        if(a[i]<0)
        max=0;
        if(max>maxs)
        maxs=max;
    }
    cout<<maxs;
}
