/*
 * Author: Sword Lord of the Lonely Peak
 * Date: 2020/05/18
 * Program: Review for Binary Trees!
 */
 
 /****************************************************************************************************************************************
 Binary Trees: 
 => Each node can have at most 2 children. 
 => A node can have both a left-child and right-child or either one right-child or left-child. 
 => If a node only has a right-child, in a c program, the reference or pointer to the left-child will be set to NULL. 
 => A binary tree is called a strict/proper binary tree if each node can have either 2 or 0 children. 
 => A binary tree can be called a complete binary tree only if all levels except possibly the last are completely filled and all nodes are as far left as possible.  
 => Example:
 
    //This is not a strict binary tree!
    
         A
       /   \
      B     C          //B is the left-child of "root" A. C is the right-child of "root" A. 
     / \   / \
    D  E  F   G
      / \      \ 
     H   I      K
   
   //This is a strict binary tree, but not a complete binary tree!

         A             //L-0 => Max number of nodes in this level is 2^0 = 1
       /   \
      B     C          //L-1 => Max number of nodes in this level is 2^1 = 2
     / \   / \
    D  E  F   G        //L-2 => Max number of nodes in this level is 2^2 = 4
      / \       
     H   I             //L-3 => Max number of nodes in this level is 2^3 = 8
     
  +++Based on these levels, the maximum number of nodes that we can have at level i is equal to 2^(i). 
  +++For a complete binary tree all the levels must be completely filled, with the exception of the last level. 
     Moreover, the nodes at the last level must be at left as possible
     Thus to make the above tree, a complete binary tree, we must do the following: 
     
         A             //L-0 => Max number of nodes in this level is 2^0 = 1
       /   \
      B     C          //L-1 => Max number of nodes in this level is 2^1 = 2
     / \   / \
    D  E  F   G        //L-2 => Max number of nodes in this level is 2^2 = 4
   / \       
  H   I                //L-3 => Max number of nodes in this level is 2^3 = 8
  
  +++Now it is a COMPLETE BINARY TREE! Because the last level has its nodes as far left as possible!
  
           A             //L-0 => Max number of nodes in this level is 2^0 = 1
       /      \
      B        C          //L-1 => Max number of nodes in this level is 2^1 = 2
    /  \      / \
   D    E    F   G        //L-2 => Max number of nodes in this level is 2^2 = 4
  /\   /\   /\   /\
 H  I J  K L  M N  O      //L-3 => Max number of nodes in this level is 2^3 = 8
 
 +++Now if all levels of the binary tree are completelely filled, then it is called a PERFECT BINARY TREE (such as seen above)!
 +++The maximum number of nodes in a binary tree with a height h is equal to 2^0 + 2^1 + .... + 2^h.
    This can also be written as 2^(h+1) - 1 or 2^(number of levels) - 1.
    To find height of a binary tree with n number of nodes, we do the following: h = log2(n+1) - 1 
    We can also to do the following to find the height of a complete binary tree: floor(log2(n)). 
    HEIGHT OF EMPTY TREE IS -1!
    HEIGHT OF TREE WITH 1 NODE is 0!
+++Balanced Binarry Tree
   We call a binary tree, a balanced binary tree if the differemce between height of left and right subtree for every node is not more than k (mostly 1). 
   The difference between right and left subtree of a node can be calculatted as |h(left) - h(right)|. 
   
         A             
       /  \
      B    C          // The diff of B is 2 (1--1), while the diff of C is 1 (1-0). Thus, this is not a balanced binary tree!
    /     / \
   D     F   G        
  /\         /\
 H  I       N  O      
 
 +++Diff of B is equal absolute value of the height left subtree, which 1. minus the value of the height right subtree, which is -1 (it is empty).
    Thus, |1--1| = 2!
    Diff of C is equal absolute value of the height left subtree, which 1. minus the value of the height right subtree, which is 0 (it has a "leaf" node).
    Thus, |1-0| = 1!

Storing Binary Tree in memory: 
=> We can implement binary trees using:
   1) dynamically created nodes. 
   2) Arrays are used to implement heap binary tree.  
      For a COMPLETE BINARY TREE: 
      =>For node at index i: 
        left-child-index  = 2i+1; 
        right-child-index = 2i+2;
 
 *****************************************************************************************************************************************/
