/*
** my_putstr.c for my_putstr in /home/boulat_m/rendu/Piscine_C_J04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct  2 09:37:30 2014 Mickael BOULAT
** Last update Fri Oct  3 08:44:07 2014 Mickael BOULAT
*/

int my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
  return (0);
}
