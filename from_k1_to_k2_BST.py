#Ashena Gorgan Mohammadi, 61039128

"""print all the values of a BST that are between k1 and k2"""

def print_values(T, k1, k2):
    if(T != 0):
        print_values(T.lchild, k1, k2)
        if(k1 <= T.data <= k2):
            print(T.data)
        if(T.data > k2):
            sys.exit(0)
        print_values(T.rchild, k1, k2)