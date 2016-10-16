/*
** search_builtin_and_run.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_builtin
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May  9 01:18:44 2015 adam soto
** Last update Sun May 24 18:41:35 2015 adam soto
*/

#include "42sh.h"

static t_builtin	g_tab_builtin[] =
  {
    {"cd\0", &builtin_cd},
    {"exit\0", &builtin_exit},
    {"env\0", &builtin_env},
    {"setenv\0", &builtin_setenv},
    {"unsetenv\0", &builtin_unsetenv},
    {"alias\0", &builtin_alias},
    {"unalias\0", &builtin_unalias},
    {"echo\0", &builtin_echo},
    {"history\0", &builtin_history},
    {NULL, NULL},
  };

int	search_builtin_and_run(char **tab_input)
{
  int	i;
  int	boolean;

  i = 0;
  boolean = 1;
  while (g_tab_builtin[i].id != NULL && boolean != 0)
    {
      if (strncmp(g_tab_builtin[i].id, tab_input[0],
		  strlen(g_tab_builtin[i].id)) == 0
	  && strlen(tab_input[0]) == strlen(g_tab_builtin[i].id))
        {
	  boolean = 0;
	  g_tab_builtin[i].func_builtin(tab_input, 0);
        }
      i++;
    }
  return (boolean == 0 ? 1 : 0);
}
