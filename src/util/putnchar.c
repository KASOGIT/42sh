/*
** putnchar.c for 42sh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Sat May 23 23:08:54 2015 Benjamin Rascol
** Last update Sat May 23 23:13:23 2015 Benjamin Rascol
*/

#include "42sh.h"

int	putnchar(char c, int nb)
{
  while (nb > 0)
    {
      my_putchar(c);
      nb--;
    }
  return (SUCCESS);
}
