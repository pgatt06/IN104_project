
#include "unity.h"
#include "utils.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_max(void) {
    int l1[5] = {5,6,7,2,3};
    int n = max(5, l1);
    TEST_ASSERT_EQUAL_INT(n, 7);
    int l2[5] = {5,6,7,2,9};
    int m = max(5, l2);
    TEST_ASSERT_EQUAL_INT(m, 9);
}

void test_function_in_list(void) {
    int l1[5] = {5,6,7,2,3};
    int n = in_liste(6, l1,5);
    TEST_ASSERT_EQUAL_INT(n, 1);
    n = in_liste(3, l1,5);
    TEST_ASSERT_EQUAL_INT(n, 1);
    n = in_liste(9, l1,5);
    TEST_ASSERT_EQUAL_INT(n, 0);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_max);
    RUN_TEST(test_function_in_list);
    // RUN_TEST(test_function_should_doAlsoDoBlah);
    return UNITY_END();
}
