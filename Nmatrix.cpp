// Ashena Gorgan Mohammadi, 610394128

/* This program is to represent another data structure for keeping and accessing
 * elements of an N-matrix. Putting them in an array with the order up-left to
 * down-left, up-left to down-right, up-right to down-right.
 */

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
            if(i == j && i != n_matrix[0] - 1)
                return n_matrix[n_matrix[0] + i];
            if(j == n_matrix[0] - 1)
                return n_matrix[2 * n_matrix[0] + i - 1];
            else
                return 0;
        }

        void print(){
        	for(int i = 0; i < n_matrix[0]; i++){
        		for(int j = 0; j < n_matrix[0]; j++){
        			if(j == 0)
        				cout << n_matrix[i + 1] << " ";
        			else if(i == j && i != n_matrix[0] - 1)
        				cout << n_matrix[i + n_matrix[0]] << " ";
        			else if(j == n_matrix[0] - 1)
        				cout << n_matrix[i + 2 * n_matrix[0] - 1] << " ";
        			else
        				cout << 0 << " ";
        		}
        		cout << endl;
        	}
        	cout << "The array is:" << endl;
            for(int i = 0; i < 3 * n_matrix[0] - 1; i++)
                cout << n_matrix[i] << " ";
            cout << endl;
        }

    private:

        int *n_matrix;
};

int main(){
	int n;
	cin >> n;
    int **M = new int *[n];
    for(int i = 0; i < n; i++)
        M[i] = new int[n];
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		cin >> M[i][j];
   	cout << endl;
    Nmatrix matrix(M, n);
    matrix.print();
    return 0;
}
