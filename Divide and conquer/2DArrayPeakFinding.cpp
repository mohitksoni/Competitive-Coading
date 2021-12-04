// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom
// Idea Behind solving this problem is to utilize the concept of Divide and conquer
// first we are taking the middle row and finding the maximum element in this row
// Now check if the upper element is greater than this one, if that's true than there will be a peak in the upper half of the array
//     Then repeat the same process in the upper half matrix
// if the lower element to this one is greater than there will be a peak in the lower half of the matrix.
//     Then repeat the same process in the lower half matrix
// if the element is in the first or last row then it will be the peak of the array(it will be maximum element of that row).

#include<iostream>
using namespace std;
typedef long long int llint;

int findMaxIndex(llint *arr, int temp, int r,int c){
    int index = 0;
    for(int i = 0;i<c;i++){
        if(*(arr + temp*c + index) < *(arr + temp*c + i)){
            index = i;
        }
    }
    return index;
}

llint find2DpeakArray(llint *a, int startR, int startC, int r, int c){
    int temp = startR + (r-startR)/2;
    int maxIndexRow = findMaxIndex(a, temp,r,c);
    llint maxInRow = *(a + temp*c + maxIndexRow);
    
    if(temp == 0 || temp == c-1){
        return maxInRow;
    }
    else if(maxInRow > *(a + (temp-1)*c + maxIndexRow) && maxInRow > *(a + (temp+1)*c + maxIndexRow)){
        return maxInRow;
    }
    else if(maxInRow < *(a + (temp-1)*c + maxIndexRow)){
        return find2DpeakArray(a,startR,startC,temp,c);
    }
    else if(maxInRow < *(a + (temp+1)*c + maxIndexRow)){
        return find2DpeakArray(a,temp,startC,r,c);
    }
    return 0;
}


int main(){
    int row,column;
    cin>>row>>column;
    llint array[row][column];
    
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            llint temp;
            cin>>temp;
            array[i][j] = temp;
        }
    }
    cout<<find2DpeakArray(&array[0][0], 0, 0, row, column);
    return 0;
}
