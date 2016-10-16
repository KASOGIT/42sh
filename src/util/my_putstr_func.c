/*
** my_putstr_func.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed May  6 17:33:37 2015 adam soto
** Last update Sun Oct 16 15:40:55 2016 
*/

#include "42sh.h"

void	my_putstr(char *str)
{
  if (write(1, str, strlen(str)) == -1)
    printf("Error write\n");
}

void	my_putstr_color(char *str, char *color)
{
  my_putstr(color);
  my_putstr(str);
  my_putstr(ANSI_COLOR_RESET);
}
