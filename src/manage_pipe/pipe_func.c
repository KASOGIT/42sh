/*
** pipe_func.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_pipe
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  8 16:06:53 2015 adam soto
** Last update Sun Oct 16 15:38:04 2016 
*/

#include "42sh.h"

static int	get_type_data(char *data, char **op)
{
  int		i;

  i = 0;
  while (op[i])
    {
      if (strncmp(op[i], data, strlen(op[i])) == 0)
	return (i);
      i++;
    }
  return (i);
}

static int	proc_pipe(t_tree **node)
{
  int		type;
  int		pipe_fd[2];
  pid_t		pid;
  int		status_proc;

  if (pipe(pipe_fd) == -1)
    printf("Error on pipe\n");
  if ((*node)->left && (*node)->left->data)
    type = get_type_data((*node)->left->data, g_info.op);
  if ((pid = vfork()) == 0)
    {
      close(pipe_fd[0]);
      dup2(pipe_fd[1], 1);
      run_tree(&((*node)->left));
    }
  else
    {
      close(pipe_fd[1]);
      if (type != 8)
      	waitpid(pid, &status_proc, 0);
      dup2(pipe_fd[0], 0);
      run_tree(&((*node)->right));
      if (type == 8)
	waitpid(pid, &status_proc, 0);
    }
  return (EXIT_SUCCESS);
}

static	int	catch_error_expr()
{
  g_info.status = EXIT_FAILURE;
  if (g_info.state_multi == 1)
    kill(getpid(), SIGKILL);
  return (EXIT_FAILURE);
}

int		pipe_func(t_tree **node)
{
  static int	count = 0;
  pid_t		pid;

  if (!(*node)->left || !(*node)->right
      || strlen((*node)->left->data) < 1 || strlen((*node)->right->data) < 1)
    return (catch_error_expr());
  count++;
  g_info.state_multi = 1;
  if (count == 1)
    {
      if ((pid = vfork()) == 0)
  	proc_pipe(node);
      else
  	waitpid(pid, 0, 0);
    }
  else
    proc_pipe(node);
  g_info.state_multi = 0;
  count = 0;
  if (g_info.state_redir == 1)
    kill(getpid(), SIGKILL);
  return (EXIT_SUCCESS);
}
