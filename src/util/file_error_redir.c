/*
** file_error_redir.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun May 17 22:11:44 2015 adam soto
** Last update Sun May 17 22:12:27 2015 adam soto
*/

#include "42sh.h"

int	file_error_redir()
{
  fprintf(stderr, "file: Permission denied.\n");
  g_info.status = EXIT_FAILURE;
  if (g_info.state_multi == 1)
    kill(getpid(), SIGKILL);
  return (EXIT_FAILURE);
}
