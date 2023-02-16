/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:35:53 by ligabrie          #+#    #+#             */
/*   Updated: 2023/02/16 22:28:23 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Here are the requirements:
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library. Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository.

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign

Makefile, *.h, * / *.h, *.c, * / *.c

Makefile
NAME, all, clean, fclean, re

External Functions
malloc, free, write, va_start, va_arg, va_copy, va_end

Libft allowed!
*/

#include <stdarg.h>
#include <stdio.h>
/* 
int	count_percent(char *s)
{
	int	i;
	int	nb_percent;
	int	pps;

	i = -1;
	nb_percent = 0;
	pps = 0;
	while (s[++i])
	{
		if (s[i] == '%' && pps == 0)
		{
			pps = -1;
			nb_percent++;
		}
		else
		{
			pps = 0;
		}
	}
	//if last char is unbound % retrun error!
	if (pps == -1)
		return (-1);
	return(nb_percent);
}
 */

int	count_percent(const char *s)
{
	int	i;
	int	nb_percent;
	int	pps;

	i = -1;
	nb_percent = 0;
	pps = 0;
	while (s[++i])
	{
		if (s[i] == '%' && pps == 0)
		{
			pps = -1;
			nb_percent++;
		}
		else
			pps = 0;
	}
	//if last char is unbound % retrun error!
	if (pps == -1)
		return (-1);
	return(nb_percent);
}

char	find_cmd_char (const char *s, int loc)
{
	int	i;
	int	nb_percent;
	int	pps;

	i = -1;
	nb_percent = 0;
	pps = 0;
	while (s[++i])
	{
		if (pps == -1 && nb_percent == loc)
			return (s[i]);
		if (s[i] == '%' && pps == 0)
		{
			pps = -1;
			nb_percent++;
		}
		else
			pps = 0;
	}
	//if last char is unbound % retrun error!
	if (pps == -1)
		return (-1);
	return(nb_percent);
}

int	ft_printf(const char *cs, ...)
{
	va_list	valist;
	int		nb_var;
	int		i;

	//count variables (num of %)
	nb_var = count_percent(cs);
	if (nb_var	== -1)
		return (-1);
	va_start(valist, nb_var);
	i = -1;
	while (++i < nb_var)
	{
		//va_arg(valist, int);
		//find cmd char and infer type
		printf("%c, ", find_cmd_char(cs, i + 1));
	}
	va_end(valist);
	return (0);
}

int	main()
{
	//printf("%d\n", count_percent("%a %df%%%%%%%%wa%sd %w %da%%%%%--% % %-%daw%"));
	ft_printf ("%a %df%%%%%%%%wa%sd %w %da%%%%%--% % %-%daw%");
	return (0);
}