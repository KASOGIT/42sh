/*
** my_putchar.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed May  6 17:24:56 2015 adam soto
** Last update Sun Oct 16 15:40:22 2016 
*/

#include "42sh.h"

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    printf("Error write\n");
}
