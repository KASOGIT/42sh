/*
** semicolon_func.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_tree
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  8 14:48:24 2015 adam soto
** Last update Sat May 23 22:07:42 2015 adam soto
*/

#include "42sh.h"

int	semicolon_func(t_tree **node)
{
  pid_t	pid;

  if (g_info.state_redir == 1 || g_info.state_multi == 1)
    {
      if ((pid = vfork()) == 0)
	run_tree(&((*node)->left));
      else
	{
	  waitpid(pid, 0, 0);
	  run_tree(&((*node)->right));
	}
    }
  else
    {
      run_tree(&((*node)->left));
      run_tree(&((*node)->right));
    }
  return (EXIT_SUCCESS);
}
