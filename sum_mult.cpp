// Ashena Gorgan Mohammadi, 610394128

#include <iostream>

int *sum1(int *A, int *B){
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

int main(){
    int A[6] = {4, 4, -3, 2, 0, -11};
    int B[8] = {6, 1, 0, 0, 4, -5, 10, 6};
    int *ans = sum1(A, B);
    for(int i = 0; i < 8; i++)
        std::cout << ans[i] << " ";
    std::cout << std::endl;
    ans = multiply1(A, B);
    for(int i = 0; i < 12; i++)
        std::cout << ans[i] << " ";
    return 0;
}