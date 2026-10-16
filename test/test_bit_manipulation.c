#include "unity.h"
#include "bit_manipulation.h"

void setUp(void)    {}
void tearDown(void) {}

// ---------- set_bit ---------- 
void test_set_bit_sets_a_clear_bit(void){
    TEST_ASSERT_EQUAL_HEX32(0x08, set_bit(0x00, 3));
    TEST_ASSERT_EQUAL_INT(1, 1); 
}

void test_set_bit_leaves_an_already_set_bit_unchanged(void){
    TEST_ASSERT_EQUAL_HEX32(0x08, set_bit(0x08, 3));
}

void test_set_bit_works_on_bit_31(void){
    TEST_ASSERT_EQUAL_HEX32(0x80000000, set_bit(0, 31));
}

// ---------- clear_bit ---------- 
void test_clear_bit_clears_a_set_bit(void){
    TEST_ASSERT_EQUAL_HEX32(0xFE, clear_bit(0xFF, 0));
}

void test_clear_bit_leaves_an_already_clear_bit_unchanged(void){
    TEST_ASSERT_EQUAL_HEX32(0x00, clear_bit(0x00, 5));
}

// ---------- toggle_bit ---------- 
void test_toggle_bit_flips_0_to_1(void){
    TEST_ASSERT_EQUAL_HEX32(0x08, toggle_bit(0x00, 3));
}

void test_toggle_bit_flips_1_to_0(void){
    TEST_ASSERT_EQUAL_HEX32(0x00, toggle_bit(0x08, 3));
}

void test_toggle_bit_twice_returns_original(void){
    TEST_ASSERT_EQUAL_HEX32(0xA5, toggle_bit(toggle_bit(0xA5, 4), 4));
}

// ---------- check_bit ---------- 
void test_check_bit_returns_true_when_bit_is_set(void){
    TEST_ASSERT_TRUE(check_bit(0xFA, 1));    /* 0xFA = 1111 1010 */
}

void test_check_bit_returns_false_when_bit_is_clear(void){
    TEST_ASSERT_FALSE(check_bit(0xFA, 2));
}

// ---------- count_set_bits ---------- 
void test_count_set_bits_of_zero_is_zero(void){
    TEST_ASSERT_EQUAL_INT(0, count_set_bits(0));
}

void test_count_set_bits_of_all_ones_is_32(void){
    TEST_ASSERT_EQUAL_INT(32, count_set_bits(0xFFFFFFFF));
}

void test_count_set_bits_of_0xFFFFFFF0_is_28(void){
    TEST_ASSERT_EQUAL_INT(28, count_set_bits(0xFFFFFFF0));
}

// ---------- is_power_of_two ---------- 
void test_is_power_of_two_true_for_1_and_2(void){
    TEST_ASSERT_TRUE(is_power_of_two(1));
    TEST_ASSERT_TRUE(is_power_of_two(2));
}

void test_is_power_of_two_true_for_0x8000(void){
    TEST_ASSERT_TRUE(is_power_of_two(0x00008000));
}

void test_is_power_of_two_false_for_zero(void){
    TEST_ASSERT_FALSE(is_power_of_two(0));
}

void test_is_power_of_two_false_for_non_powers(void){
    TEST_ASSERT_FALSE(is_power_of_two(3));
    TEST_ASSERT_FALSE(is_power_of_two(6));
    TEST_ASSERT_FALSE(is_power_of_two(0xFFFFFFFF));
}

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_set_bit_sets_a_clear_bit);
    RUN_TEST(test_set_bit_leaves_an_already_set_bit_unchanged);
    RUN_TEST(test_set_bit_works_on_bit_31);

    RUN_TEST(test_clear_bit_clears_a_set_bit);
    RUN_TEST(test_clear_bit_leaves_an_already_clear_bit_unchanged);

    RUN_TEST(test_toggle_bit_flips_0_to_1);
    RUN_TEST(test_toggle_bit_flips_1_to_0);
    RUN_TEST(test_toggle_bit_twice_returns_original);

    RUN_TEST(test_check_bit_returns_true_when_bit_is_set);
    RUN_TEST(test_check_bit_returns_false_when_bit_is_clear);

    RUN_TEST(test_count_set_bits_of_zero_is_zero);
    RUN_TEST(test_count_set_bits_of_all_ones_is_32);
    RUN_TEST(test_count_set_bits_of_0xFFFFFFF0_is_28);

    RUN_TEST(test_is_power_of_two_true_for_1_and_2);
    RUN_TEST(test_is_power_of_two_true_for_0x8000);
    RUN_TEST(test_is_power_of_two_false_for_zero);
    RUN_TEST(test_is_power_of_two_false_for_non_powers);

    return UNITY_END();
}