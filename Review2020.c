//Name of File: NOTES FOR APS105 (REVIEW FOR EXAM)
//Author: Sword Lord of the Lonely Peak
//Date: 2020/05/18
/*
 * Structures:
 * What is a structure?
 * => A user defined datatype!
 * => Using strcuture we can defined a datatype that can hold more than one element. 
 * Syntax: 
 *      struct <IDENTITY>
 *      {
 *          datatype element1; 
 *          datatype element2; 
 *      }; 
 * Ex:
 *      struct employee
 *      {
 *          int employeeNumber; 
 *          char employeeName[20];
 *          float employeeSalary; 
 *      };
 * Array vs. Structure:
 * => Arrays only accept homogenous elements (all elements must be of type int, char, double, etc...)
 * => Thus, arrays only accept values of the same datatype!
 *      int arr[5] = {10, 20, 30, 40, 50};
 *      char str[5] = "tour";
 * => Structures can, unlike array, can store various datatype within it!
 *      struct employee //Datatype!
 *      {
 *          int employeeNumber; 
 *          char employeeName[20]; 
 *          float employeeSalary;
 *      };
 *      int main()
 *      {
 *          int a; //primative datatype like int is just one word!
 *          struct employee p1; //user-defined datatype is two word here, struct employee! 
 *                                          //p1 is an internal pointer variable, because it is holding the base address!
 *      }
 * Accessing (members of a structure!):
 *  => e.employeeNumber
 *  => e.employeeName
 *  => e.employeeSalary 
 * How to find the size of a structure: 
 *          struct Employee
 *          {
 *              int employeeName; 
 *              char employeeName[20]; 
 *              float employeeSalary;
 *          }
 *          int main()
 *          {
 *              struct Employee p1; 
 *              printf("Size of employee: %d", sizeof(p1)); // This way works!
 *              printf("Size of employee: %d", sizeof(strcut Employee)); //As well as this way!
 *          }
 * Local / Global structures:
 * => The structure definition that is common for all is called global!
 * => The structure definition that is specific to a particular function is called local!
 * => A structure that is found inside a particular function is called local!
 * => A structure that is found outside all the functions is called a global!
 * Local: 
 * => Definition inside function!
 *      int main()
 *      {
 *         struct LOCAL
 *         {
 *              int a, b; 
 *         }; 
 *         struct LOCAL p1; //This is correct because you are accessing the structure inside the function and not outside of it!
 *      }
 *      int check()
 *      {
 *          struct LOCAL p1; //This INCORRECT! Undefined structure inside check function!
 *                                      //Local strcuture can only be access within the function where it was defined. 
 *      }
 *  Global: 
 *  => Definition outside to all the functions!
 *  => You can access it anywhere in your code without any limitations!
 *      struct GLOBAL
 *      {
 *         int a, b; 
 *      };
 *      int main()
 *      {
 *         struct GLOBAL g;  //This is correct!
 *      }
 *      int check()
 *      {
 *         struct GLOBAL g; //This is correct!
 *      }
 * Example:
 *      struct Employee
 *      {
 *          int employeeNumber;
 *          char employeeName[20];
 *          float employeeSalary; 
 *      }
 *      void main()
 *      {
 *          struct Employee p1 = {1001, "Sword Lord", 80000}; // Must define in the same order as you defined them in the struct. 
 *          printf("Employee details: \n"); 
 *          printf("Employee Number: %d\n", p1.employeeNumber); 
 *          printf("Employee Name: %d\n", p1.employeName); 
 *          printf("Employee Salary: %d\n",  p1. employeeSalary); 
 *      }
 **************************************************************************************************
 * Array of Structure: 
 * Example 1:
 *      struct Employee 
 *      {
 *          int employeeNumber; 
 *          char employeeName[20];
 *          float employeeSalary; 
 *      };
 *      struct Employee e[3]; 
 **************************************************************************************************
 * Arrays in Stuctures
 * Example 1:
 *      struct Students
 *      {
 *          int studentNumber;
 *          char studentName[20]; 
 *          int studentMark[4]; 
 *      };
 *      struct Students s[3]; 
 **************************************************************************************************
 * Unions: 
 * => Unions vs. structures
 *        1) Structure: //All elements get independent memory locations!
 *                            //At one time, we can process all the elements!
 *              struct Identity
 *              {
 *                  datatype element1;
 *                  datatype element 2; 
 *              };
 *           Example:
 *              struct st
 *              {
 *                  char c; 
 *                  short s; 
 *                  float f; 
 *              };
 *              struct st p1; 
 *        2) Union: //All elements share memory location.
 *                       //At one time, we cannot process all the elements!
 *              union Identity
 *              {
 *                  datatype element1;
 *                  datatype element 2; 
 *              };
 *           Example 1: 
 *              union un
 *              {
 *                  char c; 
 *                  short s; 
 *                  float f; 
 *              };
 *              union un p1; 
 *          Example 2: 
 *              union un
 *              {
 *                  short a; 
 *                  short b; 
 *              };
 *              int main()
 *              {
 *                  union un p1; //Size of memory is only 2 bytes because it is a shared (all values are stored in single memory location) memory location (short variable is 2 bytes in size). 
 *                  p1.a = 10;
 *                  printf("b value is %d\n", p1.a); //Stores the value of 10. 
                    p1.b = 20;
                    printf("a value is %d\n", p1.b); //Replaces the values of 10 (because a and b point to same memory location) and prints 20 instead!
 *              }
 **************************************************************************************************
 * Pointers:
 * => What is a pointer?
 *       Pointer is used to access the information of a particular memory location. 
 * => Syntax: 
 *       datatype* identifier; 
 *       Example: 
 *       int* a; // or int *a; 
 * => Type of pointer: 
 *       Typed: 
 *       => Points to a specific type of data.
 *       => For Example: 
 *              => int* can only point to integer data. 
 *              => double* can only point to double data. 
 *              => struct Emp* can only point Emp data. 
 *       => Thus, typed pointer is a pointer that always points to a specific type of data. 
 *       UnTyped: 
 *       => Can point to any type of data. 
 *       => This is also called generic pointer.
 *       => Example: 
 *             => void* can point to any type of data. 
 * =>Operators:
 *      => & and *. 
 *      => & returns the address of a particular variable. 
 *      => * returns the value which is inside a specified address. 
 *      => Example: 
 *          void main()
 *           {
 *               int i = 100; 
 *               int* ptr; 
 *               ptr = &i; 
 *              //When printing address, it is better to use %u (represents only unsigned values).
 *              //Remember that addresses are only in positive values and not negative.
 *              //%d prints both positive and negative values, which is why it is better to use %u, when dealing with printing addresses. 
 *              printf("%d", i); // It will print 100. 
 *              printf("%u", ptr); //It will print 2046, which we will assume is the value of ptr (which is the address of i).
 *              printf("%u", &i); //It will print 2046, which we will assume is the address of i.
 *              printf("%u", &ptr); //It will print 3002, which we will assume is the address of ptr. 
 *              printf("%d", *ptr); //It will print the value stored within ptr, which is 100.
 *              printf("%d", *(&i)); //It will print the value inside the address 2046, which is 100. 
 *           }
 * => Size of pointer: 
 *      Compiler                      int                          pointer
 *       16 bit                       2 bytes                      2 bytes
 *       32 bit                       4 bytes                      4 bytes
 *      Example: 
 *      struct Employee
 *      {
 *          int employeeNumber;
 *          char employeeName[20];
 *          float employeeSalary; 
 *      };
 *      int main()
 *      {
 *          char *cp; 
 *          int *ip; 
 *          struct Emp* p1; 
 *          printf("size of char* is: %d\n", sizeof(cp)); 
 *          printf("size of int* is: %d\n", sizeof(ip)); 
 *          printf("size of struct Emp* is: %d\n", sizeof(p1)); 
 *      }
 *      Ouput is: 
 *          char * : 2
 *          int * : 2 
 *          Emp* : 2 
 *      Thus any of pointer can only occupy 2 bytes or 4 bytes. 
 *      Why do pointer can only occupy 2 bytes or 4 bytes? 
 *      => Because pointer variables always store the same type of data. 
 *      => It is not holding the data of the variables that it points to, but their addresses. 
 *      => Pointer variable always store addresses (the value between 0 to 2^16 (16 being size of compiler)), which is for 16bit compiler, 2 bytes memory.
 *      => Pointer are not storing information, thus pointer size will not vary from one type to another type like primitive, derived, or user-defined datatypes. 
 *      => Pointer size is fixed because it holding the address of the data instead of the data itself. 
 * => Call by value:
 *      #include <stdio.h>
 *      void swap(int a, int b)
 *      {
 *          int temp = a; 
 *          a = b;
 *          b = temp;  
 *          printf("After swap: \t %d \t %d", a, b); 
 *      }
 *      int main()
 *      {
 *          int a = 10, b = 20; 
 *          printf("Before swap: \t %d \t %d", a, b); 
 *          swap(a,b); 
 *          printf("After swap: \t %d \t %d", a, b); 
 *      }
 * => Call by reference:
 *       #include <stdio.h>
 *       void swap(int *a, int *b)
 *       {
 *          int temp = *a; 
 *          *a = *b;
 *          *b = temp;  
 *       }
 *       int main()
 *       {
 *          int a = 10, b = 20; 
 *          printf("Before swap: \t %d \t %d", a, b); 
 *          swap(&a,&b); 
 *          printf("\nAfter swap: \t %d \t %d\n", a, b); 
 *       }
 * => Pointer to function (function pointer): 
 *       Syntax: 
 *          return_type (*Identifier)(args_list); 
 *       Example 1: 
 *          int (*ptr)(int, int);  //can point to any function that is taking 2 integer arguments and that returns integer data. 
 *       Example 2:
 *          int add(int a, int b)
 *          {
 *              int z = a+b; 
 *              return z; 
 *          }
 *          int multiplication(int *, int y, int z)
 *          {
 *              int w = x*y*z;
 *              return w; 
 *          }
 *          int main()
 *          {
 *              int n1, n2, n3; 
 *              int (*ptr)(int, int); // can only point to add function, bacuse the add function has the same return type and number of arguments. 
 *              n1 = add(10,20);
 *              n2 = multiply(2,3,4);
 *              printf("%d, %d", n1, n2); // prints 30 and 24.
 *              ptr = &add; 
 *              n3 = ptr(30,50);
 *              printf("%d", n3); // prints 80.  
 *          }
 *      We need to have () in the declaration of pointer to function, because of the following
 *      => Declaration: 
 *                  int (*ptr)(int, int); //(*ptr) is a pointer pointing to a function that is taking two integer values as its arguments and returning an integer.   
 *            Re-write as: 
 *                  int *ptr (int, int);
 *            System Considers: 
 *                  int* ptr (int, int); // "ptr" is now a function which is pointing to 2 integers and returns adress of integer varaible (*int). 
 * =>Dangling Pointer
 *      1) A Dangling pointer is a pointer that does not point to a valid memory location.
 *      2) Dangling pointers arise when a variable is deleted, without modifying the value of the pointer, so that the pointer still points to the memory location of the deleted memory.
 *      In short, pointer pointing to non-existing memory location is called dangling pointer.
 *      Example program 1:
 *      int *ab()
 *      {
 *          int x = 5; // x is only valid in this function and not anywhere else.
 *          return &x;
 *      }
 *      int main()
 *      {
 *          int *p = ab();
 *          printf("%d", *p);
 *          getch();
 *      }
 * => Causes of Dangling Pointer: 
 *       + Segmentation faults when the memory is no longer accessible.
 *       + Unpredictable behavior if the memory is accessed.
 *       + Potential security risks
 **************************************************************************************************
 * Dynamic Memory Allocation: 
 * => Static memory variables (examples): 
 *       int a; // static memory (fixed size).
 *       int arr[5] // static memory (fixed size).
 *       struct Employee e[5]; // static memory (fixed size).
 * => We need to use stdlib.h (library) in order to perform dynamic memory allocation:
 *       malloc( ) ------> Used to allocate memory to structures or user defined datatypes. 
 *       realloc( ) ------> Used to allocate memory to array. 
 *       calloc( ) -------> Used to increase/decrease the size of an array.
 *       free( ) ---------> Used to "free" or "release" the memory. 
 * => Malloc( ) ----> Used to allocate memory to structures. 
 *       Prototype: void* malloc(size_t size); // size_t is unsigned (positive integer value) and the return type is void*, which is a generic pointer (untyped). 
 *       If memory is allocated successfully, it returns base address of memory block. 
 *       If it fails to allocate the memory, it returns NULL pointer. 
 *       Example:
 *       struct Employee 
 *       {
 *          int employeeNumber; 
 *          char employeeName[20];
 *          float employeeSalary; 
 *       };
 *       int main()
 *       {
 *          struct Employee* ptr;
 *          ptr = (struct Employee*)malloc(sizeof(struct Employee));
 *          if(ptr == NULL)
 *          {
 *              printf("Out of memory ERROR!"); 
 *          }
 *          else 
 *          {
 *              printf("Enter Employee Details\n");
 *              //When a pointer is pointing to a structure, we cannot use the . operator to read the elements into structure. 
 *              // We must the arrow operator. 
 *              //If any ordinary variable is pointing to the structure, we use . operator to read the elements. 
 *              //If a pointer is pointing to the structure, we must use the arrow operator to read the elements. 
 *              scanf("%d %s %f", &ptr->employeeNumber, ptr->employeeName, &ptr->employeeSalary); 
 *              //We don't give address operator to employeeName, because to read any elements into a character array, there is no need to specify the base address. 
 *              //This is also because the variable is holding the address. 
 *               printf("Employee Number \t Employee Name \t Employee Salary\n"); 
 *               printf("%d \t %s \t %f", ptr->employeeNumber, ptr->employeeName, ptr->employeeSalary); 
 *          }
 *       }
 * => Static Memory and Dynamic Memory:
 *       static memory -----> compile time (fixed memory that you will fixed- You cannot decreased or increase the size of the memory).
 *       dynamic memory -> runtime (not fixed memory. Memory size is not constant (vary from time to time) - it can shrink or grow). 
 *       ****Remember that memory allocation always occurs at runtime. 
 * => calloc() 
 *          ---> we can allocate memory to an array.
 *          ---> we cannot increase or decrease the size of an array.
 * => realloc() 
 *          ---> increase or decrease the size of an array. 
 *       Prototype: void* realloc(void* ptr, size_t size); // The void* ptr  is address of the memory block to resize. 
 *                                                                                // The size_t size is the size of the new block of memory. 
 *       Example: 
 *          Stack Creation:
 *              int capacity = 5, *stack; 
 *              stack = (int*)calloc(capacity, sizeof(int)); 
 *              capacity++;
 *              stack = (void*)realloc(stack, capacity*sizeof(int)); 
 * => calloc()
 *      ---> memory allocation to arrays.
 *      Prototype: (void*)calloc(size_t n, size_t size); // size_t n is the size of array.
 *                                                                  // size_t size is the size of each element in the array.
 *      If it is successful in allocating a memory block, it returns address of memory block.
 *      If it fails, it returns NULL pointer.  
 *      Example:
 *      #include <stdio.h>
 *      #include <stdlib.h>
 *      int main()
 *      {
 *          int n, *arr, i; 
 *          printf("Enter size of array:");
 *          scanf("%d", &n); 
 *          arr = (*int)calloc(n, sizeof(int)); //type casting is required which is why there is (*int) in front of calloc(n, sizeof(int)).
 *          if(arr == NULL)
 *              printf("No memory to allocate!"); 
 *          else
 *          {
 *              printf("Array elements are: ");
 *              for(i = 0; i < n; i++)
 *              {
 *                  printf("%d\n", *(arr+i)); //Whenever we increase the value of the pointer by 1, it is pointing to the next location in the array. 
 *              }
 *          }
 *      }
 */
