#include "provider.h"

/**
 * \author              CDL.
 * \version             1.0.
 * \brief               Tests all the functions provided in the TA using extremes (N/A for Padovan & Van Eck since undecidable).
*/


/**
 * \brief               Unit test for the factorial problem.
 * \param[out{ptr_t}]   data[struct Data*]          Memory.
 * \param[out{ptr_t}]   n_tests_passed[uint8_t*]    Keeps track of the number of unique unit test passed.
 * \param[in]           x[const uint8_t]            Value for x.
 * \param[in]           n[const uint8_t]            Value for n.
 * \param[in]           ex[const uint8_t]           Expected value after computation.
*/
void testFactorial(struct Data *data, uint8_t *n_tests_passed, const uint8_t x, const uint8_t n, const uint8_t ex) {
    printf(TEST_FACTORIAL_HEADER);

    preAllocate(data);
    q21Factorial(data, x, n);

    if (strcmp(data->indexes[0], TRIVIAL_RES_ETIQ) != 0)
        printf(TRIVIAL_ERROR_NO_RES);
    
    printf("-> q21Factorial(%d, %d): ", x, n);

    if (data->values[0] == ex) {
        printf(ALL_PASSED);
        *n_tests_passed += 1;
    } else
        printf("FAILURE [output=%d, expected=%d]\n", data->values[0], ex);
}

/**
 * \brief               Executes unit tests in batch for the factorial problem.
 * \param[out{ptr_t}]   data[struct Data*]  Memory.
*/
void executeTestsFactorial(struct Data *data) {
    uint8_t n_tests_passed = 0;

    testFactorial(data, &n_tests_passed, 1, 2, 1);
    testFactorial(data, &n_tests_passed, 1, 3, 1);
    testFactorial(data, &n_tests_passed, 1, 99, 1);
    testFactorial(data, &n_tests_passed, 1, 100, 1);
    testFactorial(data, &n_tests_passed, 2, 2, 0);
    testFactorial(data, &n_tests_passed, 2, 3, 2);
    testFactorial(data, &n_tests_passed, 2, 99, 2);
    testFactorial(data, &n_tests_passed, 2, 100, 2);
    testFactorial(data, &n_tests_passed, 5, 2, 0);
    testFactorial(data, &n_tests_passed, 5, 3, 0);
    testFactorial(data, &n_tests_passed, 5, 99, 21);
    testFactorial(data, &n_tests_passed, 5, 100, 20);
    testFactorial(data, &n_tests_passed, 10, 2, 0);
    testFactorial(data, &n_tests_passed, 10, 3, 0);
    testFactorial(data, &n_tests_passed, 10, 99, 54);
    testFactorial(data, &n_tests_passed, 10, 100, 0);

    printf("\nSummary for q21Factorial... %d tests passed out of %d!\n", n_tests_passed, N_TESTS_FACTORIAL);
    
    if (n_tests_passed == N_TESTS_FACTORIAL)
        printf(TEST_FACTORIAL_COMPLETED);
    else
        printf(TEST_FACTORIAL_INCOMPLETED);
}

/**
 * \brief               Unit test for the twins problem.
 * \param[out{ptr_t}]   data[struct Data*]          Memory.
 * \param[out{ptr_t}]   n_tests_passed[uint8_t*]    Keeps track of the number of unique unit test passed.
 * \param[in]           n[const uint8_t]            Value for n.
 * \param[in]           m[const uint8_t]            Value for m.
 * \param[in]           ex1[const uint8_t]          Expected value after computation for the first twin.
 * \param[in]           ex2[const uint8_t]          Expected value after computation for the second twin.
*/
void testTwins(struct Data *data, uint8_t *n_tests_passed, const uint8_t n, const uint8_t m, const uint8_t ex1, const uint8_t ex2) {
    printf(TEST_TWINS_HEADER);

    preAllocate(data);
    q22Twins(data, n, m);

    if (strcmp(data->indexes[0], TRIVIAL_PRIME1_ETIQ) != 0)
        printf(TRIVIAL_ERROR_NO_PRIME1);

    if (strcmp(data->indexes[1], TRIVIAL_PRIME2_ETIQ) != 0)
        printf(TRIVIAL_ERROR_NO_PRIME2);

    printf("-> q22Twins(%d, %d): ", n, m);

    if (data->values[0] == ex1 && data->values[1] == ex2) {
        printf(ALL_PASSED);
        *n_tests_passed += 1;
    } else
        printf("FAILURE [output=(%d, %d), expected=(%d, %d)]\n", data->values[0], data->values[1], ex1, ex2);
}

