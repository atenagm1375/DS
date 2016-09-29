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

int *sum2(int *A, int *B){
    int m = A[0], n = B[0];
    int len = A[1] > B[1] ? A[1] : B[1];
    int *ans = new int[2 * len + 1];
    int i = 1, j = 1, k = 1, counter = 0;
    while(true){
        while(A[i] > B[j] || (i < 2 * m && j >= 2 * n)){
            counter++;
            ans[k++] = A[i++];
            ans[k++] = A[i++];
        }
        while(B[j] > A[i] || (j < 2 * n && i >= 2 * m)){
            counter++;
            ans[k++] = B[j++];
            ans[k++] = B[j++];
        }
        while(i < 2 * m && j < 2 * n && A[i] == B[j]){
            counter++;
            ans[k++] = A[i++];
            ans[k++] = A[i++] + B[++j];
            j++;
        }
        if(i >= 2 * m && j >= 2 * n)
            break;
    }
    int *result = new int[2 * counter + 1];
    result[0] = counter;
    for(int x = 1; x <= 2 * counter; x++)
        result[x] = ans[x];
    return result;
}

int main(){
    int A1[6] = {4, 4, -3, 2, 0, -11};
    int B1[8] = {6, 1, 0, 0, 4, -5, 10, 6};
    int *ans = sum1(A1, B1);
    for(int i = 0; i < 8; i++)
        std::cout << ans[i] << " ";
    std::cout << std::endl;
    ans = multiply1(A1, B1);
    for(int i = 0; i < 12; i++)
        std::cout << ans[i] << " ";
    std::cout << std::endl;

    int A2[11] = {5, 10, -5, 8, -1, 7, 3, 4, 2, 0, 4};
    int B2[13] = {6, 5, -1, 4, 3, 3, 2, 2, 3, 1, 2, 0, -2};
    ans = sum2(A2, B2);
    for(int i = 0; i <= 2 * ans[0]; i++)
        std::cout << ans[i] << " ";
    return 0;
}