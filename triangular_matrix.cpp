// Ashena Gorgan Mohammadi, 610394128

/* This is program is to implement a data structure for implementing
 * elements of a triangular matrix. They are stored in the order of up-left to
 * down-right in an array
 */

#include <iostream>

using namespace std;

class TriangularMatrix{
    public:

        TriangularMatrix(int **A, int n){
            dim = n;
            size = dim * (dim + 1) / 2;
            matrix = new int[size];
            isLowerTriangular = true;

            for(int i = 0; isLowerTriangular && i < dim; i++)
                for(int j = i + 1; isLowerTriangular && j < dim; j++)
                    if(A[i][j] != 0)
                        isLowerTriangular = false;
            if(isLowerTriangular){
                int lim = 0;
                for(int k = 0, i = 0; i < dim; i++, lim++)
                    for(int j = 0; j <= lim; j++)
                        matrix[k++] = A[i][j];
            }
            else{
                for(int k = 0, i = 0; i < dim; i++)
                    for(int j = i; j < dim; j++)
                        matrix[k++] = A[i][j];
            }
        }

        void print(){
            if(isLowerTriangular){
                for(int i = 0; i < dim; i++){
                    for(int j = 0; j < dim; j++){
                        j > i ? cout << 0 << " " : cout << matrix[i * (i + 1) / 2 + j] << " ";
                    }
                    cout << endl;
                }
            }
            else{
                for(int i = 0; i < dim; i++){
                    for(int j = 0; j < dim; j++){
                        i > j ? cout << 0 << " " : cout << matrix[i * (i + 1) / 2 + j] << " ";
                    }
                    cout << endl;
                }
            }
        }

    private:

        int *matrix;
        int dim;
        int size;
        bool isLowerTriangular;
};

int main(){
    int n;
    cin >> n;
    int **A = new int *[n];
    for(int i = 0; i < n; i++)
        A[i] = new int[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    TriangularMatrix tm(A, n);
    tm.print();
}