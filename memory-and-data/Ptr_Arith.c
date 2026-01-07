//has code related to understanding pointer artihmetic 
// pointer has the following syntax : <variable_type> *<name>, as per the name they point towards a variable
// <name> = &<act_var>|| here & is used to point or get the address of the variable, same can be used on a pointer to show the data it is pointing at. 

#include <stdio.h>

int main() {

    /* Basic pointers */
    int x = 10;
    int *p = &x;

    printf("%d\n", x);          // prints 10
    printf("%d\n", *p);         // dereferences pointer
    printf("%p\n", (void*)p);   // prints address safely

    /* Pointer arithmetic example */
    int a = 10, b = 5;
    int *p1 = &a;
    int *p2 = &b;

    printf("%d\n", a + b);          // normal addition
    printf("%d\n", *p1 + *p2);      // pointer-based addition

    // pre-increment via pointer vs directly
    printf("inc with pointer: %d\n", ++(*p1));
    printf("inc wrt actual var: %d\n", ++a);
    printf("value of a now: %d\n", a);

    /* Pointers and arrays */
    int arr[] = {1,2,3,4,5};
    int *ptr = arr;  // equivalent to &arr[0]

    printf("%d\n", *ptr);  // first element

    // traverse array by moving pointer
    size_t len = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", *(ptr + i));  // safer than ptr++
    }

    return 0;
}
// Demonstrates pointer basics, pointer arithmetic, and arrays with pointers.
