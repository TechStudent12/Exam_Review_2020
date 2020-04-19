/*#include <stdio.h> 
 #include <stdlib.h> 
 
 typedef struct myList {
     int info; 
     struct myList *link;
 }Node;
 
 Node *_getnode(); 
 
 int main()
 {
     Node *a = _getnode(); 
     Node *b = _getnode(); 
     Node *c = _getnode(); 
     
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
 }*/
 
 #include <stdio.h> 
 #include <stdlib.h> 
 
 typedef struct myList {
     int info; 
     struct myList *link;
 }Node;
 
 Node *_getnode(); 
 
 int main()
 {
     /*
     Node *a = _getnode(); 
     Node *t = a; 
     a -> link = NULL; 
     a -> link = _getnode(); 
     a -> link -> link = _getnode(); 
     a -> link -> link -> link= NULL; 
     
     printf("a data = ?");
     scanf("%d", &a ->info);
     printf("b data = ?");
     scanf("%d", &a -> link ->info);
     printf("c data = ?");
     scanf("%d", &a -> link -> link ->info);
     
     while(a != NULL)
     {
         printf("%d -> ", a -> info); 
         a = a -> link; 
     }
     printf("NULL\n"); 
     a = t; 
     while(a != NULL)
     {
         printf("%d -> ", a -> info); 
         a = a -> link; 
     }
     printf("NULL\n"); 
     return 0; */
     Node *s = _getnode();
     s -> link = NULL;
     Node *t = s; 
     char c;
     int true = 1; 
     while(true)
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
         s -> link = _getnode(); 
         s = s -> link; 
      }
      s = t; 
      while(s != NULL)
      {
          printf("%d -> ", s->info);
          s = s->link; 
      }
      printf("NULL\n");
 }
 
 Node *_getnode() 
 {
     return((Node *)malloc(sizeof(Node)));
 }
