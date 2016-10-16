/*
** builtin_env.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_builtin
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May  9 02:03:09 2015 adam soto
** Last update Sat May 16 13:32:39 2015 adam soto
*/

#include "42sh.h"

int	builtin_env(char **tab_input)
{
  (void)(tab_input);
  my_show_list(1, g_info.ev, 0);
  if (g_info.state_multi == 1)
    kill(getpid(), SIGKILL);
  return ((g_info.status = EXIT_SUCCESS));
}
