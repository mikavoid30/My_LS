/*
** utils.c for utils in /home/boulat_m/rendu/Projets/my_ls/functions
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Sun Nov  2 20:06:38 2014 Mickael BOULAT
** Last update Sun Nov  2 22:09:32 2014 Mickael BOULAT
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

DIR	*get_dir(char *directory_name)
{
  DIR		*dir;
  struct stat	st;

  dir = NULL;
  stat(directory_name, &st);
  if ((dir = opendir(directory_name)) == NULL)
    {
      perror("Cannot open this directory");
      exit(1);
    }
  return (dir);
}

char	get_file_type(unsigned char m)
{
  char c;

  c = '-';
  if (m == DT_REG)
    c = '-';
  else if (m == DT_DIR)
    c = 'd';
  else if (m == DT_LNK)
    c = 'l';
  else if (m == DT_FIFO)
    c = 'p';
  else if (m == DT_CHR)
    c = 'C';
  else if (m == DT_BLK)
    c = 'b';
  else if (m == DT_SOCK)
    c = 's';
  else if (m == DT_UNKNOWN)
    c = '?';
  return (c);
}

void	print_user_rights(struct stat *st)
{
  if (st->st_mode & S_IRUSR)
    my_putchar('r');
  else
    my_putchar('-');
  if (st->st_mode & S_IWUSR)
    my_putchar('w');
  else
    my_putchar('-');
  if (st->st_mode & S_IXUSR)
    my_putchar('x');
  else
    my_putchar('-');
}

void	print_group_rights(struct stat *st)
{
  if (st->st_mode & S_IRGRP)
    my_putchar('r');
  else
    my_putchar('-');
  if (st->st_mode & S_IWGRP)
    my_putchar('w');
  else
    my_putchar('-');
  if (st->st_mode & S_IXGRP)
    my_putchar('x');
  else
    my_putchar('-');
}

void	print_other_rights(struct stat *st)
{
  if (st->st_mode & S_IROTH)
    my_putchar('r');
  else
    my_putchar('-');
  if (st->st_mode & S_IWOTH)
    my_putchar('w');
  else
    my_putchar('-');
  if (st->st_mode & S_IXOTH)
    my_putchar('x');
  else
    my_putchar('-');
}
