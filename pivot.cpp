// Ashena Gorgan Mohammadi, 610394128

/* There is an array A with n elements. change the order of elements in A
 * such that all elements less than or equal to a given k appear before the
 * elements bigger than k.
 * */

#include <iostream>

using namespace std;

int n, k; // number of elements and the pivot

void compare_to_pivot(int *A, int left, int right) {
    int l = left - 1;
    int h = right + 1;
    while (l < h) {
        do {
            l++;
        } while (A[l] < k);
        do {
            h--;
        } while (A[h] > k);
        if (l < h) {
            int a = A[l];
            A[l] = A[h];
            A[h] = a;
        }
    }
}

int main() {
    cin >> n;
    int *A = new int[n];
    for(int i = 0; i < n; i++)
        cin >> A[i];
    cin >> k;
    compare_to_pivot(A, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}