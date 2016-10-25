// Ashena Gorgan Mohammadi, 610394128

template<class X> bool areIsomorphic(Node<X> *T1, Node<X> *T2){
    if(T1 == 0 && T2 == 0)
        return true;
    if(T1->data != T2->data)
        return false;
    if(T1->left->data != T2->left->data)
        swap(T1->left, T1->right);
    return areIsomorphic(T1->left, T2->left) && areIsomorphic(T1->right, T2->right);
}