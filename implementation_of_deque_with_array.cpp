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

        void insertFront(T& val){
            //cout << "INSERT FRONT:" << endl;
            //cout << head << " " << tail << endl;
            if(head == 0)
                head = max_length - 1;
            else
                head--;
            if(head == tail){
                cout << "Deque is full" << endl;
                return;
            }
            deque[head + 1] = val;
            //cout << head << " " << tail << endl;
        }

        void insertLast(T& val){
            //cout << "INSERT LAST:" << endl;
            //cout << head << " " << tail << endl;
            if(tail == max_length - 1)
                tail = 0;
            else
                tail++;
            //cout << head << " " << tail << endl;
            if(head == tail){
                cout << "Deque is full" << endl;
                return;
            }
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
            if(head == max_length - 1)
                head = 0;
            else
                head++;
            //cout << head << " " << tail << endl;
            return deque[head];
        }

        T removeLast(){
            //cout << "REMOVE LAST:" << endl;
            //cout << head << " " << tail << endl;
            if(empty()){
                cout << "Deque is empty" << endl;
                return 0;
            }
            //cout << head << " " << tail << endl;
            if(tail == 0){
                tail = max_length - 1;
                //cout << head << " " << tail << endl;
                return deque[0];
            }
            else{
                tail--;
                //cout << head << " " << tail << endl;
                return deque[tail + 1];
            }
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
    Deque<int> D(10);
    for(int i = 0; i < 5; i++)
        D.insertFront(i);
    while(!D.empty())
        cout << D.removeFirst() << " ";
    return 0;
}