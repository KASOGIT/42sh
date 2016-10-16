/*
** my_putnbr.c for my_putnbr.c in /home/soto_a
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Nov 22 14:11:15 2014 Kaso Soto
** Last update Sun Oct 16 15:39:56 2016 
*/

#include "42sh.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      if (write(1, "-", 1) == -1)
	printf("Error write\n");
      nb = -nb;
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    {
      my_putchar('0' + nb);
    }
}
