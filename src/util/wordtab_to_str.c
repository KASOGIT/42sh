/*
** wordtab_to_str.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_redir/manage_exotic
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun May 17 23:14:21 2015 adam soto
** Last update Sun May 17 23:15:19 2015 adam soto
*/

#include "42sh.h"

char	*wordtab_to_str(char **array)
{
  char	*str;
  int	i;

  i = 0;
  while (array[i])
    {
      if (i == 0)
        str = strdup(array[i]);
      else
        {
          if ((str = realloc(str,
	     (strlen(str) + strlen(array[i]) + 1))) == NULL)
            return (NULL);
          str = strcat(str, array[i]);
        }
      if (array[i + 1])
        {
          if ((str = realloc(str, (strlen(str) + 2))) == NULL)
            return (NULL);
          str = strcat(str, " ");
        }
      i++;
    }
  free_tab(array);
  return (str);
}
