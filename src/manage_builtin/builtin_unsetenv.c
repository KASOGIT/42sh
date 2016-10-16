/*
** builtin_unsetenv.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_builtin
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May  9 02:04:39 2015 adam soto
** Last update Mon May 18 13:59:48 2015 adam soto
*/

#include "42sh.h"

static void	unsetenv_error()
{
  g_info.status = EXIT_FAILURE;
  fprintf(stderr, "unsetenv: Too few arguments.\n");
}

static void	compare_on_ev_and_delete(t_list *ev, char *sending)
{
  t_list	*tmp_ev;
  int		boolean;

  boolean = 1;
  tmp_ev = ev->next;
  while (tmp_ev != ev && boolean != 0)
    {
      if (strncmp(tmp_ev->str, sending, strlen(sending)) == 0)
        {
          my_delete_elem(tmp_ev);
          boolean = 0;
        }
      else
        tmp_ev = tmp_ev->next;
    }
}

int	builtin_unsetenv(char **tab_input, int choice)
{
  int	i;
  int	nb_arg;

  i = 1;
  nb_arg = size_tab(tab_input);
  if (nb_arg != 1 || choice == 1)
    {
      while (tab_input[i])
        compare_on_ev_and_delete(g_info.ev, tab_input[i++]);
    }
  else
    unsetenv_error();
  return (kill_proc_and_set_status());
}
