/*
** get_next_line.c for get_next_line in /home/soto_a/rendu/CPE_2014_get_next_line
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri Nov 14 12:30:43 2014 Kaso Soto
** Last update Wed May  6 16:49:11 2015 adam soto
*/

#include "42sh.h"

static char	*my_realloc(char *str, int size)
{
  int		i;
  char		*tmp;

  i = 0;
  if ((tmp = malloc(sizeof(char) * (BUFF_SIZE + size + 1))) == NULL)
    return (NULL);
  while (i != size)
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = 0;
  if (str != NULL)
    free(str);
  return (tmp);
}

static void	my_reset_buff(char *buffer)
{
  int		i;

  i = 0;
  while (i < BUFF_SIZE)
    {
      buffer[i] = 0;
      i++;
    }
}

static char	*get_line(char *str, int pos, const int fd)
{
  static char	buffer[BUFF_SIZE];
  static int	i = 0;
  static int	test = 0;

  if ((str = my_realloc(str, pos)) == NULL)
    return (NULL);
  if (buffer[i] == '\0')
    {
      my_reset_buff(&(*buffer));
      i = 0;
      if ((test = read(fd, buffer, BUFF_SIZE)) < 1)
	{
	  free(str);
	  return (NULL);
	}
      buffer[test] = '\0';
    }
  while (buffer[i] != '\n' && buffer[i] != '\0' && i < test)
    str[pos++] = buffer[i++];
  str[pos] = '\0';
  i++;
  if (pos != 0 && i > BUFF_SIZE)
    return (get_line(str, pos, fd));
  str[pos] = '\0';
  return (str);
}

char	*get_next_line(const int fd)
{
  char	*str;
  int	pos;

  pos = 0;
  str = NULL;
  return (get_line(str, pos, fd));
}
