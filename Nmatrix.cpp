// Ashena Gorgan Mohammadi, 610394128

#include <iostream>

using namespace std;

class Nmatrix{
    public:

        Nmatrix(int **M, int dim){
            n_matrix = new int[3 * dim - 1];
            n_matrix[0] = dim;
            for(int i = 0; i < dim; i++)
                n_matrix[i + 1] = M[i][0];
            for(int i = 1; i < dim - 1; i++)
                n_matrix[i + dim] = M[i][i];
            for(int i = 0; i < dim; i++)
                n_matrix[i + 2 * dim - 1] = M[i][dim - 1];
        }

        int operator()(int i, int j){
            if(j == 0)
                return n_matrix[i + 1];
            if(i == j)
                return n_matrix[n_matrix[0] + i];
            if(j == n_matrix[0] - 1)
                return n_matrix[2 * n_matrix[0] + i - 1];
            else
                return 0;
        }

        void print(){
            for(int i = 0; i < 3 * n_matrix[0] - 1; i++)
                cout << n_matrix[i] << " ";
            cout << endl;
        }

    private:

        int *n_matrix;
};

int main(){
    int **M = new int *[5];
    for(int i = 0; i < 5; i++)
        M[i] = new int[5];
    for(int i = 0; i < 5; i++){
        M[i][0] = i + 1;
        M[i][4] = i + 6;
    }
    for(int i = 1; i < 4; i++)
        M[i][i] = i + 11;
    Nmatrix matrix(M, 5);
    matrix.print();
    cout << matrix(4, 4) << " " << matrix(2, 1) << endl;
    return 0;
}