//Given an array A of integers, write a program to find the maximum sum sub-array.
//Note: Maximum sum sub-array is defined in terms of the sum of the elements in the sub-array.
//The sub-array should be contiguous, i.e., a sub-array created by choosing the second and fourth
//element by skipping the third element is invalid.


#include <iostream>
#include <climits>
using namespace std;

typedef long long ll;

ll find_cross_sum(int array[], int low, int mid, int high)
{
    ll left_sum = LLONG_MIN, sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += array[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    ll right_sum = LLONG_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += array[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return (right_sum + left_sum);
}

ll max_subarray(int array[], int low, int high)
{
    if (high == low)
    {
        return array[low];
    }
    else
    {
        int mid = (low + high) / 2;

        ll left_sum = max_subarray(array, low, mid);
        ll right_sum = max_subarray(array, mid + 1, high);
        ll cross_sum = find_cross_sum(array, low, mid, high);

        if (left_sum >= right_sum && left_sum >= cross_sum)
            return left_sum;
        else if (right_sum >= left_sum && right_sum >= cross_sum)
            return right_sum;
        else
            return cross_sum;
    }
}

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    ll sum = max_subarray(array, 0, n - 1);
    cout << sum;

    return 0;
}


/Second Method

#include<iostream>
#include<vector>
using namespace std;
#define ll long long int


int main(){
    int n;
    cin>>n;
    vector<ll> v1;
    
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        v1.push_back(temp);
    }
    
    ll sum = v1[0],max = v1[0];
    for(int i=1;i<n;i++){
        if(sum + v1[i] >= v1[i]){
            sum += v1[i];
        }
        else{
            sum = v1[i];
        }
        if(max < sum){
            max = sum;
        }
    }
    cout<<max;
}
