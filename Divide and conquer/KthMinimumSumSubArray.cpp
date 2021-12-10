// Kth minimum Sum Sub-Array

// Given a sorted(non-decreasing order) array A of positive numbers and an integer K. 
// Write an efficient program to find the Kth minimum sum sub-array.
// Note: minimum sum sub-array is defined in terms of the sum of the elements in the sub-array.

//Takes too much time for large data efficient one is given below
#include <algorithm> 
#include <iostream> 
#include <vector>
using namespace std; 
#define ll long long int
  
vector<ll> v;
 

void combine(ll a[], int start, int mid, int end){
    int n1 = mid + 1 - start;
    int n2 = end - mid;
    
    ll left[n1];
    ll right[n2];
    
    for(int i = 0;i<n1;i++){
        left[i] = a[start + i];
    }
    for(int j = 0;j<n2;j++){
        right[j] = a[mid + 1 + j];
    }
    int i = n1,j = 0;
    ll sum1 = 0,sum2 = 0;
    while(i>0 && j<n2){
        if(left[i - 1] < right[j]){
            sum1+=left[i - 1];
            v.push_back(sum1 + right[j]);
            i--;
        }
        if(i == 0 && j<n2){
            i = n1;
            sum2+= right[j];
            sum1 = sum2;
            j++;
        }
    }
}

void findKthSmallestSum(ll a[], ll start, ll end) 
{ 
    if(start == end){
        v.push_back(a[start]);
    }
    else{
        int mid = (start + end)/2;
        findKthSmallestSum(a, start, mid);
        findKthSmallestSum(a, mid + 1,end);
        combine(a, start, mid, end);
    }
} 
  
int main() 
{ 
    int n,k;
    cin>>n>> k;
    ll a[n];
    
    for(ll i=0;i<n;i++)
    cin>>a[i];
    
    findKthSmallestSum(a,0, n-1);
    auto itr = v.begin();

    sort(v.begin(),v.end());
    cout<<v.at(k - 1);
    return 0; 
}


// More Efficient Solution
#include <algorithm> 
#include <iostream> 
#include <vector>
using namespace std; 
#define ll long long int
  
ll CalculateRank(vector<ll> prefix, ll n, ll x) 
{ 
    ll cnt; 
  
    // Initially rank is 0. 
    ll rank = 0; 
    ll sumBeforeIthindex = 0; 
    for (ll i = 0; i < n; ++i) { 
  
        // Calculating the count the subarray with 
        // starting at ith index 
        cnt = upper_bound(prefix.begin(), prefix.end(),  
                sumBeforeIthindex + x) - prefix.begin(); 
  
        // Subtracting the subarrays before ith index. 
        cnt -= i; 
  
        // Adding the count to rank. 
        rank += cnt; 
        sumBeforeIthindex = prefix[i]; 
    } 
    return rank; 
} 
  
ll findKthSmallestSum(ll a[], ll n, ll k) 
{ 
    // PrefixSum array. 
    vector<ll> prefix; 
  
    // Total Sum initially 0. 
    ll sum = 0; 
    for (ll i = 0; i < n; ++i) { 
        sum += a[i]; 
        prefix.push_back(sum); 
    } 
  
    // Binary search on possible 
    // range i.e [0, total sum] 
    ll ans = 0; 
    ll start = 0, end = sum; 
    while (start <= end) { 
  
        ll mid = (start + end) >> 1; 
  
        // Calculating rank of the mid and  
        // comparing with K 
        if (CalculateRank(prefix, n, mid) >= k) { 
             
            // If greater or equal store the answer 
            ans = mid; 
            end = mid - 1; 
        } 
        else { 
            start = mid + 1; 
        } 
    } 
  
    return ans; 
} 
  
int main() 
{ 
    ll n,k;
    cin>>n>>k;
    ll a[n];
    
    for(ll i=0;i<n;i++)
    cin>>a[i];
    
    cout << findKthSmallestSum(a, n, k); 
    return 0; 
} 
