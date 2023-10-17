#include "provider.h"

/**
 * \author              CDL.
 * \version             1.0.
 * \brief               Provides memory preallocation & transparency.
*/


/**
 * \brief               Preallocates enough space for data's indexes & values.
 * \param[out{ptr_t}]   data[struct Data*]    Said allocated data.
*/
void preAllocate(struct Data *data) {
    if (data->indexes) {
        for (int i = 0; i < MEM_MAX; ++i)
            if (data->indexes[i])
                free(data->indexes[i]);
        free(data->indexes);
    }

    data->indexes = calloc(MEM_MAX, sizeof(char*));

    if (!data->indexes) {
        perror(FATAL_ERROR_MEM_ALLOC_IDX);
        exit(1);
    }

    for (int i = 0; i < MEM_MAX; ++i) {
        data->indexes[i] = calloc(MEM_MAX, sizeof(char));
        if (!data->indexes[i]) {
            perror(FATAL_ERROR_MEM_ALLOC_I_IDX);
            exit(1);
        }
    }

    if (data->values)
      free(data->values);

    data->values = calloc(MEM_MAX, sizeof(uint32_t));
    if (!data->values) {
        perror(FATAL_ERROR_MEM_ALLOC_VAL);
        exit(1);
    }
}

/**
 * \brief               Shows console transparency of data's indexes & values (useful for debug).
 * \param[out{ptr_t}]   data[struct Data*]  Data to display.
*/
void showMemory(struct Data *data) {
   const uint8_t OFFSET = TRIVIAL_OFFSET;

   char bufferIndexes[MEM_MAX * (MEM_MAX + OFFSET)];
   char bufferValues[MEM_MAX * OFFSET];

   bufferIndexes[0] = TRIVIAL_BUFFER_VAL;
   bufferValues[0]  = TRIVIAL_BUFFER_VAL;

   for (uint8_t i = 0; i < MEM_MAX; ++i) {
      if (data->indexes[i] && data->indexes[i][0] != TRIVIAL_BUFFER_VAL)
        strcat(bufferIndexes, data->indexes[i]);
      else
        strcat(bufferIndexes, CUSTOM_NO_BUFFER_OUT);

      strcat(bufferIndexes, TRIVIAL_SEP);

      char valueStr[OFFSET];

      sprintf(valueStr, "%u, ", data->values[i]);

      strcat(bufferValues, valueStr);
   }

   bufferIndexes[strlen(bufferIndexes)  - BUFFER_TO_IDX_OFFSET]     = TRIVIAL_BUFFER_VAL;
   bufferValues [strlen(bufferValues)   - BUFFER_TO_IDX_OFFSET]     = TRIVIAL_BUFFER_VAL;

   printf("[ %s ]\n", bufferIndexes);
   printf("[ %s ]\n", bufferValues);
}
