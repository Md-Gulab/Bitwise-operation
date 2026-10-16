#include"bit_manipulation.h"
#include<stdio.h>
#include<stdint.h>
#include <inttypes.h>

//this is ust a helper function to print a number in binary------------------
void print_binary(uint32_t n) {
    for (uint32_t i = 0; i <= 31; i++) {
        uint32_t k = n >> (31-i);
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}
//--------------------------------------------------------------------------

void set_bit(uint32_t num, uint32_t pos){
    int temp = num ;
    if(pos>31){
        printf("set_bit() executing.....\n") ;
        printf("EXITING-invalid (%d) bit position entered!\n",pos) ;
        return ;
    }
    temp |= (1U << pos) ;
    printf("Given Number(%d)                     = ",num) ;
    print_binary(num) ;
    printf("After bit no %d set (%-15d)  = ",pos,temp) ;
    print_binary(temp) ;
    return ;
}

void clear_bit(uint32_t num, uint32_t pos){
    int temp = num ;
    if(pos>31){
        printf("clear_bit() executing.....\n") ;
        printf("EXITING-invalid (%d) bit position entered!\n",pos) ;
        return ;
    }
    temp &= ~(1U << pos) ; 
    printf("Given Number(%-2d)                         = ",num) ;
    print_binary(num) ;
    printf("After bit no %d cleared (%-15d)  = ",pos,temp) ;
    print_binary(temp) ;
    return ;
}

void toggle_bit(uint32_t num, uint32_t pos){
    int temp = num ;
    if(pos>31){
        printf("clear_bit() executing.....\n") ;
        printf("EXITING-invalid (%d) bit position entered!\n",pos) ;
        return ;
    }
    temp ^= (1U << pos) ;
    printf("Given Number(%-2d)                         = ",num) ;
    print_binary(num) ;
    printf("After bit no %d toglled (%-15d)  = ",pos,temp) ;
    print_binary(temp) ;
    return ;
}

void check_bit(uint32_t num, uint32_t pos){
    int temp = num ;
    if(pos>31){
        printf("clear_bit() executing.....\n") ;
        printf("EXITING-invalid (%d) bit position entered!\n",pos) ;
        return ;
    }
    temp &= (1U << pos) ;
    temp = temp >> pos ;
    printf("Given Number(%-5d)                           = ",num) ;
    print_binary(num) ;
    printf("Bit no %-2d is = %d\n",pos,temp) ;
    //print_binary(temp) ;
    return ;  
}


int count_set_bits(uint32_t num){
    int temp = num ;
    uint8_t count = 0 ;
    for(int i=0 ; i<32 ; i++){
        temp &= (1U<<i) ;
       // temp = temp >> i ;
        if(temp){
            count ++ ;
        }
        temp = num ;
    }
    printf("Given Number(%d) = ",num) ;
    print_binary(num) ;
    return count ;
}

bool is_power_of_two(uint32_t num){
    bool powerOfTwo = false ;
    if(num==0){
        return 0 ;
    }

    if((num & (num-1)) == 0){
        powerOfTwo = true ;
    }
    return powerOfTwo ;
}