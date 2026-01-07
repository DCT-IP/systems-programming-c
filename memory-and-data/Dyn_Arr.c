/*This will showcase the usage of malloc, free, oth and 2d array*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    /*malloc is used to allocate memory on heap rather than stack. It at once will allocate single block of contaguous memory on the heap*/
    int a, r, c;
    printf("Enter size: ");scanf("%d",&a);
    int *ptr = (int *)malloc(a * sizeof(int));
    printf("Enter the elements of the array:-\n");
    for(int i = 0;i<a;i++){
        scanf("%d",(ptr+i));
    }
    printf("\nThe array:- ");
    for(int i = 0;i<a;i++){
        printf("%d ",*(ptr+i));
    }
    free(ptr);
    /*Malloc and free ends here.
    apart from Malloc, we have realloc which reallocates memory given but can cause problems while reallocation*/

    /*2d arrays can be declared in to ways
        One way is to declare a 1-d array and stack it accordingly, another being utilizing an array of pointers*/
        
    //1-D array's usage
    printf("\nEnter both Row size and Col size:-\n"); scanf("%d %d", &r, &c);
    int *arr1 = (int *)malloc(r*c*sizeof(int));
    printf("Enter the elements:-\n");
    for(int i = 0; i<r;i++){
        for(int j = 0;j<c;j++){
            scanf("%d", (arr1 + i*c + j));
        }
    }
    printf("The array:-\n");
    for(int i = 0; i<r;i++){
        for(int j = 0;j<c;j++){
            printf("%d ",*(arr1+i+j));
        }
        printf("\n");
    }
    //
    //array of pointers
    int** arr = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
        arr[i] = (int*)malloc(c * sizeof(int));

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    int count = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r; i++)
        free(arr[i]);
    free(arr1);
    free(arr);

}