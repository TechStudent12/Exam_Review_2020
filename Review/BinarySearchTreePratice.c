/*
 * Author: Sword Lord of the Lonely Peak
 * Date: 2020/05/19
 * Program: Binary Search Tree Implementation!
 */

/***************************************************************************************************************************************
 * Tree Traversal
 * => Tree traversal is defined the process of visiting each node in the tree eactly onece in some order. 
 *    Visit means reading/processing data in each node. 
 * => Two types of traversal techniques: breadth-first and depth-first. 
 *    Breadth-First Approach: 
 *    => In a tree, using breadth-first approach, we would visit all the nodes at the same depth or levels before visiting the nodes at the next level. 
 *    => Example: 
 *
 *            A             //L-0
 *          /   \
 *         B     C          //L-1
 *        / \   / \
 *       D  E  F   G        //L-2
 *         / \      \ 
 *        H   I      K      //L-3
 *    
 *    +++In breadth-first approach, we would visit the nodes in this order (from left to right): F B C D E F G H I K
 *    +++This kind of breadth-first traversal is called level-order traversal.  
 *    Depth-First Approach: 
 *    => 3 most used strategies for this approach are visiting:
 *       - Root, Left, and Right ---------------->This is called Preorder traversal (DLR).
 *       - Left, Root, and Right ---------------->This is called Inorder traversal (LDR).
 *       - Left, Right, and Root ---------------->This is called Postorder traversal (LRD).
 *    => Example (Preorder traversal): 
 *
 *       //Remember this sequence! ROOT LEFT RIGHT
 *       //DLR stands for data, left, right! Thus, we need to travel from left to right in this approach starting from the root!
 *
 *            A             //L-0
 *          /   \
 *         B     C          //L-1
 *        / \   / \
 *       D  E  F   G        //L-2
 *         / \      \ 
 *        H   I      K      //L-3
 *    
 *    +++In depth-first approach (also called preorder traversal (Data Left Right)), we would visit the nodes in this order: A B D E H I C F G K
 *    => Example (Inorder traversal): 
 *
 *       //INORDER traversal of BINARY SEARCH TREE will give you a SORTED LIST!
 *       //Remember this sequence! LEFT ROOT RIGHT
 *       //LDR stands for left, data, right! Thus, we need to travel from left to right in this approach starting from the left subtree!
 *
 *            A             //L-0
 *          /   \
 *         B     C          //L-1
 *        / \   / \
 *       D  E  F   G        //L-2
 *         / \      \ 
 *        H   I      K      //L-3
 *    
 *    +++In depth-first approach (also called preorder traversal (Data Left Right)), we would visit the nodes in this order: B D E H I A C F G K
 *    => Example (Postorder traversal): 
 *
 *       //Remember this sequence! LEFT RIGHT ROOT
 *       //LRD stands for left, right, data! Thus, we need to travel from left to right in this approach starting from the left subtree!
 *
 *            A             //L-0
 *          /   \
 *         B     C          //L-1
 *        / \   / \
 *       D  E  F   G        //L-2
 *         / \      \ 
 *        H   I      K      //L-3
 *    
 *    +++In depth-first approach (also called preorder traversal (Data Left Right)), we would visit the nodes in this order: B D E H I C F G K A
 ***************************************************************************************************************************************/

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

