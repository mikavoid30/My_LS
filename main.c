/*
** main.c for my_ls in /home/boulat_m/rendu/my_ls
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct 28 10:06:14 2014 Mickael BOULAT
** Last update Sun Nov  2 21:38:38 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include "myls.h"
#include "my.h"

t_list		*my_putinlist(t_list **b, struct dirent  *pt, char *p, char *d_p)
{
  t_list	*current;
  struct stat	*ptst;
  struct passwd	*pw;
  struct group	*gr;

  ptst = xmalloc(sizeof(struct stat));
  current = xmalloc(sizeof(t_list));
  current->dt = xmalloc(sizeof(struct dirent));
  current->dt = pt;
  current->dir_path = my_strdup(d_p);
  current->path = my_strdup(p);
  stat(current->path, ptst);
  current->st = ptst;
  pw = getpwuid(ptst->st_uid);
  gr = getgrgid(ptst->st_gid);
  current->pw = pw;
  current->gr = gr;
  current->next = *b;
  *b = current;
  return (current);
}

int		get_nb_elem_in_list(t_list *begin)
{
  t_list	*current;
  int		i;

  i = 0;
  current = begin;
  while (current != NULL)
    {
      i++;
      current = current->next;
    }
  return (i);
}

void	print_title(t_main *conf, int i)
{
  if ((conf->nb_directories > 1) && (!is_in_tab('d', conf->options)))
    {
      if (i > 0)
	my_putchar('\n');
      my_putstr(rem_end_slash(conf->directories[i]));
      my_putstr(":\n");
    }
}

int		main(int argc, char **argv)
{
  t_main	*conf;
  DIR           *directory;
  t_list	*begin;
  int		i;

  i = 0;
  begin = NULL;
  conf = NULL;
  conf = get_conf(argc, argv, conf);
  while (i < conf->nb_directories)
    {
      directory = get_dir(conf->directories[i]);
      if (is_in_tab('d', conf->options) && !is_in_tab('l', conf->options))
	my_putstr_n(conf->directories[i], '\n');
      else
	{
	  print_title(conf, i);
	  save_in_list(directory, &begin, conf->directories[i]);
	  print_list(begin, conf);
	  begin = NULL;
	}
      i++;
    }
  return (0);
}
