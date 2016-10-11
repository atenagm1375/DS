// Ashena Gorgan Mohammadi, 610394128

/* This program is to represent algorithms which calculate summation and multiplication
 * of polynomials in two methods of their implementation. "sum1" and "multiply1" calculate
 * the summation and multiplication of polynomials in their first implementation while
 * "sum2" and "multiply2" calculate the result for the second implementation
 */

#include <iostream>
#include <algorithm>

using namespace std;

int *sum1(int *A, int *B){

    /* Traversing the elements of the arrays from last to first, we add up the multipliers
     * and when we reach the begining of one array, the elements of the other one should be
     * copied in array of answer
     */

    int m = A[0] + 1, n = B[0] + 1;
    int i = m > n ? m : n;
    int *ans = new int[i + 1];
    ans[0] = i - 1;
    while(m > 0 || n > 0){
        if(m <= 0){
            ans[i--] = B[n--];
            continue;
        }
        if(n <= 0){
            ans[i--] = A[m--];
            continue;
        }
        ans[i--] = A[m--] + B[n--];
    }
    return ans;
}

int *multiply1(int *A, int *B){

    /* Think of i as a pointer moving on the first array and j as a pointer on
     * on the second array. The index i+j-1 of the answer will contain the multiplication
     * of the two arrays
     */

    int m = A[0] + 1, n = B[0] + 1;
    int *ans = new int[m + n];
    for(int i = 0; i < m + n; i++)
        ans[i] = 0;
    ans[0] = m + n - 2;
    for(int i = m; i >= 1; i--)
        for(int j = n; j >= 1; j--)
            ans[i + j - 1] += (A[i] * B[j]);
    return ans;
}

int *sum2(int *A, int *B){

    /* Traversing the two arrays, two indices will be added up if and only if they
     * are equal. So we continue searching for the ones that are equal and add up their
     * multipliers
     */
     
    int m = A[0], n = B[0];
    int len = 2 * max(m, n) + 1;
    int *ans = new int[len];
    ans[0] = (len - 1) / 2;
    int i = 1, j = 1, k = 1;
    while(true){
        while(A[i] > B[j] || (i < 2 * m && j >= 2 * n)){
            ans[k++] = A[i++];
            ans[k++] = A[i++];
        }
        while(B[j] > A[i] || (j < 2 * n && i >= 2 * m)){
            ans[k++] = B[j++];
            ans[k++] = B[j++];
        }
        while(i < 2 * m && j < 2 * n && A[i] == B[j]){
            ans[k++] = A[i++];
            ans[k++] = A[i++] + B[++j];
            j++;
        }
        if(i >= 2 * m && j >= 2 * n)
            break;
    }
    return ans;
}

int *multiply2(int *A, int *B){

    /* There is no better way than multiplying the two arrays and sorting them
     * in descending order. In each phase of multiplication, the previously calculated
     * powers will be checked for repeated ones.
     */

    int *max = new int[2 * A[0] * B[0]];
    int k = 0;
    for(int i = 1; i < A[0] * 2; i += 2){
        int counter = 0;
        for(int j = 1; j < B[0] * 2; j += 2){
            int l = 0;
            for(; l < k; l += 2)
                if(A[i] + B[j] == max[l]){
                    max[l + 1] += (A[i + 1] * B[j + 1]);
                    break;
                }
            if(l >= k){
                max[k++] = A[i] + B[j];
                max[k++] = A[i + 1] * B[j + 1];       
            }
        }
    }
    int *ans = new int[k + 1];
    for(int i = 0; i < k; i++)
        ans[i + 1] = max[i];
    ans[0] = k / 2;
    for(int i = 1; i < k; i += 2){
        for(int j = i + 2; j < k + 1; j += 2){
            if(ans[i] < ans[j]){
                int a = ans[i];
                int b = ans[i + 1];
                ans[i] = ans[j];
                ans[i + 1] = ans[j + 1];
                ans[j] = a;
                ans[j + 1] = b;
            }
        }
    }
    return ans;
}

int main(){
    int A1[4] = {2, 1, 1, 1};
    int B1[4] = {2, 1, 1, 1};
    int *ans = sum1(A1, B1);
    for(int i = 0; i < ans[0] + 2; i++)
        cout << ans[i] << " ";
    cout << endl;
    ans = multiply1(A1, B1);
    for(int i = 0; i < ans[0] + 2; i++)
        cout << ans[i] << " ";
    cout << endl;

    int A2[7] = {3, 2, 1, 1, 1, 0, 1};
    int B2[7] = {3, 2, 1, 1, 1, 0, 1};
    ans = sum2(A2, B2);
    for(int i = 0; i <= 2 * ans[0]; i++)
        cout << ans[i] << " ";
    cout << endl;
    ans = multiply2(A2, B2);
    for(int i = 0; i <= 2 * ans[0]; i++)
        cout << ans[i] << " ";
    return 0;
}
