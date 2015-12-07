/*
** xmalloc.c for xmalloc in /home/boulat_m/rendu/Projets/my_ls/functions/xfuntions
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct 30 09:21:39 2014 Mickael BOULAT
** Last update Thu Oct 30 09:27:59 2014 Mickael BOULAT
*/

#include <stdlib.h>

void	*xmalloc(int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == 0)
    {
      exit(-1);
    }
  return (ptr);
}
