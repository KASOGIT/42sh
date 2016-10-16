/*
** double_left_func.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_redir
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  8 14:52:15 2015 adam soto
** Last update Sun Oct 16 15:37:16 2016 
*/

#include "42sh.h"

static	int	error_tmp_file()
{
  fprintf(stderr, "Error when opening tmp file\n");
  g_info.status = EXIT_FAILURE;
  if (g_info.state_multi == 1)
    kill(getpid(), SIGKILL);
  return (EXIT_FAILURE);
}

static int	write_to_tmp(char *EOT, int fd_to_close)
{
  int		flags;
  int		tmp_fd;
  char		buffer[4096];

  close(fd_to_close);
  flags = O_CREAT | O_WRONLY | O_APPEND;
  memset(buffer, 0, 4096);
  while (read(0, buffer, 4096) > 0
	 && strncmp(EOT, buffer, strlen(EOT)) != 0)
    {
      if ((tmp_fd = open("./.tmp_42sh", flags, g_info.mode)) == -1)
	return (error_tmp_file());
      if (write(tmp_fd, buffer, strlen(buffer)) == -1)
	printf("Error on write\n");
      memset(buffer, 0, 4096);
      close(tmp_fd);
    }
  return (EXIT_SUCCESS);
}

static int	exec_double_left(t_tree **node, int tmp_fd)
{
  dup2(tmp_fd, 0);
  run_tree(&((*node)->left));
  return (EXIT_SUCCESS);
}

static int	fork_and_exec(t_tree **node, int fd_file)
{
  pid_t		pid;

  g_info.state_multi = 1;
  g_info.state_redir = 1;
  if ((pid = fork()) == 0)
    exec_double_left(node, fd_file);
  else
    waitpid(pid, 0, 0);
  return (EXIT_SUCCESS);
}

int		double_left_func(t_tree **node)
{
  char		**tab_epur_name;
  int		tmp_fd;

  if ((*node)->right && (*node)->left
      && (*node)->left->data && strlen((*node)->left->data) > 0
      && (*node)->right->data && strlen((*node)->right->data) > 0
      && (tab_epur_name = str_to_wordtab((*node)->right->data)) != NULL)
    {
      put_in_order_exotic_param(node, tab_epur_name);
      if ((tmp_fd = open("./.tmp_42sh", O_CREAT | O_TRUNC, g_info.mode)) == -1)
	return (error_tmp_file());
      write_to_tmp(tab_epur_name[0], tmp_fd);
      if ((tmp_fd = open("./.tmp_42sh", O_RDONLY, g_info.mode)) == -1)
	return (error_tmp_file());
      if (g_info.state_multi == 0)
	fork_and_exec(node, tmp_fd);
      else
	exec_double_left(node, tmp_fd);
      close(tmp_fd);
      free_tab(tab_epur_name);
    }
  else
    return (kill_set_and_put_error_redir());
  return (redir_reset_glob_and_set_status());
}
