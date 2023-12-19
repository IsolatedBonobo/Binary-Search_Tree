#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left ;
    Node* right;
    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};


void convertIntoSortedDLL(Node* root, Node* &head){
    if(root == NULL)
        return ;
    
    convertIntoSortedDLL(root -> right, head);

    root -> right = head;
    if(head != NULL){
        head -> left = root ;
    }

    head = root ;

    convertIntoSortedDLL(root -> left,  head);
}
Node* createBST(vector<int>inorder, int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/ 2;
    int value = inorder[mid];
    Node* root = new Node(value);
    root -> left = createBST(inorder, start, mid - 1);
    root -> right = createBST(inorder, mid + 1, end);

    return root;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> right;
    }
}
int main(){
    vector<int>inorder = {1,2,3,4,5,6,7,8,9};
    int start = 0;
    int end = inorder.size() - 1;
    Node* root = createBST(inorder, start, end);
    Node* head = NULL;
    convertIntoSortedDLL(root, head);
    printLL(head);
    
}