//this program demonstrates several concepts used in bitwise operations
#include<stdio.h>
#include"bit_manipulation.h"

int main(){

    // printf("\n\r") ;
    // set_bit(345,8) ;

    // printf("\n\r") ;
    // clear_bit(390897,18) ;
    // printf("\n\r") ;

    // toggle_bit(38,3) ;
    // printf("\n\r") ;

    // check_bit(0Xfa,2) ;

    // printf("\n\r") ;
    // int a = count_set_bits(0xfffffff0) ;
    // printf("Number of set bits = %d\n",a) ;
    // printf("\n\r") ;

    printf("\n\r") ;
    bool var1 = is_power_of_two(0x00008000) ;
    printf("var1 = %d\n",var1) ;
    printf("\n\r") ;

    return 0 ;
}