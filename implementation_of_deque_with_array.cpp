// Ashena Gorgan Mohammadi, 610394128

/* Implementing a deque using array
 */

#include <iostream>

using namespace std;

template<class T> class Deque{

    public:
        
        Deque(int l){
            max_length = l;
            deque = new T[max_length];
            head = tail = -1;
        }

        void insertFront(T val){
            //cout << "INSERT FRONT:" << endl;
            //cout << head << " " << tail << endl;
            if(empty()){
                insertLast(val);
                return;
            }
            if(tail == max_length - 1){
                cout << "Deque is full" << endl;
                return;
            }
            else
                tail++;
            for(int i = tail - 1; i > head; i--){
                    deque[i + 1] = deque[i];
            }
            deque[head + 1] = val;
            //cout << head << " " << tail << endl;
        }

        void insertLast(T val){
            //cout << "INSERT LAST:" << endl;
            //cout << head << " " << tail << endl;
            if(tail == max_length - 1){
                cout << "Deque is full" << endl;
                return;
            }
            else
                tail++;
            //cout << head << " " << tail << endl;
            deque[tail] = val;
        }

        T removeFirst(){
            //cout << "REMOVE FIRST:" << endl;
            //cout << head << " " << tail << endl;
            if(empty()){
                cout << "Deque is empty" << endl;
                return 0;
            }
            //cout << head << " " << tail << endl;
            int a = deque[head + 1];
            for(int i = head + 2; i <= tail; i++)
                deque[i - 1] = deque[i];
            tail--;
            //cout << head << " " << tail << endl;
            return a;
        }

        T removeLast(){
            //cout << "REMOVE LAST:" << endl;
            //cout << head << " " << tail << endl;
            if(empty()){
                cout << "Deque is empty" << endl;
                return 0;
            }
            tail--;
            return deque[tail + 1];
        }

        bool empty(){
            //cout << "EMPTY:" << endl;
            //cout << head << " " << tail << endl;
            return head == tail;
        }

    private:

        int max_length;
        T *deque;
        int head, tail;
};

int main(){
    Deque<int> D(5);
    D.insertLast(1);
    D.insertLast(3);
    D.insertLast(5);
    D.insertLast(7);
    D.insertLast(9);
    D.removeFirst();
    D.insertLast(2);
    while(!D.empty())
        cout << D.removeFirst() << " ";
    return 0;
}