#Ashena Gorgan Mohammdi, 610394128

"""Inserting a node in a threaded BST such that the tree remains threaded"""

def insert(T, X):
    if(T == 0):
        T = X
    if(T.lchild.rchild == T or T.rchild.lchild == T):
        if(X.data < T.data):
            T = T.lchild
        else:
            T = T.rchild
        if(T.data < X.data):
            X.lchild = T.lchild
            X.rchild = T
            T.lchild = X
            T.lbit = 1
            X.lbit = X.rbit = 0
        else:
            X.rchild = T.rchild
            X.lchild = T
            T.rchild = X
            T.lbit = 1
            X.lbit = X.rbit = 0
    else:
        if(X.data < T.data):
            insert(T.lchild, X)
        else:
            insert(T.rchild, X)