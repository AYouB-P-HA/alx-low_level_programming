#include <stdio.h>
#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */

void print_binary(unsigned long int n) {
    int size = sizeof(unsigned long int) * 8 - 1;
    int binary=0;

    while (size >= 0) {
        unsigned long int mimic = 1 << size;
      if(mimic>n)
         mimic<<=1;
       
        if ((n & mimic)){
            putchar('1');
            binary=1;
        }
         else if (binary) {
            putchar('0');
         }
         size--;
         }   
   if (!binary)
   {putchar('0');
   }
}
