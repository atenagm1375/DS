// Ashena Gorgan Mohammadi, 610394128

#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

#include "Node.h"

template <class T> class SimpleLinkedList{

    public:

        SimpleLinkedList(){
            head = 0;
            length = 0;
        }

        void insertFirst(T val){
            Node<T> *node = getNode(val);
            node->link = head;
            head = node;
            length++;
        }

        void insertLast(T val){
            if(empty()){
                insertFirst(val);
                return;
            }
            Node<T> *node = head;
            while(node->link != 0)
                node = node->link;
            Node<T> *newNode = getNode(val);
            node->link = newNode;
            length++;
        }

        void insert(Node<T> *prev, Node<T> *val){
            Node<T> *node = head;
            while(node != prev)
                node = node->link;
            val->link = node->link;
            node->link = val;
            length++;
        }

        bool removeFirst(){
            if(empty())
                return false;
            Node<T> *node = head;
            head = head->link;
            delete node;
            length--;
            return true;
        }

        bool removeLast(){
            if(empty())
                return false;
            if(length == 1)
                return removeFirst();
            Node<T> *node = head;
            while(node->link->link != 0)
                node = node->link;
            Node<T> *aid = node->link;
            node->link = 0;
            delete aid;
            length--;
            return true;
        }

        bool remove(Node<T> *n){
            if(empty())
                return false;
            if(length == 1){
                if(head->getData() == n->getData())
                    return removeFirst();
                else
                    return false;
            }
            Node<T> *node = head;
            while(node->link != n)
                node = node->link;
            node->link = n->link;
            delete n;
            length--;
            return true;
        }

        bool empty(){
            return length == 0;
        }

        int size(){
            return length;
        }

        Node<T> *getHead(){
            return head;
        }

        void setHead(Node<T> *h){
            head = h;
        }

        private:

        Node<T> *head;
        int length;

        Node<T> *getNode(T& val){
            return new Node<T>(val);
        }
};

#endif
