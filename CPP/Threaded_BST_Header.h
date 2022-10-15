#ifndef _Threaded_BST_H_
#define _Threaded_BST_H_
#include <bits/stdc++.h>
#include <queue>
#define max(a, b) (((a) > (b)) ? (a) : (b))  //defining user defined macro preprocessor function
using namespace std;

template<typename B>
struct Node
{
    B data;
    Node<B> *left, *right;
    bool lthread, rthread;
};

template<typename B>
class Threaded_BST
{
    private :
        struct Node<B>* root;
    public :
        Threaded_BST()
        {
            root = NULL;
        }
        Node<B>* Makenode(B x);
        Node<B>* GetRoot();
        void Insert(B x);
        void InsertArray(B *arr, int size);
        bool isPresent(B k);
        Node<B>* Search(B k);
        Node<B>* GetNodeOf(B k);
        Node<B>* findMin(Node<B>* root);
        void Inorder(Node<B>*);
		void Preorder(Node<B>*);
		// void PostorderRec(Node<B>*);
        int Height(Node<B>*);
        void DisplayLeafNodes(Node<B>*);
        void DisplayLevelWise(Node<B>*);
};

template<typename B>
Node<B>* Threaded_BST<B> :: Makenode(B x)  //creates one node with data as parameter passed
{
    Node<B>* newNode = new struct Node<B>();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthread = newNode->rthread = false;
    return newNode;
}

template<typename B>
Node<B>* Threaded_BST<B> :: GetRoot()
{
    return root;
}

template<typename B>
void Threaded_BST<B> :: Insert(B x)
{
    // Searching for a Node with given value
    Node<B> *ptr = root;
    Node<B> *par = NULL; // Parent of key to be inserted
    while(ptr != NULL)
    {
        // If key already exists, return
        if(x == (ptr->data))
        {
            cout<<"\n[ Duplicate Key ! ]";
            return;
        }
        par = ptr; // Update parent pointer
        // Moving on left subtree.
        if(x < ptr->data)
        {
            if(ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        // Moving on right subtree.
        else if(x > ptr->data)
        {
            if(ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
        // else
        // {
        //     root->data = x;
        //     root->left = NULL;
        //     root->right = NULL;
        //     root->lthread = false;
        //     root->rthread = false;
        //     return;
        // }
    }
    // Create a new node
    Node<B> *tmp = new Node<B>;
    tmp->data = x;
    tmp->lthread = true;
    tmp->rthread = true;
    if(par == NULL)
    {
        root = tmp;
        tmp->left = NULL;
        tmp->right = NULL;
    }
    else if(x < (par->data))
    {
        tmp->left = par->left;
        tmp->right = par;
        par->lthread = false;
        par->left = tmp;
    }
    else
    {
        tmp->left = par;
        tmp->right = par->right;
        par->rthread = false;
        par->right = tmp;
    }
    return;
}

template<typename B>
void Threaded_BST<B> :: InsertArray(B *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        Threaded_BST<B> :: Insert(*(arr + i));
    }
}

template<typename B>
bool Threaded_BST<B> :: isPresent(B k)
{
    if(root == NULL)
    {
        cout<<"\n[ Empty Tree ]";
        return false;
    }
    else
    {
        if(Threaded_BST :: GetNodeOf(k) != NULL)
        {
            cout<<"\n[ "<<k<<" is present in the tree ]";
            return true;
        }
        else
        {
            // cout<<"\n[ Element "<<k<<" not present in the tree ]";
            return false;
        }
    }
}

template<typename B>
Node<B>* Threaded_BST<B> :: GetNodeOf(B k)
{
    if(root == NULL)
    {
        root = Makenode(k);
        cout<<"\n[ Tree is empty, creating root node ]";
        return root;
    }
    else
    {
        Node<B>* p = root;
        while(p)
        {
            if(k == p->data)
            {
                return p;
            }
            else if(k < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        cout<<"\n[ Element "<<k<<" is not present in the tree returning NULL ]";
        return NULL;
    }
}

template<typename B>
Node<B>* Threaded_BST<B> :: findMin(Node<B>* root)
{
    Node<B>* c = root;
	while(c && c->left != NULL){c = c->left;}
	return c;
}

template<typename B>
void Threaded_BST<B> :: Inorder(struct Node<B>* root)
{
    if(root == NULL)
        cout<<"\n[ Tree is empty ]";
    // Reach leftmost node
    struct Node<B> *ptr = root;
    while(ptr->lthread == false)
        ptr = ptr -> left;
    // One by one print successors
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        if(ptr->rthread == true)
        {
            ptr = ptr->right;
        }
        else
        {
            // Else return leftmost child of right subtree
            ptr = ptr->right;
            while(ptr->lthread == false)
                ptr = ptr->left;
        }
    }
}

template<typename B>
void Threaded_BST<B> :: Preorder(struct Node<B>* root)
{
    cout<<root->data<<" ";
    if(!root->lthread)
        Threaded_BST :: Preorder(root->left);
    if(!root->rthread)
        Threaded_BST :: Preorder(root->right);
}

template<typename B>
int Threaded_BST<B> :: Height(Node<B>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(Height(root->left), Height(root->right));
    }
}

template<typename B>
void Threaded_BST<B> :: DisplayLeafNodes(Node<B>* root)
{
    if(!root)
    {
        cout<<"\n[ Tree is Empty ]";
        return;
    }
    if(root->rthread && root->lthread)
    {
        cout<<root->data<<" ";
        return;
    }
    if(root->left)
       DisplayLeafNodes(root->left);
    if(root->right)
       DisplayLeafNodes(root->right);
}

template<typename B>
void Threaded_BST<B> :: DisplayLevelWise(Node<B>* root)
{
    queue<Node<B>*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node<B>* temp = Q.front();
        Q.pop();
        cout<<"\n\t\t\t"<<temp->data<<endl;
        if(temp->left != NULL || temp->lthread != true) {Q.push(temp->left);}
        if(temp->right != NULL || temp->rthread != true) {Q.push(temp->right);}
        if(temp->lthread == true && temp->rthread == true)
        {
            Node<B>* temp = Q.front();
            Q.pop();
            cout<<"\n\t\t\t"<<temp->data<<endl;
            break;
        }
    }
}
#endif