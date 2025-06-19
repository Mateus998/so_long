/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:29:28 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 12:06:38 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_putpointer(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n / 16)
		count += pf_putpointer(n / 16, base);
	pf_putchar(base[n % 16]);
	count++;
	return (count);
}

static int	write_pointer(unsigned long arg)
{
	if (arg == 0)
		return (pf_putstr("(nil)"));
	return (pf_putstr("0x") + pf_putpointer(arg, "0123456789abcdef"));
}

static int	write_arg(char type, va_list arg)
{
	if (type == 's')
		return (pf_putstr(va_arg(arg, char *)));
	else if (type == 'i' || type == 'd')
		return (pf_putint(va_arg(arg, int)));
	else if (type == '%')
		return (pf_putchar('%'));
	else if (type == 'c')
		return (pf_putchar((char)va_arg(arg, int)));
	else if (type == 'u')
		return (pf_putuint(va_arg(arg, unsigned int)));
	else if (type == 'x')
		return (pf_putxint(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (pf_putxint(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else if (type == 'p')
		return (write_pointer((unsigned long)va_arg(arg, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (str == NULL)
		return (-1);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			count += write_arg(*++str, args);
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int i = 0;

	ft_printf("\nTESTE FINAIS COM %%\n\n");
	i = printf("|%c %%|\n", '0');
	printf("|Result = %d|\n", i);
	i = ft_printf("|%c %%|\n", '0');
	ft_printf("|Result = %d|\n", i);

	ft_printf("\nTESTE NULL\n\n");
	i = printf(NULL);
	printf("|NULL OLD = %d|\n", i);
	i = ft_printf(NULL);
	ft_printf("|NULL NEW = %d|\n", i);

	ft_printf("\nTESTE PARA %%C\n\n");
	i = printf("|OLD %c|\n", 'a');
	i += printf("|OLD %c|\n", -123);
	i += printf("|OLD %c|\n", 123);
	printf("Result OLD = %d\n\n", i);
	i = ft_printf("|NEW %c|\n", 'a');
	i += ft_printf("|NEW %c|\n", -123);
	i += ft_printf("|NEW %c|\n", 123);
	ft_printf("Result NEW = %d\n", i);

	ft_printf("\nTESTE PARA %%S\n\n");
	i = printf("|OLD %s|\n", NULL);
	printf("Result OLD NULL = %d\n", i);
	i += printf("|OLD %s|\n", "Ola meus amigos");
	i += printf("|OLD %s|\n", "123");
	printf("Result OLD = %d\n\n", i);
	i = ft_printf("|NEW %s|\n", NULL);
	ft_printf("Result NEW NULL = %d\n", i);
	i += ft_printf("|NEW %s|\n", "Ola meus amigos");
	i += ft_printf("|NEW %s|\n", "123");
	ft_printf("Result NEW = %d\n", i);

	ft_printf("\nTESTE PARA %%I\n\n");
	i = printf("|OLD %i|\n", NULL);
	printf("Result OLD NULL = %i\n", i);
	i += printf("|OLD %i|\n", 123);
	i += printf("|OLD %i|\n", -123);
	printf("Result OLD = %i\n\n", i);
	i = ft_printf("|NEW %i|\n", NULL);
	ft_printf("Result NEW NULL = %i\n", i);
	i += ft_printf("|NEW %i|\n", 123);
	i += ft_printf("|NEW %i|\n", -123);
	ft_printf("Result NEW = %i\n", i);

	ft_printf("\nTESTE PARA %%D\n\n");
	i = printf("|OLD %d|\n", NULL);
	printf("Result OLD NULL = %d\n", i);
	i += printf("|OLD %d|\n", 123);
	i += printf("|OLD %d|\n", -123);
	printf("Result OLD = %d\n\n", i);
	i = ft_printf("|NEW %d|\n", NULL);
	ft_printf("Result NEW NULL = %d\n", i);
	i += ft_printf("|NEW %d|\n", 123);
	i += ft_printf("|NEW %d|\n", -123);
	ft_printf("Result NEW = %d\n", i);

	ft_printf("\nTESTE PARA %%U\n\n");
	i = printf("|OLD %u|\n", NULL);
	printf("Result OLD NULL = %d\n", i);
	i += printf("|OLD %u|\n", 123);
	i += printf("|OLD %u|\n", -123);
	printf("Result OLD = %d\n\n", i);
	i = ft_printf("|NEW %u|\n", NULL);
	ft_printf("Result NEW NULL = %d\n", i);
	i += ft_printf("|NEW %u|\n", 123);
	i += ft_printf("|NEW %u|\n", -123);
	ft_printf("Result NEW = %d\n", i);

	ft_printf("\nTESTE PARA %%P\n\n");
	i = printf("|OLD %p|\n", NULL);
	printf("Result OLD NULL = %d\n", i);
	i += printf("|OLD %p|\n", 123);
	i += printf("|OLD %p|\n", -123);
	i += printf("|OLD %p|\n", "OLA");
	printf("Result OLD = %d\n\n", i);
	i = ft_printf("|NEW %p|\n", NULL);
	ft_printf("Result NEW NULL = %d\n", i);
	i += ft_printf("|NEW %p|\n", 123);
	i += ft_printf("|NEW %p|\n", -123);
	i += ft_printf("|OLD %p|\n", "OLA");
	ft_printf("Result NEW = %d\n", i);

	ft_printf("\nTESTE PARA %%x\n\n");
	i = printf("|OLD %x|\n", NULL);
	printf("Result OLD NULL = %d\n", i);
	i += printf("|OLD %x|\n", 123);
	i += printf("|OLD %x|\n", -123);
	i += printf("|OLD %x|\n", "OLA");
	printf("Result OLD = %d\n\n", i);
	i = ft_printf("|NEW %x|\n", NULL);
	ft_printf("Result NEW NULL = %d\n", i);
	i += ft_printf("|NEW %x|\n", 123);
	i += ft_printf("|NEW %x|\n", -123);
	i += ft_printf("|OLD %x|\n", "OLA");
	ft_printf("Result NEW = %d\n", i);

	ft_printf("\nTESTE PARA %%X\n\n");
	i = printf("|OLD %X|\n", NULL);
	printf("Result OLD NULL = %d\n", i);
	i += printf("|OLD %X|\n", 123);
	i += printf("|OLD %X|\n", -123);
	i += printf("|OLD %X|\n", "OLA");
	printf("Result OLD = %d\n\n", i);
	i = ft_printf("|NEW %X|\n", NULL);
	ft_printf("Result NEW NULL = %d\n", i);
	i += ft_printf("|NEW %X|\n", 123);
	i += ft_printf("|NEW %X|\n", -123);
	i += ft_printf("|OLD %X|\n", "OLA");
	ft_printf("Result NEW = %d\n", i);

	ft_printf("\nTESTE PARA %%%%\n\n");
	printf("OLD = %%\n");
	printf("OLD = %%%%\n\n");
	ft_printf("NEW = %%\n");
	ft_printf("NEW = %%%%\n");
	return (0);
}*/
