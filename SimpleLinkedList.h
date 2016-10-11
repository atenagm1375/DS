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

        void insertFirst(T& val){
            Node<T> *node = getNode(val);
            node->link = head;
            head = node;
            length++;
        }

        void insertLast(T& val){
            if(empty()){
                insertFirst(val);
                return;
            }
            Node<T> *node = head;
            while(node->next != 0)
                node = node->link;
            Node<T> *newNode = getNode(val);
            node->link = newNode;
            length++;
        }

        void insert(T& prev, T& val){
            Node<T> *node = head;
            while(node->getData() != prev)
                node = node->link;
            Node<T> *newNode = getNode(val);
            newNode->link = node->link;
            node->link = newNode;
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

        bool remove(T& val){
            if(empty())
                return false;
            if(length == 1){
                if(head->getData() == val)
                    return removeFirst();
                else
                    return false;
            }
            Node<T> *node = head;
            while(node->link->getData() != val)
                node = node->link;
            Node<T> *aid = node->link;
            node->link = 0;
            delete aid;
            length--;
            return true;
        }

        bool empty(){
            return length == 0;
        }

        int size(){
            return length;
        }

        Node<T> getHead(){
            return head;
        }

        private:

        Node<T> *head;
        int length;

        Node<T> *getNode(T& val){
            return new Node<T>(val);
        }
};

#endif