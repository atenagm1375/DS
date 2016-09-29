// Ashena Gorgan Mohammadi, 610394128

#include <iostream>

int *sum1(int *A, int *B){
    int m = A[0], n = B[0];
    int i = m > n ? m : n;
    int *ans = new int[i + 1];
    ans[0] = i;
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

int main(){
    int A[6] = {5, 4, -3, 2, 0, -11};
    int B[8] = {7, 1, 0, 0, 4, -5, 10, 6};
    int *ans = sum1(A, B);
    for(int i = 0; i < 8; i++)
        std::cout << ans[i] << " ";
    return 0;
}