//Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void quickSort(int *arr, int n){
    stack<int> s;
    int pivot = 0, l = 0, r= n;
    s.push(l);
    s.push(r);
    while(!s.empty()){
        bool sw = true;
        r = s.top();
        s.pop();
        l = s.top();
        s.pop();
        pivot = l;
        if(l < r){
        int i = l, j = r;
        while(sw){
            do{ i++; } while(arr[i] < arr[pivot]);
            do{ j--; } while(arr[j] > arr[pivot]);
            if(i < j)
                swap(arr[i], arr[j]);
            else
                sw = false;
        }
        swap(arr[j], arr[pivot]);
        pivot = j;
        if(pivot > l){
            s.push(l);
            s.push(pivot);
        }
        if(pivot + 1 < r){
            s.push(pivot + 1);
            s.push(r);}
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
