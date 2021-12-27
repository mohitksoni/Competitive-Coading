// Build Complete Binary Tree from Array

// Given a list of numbers in Level-Order sequence, write a program to
// read input into an array and build a Complete Binary Tree.

// Input
// First line contains space separated integers.

// Output
// Print the elements of the Complete Binary Tree separated by a space
// in Pre-Order sequence.

// Constraints
// 1 <= length of list
// 1 <= numbers in list <= 10^9

// Sample Input 1
// 1 2 3 4 5
// Sample Output 1
// 1 2 4 5 3

#include<iostream>
#include<vector>
#include<cstdlib>
#define ll long long int
using namespace std;

typedef struct TreeNode {
    ll data;
    struct TreeNode *left, *right;
}Node;

Node *create_node(ll data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* create_tree(vector<ll> &v, int i){
    if(i < v.size()){
        Node* root = create_node(v[i]);
        root->left = create_tree(v, 2*i + 1);
        root->right = create_tree(v, 2*i + 2);
        return root;
    }
    return NULL;
}
void preOrderTraversal(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
int main(){
    ll temp;
    vector<ll> v;
    while(cin>>temp){
        v.push_back(temp);
    }
    Node * root = create_tree(v, 0);
    preOrderTraversal(root);
}
