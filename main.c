#include "provider.h"

/**
 * \author              CDL.
 * \version             1.0.
 * \brief               Executes q21Factorial, q22Twins, q31Padovan, and q32VanEck with respect to user's own inputs.
*/


int main(int argc, char **argv) {
   struct Data *data = malloc(sizeof(struct Data));

   if (!data) {
      perror("Failed to allocate memory for data");
      return 1;
   }

   // vvv VARIABLES MODIFIABLES POUR VOS TESTS A LA MAIN vvv
   const uint8_t x = 7;
   const uint8_t n = 11;
   const uint8_t m = 13;
   // -------------------------------------------------------
   
   preAllocate(data);
   q21Factorial(data, x, n);
   // vvv UTILE POUR DEBOGAGE
   // showMemory(data);
   // -----------------------

   preAllocate(data);
   q22Twins(data, n, m);
   // vvv UTILE POUR DEBOGAGE
   // showMemory(data);
   // -----------------------

   preAllocate(data);
   q31Padovan(data, n);
   // vvv UTILE POUR DEBOGAGE
   // showMemory(data);
   // -----------------------

   preAllocate(data);
   q32VanEck(data, n);
   // vvv UTILE POUR DEBOGAGE
   // showMemory(data);
   // -----------------------

   free(data->indexes);
   free(data->values);
   free(data);

   return 0;
}
