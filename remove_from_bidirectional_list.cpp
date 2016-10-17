// Ashena Gorgan Mohammadi, 610394128

/* removing elements of a bidirectional list from KMIN to KMAX.
 */

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void remove(DoublyLinkedList<int> &list, int Kmin, int Kmax){
    DNode<int> *temp = list.getHead();
    while(temp->KEY < Kmax){
        DNode<int> *aid = temp->SLINK;
        if(temp->KEY >= Kmin){
            temp->PLINK->SLINK = temp->SLINK;
            temp->SLINK->PLINK = temp->PLINK;
            temp->SLINK = temp->PLINK = 0;
        }
        temp = aid;
    }
}

int main(){
    int Kmin, Kmax;
    cin >> Kmin >> Kmax;
    DoublyLinkedList<int> list;
    ...
    remove(list, Kmin, Kmax);
    return 0;
}