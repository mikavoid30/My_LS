/*
** main.c for my_ls in /home/boulat_m/rendu/my_ls
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct 28 10:06:14 2014 Mickael BOULAT
** Last update Sun Nov  2 21:42:11 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "list.h"
#include "my.h"
#include "myls.h"

int	get_nb_opts(int argc, char **argv)
{
  int	i;
  int	j;
  int	cpt;

  cpt = 0;
  i = 1;
  while (i < argc)
    {
      if (argv[i][0] == '-')
	{
	  cpt--;
	  j = 0;
	  while ((argv[i][j + 1] != ' ') && (argv[i][j + 1] != '\0'))
	    {
	      j++;
	      cpt++;
	    }
	}
      cpt++;
      i++;
    }
  return (cpt);
}

int	is_in_tab(char c, char *tab)
{
  int	res;
  int	i;

  res = 0;
  i = 0;
  if (tab != NULL)
    {
      while ((tab[i] != '\0') && (res != 1))
	{
	  if (tab[i] == c)
	    {
	      res = 1;
	    }
	  i++;
	}
    }
  return (res);
}

void	check(char c, t_main *config, int *cpt)
{
  int	nb;

  nb = *cpt;
  if (is_in_tab(c, config->enabled_options))
    {
      if (!is_in_tab(c, config->options))
	{
	  config->options[nb + 1] = c;
	  config->options[nb + 2] = '\0';
	  nb = nb + 1;
	  *cpt = nb;
	}
    }
  else
    {
      my_putstr("my_ls: invalid option -- '");
      my_putchar(c);
      my_putstr("'\n");
      exit(-1);
    }
}

int	save_options(int argc, char **argv, t_main *config)
{
  int   i;
  int   j;
  int   cpt;
  char  c;

  cpt = 0;
  i = 1;
  while (i < argc)
    {
      if (argv[i][0] == '-')
        {
          cpt--;
          j = 0;
          while ((argv[i][j + 1] != ' ') && (argv[i][j + 1] != '\0'))
            {
              c = argv[i][j + 1];
              check(c, config, &cpt);
              j++;
            }
	  cpt++;
	}
      i++;
    }
  return (cpt);
}

void	my_memset(char *tab, char size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      tab[i] = '\0';
      i++;
    }
}
