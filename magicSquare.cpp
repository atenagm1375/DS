// Ashena Gorgan Mohammadi, 610394128

/* The implementation of magic square for odd numbers
 * */

#include <iostream>

using namespace std;

void oddMatrix(int **matrix, int& n) {
    int i = 0;
    int j = n / 2;
    for (int number = 1; number <= n * n; )
    {
        if (i == -1 && j == -1)
        {
            j = 0;
            i += 2;
        }
        else
        {
            if (j == -1)
                j = n - 1;
            if (i == -1)
                i = n - 1;
        }
        if (matrix[i][j] != 0)
        {
            i += 2;
            j++;
            continue;
        }
        else {
            matrix[i][j] = number;
            number++;
        }

        j--;
        i--;
    }
}

int main(){
	int n; // number of rows and columns of the square
	cin >> n;
	int **magic_square = new int *[n];
	for(int i = 0; i < n; i++)
		magic_square[i] = new int[n];
	oddMatrix(magic_square, n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << magic_square[i][j] << " ";
		cout << endl;
	}
}
