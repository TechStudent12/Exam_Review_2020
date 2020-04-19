/*
 * Author: Sword Lord of the Lonely Peak
 * Date: 2020/05/19
 * Program: Review for Binary Trees!
 */ 

/**************************************************************************************************************************************
 Binary Trees Introduction: 
 => Used to represent hierarchical data
 => Trees in programming start from the root and branch out in the downward direction.  
 => Efficient way to organize and store data that is naturally hierarchial. 
 => Logically, a tree data structure is defined as a collection of entities called nodes linked together to simulate a hierarchy. 
 => Tree is a non-linear data structure (it is a hierarchical structure)!
 => The top node in the tree is called the "root".
 => Each node will contain data (of any type) and may contain links or references to some other nodes that can be called its "children". 
 => Tree is a recursive data structure. 
 => Recursively it is defined as a structure that consists of a distinguished node called a root and some sub-trees. 
    Arrangement is that the root of the tree contains links to the roots of all the sub-trees. 
 => In a tree with N nodes, there will be exactly N-1 edges or links! The root does not contain a link!
 => Example of a TREE!
 
    //"Root", which is A, is the only node without a parent!
    //When walking in tree, we can only go in ONE direction!
    //In this tree, the sub-trees start from A and B. Thus, there are 2 sub-trees in this tree. 
    
    Terms: 
    + Root => Topmost node in the tree!
    + Children
    + Cousins => Nodes that have the same grandparents, but not the same parents. 
    + Parent
    + Sibling => Must Have same parents!
    + Leaf => Nodes that do not have any "children"!
    + Internal => Nodes that have at least one "child"!
    
                 A
              /     \
             B       C          //B and C are "children" of the "root" A. B and C are "siblings". 
           /  \     /  \
          D    E   F    G       //D, E are "siblings" and are "children" of "parent" B, who is a "child" of "root" A. F, G are "siblings" and are "children" of "parent" C, who is a "child" of "root" A.
         /\       /\    
        H  I     L  M           //H and I are "siblings" and are "children" of "parent" D. 
                                //D, E are "siblings" and are "children" of "parent" B, who is a "child" of "root" A. 
                                //L and M are "siblings" and are "children" of "parent" F. 
                                //F, G are "siblings" and are "children" of "parent" C, who is a "child" of "root" A.
                                //H, I, L, M, E and G are called a "leaf" nodes, because they are nodes that do not have a "child".
                                //A, B, C, D and F are called "internal" nodes, because they are nodes that have at least one "child".
     
     Depth of node C is 1.
     Depth of node G is 2. 
     Height of node C is 2.
     Height of node F is 1. 
     Height of "leaf" node M is 0. 
     Height of the "root" node A is 3.
    
     If we can go from A to I...
     =>A, B, and D are all ancestors of I.
     =>I is a descendant of A, B, and D.
     
 => Depth of some node x in a tree can be defined as length of path from the root to node x. 
    Each edge in the path will contribute 1 unit to the length.
    Can also be defined as the number of edges in the path from root to node x. 
 => Height of the node x in a tree can be defined as the number of edges in longest path from x to a leaf node. 
 => Height of the tree is defined as the height of the root node.
 
 Binary Trees:
 => A tree in which each node can have at most 2 children. 
 => Example: 
 
    Each node in the tree has 3 data field that contain the data, the address of the left child and the address of the right child.
 
                 A
              /     \
             B       C          
           /  \     /  \
          D    E   F    G       
                  /    
                 L     
                 
    Node can be defined in C as the following:
    
    struct Node{
      int data;
      Node* left; 
      Node* right; 
    }Node; 
  
 Applications of Trees: 
 => Storing naturally hierarchical data (ie. file system).
 => Organize data for quick search, insertion and deletion (ie. Binary Search Trees). 
 => Trie (tree) is used to store dictionary. 
 => Used in network routing algorithm. 
 **************************************************************************************************************************************/
