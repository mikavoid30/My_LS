/*
** my_lc.c for my_ls in /home/boulat_m/myls
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Wed Oct 15 08:18:07 2014 Mickael BOULAT
** Last update Sun Nov  2 22:08:51 2014 Mickael BOULAT
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

void	print_rights(struct stat *st)
{
  print_user_rights(st);
  print_group_rights(st);
  print_other_rights(st);
}

int		print_total_size(t_list *begin)
{
  size_t	total;
  size_t	t;
  t_list	*current;

  total = 0;
  current = begin;
  while (current != NULL)
    {
      if (get_file_type(current->dt->d_type) != 'd')
	{
	  total += current->st->st_size;
	}
      current = current->next;
    }
  t = total / 512;
  my_putstr("total ");
  my_put_nbr(t);
  my_putchar('\n');
  return (0);
}

void	print_l(t_list *current)
{
  time_t        file_date;
  char          t[18];
  struct tm     tm_file_date;

  my_memset(&t[0], 18);
  file_date = current->st->st_mtime;
  tm_file_date = *localtime(&file_date);
  strftime(t, 18, "%b %d %H:%M", &tm_file_date);
  my_putchar(get_file_type(current->dt->d_type));
  print_rights(current->st);
  my_putchar(' ');
  my_put_nbr(current->st->st_nlink);
  my_putchar(' ');
  my_putstr_n(current->pw->pw_name, ' ');
  my_putstr_n(current->gr->gr_name, '\t');
  my_put_nbr(current->st->st_size);
  my_putchar('\t');
  my_putstr_n(t, '\t');
  my_putstr_n(current->dt->d_name, '\n');
}

void	my_putstr_n(char *str, char c)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
  my_putchar(c);
}

void	print_ld(t_list *current)
{
  if (my_strcmp(rem_end_slash(current->dir_path), current->dt->d_name) == 0)
    print_l(current);
}
