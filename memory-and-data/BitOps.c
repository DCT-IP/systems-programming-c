/*
In this I will try to do 
    1.Basic bitwise operations - and, or , xor, left shift, right shift
    2.Bit Manipulation - checking a bit to be 1, setting a bit to 1, clearing a bit(set to 0), toggle a bit, LSB(extract last), check even
    3.Masks - mask to:- 1.extract specific bits,
                        2.to turn on/off specific bits,
                        3.dynamic masks using shifts.
    4.Special Bit Tricks - swapping two numbers,
    5.2's Compliment
    */
//The main focus is on understanding it so the project for this section can be done easily

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 5;//0101
    int b = 3;//0011
    
    //basic bit operators
    
    printf("\nBASIC BIT OPERATORS\n");
    printf("\ton performing AND: %d\n",(a&b)); // 0001
    printf("\ton performing OR: %d\n",(a|b)); // 0111
    printf("\ton performing XOR %d\n",(a^b)); //0110
    printf("\ton performing NOT: %d\n",(~a)); //1010
    printf("\tLeft Shift: %d\n",(a<<1));
    printf("\tRight Shift: %d\n",(a>>1));
    //end
    
    //before bit manipulation 
    
    printf("To show the binary form of the number %d :-",a);
    int temp; //used later --Made final minute changes to use a better logic for printing binaries
    for(int i = 31; i >= 0; i--)
        printf("%d", (a >> i) & 1);
    printf("\n");
    /*this plays out as to checkif our outcomes are correct or not 
    ..1. checking a bit at k'th position*/
    
    int num = 9, k = 3;
    printf("\nto check:-\n");
    if(num&(1<<(k-1)))
        printf("The %dth bit is set",k);
    else
        printf("Not set");
    /*we used num & (1<<k) as on performing left shift of k on 1 it will shift the 1 by k thus on performing an & operation
    ..it should only return the kth bit as the only 1*/

    //2.setting a bit to 1
    printf("\nTo set a bit at kth position:-\n");
    printf("before setting the bit: %d\n",num); //101
    k = 2;//changing k here as 3rd bit is already set
    int ans = (num|(1<<k));
    printf("After setting the bit at %d to 1: %d\n",k,ans);//111
    /*Here using the similar logic to above, we just use OR so we get 1 regardless of the bit being 0 or 1 in the original number*/

    //3.clearing the bit
    printf("\nTo clear the bit:-\n");
    printf("Before clearing: %d\n",ans);//13
    ans &= ~(1<<k);
    printf("After: %d\n",ans);//again 9
    /*same logic as 2 just ~ is used to to get inversion of and & is used to make sure the rest of bits don't change*/

    //4.toggle a bit at kth position
    printf("\nTo toggle the bit at a position:- \n");
    printf("Pre Toggle:- %d\n",num);
    k = 3;
    ans ^= (1 << k);
    printf("After:- %d\n",ans);
    /*XOR is used to toggle ~ could have been but it would have flipped everything that's why we shift then use XOR to get "exclusively" toggled bit*/

    //5.LSB
    printf("\nLeast Significant Bit:- \n");
    printf("this is the easiest as the logic is that of 1. but no need to shift\n");
    printf("%d\n",num&1);

    //6.to check for even
    printf("\nTo check for even\n");
    printf("The way is by utilizing the LSB concept\n");
    printf("num here is %d\n",num);
    if((num&1)==0)
        printf("it is even\n");
    else 
    printf("It is odd\n");
    //bit manipulation end --- AFAIK

    //Bit masks and masking
    /*AND is used to get only certain bits
    ..XOR is used to toggle certain bits
    ..OR is used to set certain bits
    ..As per the name we are giving the number a mask i.e. we r making sure it shows only the data we want. for the logic it's similar to the oen used above*/
    
    int x = 0b01100110;
    printf("value of x; %d\n",x);
    printf("getting only last 3 bits: %d\n",x&0b00000111);
    printf("To extract certain bits:- %d\n",x&0b01100100);
    printf("To toggle certain bits:- %d\n",x^0b10100000);
    //dynamic masking -- operation 2  from above
    //end

    //To Swap two numbers using XOR and without using third number
    //from above a = 5, b = 3
    printf("a:-%d  b:-%d",a,b);
    a ^= b;
    b ^= a;
    a ^= b;
    printf("a:-%d  b:-%d",a,b);
    /*Additional
    1. to check if the number is of power 2
    2. count the number of 1s*/

    printf("1. to check if the number is of power 2\n");
    num = 5;
    if ((num & (num - 1)) == 0)
        printf("%d is of power 2\n",num);
    else
        printf("%d is not of power 2\n",num);

    printf("2. count the number of 1s\n");
    num = 13;int count = 0;
    while(num){
        num &= (num-1);
        count++;
    }
    printf("the number of 1s is :- %d\n", count);
    //end

    //2's compliment

    num = 13;
    printf("Before 2's compliment:- %d\n", num);
    temp =~num;
    printf("%d\n",temp);
    temp = temp+1;
    printf("After 2's compliment:- %d\n", temp);
    return 0;
}
//end of bit ops
