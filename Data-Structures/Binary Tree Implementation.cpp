#include <iostream>

using namespace std;

template <class T>
class TreeNode
{
    public:
        T *key;
        TreeNode<T> *parent;
        TreeNode<T> *left_child;
        TreeNode<T> *right_child;

        TreeNode()
        {
            key = NULL;
            parent = NULL;
            left_child = NULL;
            right_child = NULL;
        }
};

template <class T>
class BST
{
    TreeNode<T> *root = NULL;

    public:
        /* This function inserts an element in the binary search tree according to the binary search tree property if the
         * element is not present in the tree and return its pointer.
         */
        TreeNode<T>* insert(T *datap)
        {
            TreeNode<T> *x = root;
            TreeNode<T> *y = NULL;
            while(x!=NULL && x->key!=datap) // while x becomes null  or there is an element in the tree with the same key
            {
                y = x;
                if(*datap<*(x->key))    // if the element to be inserted has a key smaller than the present node, check the left child.
                    x = x->left_child;
                else
                    x = x->right_child; // else check the right child.
            }
            if(x!=NULL) // if the element is found in the tree, return the pointer.
            {
                return x;
            }
            else
            {
                if(y==NULL)
                {
                    root = new TreeNode<T>;
                    root->key = datap;
                    root->parent = NULL;
                    return root;
                }
                else
                {
                    if(*datap<*(y->key))
                    {
                        y->left_child = new TreeNode<T>;
                        y->left_child->key = datap;
                        y->left_child->parent = y;
                        return y->left_child;
                    }
                    else
                    {
                        y->right_child = new TreeNode<T>;
                        y->right_child->key = datap;
                        y->right_child->parent = y;
                        return y->right_child;
                    }
                }

            }
        }

        void transplant(TreeNode<T> *x, TreeNode<T> *y)
        {
            if(x->parent==NULL)
                root = y;
            else
            {
                if(x->parent->left_child==x)
                    x->parent->left_child = y;
                else
                    x->parent->right_child = y;
            }

            if(y!=NULL)
                y->parent = x->parent;
        }

        /* This function deletes an element from the tree, if the element with the given key exists. */
        void del(T *datap)
        {
            TreeNode<T> *x = search(datap);

            if(x!=NULL)
            {
                if(x->left_child==NULL)
                {
                    transplant(x, x->right_child);
                }

                else if(x->right_child==NULL)
                {
                    transplant(x, x->left_child);
                }

                else
                {
                    TreeNode<T> *y = min(x->right_child);
                    if(x->right_child!=y)
                    {
                        transplant(y, y->right_child);
                        y->right_child = x->right_child;
                        y->right_child->parent = y;
                    }
                    transplant(x, y);
                    y->left_child = x->left_child;
                    y->left_child->parent = y;
                    delete x;
                }
            }
            else
                cout<<"Element not found, deletion could not be done\n";
        }

        TreeNode<T>* search(T *datap)
        {
            TreeNode<T> *x = root;
            while(x!=NULL && *(x->key)!=*datap)
            {
                if(*datap<*(x->key))
                    x = x->left_child;
                else
                    x = x->right_child;
            }
            return x;
        }

        TreeNode<T>* min(TreeNode<T> *x)
        {
            if(x==NULL)
                return x;

            while(x->left_child!=NULL)
                x = x->left_child;

            return x;
        }

        TreeNode<T>* min()
        {
            TreeNode<T> *x = root;
            if(x==NULL)
                return NULL;
            while(x->left_child!=NULL)
                x = x->left_child;
            return x;
        }

        TreeNode<T>* max(TreeNode<T> *x)
        {
            if(x==NULL)
                return x;

            while(x->right_child!=NULL)
                x = x->right_child;

            return x;
        }

        TreeNode<T>* max()
        {
            TreeNode<T> *x = root;

            if(x==NULL)
                return x;

            while(x->right_child!=NULL)
                x = x->right_child;
            return x;
        }

        TreeNode<T>* inOrderSuccessor(T *datap)
        {
            TreeNode<T> *x = search(datap);
            if(x!=NULL)
            {
                if(x->right_child!=NULL)
                    return min(x->right_child);
                else
                {
                    TreeNode<T> *y = x->parent;
                    while(y!=NULL && y->right_child==x)
                    {
                        x = y;
                        y = y->parent;
                    }
                    return y;
                }
            }
            else
            {
                cout<<"Element not found. NoSuccessor can be found.\n";
                return NULL;
            }
        }

        TreeNode<T>* inOrderPredecessor(T *datap)
        {
            TreeNode<T> *x = search(datap);
            if(x!=NULL)
            {
                if(x->left_child!=NULL)
                    return max(x->right_child);
                else
                {
                    TreeNode<T> *y = x->parent;
                    while(y!=NULL && y->left_child==x)
                    {
                        x = y;
                        y = y->parent;
                    }
                    return y;
                }
            }
            else
            {
                cout<<"Element not found. No Predecessor can be found.\n";
                return NULL;
            }
        }

