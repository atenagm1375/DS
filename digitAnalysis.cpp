//Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int evenPlace(int data){
    int ans = 0;
    for(int i = 6; i >= 1; i--)
        if(i % 2 == 0){
            int a = data;
            int m = 0;
            for(int j = 0; j < 7 - i; j++){
                m = a % 10;
                a /= 10;
            }
            ans += m * (int)pow(10, i / 2 - 1);
        }
    return ans;
}

int oddPlace(int data){
    int ans = 0;
    for(int i = 6; i >= 1; i--)
        if(i % 2 == 1){
            int a = data;
            int m = 0;
            for(int j = 0; j < 7 - i; j++){
                m = a % 10;
                a /= 10;
            }
            ans += m * (int)pow(10, i / 2);
        }
    return ans;
}

int triplePlace(int data){
    int ans = 0;
    for(int i = 6; i >= 1; i--)
        if(i % 3 == 0){
            int a = data;
            int m = 0;
            for(int j = 0; j < 7 - i; j++){
                m = a % 10;
                a /= 10;
            }
            ans += m * (int)pow(10, i / 3 - 1);
        }
    return ans;

}

int main(){
    srand(time(0));
    int *Htable1 = new int[1000];
    int *Htable2 = new int[1000];
    int *Htable3 = new int[100];
    int c1 = 0, c2 = 0, c3 = 0;
    cout << "Random 6-digit numbers:" << endl;
    for(int i = 0; i < 100; i++){
        int data = rand() % 900000 + 100000;
        cout << data << " ";
        int j1 = evenPlace(data);
        while(Htable1[j1] != 0){
            j1++;
            c1++;
        }
        Htable1[j1] = data;
        int j2 = oddPlace(data);
        while(Htable2[j2] != 0){
            j2++;
            c2++;
        }
        Htable2[j2] = data;
        int j3 = triplePlace(data);
        while(Htable3[j3] != 0){
            j3++;
            c3++;
        }
        Htable3[j3] = data;
    }
    cout << endl << endl;
    cout << "Hash table for even-place-based digit analysis:" << endl;
    for(int i = 0; i < 1000; i++)
        cout << Htable1[i] << " ";
    cout << endl << endl;
    cout << "Hash table for odd-place-based digit analysis:" << endl;
    for(int i = 0; i < 1000; i++)
        cout << Htable2[i] << " ";
    cout << endl << endl;
    cout << "Hash table for triple-place-based digit analysis:" << endl;
    for(int i = 0; i < 100; i++)
        cout << Htable3[i] << " ";
    cout << endl << endl;

    if(c3 <= c2 && c3 <= c1)
        cout << "Third one is the best" << endl;
    if(c1 < c2)
        cout << "First one is the best" << endl;
    if(c2 < c1)
        cout << "Second one is the best" << endl;
    return 0;
}
