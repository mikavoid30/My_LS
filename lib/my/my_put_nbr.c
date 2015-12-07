/*
** my_put_nbr.c for my_put_nbr in /home/boulat_m/rendu/Piscine_C_J04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct  2 20:25:59 2014 Mickael BOULAT
** Last update Fri Oct  3 12:04:17 2014 Mickael BOULAT
*/

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr(-1 * nb);
    }
  else
    {
      if ((nb / 10) > 0)
	{
	  my_put_nbr(nb / 10);
	}
      my_putchar((nb % 10) + 48);
    }
  return (0);
}
