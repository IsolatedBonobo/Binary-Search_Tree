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
bool search_target(node* root, int &target){
    if(root == NULL)
        return false;
    
    if(root -> data == target)
        return true;
    else if(root -> data > target)
        search_target(root -> left, target);
    else if(root -> data < target)
        search_target(root -> right, target);



    
}
int main(){
    cout<<"enter the data you want to play"<<endl;
    int a ;
    cin>>a;
    cout<<a;
    // node* root = NULL;
    // takeInput(root);
    // int target;
    // cin>>target;
    // levelorder(root);
    // bool a = search_target(root, target);
    // cout<<endl<<a;
}