/*
** my_getnbr.c for my_getnbr.c in /home/soto_a/rendu/Piscine_C_J04
** 
** Made by adam kaso
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Oct  3 09:11:30 2014 adam kaso
** Last update Sat May 16 12:07:32 2015 adam soto
*/

#include "42sh.h"

int	my_getnbr(char *str)
{
  int	count;
  int	s;
  int	nbr;

  s = 1;
  count = 0;
  while (str[count] != '\0' && (str[count] == '+' || str[count] == '-'))
    {
      if (str[count] == '-')
	s *= -1;
      count++;
    }
  str += count;
  nbr = 0;
  count = 0;
  while (str[count] >= '0' && str[count] <= '9')
    {
      nbr *= 10;
      nbr -= str[count] - '0';
      count++;
    }
  return (nbr * s * -1);
}
