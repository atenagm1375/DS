#Ashena Gorgan Mohammadi, 610394128

"""convert a binary tree to a threaded binary tree"""

def make_threaded(T):
    inordered = []
    inorder_traverse(T, inordered)
    convert(T, inordered, 0)
    

def inorder_traverse(T, inordered):
    if(T != 0):
        inorder_traverse(T.lchild, inordered)
        inordered += T
        inorder_traverse(T.rchild, inordered)


def convert(T, inordered):
    if(T != 0):
        if(T.lchild != 0):
            convert(T.lchild, inordered, i + 1)
        else:
            T.lchild = inordered[i / 2]
            T.lbit = 0
        i += 1
        if(T.rchild != 0):
            convert(T.rchild, inordered, i + 1)
        else:
            T.rchild = inordered[i / 2 - 1]
            T.rbit = 0