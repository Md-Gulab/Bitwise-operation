//this program demonstrates several concepts used in bitwise operations
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <inttypes.h>

//function prototypes
void set_bit(uint32_t num, uint32_t pos) ;
void clear_bit(uint32_t num, uint32_t pos) ;
void toggle_bit(uint32_t num, uint32_t pos) ;
void check_bit(uint32_t num, uint32_t pos) ;
int count_set_bits(uint32_t num) ;
void is_power_of_two(uint32_t num) ;


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


int main(){

    printf("\n\r") ;
    set_bit(345,8) ;

    printf("\n\r") ;
    clear_bit(390897,18) ;
    printf("\n\r") ;

    toggle_bit(38,3) ;
    printf("\n\r") ;

    check_bit(0Xfa,2) ;

    printf("\n\r") ;
    int a = count_set_bits(0xfffffff0) ;
    printf("Number of set bits = %d\n",a) ;
    printf("\n\r") ;

    printf("\n\r") ;
    is_power_of_two(0x00008000) ;
    printf("\n\r") ;

    return 0 ;
}

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

void is_power_of_two(uint32_t num){
    //the binary sequence is a power of two if , any one and only one , bit except LSB is high
    //if LSB is high , with all higher bit having any combination of 1&0 , number is not power of two

    if((num & (1U))){  // LSB == 1  should be executed
        printf("Executing....is_power_of_two....for '%d'\n",num) ; 
        printf("This number can't be a power of two\n") ;
        return ;
    }
    int a = count_set_bits(num) ;
    if(a == 1 ){
        printf("This number is a power of 2\n") ;
    }
    else{
        printf("This number can't be a power of two\n") ;
    }
    return ;
}