/*
 * Author: Sword Lord of the Lonely Peak
 * Date: 2020/05/19
 * Program: Binary Search Tree Implementation!
 */

/* Recap On Binary Search Trees!
 *   => Binary Search Tree (BST) is a binary tree, in which for each node, 
 *      all the nodes in the left subtree are lesser or equal and all the nodes in right subtree are greater. 
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

typedef struct BstNode //Nodes will be created in the heap using malloc function!
{
  int data; 
  struct BstNode* left;
  struct BstNode* right;
}BstNode; 

BstNode*_getnewnode(int data)
{
    struct BstNode* newNode = malloc(sizeof(struct BstNode*));
    newNode->data = data; //Or *(newNode).data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
}

BstNode* insert(BstNode* root, int data)
{
  if(root == NULL) //If there is no root (ie. tree is empty)
        root = _getnewnode(data); 
  else if(data <= root->data) //If the value is less or equal to the root, which is 15. 
        root->left = insert(root->left, data);
  else //If the value is greater than root, which is 15. 
        root->right= insert(root->right, data); 
  return root; 
}

bool search(BstNode* root, int data)
{
    if(root == NULL)
        return false; 
    else if(root->data == data)
        return true; 
    else if(data <= root->data)
        return search(root->left,data);
    else
        return search(root->right, data);         
}

int FindMin(Bst* root)
{
  //if(root == NULL); 
  //{
  //    printf("ERROR! Tree is empty!");
  //    return -1; 
  //}
  while(root->left != NULL)
  {
     root = root->next; 
  }
  return root->data; 
}

int FindMax(Bst* root)
{
  //if(root == NULL); 
  //{
  //    printf("ERROR! Tree is empty!");
  //    return -1; 
  //}
  while(root->right != NULL)
  {
     root = root->next; 
  }
  return root->data; 
}

int main()
{
   struct BstNode* root; //To store address of root node. 
   root = NULL; // setting tree as empty
   root = insert(root, 15); 
   root = insert(root, 10);
   root = insert(root, 20); 
   root = insert(root, 25); 
   root = insert(root, 8);
   root = insert(root, 12); 
   int max = FindMax(root); 
   int min = FindMin(root); 
   printf("The maximum value in the tree is %d!\nThe minimum value of the tree is %d!\n", max, min);
   int num = 0;
   printf("Enter a number to search in the tree: ");
   scanf("%d", &num);
   if(search(root, num) == true)
       printf("Number has been found!");
    else
       printf("Number is nor found!"); 
}
