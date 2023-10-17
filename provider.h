#ifndef PROVIDER_H
#define PROVIDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * \author              CDL.
 * \version             1.0.
 * \brief               Provides constants, structs, and function definitions for whole TA.
*/

#define ANSI_BLUE_BOLD              "\033[1;34m"
#define ANSI_YELLOW_BOLD            "\033[1;33m"
#define ANSI_GREEN_BOLD             "\033[1;32m"
#define ANSI_RED_BOLD               "\033[1;31m"
#define ANSI_RESET                  "\033[0m"

#define MEM_MAX                     256
#define FATAL_ERROR_MEM_ALLOC_IDX   ANSI_RED_BOLD     "\nFailed to allocate memory for indexes\n"                                            ANSI_RESET
#define FATAL_ERROR_MEM_ALLOC_I_IDX ANSI_RED_BOLD     "\nFailed to allocate memory for an individual index\n"                                ANSI_RESET
#define FATAL_ERROR_MEM_ALLOC_VAL   ANSI_RED_BOLD     "\nFailed to allocate memory for values\n"                                             ANSI_RESET
#define TRIVIAL_ERROR_MEM_ALLOC     ANSI_RED_BOLD     "\nFailed to allocate memory for data\n"                                               ANSI_RESET

/* >>> HELPER-SPECIFIC <<< */
#define TRIVIAL_OFFSET              20
#define TRIVIAL_BUFFER_VAL          '\0'
#define TRIVIAL_SEP                 ", "
#define CUSTOM_NO_BUFFER_OUT        "<EMPTY>"
#define BUFFER_TO_IDX_OFFSET        2
/* >>> HELPER-SPECIFIC <<< */

/* >>> TEST-SPECIFIC <<< */   
#define N_TESTS_FACTORIAL           16
#define N_TESTS_TWINS               7
#define N_TESTS_PADOVAN             10
#define N_TESTS_VAN_ECK             96

#define TRIVIAL_ERROR_NO_RES        ANSI_RED_BOLD     "\nFirst data index must be 'res'\n"                                                   ANSI_RESET
#define TRIVIAL_ERROR_NO_PRIME1     ANSI_RED_BOLD     "\nFirst data index must be 'prime1'\n"                                                ANSI_RESET
#define TRIVIAL_ERROR_NO_PRIME2     ANSI_RED_BOLD     "\nSecond data index must be 'prime2'\n"                                               ANSI_RESET

#define TRIVIAL_RES_ETIQ            "res"
#define TRIVIAL_PRIME1_ETIQ         "prime1"
#define TRIVIAL_PRIME2_ETIQ         "prime2"
#define ALL_PASSED                  ANSI_GREEN_BOLD   "OK\n"                                                                                 ANSI_RESET

#define TEST_FACTORIAL_HEADER       ANSI_BLUE_BOLD    "\nTesting q21Factorial...\n"                                                          ANSI_RESET
#define TEST_FACTORIAL_COMPLETED    ANSI_GREEN_BOLD   "\nq21Factorial completed successfully!\n"                                             ANSI_RESET
#define TEST_FACTORIAL_INCOMPLETED  ANSI_YELLOW_BOLD  "\nPlease review your implementation of nq21Factorial.\n"                              ANSI_RESET

#define TEST_TWINS_HEADER           ANSI_BLUE_BOLD    "\nTesting q22Twins...\n"                                                              ANSI_RESET
#define TEST_TWINS_COMPLETED        ANSI_GREEN_BOLD   "\nq22Twins completed successfully!\n"                                                 ANSI_RESET
#define TEST_TWINS_INCOMPLETED      ANSI_YELLOW_BOLD  "\nPlease review your implementation of q22Twins.\n"                                   ANSI_RESET

#define TEST_PADOVAN_HEADER         ANSI_BLUE_BOLD    "\nTesting q31Padovan...\n"                                                            ANSI_RESET
#define TEST_PADOVAN_COMPLETED      ANSI_GREEN_BOLD   "\nq31Padovan completed successfully!\n"                                               ANSI_RESET
#define TEST_PADOVAN_INCOMPLETED    ANSI_YELLOW_BOLD  "\nPlease review your implementation of q31Padovan.\n"                                 ANSI_RESET

#define TEST_VAN_ECK_HEADER         ANSI_BLUE_BOLD    "\nTesting q32VanEck...\n"                                                             ANSI_RESET
#define TEST_VAN_ECK_COMPLETED      ANSI_GREEN_BOLD   "OK\n\nq32VanEck completed successfully!\n"                                            ANSI_RESET 
#define TEST_VAN_ECK_INCOMPLETED    ANSI_RED_BOLD     "FAILURE.\n\nPlease output memory for further analysis of q32VanEck's computation.\n"  ANSI_RESET
/* >>> TEST-SPECIFIC <<< */

/* >>> MEMORY <<< */
struct Data {
   char **indexes;
   uint32_t *values;
};
/* >>> MEMORY <<< */

/* >>> HELPERS <<< */
void preAllocate(struct Data *data);
void showMemory(struct Data *data);
/* >>> HELPERS <<< */

/* >>> FUNCTIONS <<< */
void q21Factorial(struct Data *data, const uint8_t x, const uint8_t n);
void q22Twins(struct Data *data, const uint8_t n, const uint8_t m);
void q31Padovan(struct Data *data, const uint32_t n);
void q32VanEck(struct Data *data, const uint32_t n);
/* >>> FUNCTIONS <<< */

#endif // PROVIDER_H
