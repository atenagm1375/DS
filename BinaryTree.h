// Ashena Gorgan Mohammadi, 610394128

template<class T> struct node{
    T data;
    node<T> *left;
    node<T> *right;
};

template<class T> class BinaryTree{
    
    public:

        BinaryTree(){
            root = 0;
        }

        void insert(T val){
            if(root != 0)
                insert(val, root);
            else{
                root = new node<T>;
                root->data = val;
                root->left = 0;
                root->right = 0;
            }
        }

        node<T> *root;

    private:

        void insert(T val, node<T> *leaf){
            if(val < leaf->data){
                if(leaf->left != 0)
                    insert(val, leaf->left);
                else{
                    leaf->left = new node<T>;
                    leaf->left->data = val;
                    leaf->left->left = 0;
                    leaf->left->right = 0;
                }
            }
            else{
                if(leaf->right != 0)
                    insert(val, leaf->right);
                else{
                    leaf->right = new node<T>;
                    leaf->right->data = val;
                    leaf->right->left = 0;
                    leaf->right->right = 0;
                }
            }
        }
};
