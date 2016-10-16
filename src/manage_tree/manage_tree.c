/*
** manage_tree.c for manage_tree in /home/soto_a/rendu/PSU_2014_minishell2
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun Feb  8 15:48:35 2015 Kaso Soto
** Last update Sun May 24 23:24:38 2015 adam soto
*/

#include "42sh.h"

int	run_act_on_tree(char *input)
{
  g_info.tree = NULL;
  g_info.op = str_to_wordtab("; || && | >> > << <");
  eval_and_create_tree(&g_info.tree, input);
  run_tree(&(g_info.tree));
  free_tab(g_info.op);
  free_binary(g_info.tree);
  return (g_info.status);
}
