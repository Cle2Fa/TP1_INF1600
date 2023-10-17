#include "provider.h"

/**
 * \author              CDL & <élève 1, mat. 1> & <élève 2, mat. 2>.
 * \version             1.X.
 * \brief               Provides computation solving for q21Factorial, q22Twins, q31Padovan & q32VanEck.
*/


/**
 * \brief               Solves question q21Factorial.
 * \param[out{ptr_t}]   data[struct Data*]   Memory.
 * \param[in]           x[const uint8_t]     Value for x.
 * \param[in]           n[const uint8_t]     Value for n.        
*/
void q21Factorial(struct Data *data, const uint8_t x, const uint8_t n) {
   // PROLOGUE
   strcpy(data->indexes[0], "res");
   uint8_t res = 1;
   // PROLOGUE

   // VOTRE IMPLEMENTATION ICI
   
   // VOTRE IMPLEMENTATION ICI
   
   // EPILOGUE
   data->values[0] = (uint32_t)res;
   // EPILOGUE
}

/**
 * \brief               Solves question q22Twins.
 * \param[out{ptr_t}]   data[struct Data*]   Memory.
 * \param[in]           n[const uint8_t]     Value for n.
 * \param[in]           m[const uint8_t]     Value for m.        
*/
void q22Twins(struct Data *data, const uint8_t n, const uint8_t m) {
   // PROLOGUE
   strcpy(data->indexes[0], "prime1");
   strcpy(data->indexes[1], "prime2");
   uint8_t prime1 = 1;
   uint8_t prime2 = 1;
   // PROLOGUE

   // VOTRE IMPLEMENTATION ICI
   
   // VOTRE IMPLEMENTATION ICI
   
   // EPILOGUE
   data->values[0] = (uint32_t)prime1;
   data->values[1] = (uint32_t)prime2;
   // EPILOGUE
}

/**
 * \brief               Solves question q31Padovan.
 * \param[out{ptr_t}]   data[struct Data*]   Memory.
 * \param[in]           n[const uint8_t]     Value for n.      
*/
void q31Padovan(struct Data *data, const uint32_t n) {
   // PROLOGUE
   strcpy(data->indexes[0], "res");
   data->values[1] = (uint32_t)1; // P_0
   data->values[2] = (uint32_t)1; // P_1
   data->values[3] = (uint32_t)1; // P_2
   uint32_t res = 1;
   // PROLOGUE

   // VOTRE IMPLEMENTATION ICI
   for(int i=2; i<n; i++){

      res =  data->values[1] + data->values[2];

      data->values[1] = data->values[2];
      data->values[2] = data->values[3];
      data->values[3] = res; 
   }
   // VOTRE IMPLEMENTATION ICI
   
   // EPILOGUE
   data->values[0] = (uint32_t)res;
   // EPILOGUE
}

/**
 * \brief               Solves question q32VanEck.
 * \param[out{ptr_t}]   data[struct Data*]   Memory.
 * \param[in]           n[const uint8_t]     Value for n.      
*/
void q32VanEck(struct Data *data, const uint32_t n) {
   // PROLOGUE
   data->values[0] = (uint32_t)0; // V_0
   data->values[1] = (uint32_t)0; // V_1
   data->values[2] = (uint32_t)1; // V_2
   // PROLOGUE

   // VOTRE IMPLEMENTATION ICI
   int ma = 0;
   int compteur = 0;
   for(int i = 2; i<n; i++){
      while ((data->values[i-1-compteur] != ma) && (compteur<i)) {
         compteur++;
      }
      if (compteur==i)
         ma=0;
      else
         ma=compteur;
      compteur = 0;
      data->values[i]=ma;
   }
   // VOTRE IMPLEMENTATION ICI
}