/**
 * \brief               Executes unit tests in batch for the twins problem.
 * \param[out{ptr_t}]   data[struct Data*]  Memory.
*/
void executeTestsTwins(struct Data *data) {
    uint8_t n_tests_passed = 0;

    testTwins(data, &n_tests_passed, 2, 5, 3, 5);
    testTwins(data, &n_tests_passed, 2, 100, 3, 5);
    testTwins(data, &n_tests_passed, 3, 100, 3, 5);
    testTwins(data, &n_tests_passed, 7, 100, 11, 13);
    testTwins(data, &n_tests_passed, 9, 100, 11, 13);
    testTwins(data, &n_tests_passed, 55, 100, 59, 61);
    testTwins(data, &n_tests_passed, 70, 100, 71, 73);

    printf("\nSummary for q22Twins... %d tests passed out of %d!\n", n_tests_passed, N_TESTS_TWINS);
    
    if (n_tests_passed == N_TESTS_TWINS)
        printf(TEST_TWINS_COMPLETED);
    else
        printf(TEST_TWINS_INCOMPLETED);
}

/**
 * \brief               Unit test for the Padovan problem.
 * \param[out{ptr_t}]   data[struct Data*]          Memory.
 * \param[out{ptr_t}]   n_tests_passed[uint8_t*]    Keeps track of the number of unique unit test passed.
 * \param[in]           n[const uint8_t]            Value for n.
 * \param[in]           ex[const uint8_t]           Expected value after computation.
*/
void testPadovan(struct Data *data, uint8_t *n_tests_passed, const uint32_t n, const uint32_t ex) {
    printf(TEST_PADOVAN_HEADER);

    preAllocate(data);
    q31Padovan(data, n);

    if (strcmp(data->indexes[0], TRIVIAL_RES_ETIQ) != 0)
        printf(TRIVIAL_ERROR_NO_RES);

    printf("-> q31Padovan(%d): ", n);

    if (data->values[0] == ex) {
        printf(ALL_PASSED);
        *n_tests_passed += 1;
    } else
        printf("FAILURE [output=%d, expected=%d]\n", data->values[0], ex);
}

/**
 * \brief               Executes unit tests in batch for the Padovan problem.
 * \param[out{ptr_t}]   data[struct Data*]  Memory.
*/
void executeTestsPadovan(struct Data *data) {
    uint8_t n_tests_passed = 0;

    testPadovan(data, &n_tests_passed, 0, 1);
    testPadovan(data, &n_tests_passed, 1, 1);
    testPadovan(data, &n_tests_passed, 2, 1);
    testPadovan(data, &n_tests_passed, 3, 1);
    testPadovan(data, &n_tests_passed, 4, 2);
    testPadovan(data, &n_tests_passed, 5, 2);
    testPadovan(data, &n_tests_passed, 6, 3);
    testPadovan(data, &n_tests_passed, 7, 4);
    testPadovan(data, &n_tests_passed, 11, 12);
    testPadovan(data, &n_tests_passed, 36, 13581);

    printf("\nSummary for q31Padovan... %d tests passed out of %d!\n", n_tests_passed, N_TESTS_PADOVAN);
    
    if (n_tests_passed == N_TESTS_PADOVAN)
        printf(TEST_PADOVAN_COMPLETED);
    else
        printf(TEST_PADOVAN_INCOMPLETED);
}

/**
 * \brief               Executes a single, yet complex and deep, unit test for the Van Eck problem.
 * \param[out{ptr_t}]   data[struct Data*]  Memory.
*/
void executeTestsVanEck(struct Data *data) {
    printf(TEST_VAN_ECK_HEADER);

    preAllocate(data);
    q32VanEck(data, N_TESTS_VAN_ECK);

    printf("-> q32VanEck(%d): ", N_TESTS_VAN_ECK);

    const uint32_t EXPECTED[N_TESTS_VAN_ECK + 1] = {
        0, 0, 1, 0, 2, 0, 2, 2, 1, 6, 0, 5, 0, 2, 6, 
        5, 4, 0, 5, 3, 0, 3, 2, 9, 0, 4, 9, 3, 6, 14, 
        0, 6, 3, 5, 15, 0, 5, 3, 5, 2, 17, 0, 6, 11, 
        0, 3, 8, 0, 3, 3, 1, 42, 0, 5, 15, 20, 0, 4, 
        32, 0, 3, 11, 18, 0, 4, 7, 0, 3, 7, 3, 2, 31, 
        0, 6, 31, 3, 6, 3, 2, 8, 33, 0, 9, 56, 0, 3, 
        8, 7, 19, 0, 5, 37, 0, 3, 8, 8, 1
    };

    bool isValid = true;

    for (uint32_t i = 0; i < N_TESTS_VAN_ECK; ++i)
        if (data->values[i] != EXPECTED[i])
            isValid = false;

    if (isValid)
        printf(TEST_VAN_ECK_COMPLETED);
    else
        printf(TEST_VAN_ECK_INCOMPLETED);
}

/**
 * \brief               Executes all test suites.
 * \param[out{ptr_t}]   data[struct Data*]  Memory.
*/
void executeTests(struct Data* data) {
    executeTestsFactorial(data);
    executeTestsTwins(data);
    executeTestsPadovan(data);
    executeTestsVanEck(data);
}

int main(){
    struct Data *data = malloc(sizeof(struct Data));

    if (!data) {
        perror(TRIVIAL_ERROR_MEM_ALLOC);
        return 1;
    }

    executeTests(data);

    free(data->indexes);
    free(data->values);
    free(data);

    return 0;
}
