/*
** builtin_history.c for 42sh in /home/benjamin/rendu/C/PSU/tmp/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed May 20 14:08:49 2015 Benjamin Rascol
** Last update Sun May 24 15:28:15 2015 Manuel Trambert
*/

#include "42sh.h"

int		builtin_history(char **tab_input)
{
  t_hist_list	*tmp;

  if (tab_input[1] == NULL)
    {
      tmp = g_history.start;
      while (tmp != NULL)
	{
	  printf("%s\n", tmp->str);
	  tmp = tmp->next;
	}
    }
  else if (strcmp(tab_input[1], "-c") == 0)
    {
      tmp = g_history.start;
      free_list_hist(&tmp);
      g_history.start = NULL;
      g_history.current = g_history.start;
    }
  kill_proc_and_set_status();
  return (0);
}
