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

uint32_t set_bit(uint32_t num, uint32_t pos){
    int temp = num ;
    if(pos>31){
        printf("set_bit() executing.....\n") ;
        printf("EXITING-invalid (%d) bit position entered!\n",pos) ;
        return -1 ;
    }
    temp |= (1U << pos) ;

    return temp ;
}

uint32_t clear_bit(uint32_t num, uint32_t pos){
    int temp = num ;
    if(pos>31){
        printf("clear_bit() executing.....\n") ;
        printf("EXITING-invalid (%d) bit position entered!\n",pos) ;
        return -1 ;
    }
    temp &= ~(1U << pos) ; 

    return temp ;
}

uint32_t toggle_bit(uint32_t num, uint32_t pos){
    int temp = num ;
    if(pos>31){
        printf("clear_bit() executing.....\n") ;
        printf("EXITING-invalid (%d) bit position entered!\n",pos) ;
        return -1 ;
    }
    temp ^= (1U << pos) ;

    return temp ;
}

bool check_bit(uint32_t num, uint32_t pos){
    int temp = num ;
    if(pos>31){
        printf("clear_bit() executing.....\n") ;
        printf("EXITING-invalid (%d) bit position entered!\n",pos) ;
        return 0 ;
    }
    temp &= (1U << pos) ;
    return (bool)temp ;  
}


uint32_t count_set_bits(uint32_t num){
    int temp = num ;
    uint32_t count = 0 ;
    for(int i=0 ; i<32 ; i++){
        temp &= (1U<<i) ;
       // temp = temp >> i ;
        if(temp){
            count ++ ;
        }
        temp = num ;
    }
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