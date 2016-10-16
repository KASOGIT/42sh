/*
** delete_tree.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_tree
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Thu May  7 13:58:13 2015 adam soto
** Last update Tue May 12 11:37:00 2015 adam soto
*/

#include "42sh.h"

void	free_binary(t_tree *tree)
{
  if (tree)
    {
      free_binary(tree->left);
      free_binary(tree->right);
      free(tree->data);
      free(tree);
    }
}
