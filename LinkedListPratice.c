/*
 * Author: Sword Lord of The Lonely Peak
 * Date: 2020/05/18
 */

/**************************************************************************************************************************************/

#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

struct Node* head;

// Deleting a node at nth position
void deleteNode(int position)
{
    int i = 0; 
    struct Node* temp1 = head; 
    if(position==1)
    {
        head = temp1->next; //head now points to second node. 
        free(temp1); 
        return; 
    }
    for(i = 0; i<(position-2); i++)
    {
        temp1 = temp1->next; 
    }
    //temp1 points to (n-1)th node. 
    struct Node* temp2 = temp1->next; //nth node
    temp1->next = temp2->next; 
    free(temp2);
}

//Reverses the order of the node, such that: 
//15 10 40 45 becomes 45 40 10 15
Node* reverseNode()
{
    struct Node* next; 
    struct Node* prev = NULL; 
    struct Node* current = head; 
    while(current!=NULL)
    {
        next = current->next; 
        current->next = prev; //*(current).next = prev;
        prev = current; 
        current = next; 
    }
    head = prev; 
    return head; 
}

void print() {
    struct Node* temp = head;
    while (temp != NULL){
        printf ("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printReverse() {
    struct Node* temp = head;
    while (temp != NULL){
        printf ("%d <- ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Insert node at nth position in list. 
void insert (int data, int position) 
{
    struct Node* newNode = malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* previousNode = head;
    for (int i = 0; i < position - 2; i++) {
        previousNode = previousNode->next;
    }

    newNode->next = previousNode->next;
    previousNode->next = newNode;
}

//Creates the nodes for the list. 
Node*_getnode(int data)
{
    struct Node* newNode = malloc(sizeof(struct Node*));
    newNode -> data = data;
    newNode -> next = NULL; 
    return newNode;
}

//Finds the length of the nodes (ie. the number of nodes in the list). 
int length()
{
    int num = 0; 
    struct Node* temp = head; 
    while(temp != NULL)
    {
        num++; 
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", num); 
    return num; 
}

int main () {
    int position = 0;
    head = NULL;
    head = _getnode(3);
    head -> next = _getnode(5);
    head -> next -> next = _getnode(6);
    head -> next -> next -> next = _getnode(7);
    head -> next -> next -> next -> next = _getnode(10);
    head -> next -> next -> next -> next -> next = _getnode(15);
    insert(2,4); 
    int count = length(); 
    print();
    printf("Enter a position: ");
    scanf("%d", &position);
    if(position > count || count == 0)
    {
        printf("ERROR! Position not found!\n");
        exit(0);
    }
    else
    {
        deleteNode(position); 
        print();
        head = reverseNode(); 
        printReverse(); 
        count = length(); 
    }
}

/**************************************************************************************************************************************/

 #include <stdio.h> 
 #include <stdlib.h> 
 
 typedef struct myList {
     int info; 
     struct myList *link;
 }Node;
 
 Node *_getnode(); 
 
 int main()
 {
     Node *a = _getnode(); // First node
     Node *b = _getnode(); // Second node
     Node *c = _getnode(); // Third node
     
     a -> link = NULL; 
     b -> link = NULL; 
     c -> link = NULL;
     
     printf("a data = ?");
     scanf("%d", &a->info);
     printf("b data = ?");
     scanf("%d", &b->info);
     printf("c data = ?");
     scanf("%d", &c->info);
     
     a -> link = b; // placing address of node b into link of node a (so that they become linked!).
     b -> link = c; 
     
     while(a != NULL)
     {
         printf("%d -> ", a -> info); 
         a = a -> link; 
     }
     printf("NULL\n"); 
     return 0; 
 }
 
 Node *_getnode() 
 {
     return((Node *)malloc(sizeof(Node)));
 }

/**************************************************************************************************************************************/
 
 #include <stdio.h> 
 #include <stdlib.h> 
 
 typedef struct myList {
     int info; 
     struct myList *link;
 }Node;
 
 Node *_getnode(); 
 
 int main()
 {
     Node *a = _getnode(); 
     Node *t = a; 
  
     a -> link = NULL; //First Node
     a -> link = _getnode(); //Second Node
     a -> link -> link = _getnode(); // Third node
     a -> link -> link -> link= NULL; // Fourth node 
     
     printf("a data = ?");
     scanf("%d", &a -> info);
     printf("b data = ?");
     scanf("%d", &a -> link -> info);
     printf("c data = ?");
     scanf("%d", &a -> link -> link -> info);
     
     //Prints the values of the linked list!
     while(a != NULL)
     {
         printf("%d -> ", a -> info); 
         a = a -> link; 
     }
     printf("NULL\n"); 
     a = t; //Make sure to this before reprinting the linked list to make that a points at the first node and not the last node. 
     while(a != NULL)
     {
         printf("%d -> ", a -> info); 
         a = a -> link; 
     }
     printf("NULL\n"); 
     return 0;
 }
 
 Node *_getnode() 
 {
     return((Node *)malloc(sizeof(Node)));
 }

/**************************************************************************************************************************************/

 #include <stdio.h> 
 #include <stdlib.h> 
 
 typedef struct myList {
     int info; 
     struct myList *link;
 }Node;
 
 Node *_getnode(); 
 
 int main()
 {
     Node *s = _getnode();
     s -> link = NULL;
     Node *t = s; 
     char c;
     int true = 1; 
     while(true) //Creates x many nodes (user decides the amount). 
     {
         printf("Please enter the data for s info : ");
         scanf("%d", &s -> info); 
         printf("To add more node press Y else N : ");
         scanf(" %c", &c); 
         if(c == 'n' || c == 'N')
         {
             s -> link = NULL; 
             break; 
         }
         s -> link = _getnode(); // create next node. 
         s = s -> link; // make s equal to the next node. 
      }
      s = t; 
      //print the values of the linked list. 
      while(s != NULL) 
      {
          printf("%d -> ", s->info);
          s = s->link; 
      }
      printf("NULL\n");
 }
 
 Node *_getnode() 
 {
     return((Node *)malloc(sizeof(Node))); //allocate memory for the node. 
 }

/**************************************************************************************************************************************/
