#Ashena Gorgan Mohammadi, 610394128

"""Find parent of a given node of a threaded binary tree"""

def find_parent_threaded_BST(T):
    if(t.rbit == 0 and T.lbit == 0 and T.rchild == 0):
        return T.lchild
    if(T.rbit == 0 and T.lbit == 0 and T.lchild == 0):
        return T.rchild
    if(T.rbit == 0 and T.rchild.lchild != T):
        return T.rchild
    if(T.rbit == 0 and T.rchild.lchild == T):
        return T.rchild.lchild
    if(T.lbit == 0 and T.lchild.rchild != T):
        return T.lchild
    if(T.lbit == 0 and T.lchild.rchild == T):
        return T.lchild.rchild
    else:
        Getnode(L)
        Getnode(R)
        L = T.lchild
        R = T.rchild
        while(L.lbit == 1):
            L = T.lchild
        while(R.rchild == 1):
            R = T.rchild
        if(L.lchild == T):
            return R.rchild
        else:
            return L.lchild