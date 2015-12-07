/*
** get_conf.c for get_conf in /home/boulat_m/rendu/Projets/my_ls/functions
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct 30 09:01:30 2014 Mickael BOULAT
** Last update Sun Nov  2 22:04:10 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "myls.h"

t_main	*get_conf(int argc, char **argv, t_main *config)
{
  config = xmalloc(sizeof(t_main));
  init_config(config);
  if (argc > 1)
    {
      get_directories(argc, argv, config);
      get_options(argc, argv, config);
    }
  return (config);
}
