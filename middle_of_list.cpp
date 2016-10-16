// Ashena Gorgan Mohammadi, 610394128

/* The task is to find the middle of a bidirectional list without using any counters. having
 * iterators of end and begin, we move through the elements. If the iterator starting from
 * beginning moving forward equals the iterator starting from end moving backwards, that point
 * is the middle. If they pass each other without becoming equal, it means that the lenght of
 * the list is even and the list has no middle element.
 */

#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

typedef std::list<int>::iterator iter;

int find_mid(list<int> L){
    iter front = L.begin();
    iter last = L.end();
    last--;
    int dist = distance(front, last);
    while(dist >= 0){
        int dif = distance(front, last);
        if(dif == 0)
            return *front;
        if(dif > dist){
            cout << "The list does not have any middle element" << endl;
            exit(0);
        }
        if(dif < dist)
            dist = dif;
        front++;
        last--;
    }
}

int main(){
    int n;
    cin >> n;
    list<int> L;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        L.push_back(a);
    }
    int mid = find_mid(L);
    cout << mid << endl;
    return 0;
}