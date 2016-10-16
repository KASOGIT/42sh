/*
** builtin_echo.c for  in /home/soto_a/rendu/PSU_2014_42sh
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Thu May 21 19:46:03 2015 adam soto
** Last update Sun Oct 16 15:39:13 2016 
*/

#include "42sh.h"

static char	*wordtab_to_print(char **array)
{
  char		*str;
  int		i;

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
  return (str);
}

static void	put_echo(char *str)
{
  if (write(1, str, strlen(str)) == -1)
    printf("Error on write\n");
  if (write(1, "\n", 1) == -1)
    printf("Error on write\n");
}

int	builtin_echo(char **tab_input)
{
  char	*to_print;

  if (size_tab(tab_input) > 1)
    {
      to_print = wordtab_to_print(tab_input + 1);
      put_echo(to_print);
      free(to_print);
    }
  else
    fprintf(stderr, "too few arguments.\n");
  return (kill_proc_and_set_status());
}
