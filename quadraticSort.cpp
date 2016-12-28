//Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include <algorithm>

using namespace std;

void quadraticSort(int *arr, int n){
    int index = n - 1;
    while(index > 0){
        int *B = new int[4];
        for(int i = 0, k = 0; i <= index; i += 4, k++){
            int Max = arr[i];
            for(int j = i + 1; j <= index && j < i + 4; j++)
                Max = max(Max, arr[j]);
            B[k] = Max;
        }
        for(int i = 0; i < 4; i++)
            cout << B[i] << " ";
        cout << endl;
        swap(*find(arr, arr + index, *max_element(B, B + 4)), arr[index]);
        cout << *max_element(B, B + 4) << endl;
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        index--;
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    quadraticSort(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