        int height(TreeNode<T> *x)
        {
            int left, right, h;
            if(x==NULL)
                return -1;
            else
            {
                left = height(x->left_child);
                right = height(x->right_child);
                if(right>left)
                    left = right;
                h = left + 1;
                return h;
            }
        }

        int height()
        {
            int h = height(root);
            return h;
        }

        void inOrder(TreeNode <T> *x)
        {
            if(x->left_child!=NULL)
                inOrder(x->left_child);
            cout<<*(x->key)<<" ";
            if(x->right_child!=NULL)
                inOrder(x->right_child);
        }

        void printInOrder()
        {
            if(root==NULL)
                cout<<"The Binary Search Tree is empty. No elements found.\n";
            else
                inOrder(root);
            cout<<endl;
        }

        void preOrder(TreeNode <T> *x)
        {
            cout<<*(x->key)<<" ! ";
            if(x->left_child!=NULL)
                preOrder(x->left_child);
            if(x->right_child!=NULL)
                preOrder(x->right_child);
        }

        void printPreOrder()
        {
            if(root==NULL)
                cout<<"The Binary Search Tree is empty. No elements found.\n";
            else
                preOrder(root);
            cout<<endl;
        }

        void postOrder(TreeNode <T> *x)
        {
            if(x->left_child!=NULL)
                inOrder(x->left_child);
            if(x->right_child!=NULL)
                inOrder(x->right_child);
            cout<<*(x->key)<<" ! ";
        }

        void printPostOrder()
        {
            if(root==NULL)
                cout<<"The Binary Search Tree is empty. No elements found.\n";
            else
                postOrder(root);
            cout<<endl;
        }

        void delete_nodes(TreeNode<T> *x)
        {
            if(x->left_child!=NULL)
                delete_nodes(x->left_child);
            if(x->right_child!=NULL)
                delete_nodes(x->right_child);
            delete x;
        }

        ~BST()
        {
            if(root!=NULL)
                delete_nodes(root);
        }
};


void menu()
{
    cout<<"\nBST Menu:\n";
    cout<<"1. Insert element.\n";
    cout<<"2.Delete element.\n";
    cout<<"3. Search element.\n";
    cout<<"4. Minimum element.\n";
    cout<<"5. Maximum element.\n";
    cout<<"6. Predecessor element.\n";
    cout<<"7. Sucessor element.\n";
    cout<<"8. Height.\n";
    cout<<"9. Inorder Traversal.\n";
    cout<<"10. Preorder Traversal.\n";
    cout<<"11. Postorder Traversal.\n";
    cout<<"12. Exit.\n";
    cout<<"Enter your choice: ";
}

int main()
{
    BST<int> ob;
    TreeNode<int> *x = NULL;
    int y, choice;

    while(1)
    {
        menu();
        cin>>choice;
        cout<<endl;
        if(choice==1)
        {
            cout<<"Enter the element to be inserted: ";
            cin>>y;
            cout<<endl;
            x = ob.insert(new int(y));
        }
        else if(choice==2)
        {
            cout<<"Enter the element to be deleted: ";
            cin>>y;
            cout<<endl;
            ob.del(new int(y));
        }
        else if(choice==3)
        {
            cout<<"Enter the element to be searched: ";
            cin>>y;
            cout<<endl;
            x = ob.search(new int(y));
            if(x==NULL)
                cout<<"Element not found.\n";
            else
            {
                cout<<"The searched element is: "<<*(x->key)<<"\n";
            }
        }
        else if(choice==4)
        {
            x = ob.min();
            if(x==NULL)
                cout<<"The binary search tree is empty, No minimum element\n";
            else
                cout<<"The minimum element is: "<<*(x->key)<<"\n";
        }
        else if(choice==5)
        {
            x = ob.max();
            if(x==NULL)
                cout<<"The binary search tree is empty, No maximum element\n";
            else
                cout<<"The maximum element is: "<<*(x->key)<<"\n";
        }
        else if(choice==6)
        {
            cout<<"Enter the element whose predecessor is to be found: ";
            cin>>y;
            cout<<endl;
            x = ob.inOrderPredecessor(new int(y));
            if(x==NULL)
                cout<<"No Predecessor element found.\n";
            else
                cout<<"The predecessor element is: "<<*(x->key)<<"\n";
        }
        else if(choice==7)
        {
            cout<<"Enter the element whose sucessor is to be found: ";
            cin>>y;
            cout<<endl;
            x = ob.inOrderSuccessor(new int(y));
            if(x==NULL)
                cout<<"No Sucessor Element.\n";
            else
                cout<<"The sucessor element is: "<<*(x->key)<<"\n";
        }
        else if(choice==8)
        {
            y = ob.height();
            cout<<"The height of the tree is: "<<y<<".\n";
        }
        else if(choice==9)
        {
            cout<<"The inorder traversal is:\n";
            ob.printInOrder();
        }
        else if(choice==10)
        {
            cout<<"The preorder traversal is:\n";
            ob.printPreOrder();
        }
        else if(choice==11)
        {
            cout<<"The postrder traversal is:\n";
            ob.printPostOrder();
        }
        else if(choice==12)
        {
            break;
        }
        else
            cout<<"Wrong choice\n";
    }
    return 0;
}
