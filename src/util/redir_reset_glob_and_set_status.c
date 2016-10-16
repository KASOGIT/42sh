/*
** redir_reset_glob_and_set_status.c for  in /home/soto_a/rendu/PSU_2014_42sh/src/util
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun May 24 02:39:46 2015 adam soto
** Last update Sun May 24 02:41:52 2015 adam soto
*/

#include "42sh.h"

int	redir_reset_glob_and_set_status()
{
  g_info.state_multi = 0;
  g_info.state_redir = 0;
  return ((g_info.status = EXIT_SUCCESS));
}
