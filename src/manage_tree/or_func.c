/*
** or_func.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_tree
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  8 14:49:42 2015 adam soto
** Last update Sat May 23 22:09:34 2015 adam soto
*/

#include "42sh.h"

int	or_func(t_tree **node)
{
  pid_t	pid;

  if (g_info.state_redir == 1 || g_info.state_multi == 1)
    {
      if ((pid = vfork()) == 0)
	run_tree(&((*node)->left));
      else
	{
	  waitpid(pid, 0, 0);
	  if (g_info.status == EXIT_FAILURE)
	    run_tree(&((*node)->right));
	  else
	    kill(getpid(), SIGKILL);
	}
    }
  else
    {
      run_tree(&((*node)->left));
      if (g_info.status == EXIT_FAILURE)
	run_tree(&((*node)->right));
    }
  return (EXIT_SUCCESS);
}
