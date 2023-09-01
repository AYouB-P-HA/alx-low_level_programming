#include <stdio.h>
#include "main.h"

/*
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b) 
{
unsigned int total = 0,i = 0;
	if (b == NULL)
  return (0);
  for (i;b[i]; ) 
{
  if (b[i] != '0' && b[i] != '1')
  return (0);
  total <<= 1;
  total += b[i]-'0';
  i++;
}
return total;
}
