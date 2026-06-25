#include <stdio.h>

//This is to show that localvariable and caller variables are at different locations

void foo(int x) {
    int local = 20;
    printf("\nInside foo()\n");
    printf("Address of parameter x : %p\n", (void*)&x);
    printf("Address of local       : %p\n", (void*)&local);
}

//Shows a new stack frame coming into place
void recursive(int depth) {
    int local = depth;
    printf("Depth %d -> Address: %p\n",
           depth,
           (void*)&local);
    if(depth > 0)
        recursive(depth - 1);
}

int main() {
    int value = 10;
    printf("Inside main()\n");
    printf("Address of value       : %p\n", (void*)&value);
    foo(value);
    printf("\n");
    recursive(5);
    return 0;
}