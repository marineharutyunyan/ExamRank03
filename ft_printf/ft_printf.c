/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:08:26 by maharuty          #+#    #+#             */
/*   Updated: 2022/11/22 13:12:01 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putxd(unsigned int nb, int base)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if ((base == 10 && nb < 10) || (base == 16 && nb < 16))
	{
		count += write(1, &hex[nb], 1);
		return (count);
	}
	else
	{
		count += ft_putxd(nb / base, base);
		count += write(1, &hex[nb % base], 1);
	}
	return (count);
}

int	ft_putd(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = nb * -1;
	}
	count += ft_putxd(nb, 10);
	return (count);
}

int	ft_printf(const	char	*str, ...)
{
	int		count;
	va_list	ap;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				count += ft_putstr(va_arg(ap, char *));
			if (str[i] == 'd')
				count += ft_putd(va_arg(ap, int));
			if (str[i] == 'x')
				count += ft_putxd(va_arg(ap, unsigned int), 16);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	ft_printf("%s\n", "toto"); //toto$
	ft_printf("Magic %s is %d", "number", 42); //Magic number is 42%
	ft_printf("Hexadecimal for %dis %x\n", 42, 42); //Hexadecimal for 42 is 2a$
	return (0);
}
