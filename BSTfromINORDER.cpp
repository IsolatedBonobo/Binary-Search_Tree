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
Node* insertToBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(root -> data > data){
        // insert that data on left 
        root -> left = insertToBST(root -> left, data);
        
    }
    else{
        // insert that data on right
        root -> right = insertToBST(root -> right, data);
       
    }
    return root ;
}
void takeInput(Node* &root){
    
    int data;
    cin >> data;

    while(data != -1){
        root = insertToBST(root, data);
        cin >> data;
    }
}
void levelorder(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        // s3
        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp -> data<<" ";
        if(temp -> left )
        q.push(temp -> left);       
        if(temp -> right)
        q.push(temp -> right);
        }
    }
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
bool spotTarget(Node* root, int target, int data){
        if(root == NULL){
            return false;
        }
        int sum = data + root -> data;
        if(sum == target){
            return true;
        }
        bool leftAns = spotTarget(root -> left, target, root -> data);
        bool rightAns = spotTarget(root -> right, target, root -> data);
        return leftAns || rightAns ;
    }

int main(){
    vector<int>inorder = {1,2,3,4,5,6,7,8,9};
    int start = 0;
    int end = inorder.size();
    Node* root = createBST(inorder, start, end);
    
}