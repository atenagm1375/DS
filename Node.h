// Ashena Gorgan Mohammadi, 610394128

#ifndef NODE_H
#define NODE_H

template <class T> class SimpleLinkedList;

template <class T> class Node{

    friend class SimpleLinkedList<T>;

    public:

        Node(const T& val){
            data = val;
            link = 0;
        }

        T getData() const{
            return data;
        }
        
        void setData(T val){
        	data = val;
        }

        Node<T> *link;

    private:

        T data;
};

#endif
