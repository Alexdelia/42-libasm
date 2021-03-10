/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:51:44 by adelille          #+#    #+#             */
/*   Updated: 2021/03/10 17:54:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

#define MAG		"\033[0;35m"
#define BMAG	"\033[1;35m"
#define IMAG	"\033[3;35m"
#define BIMAG	"\033[1;3;35m"
#define RED		"\033[1;31m"
#define	GRN		"\033[1;32m"
#define DEF		"\033[0m"

#define STR		"A little turtle hug a racoon."
#define STR2	"A little turtle meet a racoon."

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int		ft_ps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

int		ft_psc(char *str, char *color)
{
	write(1, color, strlen(color));
	write(1, str, strlen(str));
	write(1, DEF, strlen(DEF));
	return (strlen(color) + strlen(str) + strlen(DEF));
}

void	t_strlen(void)
{
	ft_psc("  ~~ ft_strlen ~~\n", IMAG);
	printf("\ninput:\t\"%s\"\n your:\t%zu\n  ref:\t%lu\t%s\n\n", STR, ft_strlen(STR), strlen(STR), (ft_strlen(STR) == strlen(STR) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	printf("\ninput:\t\"%s\"\n your:\t%zu\n  ref:\t%lu\t%s\n\n", "", ft_strlen(""), strlen(""), (ft_strlen("") == strlen("") ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
}

void	t_strcmp(void)
{
	ft_psc("  ~~ ft_strcmp ~~\n", IMAG);
	printf("\ninput 1:\t\"%s\"\ninput 2:\t\"%s\"\n   your:  %d\n    ref:  %d\t%s\n\n", STR, STR, ft_strcmp(STR, STR), strcmp(STR, STR), (ft_strcmp(STR, STR) == strcmp(STR, STR) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	printf("\ninput 1:\t\"%s\"\ninput 2:\t\"%s\"\n   your:  %d\n    ref:  %d\t%s\n\n", STR, STR2, ft_strcmp(STR, STR2), strcmp(STR, STR2), (ft_strcmp(STR, STR2) == strcmp(STR, STR2) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	printf("\ninput 1:\t\"%s\"\ninput 2:\t\"%s\"\n   your:  %d\n    ref:  %d\t%s\n\n", "", "", ft_strcmp("", ""), strcmp("", ""), (ft_strcmp("", "") == strcmp("", "") ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	printf("\ninput 1:\t\"%s\"\ninput 2:\t\"%s\"\n   your:  %d\n    ref:  %d\t%s\n\n", "", STR, ft_strcmp("", STR), strcmp("", STR), (ft_strcmp("", STR) == strcmp("", STR) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));

}

void	t_strcpy(void)
{
	ft_psc("  ~~ ft_strcpy ~~\n", IMAG);
}

int		main(void)
{
	ft_psc("\n\t---\t Starting\t---\t\n", BIMAG);
	t_strlen();
	t_strcmp();
	/*t_strcpy();
	t_write();
	t_read();
	t_strdup();*/
	// ft_psc("\n\t---\t  Bonus \t---\t\n", BIMAG);
	ft_psc("\n\t---\t   Done  \t---\t\n\n", BIMAG);
	return (0);
}
