/*
** myls.h for my_ls in /home/boulat_m/rendu/Projets/my_ls
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct 28 10:43:03 2014 Mickael BOULAT
** Last update Fri Nov  7 17:18:04 2014 Mickael BOULAT
*/

#ifndef MYLS_H_
# define MYLS_H_

typedef struct  s_list
{
  struct dirent	*dt;
  struct s_list	*next;
  struct stat	*st;
  struct passwd	*pw;
  struct group	*gr;
  char		*path;
  char *dir_path;
}               t_list;

typedef struct	s_main
{
  char	**directories;
  int	nb_directories;
  char	*options;
  char	*enabled_options;
}		t_main;

void    save_in_list(DIR*, struct s_list**, char*);
t_list  *my_putinlist(t_list**, struct dirent*, char*, char*);
void    print_list(struct s_list*, t_main*);
void	my_putstr_n(char*, char);
char    get_file_type(unsigned char);
void    print_user_rights(struct stat*);
void    print_group_rights(struct stat*);
void    print_other_rights(struct stat*);
void    print_rights(struct stat*);
int     print_total_size(t_list*);
void    my_putstr_n(char*, char);
void    print_ld(t_list*);
DIR	*get_dir(char*);
void    print_l(t_list*);
char	*rem_end_slash(char*);
char	*check_slash(char*);
void	print(DIR*);
int	get_nb_dir(int, char**);
int	save_directories(int, char**, t_main*);
char	*get_directories(int, char**, t_main*);
int	get_nb_opts(int, char**);
int	is_in_tab(char, char*);
void	check(char, t_main*, int*);
int	save_options(int, char**, t_main*);
void	my_memset(char*, char);
char	*get_options(int, char**, t_main*);
int	init_config(t_main*);
t_main	*get_conf(int, char**, t_main*);
void	*xmalloc(int);

#endif /* MYLS_H_ */
