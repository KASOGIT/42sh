/*
** builtin_unalias.c for  in /home/soto_a/rendu/PSU_2014_42sh/src/manage_builtin
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Thu May 21 17:00:17 2015 adam soto
** Last update Thu May 21 17:01:21 2015 adam soto
*/

#include "42sh.h"

static void	delete_alias(t_alia *elem)
{
  if (elem->next == NULL)
    elem->prev->next = NULL;
  else
    elem->prev->next = elem->next;
  if (elem->prev == NULL)
    elem->next->prev = NULL;
  else
    elem->next->prev = elem->prev;
  free(elem->str);
  free(elem->result);
  free(elem);
}

int		builtin_unalias(char **tab_input)
{
  t_alia	*tmp;
  int		boolean;

  boolean = 1;
  if (size_tab(tab_input) > 1)
    {
      tmp = g_info.alias->next;
      while (tmp != g_info.alias && boolean)
	{
	  if (strcmp(tmp->result, tab_input[1]) == 0)
	    {
	      delete_alias(tmp);
	      boolean = 0;
	    }
	  else
	    tmp = tmp->next;
	}
    }
  else
    fprintf(stderr, "Unalias : bad formed expr\n");
  kill_proc_and_set_status();
  return ((g_info.status = EXIT_SUCCESS));
}
