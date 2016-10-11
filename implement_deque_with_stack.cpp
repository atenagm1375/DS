// Ashena Gorgan Mohammadi, 610394128

/* implementing deque using two stacks
 */

#include <iostream>
#include <stack>

using namespace std;

template<class T> class Deque{

    public:

        Deque() { }

        void insertFirst(T& val){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(val);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        void insertLast(T& val){
            s1.push(val);
        }

        T removeFirst(){
            if(s1.empty()){
                cout << "Deque is empty" << endl;
                return 0;
            }
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            T t = s2.top();
            s2.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            return t;
        }

        T removeLast(){
            if(s1.empty()){
                cout << "Deque is empty" << endl;
                return 0;
            }
            T t = s1.top();
            s1.pop();
            return t;
        }

        bool empty(){
            return s1.empty();
        }

    private:

        stack<T> s1;
        stack<T> s2;
};

int main(){
    Deque<int> D;
    for(int i = 0; i < 5; i++)
        D.insertFirst(i);
    for(int i = 5; i < 10; i++)
        D.insertLast(i);
    while(!D.empty())
        cout << D.removeLast() << endl;
    return 0;
}