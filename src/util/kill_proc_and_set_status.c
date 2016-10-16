/*
** kill_proc_and_set_status.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun May 17 19:09:38 2015 adam soto
** Last update Tue May 19 15:03:39 2015 adam soto
*/

#include "42sh.h"

int	kill_proc_and_set_status()
{
  g_info.status = EXIT_SUCCESS;
  if (g_info.state_multi == 1)
    kill(getpid(), SIGKILL);
  return (EXIT_SUCCESS);
}
