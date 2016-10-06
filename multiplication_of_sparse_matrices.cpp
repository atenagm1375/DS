// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > make_matrix(vector< vector<int> > A){
    int m = A[0][0], n = A[0][1];
    vector< vector<int> > ans(m, vector<int>(n));
    for(int i = 1; i <= A[0][2]; i++)
        ans[A[i][0]][A[i][1]] = A[i][2];
    return ans;
}

vector< vector<int> > sparseMatrix_mult(int **A, int **B){
    vector< vector<int> > ans;
    vector<int> ans_0;
    ans_0.push_back(A[0][0]);
    ans_0.push_back(B[0][1]);
    ans_0.push_back(0);
    ans.push_back(ans_0);
    int x = 0, y = 0, i = 1;
    while(x < A[0][0]){
        y = 0;
        int k = i;
        while(y < B[0][1]){
            bool t = true;
            int sum = 0;
            for( ; i <= A[0][2] && x == A[i][0]; i++){
                for(int j = 1; j <= B[0][2]; j++)
                    if(B[j][1] == y && A[i][1] == B[j][0]){
                        sum += (A[i][2] * B[j][2]);
                        t = false;
                        break;
                    }
            }
            if(!t){
                vector<int> ans_k;
                ans_k.push_back(x);
                ans_k.push_back(y);
                ans_k.push_back(sum);
                ans.push_back(ans_k);
                ans[0][2]++;
            }
            y++;
            if(y < B[0][1])
                i = k;
        }
        x++;
    }
    return ans;
}

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    int **A = new int *[k + 1];
    for(int i = 0; i <= k; i++)
        A[i] = new int[3];
    A[0][0] = m;
    A[0][1] = n;
    A[0][2] = k;
    for(int i = 1; i <= k; i++)
        for(int j = 0; j < 3; j++)
            cin >> A[i][j];

    cin >> m >> n >> k;
    int **B = new int *[k + 1];
    for(int i = 0; i <= k; i++)
        B[i] = new int[3];
    B[0][0] = m;
    B[0][1] = n;
    B[0][2] = k;
    for(int i = 1; i <= k; i++)
        for(int j = 0; j < 3; j++)
            cin >> B[i][j];

    cout << endl << endl;
    vector< vector<int> > ans = sparseMatrix_mult(A, B);
    if(ans[0][2] <= ans[0][0] * ans[0][1] / 2){
        for(int i = 0; i <= ans[0][2]; i++){
            for(int j = 0; j < 3; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    else{
        vector< vector<int> > mat(A[0][0], vector<int>(A[0][1]));
        mat = make_matrix(ans);
        for(int i = 0; i < ans[0][0]; i++){
            for(int j = 0; j < ans[0][1]; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}