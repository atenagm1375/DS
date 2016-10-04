// Ashena Gorgan Mohammadi, 610394128

#include <iostream>

using namespace std;

bool isMonge(int **matrix, int m, int n){
    for(int i = 0; i < m - 1; i++)
        for(int j = 0; j < n - 1; j++)
            if(matrix[i][j] + matrix[i + 1][j + 1] > matrix[i][j + 1] + matrix[i + 1][j])
                return false;
    return true;
}

int main(){
    int m, n;
    cin >> m >> n;
    int **A = new int *[m];
    for(int i = 0; i < m; i++)
        A[i] = new int[n];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    bool ans = isMonge(A, m, n);
    ans ? cout << "YES" << endl : cout << "NO" << endl;
}