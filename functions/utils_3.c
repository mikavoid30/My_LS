/*
** my_lc.c for my_ls in /home/boulat_m/myls
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Wed Oct 15 08:18:07 2014 Mickael BOULAT
** Last update Sun Nov  2 22:02:08 2014 Mickael BOULAT
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "myls.h"
#include "list.h"
#include "my.h"

void	print_list(t_list *begin, t_main *conf)
{
  int	i;

  i = 0;
  while (begin != NULL)
    {
      if (is_in_tab('l', conf->options) && (!is_in_tab('d', conf->options)))
	{
	  if (i == 0)
	    print_total_size(begin);
	  if (begin->dt->d_name[0] != '.')
	    print_l(begin);
	}
      else if (is_in_tab('l', conf->options) && is_in_tab('d', conf->options))
	{
	  print_ld(begin);
	}
      else
	{
	  if (begin->dt->d_name[0] != '.')
	    my_putstr_n(begin->dt->d_name, '\n');
	}
      i++;
      begin = begin->next;
    }
}

char	*check_slash(char *str)
{
  int	size;
  char	*slash;

  size = my_strlen(str);
  if (str[size - 1] == '/')
    {
      return (str);
    }
  else
    {
      slash = xmalloc(size + 2);
      slash = my_strcpy(slash, str);
      slash[size + 0] = '/';
      slash[size + 1] = '\0';
      return (slash);
    }
}

char	*rem_end_slash(char *str)
{
  int	size;

  size = my_strlen(str);
  if (str[size - 1] != '/')
    {
      return (str);
    }
  else
    {
      str[size - 1] = '\0';
      return (str);
    }
}

void		save_in_list(DIR *directory, t_list **begin, char *dir_name)
{
  struct dirent *dt;
  char		*dir_name_slash;
  char		*buff;
  int		s;

  dir_name_slash = check_slash(dir_name);
  s = (my_strlen(dir_name_slash) + 30);
  while ((dt = readdir(directory)) != 0)
    {
      buff = xmalloc(s);
      buff = my_strcpy(buff, dir_name_slash);
      buff = my_strcat(buff, dt->d_name);
      my_putinlist(begin, dt, buff, dir_name_slash);
    }
}
