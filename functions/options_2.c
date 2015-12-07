/*
** main.c for my_ls in /home/boulat_m/rendu/my_ls
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct 28 10:06:14 2014 Mickael BOULAT
** Last update Sun Nov  2 21:41:51 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "list.h"
#include "my.h"
#include "myls.h"

char	*get_options(int argc, char **argv, t_main *config)
{
  int	nb_options;

  nb_options = get_nb_opts(argc, argv);
  config->options = xmalloc(nb_options + 1);
  my_memset(config->options, (nb_options + 1));
  save_options(argc, argv, config);
  return (NULL);
}

int	init_config(t_main *config)
{
  config->options = NULL;
  config->nb_directories = 1;
  config->enabled_options = my_strdup("lRdrt");
  config->directories = xmalloc(sizeof(char*));
  config->directories[0] = xmalloc(3 * sizeof(char));
  config->directories[0] = my_strcpy(config->directories[0], "./");
  return (0);
}
