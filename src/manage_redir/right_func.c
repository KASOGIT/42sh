/*
** right_func.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_redir
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  8 14:51:29 2015 adam soto
** Last update Sun May 24 02:42:59 2015 adam soto
*/

#include "42sh.h"

static int	exec_right(t_tree **node, int fd_file)
{
  dup2(fd_file, 1);
  run_tree(&((*node)->left));
  return (EXIT_FAILURE);
}

static int	fork_and_exec(t_tree **node, int fd_file)
{
  pid_t		pid;

  g_info.state_multi = 1;
  g_info.state_redir = 1;
  if ((pid = fork()) == 0)
    exec_right(node, fd_file);
  else
    waitpid(pid, 0, 0);
  return (EXIT_SUCCESS);
}

int		right_func(t_tree **node)
{
  char		**tab_epur_name;
  int		fd_file;

  if ((*node)->right && (*node)->left
      && (*node)->left->data && strlen((*node)->left->data) > 0
      && (*node)->right->data && strlen((*node)->right->data) > 0
      && (tab_epur_name = str_to_wordtab((*node)->right->data)) != NULL)
    {
      put_in_order_exotic_param(node, tab_epur_name);
      if ((fd_file = open(tab_epur_name[0],
			  O_WRONLY | O_CREAT | O_TRUNC, g_info.mode)) == -1)
	return (file_error_redir());
      if (g_info.state_multi == 0)
	fork_and_exec(node, fd_file);
      else
	exec_right(node, fd_file);
      free_tab(tab_epur_name);
      close(fd_file);
    }
  else
    return (kill_set_and_put_error_redir());
  return (redir_reset_glob_and_set_status());
}
