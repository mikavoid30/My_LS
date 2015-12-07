/*
** my_isneg.c for my_isneg in /home/boulat_m/rendu/Piscine_C_J03
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Wed Oct  1 17:21:24 2014 Mickael BOULAT
** Last update Thu Oct  2 11:29:36 2014 Mickael BOULAT
*/

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return (0);
}
