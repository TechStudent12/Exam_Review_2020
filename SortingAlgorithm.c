/* Sorting Algorithms
 * => Sorting is arraging the elements in a list or collection in increasing or decreasing order of some property. 
 * => Unsorted: Linear Search (Westart at the first element of the list and keep scaning the whole list until we get the element we are looking for).
 *    Size = n -----> n comparisions
 *    For example, if n is equal 64, then 2^(n) ----> 2^(64)ms
 * => Sorted: Binary Search
 *    Size = n -----> log2(n) comparisions
 *    For example, if n is equal 64, then 2^(n) will be 2^(64) ----> 64ms
 * Classifications:
 *    1) Time complexity
 *    2) Space Complexity or memory usage
 *        - In certain algorithms, the memory is constant or in place. 
 *        - While in other algorithms, the memory usage grows with input size. 
 *    3) Stability
 *    4) Internal sort vs External sort 
 *        - If all the records are in main memory or RAM, then it is called an internal sort. 
 *        - If all the records are on disk or tapes, then it is called an external sort.
 *    5) Recursive or Non-recursive
 *        - Some sorting algorithm like quick sort or merge sort are recursive.
 *        - While others like insertion sort or selection sort are non-recursive. 
 * Selection Sort: 
 * => Finds the minimum element at each step.
 * => The time complexity of this algorithm is O(n^2).
 * => Code:
 *    #include <stdlib.h>
 *    #include <stdio.h> 
 *
 *    void selectionSort(int a[], int n)
 *    {
 *        int i = 0, j = 0; 
 *         for(i = 0; i<(n-1); i++)
 *         {
 *           int iMin= i;
 *           for(j = i+1; j<n; j++)
 *           {
 *             if(a[j] < a[iMin])
 *               iMin = j; 
 *           }
 *           int temp = a[i];
 *           a[i] = a[iMin];
 *           a[iMin] = temp; 
 *         }
 *     }
 *     
 *     int main()
 *     {
 *       int a[] = {2,7,4,1,5,3};
 *       selectionSort(a,6);
 *       for(int i = 0; i < 6; i++)
 *         printf("%d ", a[i]); 
 *     }
 * Bubble Sort:
 * => Scans list from left to right (multiple times).
 * => Compares element at particular position with the adjacent element at the next position.  
 * => If the element at the current position is greater than the element at the next position, then we will swap both elements. 
 * => Code: 
 *    #include <stdio.h> 
 *    #include <stdbool.h>
 *    
 *    #define MAX 10
 *    int list[MAX] = {1,8,4,6,0,3,5,2,7,9};
 *
 *    void display() 
 *    {
 *        int i;
 *        printf("[");
 *        for(i = 0; i < MAX; i++) 
 *            printf("%d ",list[i]);
 *        printf("]\n");
 *    }
 * 
 *    void bubbleSort() 
 *    {
 *        int temp;
 *        int i,j;
 *        bool swapped = false;
 *        for(i = 0; i < MAX-1; i++) { 
 *           swapped = false;
 *           for(j = 0; j < MAX-1-i; j++) {
 *            //check if next number is lesser than current no
 *            //swap the numbers. 
 *            //(Bubble up the highest number)
 *            if(list[j] > list[j+1]) {
 *               temp = list[j];
 *               list[j] = list[j+1];
 *               list[j+1] = temp;
 *               swapped = true;
 *               }
 *           }
 *           //if no number was swapped that means 
 *           //array is sorted now, break the loop. 
 *           if(!swapped) {
 *              break;
 *           }
 *         }
 *       }
 *       
 *   void main() {
 *      printf("Input Array: ");
 *      display();
 *      printf("\n");
 *      bubbleSort();
 *      printf("\nOutput Array: ");
 *      display();
 *    }
 * Insertion Sort:
 * => Code: 
 *    #include<stdio.h>
 *    #include<stdlib.h>
 *    int main()
 *    {
 *       int i,j,n,temp,a[30];
 *       printf("Enter the number of elements:");
 *       scanf("%d",&n);
 *       printf("\nEnter the elements\n");
 *       for(i=0;i<n;i++)
 *       {
 *           scanf("%d",&a[i]);
 *       }
 *       for(i=1;i<=n-1;i++)
 *       {
 *           temp=a[i];
 *           j=i-1;
 *           while((temp<a[j])&&(j>=0))
 *           {
 *               a[j+1]=a[j];    //moves element forward
 *               j=j-1;
 *           }
 *           a[j+1]=temp;    //insert element in proper place
 *        }
 *        printf("\nSorted list is as follows\n");
 *        for(i=0;i<n;i++)
 *        {
 *           printf("%d ",a[i]);
 *        }
 *        return 0;
 *       }
 */
