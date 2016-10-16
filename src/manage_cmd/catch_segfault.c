/*
** catch_segfault.c for  in /home/trambe_m/trash/PSU_2014_42sh/src/manage_cmd
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Mon May 18 21:14:37 2015 Manuel Trambert
** Last update Thu May 21 17:53:52 2015 adam soto
*/

#include "42sh.h"

void	handle_sev()
{
  fprintf(stderr, "Segmentation fault\n");
}

int	wait_pid_and_sev(pid_t pid)
{
  int	status_proc;

  signal(SIGSEGV, SIG_IGN);
  waitpid(pid, &status_proc, 0);
  if (status_proc != 0)
    g_info.status = EXIT_FAILURE;
  if (WIFSIGNALED(status_proc))
    if (WTERMSIG(status_proc) == 11)
      fprintf(stderr, "Segmentation fault\n");
  signal(SIGSEGV, handle_sev);
  return (status_proc);
}
