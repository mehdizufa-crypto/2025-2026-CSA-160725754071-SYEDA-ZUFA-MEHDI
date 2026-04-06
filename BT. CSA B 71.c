#include<stdio.h>
#include<stdlib.h>
//define structure first
struct node{
int data;
struct node *left;
struct node *right;
};
//function to create new node
struct node* createnode(int value){
struct node* temp = (struct node*)malloc(sizeof(struct node));
temp->data = value;
temp->left = NULL;
temp->right = NULL;
return temp;
}
//function to create binary tree
struct node*createTree(){
int value;
printf("Enter value(-1 for no node):");
scanf("%d", &value);
if(value==-1)
return NULL;
struct node* temp = createnode(value);
printf("Enter left child of %d\n", value);
temp->left = createTree();
printf("Enter right child of %d\n", value);
temp->right = createTree();
return temp;
}
//inorder traversal
void inorder(struct node*root){
if (root==NULL)
return;

inorder(root->left);
printf("%d", root->data);
inorder(root->right);
}
//preorder traversal
void preorder(struct node*root){
if(root==NULL)
return;

printf("%d", root->data);
preorder(root->left);
preorder(root->right);
}
//postorder traversal
void postorder(struct node*root){
if (root == NULL)
return;

postorder(root->left);
postorder(root->right);
printf("%d", root->data);
}

//Main Function
int main(){
struct node*root = NULL;

printf("Create Binary Tree\n");
root = createTree();

printf("\nInorder Traversal:");
inorder(root);

printf("\nPreorder Traversal:");
preorder(root);

printf("\nPostorder Traversal:");
postorder(root);

return 0;
}
