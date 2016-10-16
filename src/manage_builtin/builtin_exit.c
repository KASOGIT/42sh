/*
** builtin_exit.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_builtin
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May  9 02:02:11 2015 adam soto
** Last update Mon May 18 13:46:14 2015 adam soto
*/

#include "42sh.h"

static int	verif_and_exit(t_list *ev, char *sending)
{
  int		i;

  i = 1;
  (void)(ev);
  while (sending[i])
    {
      if (!(sending[i] >= '0' && sending[i] <= '9'))
        {
          fprintf(stderr, "exit: Badly formed number.\n");
          return -1;
        }
      i++;
    }
  if (sending[0] == '-')
    g_info.val_exit = 256 - (ABS(my_getnbr(sending)) % 256);
  else
    g_info.val_exit = my_getnbr(sending) % 256;
  return (0);
}

int	builtin_exit(char **tab_input)
{
  int   nb_arg;

  if (g_info.state_multi == 1)
    kill(getpid(), SIGKILL);
  nb_arg = size_tab(tab_input);
  if (nb_arg == 2 || nb_arg == 1)
    {
      if (nb_arg == 1)
	g_info.val_exit = EXIT_SUCCESS;
      else
	{
	  if (tab_input[1][0] == '-' && strlen(tab_input[1]) == 1)
	    fprintf(stderr, "exit: Badly formed number.\n");
	  else
	    {
	      if (verif_and_exit(g_info.ev, tab_input[1]) == -1)
		return (-1);
	    }
	}
      g_info.status = EXIT_MODE;
    }
  else
    fprintf(stderr, "exit: Expression Syntax\n");
  return (EXIT_SUCCESS);
}
