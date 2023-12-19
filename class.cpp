#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
node* insertToBST(node* root, int data){
    if(root == NULL){
        root = new node(data);
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
void takeInput(node* &root){
    
    int data;
    cin >> data;

    while(data != -1){
        root = insertToBST(root, data);
        cin >> data;
    }
}
void levelorder(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
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
void return_min(node* root, int &mini){
    if(root == NULL){
        return ;
    }
    if(root -> data < mini )
        mini = root -> data;

    return_min(root -> left, mini);
    return_min(root -> right, mini);
}
int minvalue(node* root){
    if(root == NULL)
        return -1 ;
    
    node* temp = root ;
    while(temp -> left s!= NULL){
        temp = temp -> left ;

    }
    return temp -> data;
}
int maxvalue(node* root){
    if(root == NULL)
        return -1 ;
    
    node* temp = root ;
    while(temp -> right != NULL){
        temp = temp -> right;

    }
    return temp -> data;
}

int main(){
    node* root = NULL;
    takeInput(root);
    // levelorder(root);
    preceed = precessor(root, );
}