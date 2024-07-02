#include <stdio.h>
#include <iostream>
using namespace std;

class treeNode
{
    public:
    treeNode* left;
    treeNode* right;
    int val;

    treeNode(int val)
    {
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }

    treeNode(int val, treeNode* leftNode, treeNode* rightNode)
    {
        this -> val = val;
        this -> left = leftNode;
        this -> right = rightNode;
    }
};

void inOrder(treeNode* root)
{
    if (root == NULL)
        return;
    
    inOrder(root -> left);

    cout << root -> val << " ";

    inOrder(root -> right);
}

void preOrder(treeNode* root)
{
    if (root == NULL)
        return;
    
    cout << root -> val << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(treeNode* root)
{
    if (root == NULL)
        return;

    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> val << " ";
}

int main(){

        //    1
        //   /  \
        //   2   3
        //    \  /
       //     4 5        
    treeNode* leftNode1 = new treeNode(4);
    treeNode* leftNode2 = new treeNode(5, NULL, NULL);
    
    treeNode* middle1 = new treeNode(2, NULL, leftNode1);
    treeNode* middle2 = new treeNode(3, leftNode2, NULL);
    
    treeNode* root = new treeNode(1);
    root->left = middle1;
    root->right = middle2;

    cout <<"This is the tree inorder: " <<endl;
    inOrder(root);
    cout << endl;

    cout <<"This is the tree preorder: " <<endl;
    preOrder(root);
    cout << endl;

    cout <<"This is the tree postorder: " <<endl;
    postOrder(root);
    cout << endl;
}