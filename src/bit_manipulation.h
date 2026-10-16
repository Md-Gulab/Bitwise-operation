#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

#include<stdint.h>

//function prototypes
void set_bit(uint32_t num, uint32_t pos) ;
void clear_bit(uint32_t num, uint32_t pos) ;
void toggle_bit(uint32_t num, uint32_t pos) ;
void check_bit(uint32_t num, uint32_t pos) ;
int count_set_bits(uint32_t num) ;
bool is_power_of_two(uint32_t num) ;
void print_binary(uint32_t n) ;

#endif