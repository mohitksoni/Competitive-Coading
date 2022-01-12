// ------Distribute Books to Students------
// Given an array A of K books sorted in increasing order based on the
// number of pages in each book and an integer L representing the
// number of students. Students are assigned to read the consecutive
// books in A. Write an efficient program to assign books to students
// such that the maximum number of pages a student gets to read is
// minimum.
  
// ------Input------
// First line contains two space separated integers K and L
// Second line contains K space separated integers A[i]

// ------Output------
// Print the maximum number of pages a student gets to read after
// assigning books based on the above context.
  
// ------Explanation------
// If K = 4, L = 2 and A = [12, 34, 67, 90]
// Books can be distributed in the following ways
// (i) [12] and [34, 67, 90]. Now the maximum number of pages
// allocated to a student is 191 (34 + 67 + 90)
// (ii) [12, 34] and [67, 90]. Now the maximum number of pages a
// student gets to read is 157 (67 + 90)
// (iii) [12, 34, 67] and [90]. Now the maximum number of pages a
// student gets to read is 113
// Among the three scenarios, case (iii) has the minimum pages.
// Therefore the output is 113
  
// ------Constraints------
// 1 <= K, L <= 10^5
// 1 <= A[i] <= 10^9
// L <= K

// ------Sample Input------
// 4 2
// 12 34 67 90
// ------Sample Output------
// 113







#include<iostream>
#include<climits>
#define ull unsigned long long int
using namespace std;

bool allocate(int a[], int n, ull pageBound, int students){
    int count = 1;
    ull pages = 0;
    for(int i = 0;i <n;i++){
        if(a[i] > pageBound){
            return false;
        }
        if(pages + a[i] <= pageBound){
            pages += a[i];
        }
        else{
            count++;
            pages = a[i];
        }
    }
    if(count > students){
        return false;
    }
    else{
        return true; // It also includes when "count < students", means that the pageBound is so high that we can
        // distribute them in less than the provided number of students so that allows us to resuse the pageBound.
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    ull sum = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        sum+= a[i];
    }
    
    // Apply Binary Search B/W minimum possible allocation(a[0])[If all pages are equal and students are 
    // equal to the pages] and maximum possible allocation(sum)[if one student]
    
    ull res = LLONG_MAX;
    ull low = a[0];
    ull high = sum;
    while(low <= high){
        ull mid = low + (high - low)/2;
        if(allocate(a, n, mid, k)){
            res = min(res,mid);
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if(res == LLONG_MAX){
        cout<<a[n - 1]; // handles the below given test case
    }
    else{
        cout<<res;
    }
}


// n = 5, k = 5
//[1, 2, 3, 4, 5]
