/*
 * Author: Sword Lord of the Lonely Peak
 * Date: 2020/05/19
 * Program: Binary Search Tree Implementation!
 */

/* Tree Traversal
 * => Tree traversal is defined the process of visiting each node in the tree eactly onece in some order. 
 *    Visit means reading/processing data in each node. 
 * => Two types of traversal techniques: breadth-first and depth-first. 
 *    Breadth-First Approach: 
 *    => In a tree, using breadth-first approach, we would visit all the nodes at the same depth or levels before visiting the nodes at the next level. 
 *    => Example: 
 *    
 */

/* Recap On Binary Search Trees!
 *   => Binary Search Tree (BST) is a binary tree, in which for each node, 
 *      all the nodes in the left subtree are lesser or equal and all the nodes in right subtree are greater. 
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <math.h>

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

int FindMin(BstNode* root)
{
  if(root == NULL)
     return -1;
  while(root->left != NULL)
  {
     root = root->left; 
  }
  return root->data; 
}

//Height of a tree is defined the number of edges in the longest path from root to a leaf node!
//Height of a tree is the height of the root node. 
//Height of a tree with 1 node is 0. 
//Depth of a node is the number of edges in path from root to that node. 
int findHeight(BstNode* root)
{
    if(root == NULL)
        return -1;
    int lefth = findHeight(root->left);
    int righth = findHeight(root->right);
    if(lefth>righth)
        return lefth + 1; 
    else
        return righth + 1; 
}

int minimumDepth(BstNode* root)
{
  if(root == NULL) 
    return 0;
  if (root->left == NULL && root->right == NULL) 
    return 1;
  if(!root->left) 
    return 1 + minimumDepth(root->right);
  else if (!root->right) 
    return 1 + minimumDepth(root->left);
  return 1 + fmin(minimumDepth(root->right), minimumDepth(root->left));
}

int FindMax(BstNode* root)
{
  if(root == NULL)
    return -1;
  while(root->right != NULL)
  {
     root = root->right; 
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
   root = insert(root, 30); 
   root = insert(root, 8);
   root = insert(root, 12);
   int max = FindMax(root); 
   int min = FindMin(root); 
   int height = findHeight(root); 
   int depth = minimumDepth(root);
   printf("The height of the tree is: %d\n", height); 
   printf("The minimum depth of the tree is: %d\n", depth); 
   printf("The maximum value in the tree is %d!\nThe minimum value of the tree is %d!\n", max, min);
   int num = 0;
   printf("Enter a number to search in the tree: ");
   scanf("%d", &num);
   if(search(root, num) == true)
       printf("Number has been found!");
    else
       printf("Number is nor found!"); 
}
