// Ashena Gorgan Mohammadi, 610394128

/* This program is to implement a queue using a head pointer and a length variable
 */

#include <iostream>

using namespace std;

template<class T> class New_Queue{

    public:
        New_Queue(int l){
            maxLength = l;
            length = 0;
            Q = new int[maxLength];
            head = -1;
        }

        void enqueue(T& val){
            if(length == maxLength)
                cout << "Queue is full" << endl;
            else{
                if(head + length == maxLength)
                    Q[maxLength - (head + length)] = val;
                else
                    Q[head + length + 1] = val;
                length++;
            }
        }

        T dequeue(){
            if(length == 0)
                cout << "Queue is empty" << endl;
            else if(head == maxLength){
                length--;
                head = 0;
            }
            else{
                head++;
                length--;
            }
            return Q[head];
        }

        bool empty(){
            return length == 0;
        }

    private:
        T *Q;
        int length;
        int maxLength;
        int head;
};

int main(){
    New_Queue<int> newQ(10);
    newQ.dequeue();
    for(int i = 0; i < 5; i++)
        newQ.enqueue(i);
    cout << newQ.dequeue() << endl;
    for(int i = 5; i <= 11; i++)
        newQ.enqueue(i);
    while(!newQ.empty())
        cout << newQ.dequeue() << endl;
    return 0;
}