// Ashena Gorgan Mohammadi, 610394128

/* This program is to count the inversions of an array. Using merge sort,
 * in each step of merge sort, we can count the inversions.
 */

#include <iostream>

using namespace std;

int merge(int *A, int *temp, int l, int m, int h){
    int counter = 0;
    int i = l, j = m + 1, k = l;
    while(i <= m && j <= h){
        if(A[i] <= A[j])
            temp[k++] = A[i++];
        else{
            counter += (m - i + 1);
            temp[k++] = A[j++];
        }
    }
    while(i <= m)
        temp[k++] = A[i++];
    while(j <= h)
        temp[k++] = A[j++];
    for(i = l; i <= h; i++)
        A[i] = temp[i];
    return counter;
}

int inversion_count(int *A, int *temp, int l, int h){
    int counter = 0;
    if(l < h){
        int m = (l + h) / 2;
        counter = inversion_count(A, temp, l, m);
        counter += inversion_count(A, temp, m + 1, h);
        counter += merge(A, temp, l, m, h);
    }
    return counter;
}

int main(){
    int n = 5;
    int A[5] = {5, 4, 3, 2, 1};
    int *temp = new int[n];
    int count = inversion_count(A, temp, 0, n - 1);
    cout << count << endl;
    return 0;
}