BstNode* FindMin2(BstNode* root)
{
    while(root->left!=NULL)
    {
        root=root->left; 
    }
    return root; 
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
//Height function that is used here is to find the height of a full binary tree (a binary tree that has all its nodes). 
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

/*Depth_First Approach => PreOrder, InOrder, and PostOrder Traversal*/

//DLR => DATA LEFT RIGHT 
//FOLLOWS SEQUENCE OF ROOT LEFT RIGHT
void preOrder(BstNode* root)
{
    if(root == NULL)
        return;
    else
    {
        printf("%d ", root->data); 
        preOrder(root->left);
        preOrder(root->right); 
    }
}

//LDR => LEFT DATA RIGHT 
//FOLLOWS SEQUENCE OF LEFT ROOT RIGHT
void inorder(BstNode* root)
{
    if(root == NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d ", root->data); 
        inorder(root->right); 
    }
}

//LRD => LEFT RIGHT DATA
//FOLLOWS SEQUENCE OF LEFT RIGHT ROOT
void postOrder(BstNode* root)
{
    if(root == NULL)
        return;
    else
    {
        postOrder(root->left);
        postOrder(root->right); 
        printf("%d ", root->data); 
    }
}

/*Breadth-First Approach => Level Order Traversal*/

//This function finds the height of the tree and its corresponding individual subtrees. 
int heightTree(BstNode* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        /* compute the height of each subtree */
        int lheight = heightTree(node->left); 
        int rheight = heightTree(node->right); 
  
        /* use the larger one */
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
}

//Prints the values of the tree in level order (from left to right). 
void printGivenLevel(BstNode* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 

//This function changes the levels (goes through the levels) of the tree. 
void levelOrder(BstNode* root) 
{ 
    int h = heightTree(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
}

//Check if a given binary tree is BST. Does not really apply here, because all of the trees are binary search trees!
bool isSubTreeLesser(BstNode* root, int value)
{
  if(root == NULL)
    return true;
  if(root->data <= value && isSubTreeLesser(root->left, value) && isSubTreeLesser(root->right, value))
    return true; 
  else
    return false; 
}

bool isSubTreeGreater(BstNode* root, int value)
{
  if(root == NULL)
    return true;
  if(root->data > value && isSubTreeGreater(root->left, value) && isSubTreeGreater(root->right, value))
    return true; 
  else
    return false; 
}

bool isBinarySearchTree(BstNode* root)
{
  if(root == NULL)
    return true; 
  if(isSubTreeLesser(root->left, root->data) && isSubTreeGreater(root->right, root->data) && isBinarySearchTree(root->left) && isBinarySearchTree(root->right))
    return true; 
  else
    return false; 
}

//Delete a node from the binary search tree!
BstNode* deleteNode(BstNode* root, int data)
{
  if(root == NULL)
    return root; 
  else if(data < root->data)
    root->left = deleteNode(root->left, data); 
  else if(data > root->data)
    root->right = deleteNode(root->right, data); 
  else
  {
    //CASE 1: No child!
    if(root->left == NULL && root->right == NULL)
    {
      free(root);
      root = NULL; 
    }
    //CASE 2: One child
    else if(root->left == NULL)
    {
      struct BstNode* temp = root;
      root = root->right; 
      free(temp);
    }
    else if(root->right == NULL)
    {
      struct BstNode* temp = root;
      root = root->left; 
      free(temp);
    }
    //CASE 3: 2 children
    else
    {
      struct BstNode* temp = FindMin2(root->right); 
      root->data = temp->data; 
      root->right = deleteNode(root->right,temp->data); 
    }
  }
  return root; 
}

int main() 
{
   struct BstNode* root; //To store address of root node. 
   root = NULL; // setting tree as empty
   root = insert(root, 5); 
   root = insert(root, 3);
   root = insert(root, 9); 
   root = insert(root, 1); 
   root = insert(root, 7); 
   root = insert(root, 15);
   root = insert(root, 6);
   root = insert(root, 12);
   root = insert(root, 19);
   int max = FindMax(root); 
   int min = FindMin(root); 
   int height = findHeight(root); 
   int depth = minimumDepth(root);
   if(isBinarySearchTree(root))
     printf("This tree is a binary search tree!\n");
   else
     printf("This tree is not a binary search tree!\n");
   printf("The height of the tree is: %d\n", height); 
   printf("The minimum depth of the tree is: %d\n", depth); 
   printf("The maximum value in the tree is %d!\nThe minimum value of the tree is %d!\n", max, min);
   printf("**Breadth approach**\n\tLevel Order traversal: ");
   levelOrder(root); 
   printf("\n**Depth Approach**\n\tPreorder traversal (DLR - DATA LEFT RIGHT): ");
   preOrder(root); 
   printf("\n\tInorder traversal (sorted binary tree)(LDR - LEFT DATA RIGHT): ");
   inorder(root);
   printf("\n\tPost Order traversal (LRD - LEFFT RIGHT DATA): ");
   postOrder(root);
   printf("\n");
   int num = 0, numDelete = 0;
   printf("Enter the number you want to delete from the tree: ");
   scanf("%d", &numDelete); 
   deleteNode(root,numDelete); 
   printf("\t**NEW**Inorder traversal (sorted binary tree)(LDR - LEFT DATA RIGHT): ");
   inorder(root);
   printf("\nEnter a number to search in the tree: ");
   scanf("%d", &num);
   if(search(root, num) == true)
       printf("Number has been found!");
    else
       printf("Number is nor found!"); 
}
