/*
** error_env.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun May 17 18:50:12 2015 adam soto
** Last update Sun May 17 18:51:26 2015 adam soto
*/

#include "42sh.h"

int	error_env(char *name_env)
{
  g_info.status = EXIT_FAILURE;
  fprintf(stderr, "%s is missing on env.\n", name_env);
  return (-2);
}
