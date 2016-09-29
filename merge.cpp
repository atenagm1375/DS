// Ashena Gorgan Mohammadi, 610394128

#include <iostream>

using namespace std;

int *merge2(int *A, int *B, int m, int n){
    int len = m + n;
    int *ans = new int[len];
    int i = 0, j = 0, k = 0;
    while(i < m && j < n){
        if(A[i] < B[j])
            ans[k++] = A[i++];
        else
            ans[k++] = B[j++];
    }
    while(i < m)
        ans[k++] = A[i++];
    while(j < n)
        ans[k++] = B[j++];
    return ans;
}

int *merge3(int *A, int *B, int *C, int m, int n, int p){
    int len = m + n + p;
    int *ans = new int[len];
    int i = 0, j = 0, k = 0, l = 0;
    while(i < m && j < n && k < p){
        if(A[i] < B[j] && A[i] < C[k])
            ans[l++] = A[i++];
        else if(B[j] < A[i] && B[j] < C[k])
            ans[l++] = B[j++];
        else
            ans[l++] = C[k++];
    }
    while(i < m && j < n){
        if(A[i] < B[j])
            ans[l++] = A[i++];
        else
            ans[l++] = B[j++];
    }
    while(i < m && k < p){
        if(A[i] < C[k])
            ans[l++] = A[i++];
        else
            ans[l++] = C[k++];
    }
    while(j < n && k < p){
        if(B[j] < C[k])
            ans[l++] = B[j++];
        else
            ans[l++] = C[k++];
    }
    while(i < m)
        ans[l++] = A[i++];
    while(j < n)
        ans[l++] = B[j++];
    while(k < p)
        ans[l++] = C[k++];
        return ans;
}

int main(){
    int m = 6, n = 9, p = 7;
    int A[6] = {3, 5, 8, 10, 16, 20};
    int B[9] = {1, 4, 6, 7, 17, 18, 22, 24, 30};
    int C[7] = {2, 9, 11, 15, 19, 23, 25};
    int *ans = merge2(A, B, m, n);
    for(int i = 0; i < m + n; i++)
        cout << ans[i] << " ";
    cout << endl;
    
    ans = merge3(A, B, C, m, n, p);
    for(int i = 0; i < m + n + p; i++)
        cout << ans[i] << " ";
    return 0;
}