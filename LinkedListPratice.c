/*
 * Author: Sword Lord of The Lonely Peak
 * Date: 2020/05/18
 */

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

/*******************************************************************************************************************************/
 
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

/*******************************************************************************************************************************/

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

/*******************************************************************************************************************************/
