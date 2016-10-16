/*
** my_strcat.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May  9 00:45:32 2015 adam soto
** Last update Sat May  9 00:49:01 2015 adam soto
*/

#include "42sh.h"

char	*my_strcat(char *dest, char *add)
{
  int	i;
  int	j;

  i = strlen(dest);
  j = 0;
  if ((dest = realloc(dest, (strlen(dest) + strlen(add) + 1))) == NULL)
    return (NULL);
  while (add[j])
    {
      dest[i] = add[j];
      i++;
      j++;
    }
  dest[i] = '\0';
  return (dest);
}
