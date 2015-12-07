/*
** my_sort_int_tab.c for my_sort_int_tab in /home/boulat_m/rendu/Piscine_C_J04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Fri Oct  3 21:20:48 2014 Mickael BOULAT
** Last update Fri Oct  3 23:22:30 2014 Mickael BOULAT
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	index_b;
  int	buffer;

  buffer = 0;
  i = 0;
  while (i < (size - 1))
    {
      buffer = 0;
      if (*tab >= *(tab + 1))
	{
	  buffer = *(tab + 1);
	  *tab = *(tab + 1);
	  *(tab + 1) = buffer;
	}
      i++;
      tab++;
    }
}
