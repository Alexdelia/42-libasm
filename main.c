/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:51:44 by adelille          #+#    #+#             */
/*   Updated: 2021/03/17 01:16:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

#define MAG		"\033[0;35m"
#define BMAG	"\033[1;35m"
#define IMAG	"\033[3;35m"
#define BIMAG	"\033[1;3;35m"
#define RED		"\033[1;31m"
#define	GRN		"\033[1;32m"
#define SBLU	"\033[5;3;34m"
#define DEF		"\033[0m"

#define STR		"A little turtle hug a racoon."
#define STR2	"A little turtle meet a racoon."

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

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
	printf("\ninput 1:\t\"%s\"\ninput 2:\t\"%s\"\n   your:  %d\n    ref:  %d\t%s\n\n", STR, STR2, ft_strcmp(STR, STR2), strcmp(STR, STR2), (ft_strcmp(STR, STR2) == strcmp(STR, STR2) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[1;3;33m"));
	printf("\ninput 1:\t\"%s\"\ninput 2:\t\"%s\"\n   your:  %d\n    ref:  %d\t%s\n\n", "", "", ft_strcmp("", ""), strcmp("", ""), (ft_strcmp("", "") == strcmp("", "") ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	printf("\ninput 1:\t\"%s\"\ninput 2:\t\"%s\"\n   your:  %d\n    ref:  %d\t%s\n\n", "", STR, ft_strcmp("", STR), strcmp("", STR), (ft_strcmp("", STR) == strcmp("", STR) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));

}

void	t_strcpy(void)
{
	char	y_dest[30];
	char	r_dest[30];
	//char	s_dest[10];
	//char	sr_dest[10];
	char	*str;

	ft_psc("  ~~ ft_strcpy ~~\n", IMAG);
	str = STR;
	printf("\ninput:\t\"%s\"\t\t(dest[30])\n your:\t%s\n  ref:\t%s\t%s\n\n", str, ft_strcpy(y_dest, str), strcpy(r_dest, str), (ft_strcmp(y_dest, r_dest) == 0 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	str = "";
	printf("\ninput:\t\"%s\"\t\t\t\t\t(dest[30])\n your:\t%s\n  ref:\t%s\t%s\n\n", str, ft_strcpy(y_dest, str), strcpy(r_dest, str), (ft_strcmp(y_dest, r_dest) == 0 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	// negliged case
	/*str = STR2;
	printf("\ninput:\t\"%s\"\t(dest[10])\n your:\t%s\n  ref:\t%s\t%s\n\n", str, ft_strcpy(s_dest, str), strcpy(sr_dest, str), (ft_strcmp(y_dest, r_dest) == 0 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m\t\033[3;33mThis case can be negliged\033[0m"));*/
}

void	t_write(void)
{
	char	*s;

	ft_psc("  ~~ ft_write ~~\n", IMAG);
	s = STR;
	ft_psc(" output of write:\n", "\033[5;3;34m");
	printf("\n\ninput:\t\"%s\"\n your:\t%zu\n  ref:\t%zd\t%s\n\n", s, ft_write(1, s, ft_strlen(s)), write(1, s, ft_strlen(s)), ((size_t)ft_write(1, s, ft_strlen(s)) == (size_t)write(1, s, ft_strlen(s)) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	s = STR2;
	ft_psc(" output of write:\n", "\033[5;3;34m");
	printf("\n\ninput:\t\"%s\"\t(fd = 4)\n your:\t%zu\n  ref:\t%zd\t%s\n\n", s, ft_write(4, s, ft_strlen(s)), write(4, s, ft_strlen(s)), ((size_t)ft_write(4, s, ft_strlen(s)) == (size_t)write(4, s, ft_strlen(s)) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	s = "";
	ft_psc(" output of write:\n", "\033[5;3;34m");
	printf("\n\ninput:\t\"%s\"\n your:\t%zu\n  ref:\t%zd\t%s\n\n", s, ft_write(1, s, ft_strlen(s)), write(1, s, ft_strlen(s)), ((size_t)ft_write(1, s, ft_strlen(s)) == (size_t)write(1, s, ft_strlen(s)) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	s = STR;
	ft_psc(" output of write:\n", "\033[5;3;34m");
	printf("\n\ninput:\t\"%s\"\t\t(underwriting)\n your:\t%zu\n  ref:\t%zd\t%s\n\n", s, ft_write(1, s, 10), write(1, s, 10), ((size_t)ft_write(1, s, 10) == (size_t)write(1, s, 10) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	s = STR2;
	ft_psc(" output of write:\n", "\033[5;3;34m");
	printf("\n\ninput:\t\"%s\"\t(overwriting)\n your:\t%zu\n  ref:\t%zd\t%s\n\n", s, ft_write(1, s, 35), write(1, s, 35), ((size_t)ft_write(1, s, 35) == (size_t)write(1, s, 35) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
}

void	t_read(void)
{	
	int		fd;
	int		tmp;
	char	buffer[1025];

	ft_psc("  ~~ ft_read ~~\n", IMAG);
	ft_psc("\n Initialising read.txt file", SBLU);
	fd = open("read.txt", O_CREAT);
	ft_write(fd, STR, ft_strlen(STR));
	ft_ps("\tDone\n");
	
	buffer[1024] = '\0';
	printf("\n\n input:\t%s\n  your:\t%zu\n", "ft_read(fd, buffer, 1024)\t(fd = -1)", ft_read(fd, buffer, 1024));
	printf("output:\t%s\n", buffer);
	printf("   ref:\t%zd\n", read(fd, buffer, 1024));
	printf("output:\t%s", buffer);
	printf("\t%s\n\n", (ft_read(fd, buffer, 1024) == ft_read(fd, buffer, 1024) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));

	buffer[10] = '\0';
	printf("\n\n input:\t%s\n  your:\t%zu\n", "ft_read(fd, buffer, 10)\t(buffer[10] = '\\0')", ft_read(fd, buffer, 10));
	printf("output:\t%s\n", buffer);
	printf("   ref:\t%zd\n", read(fd, buffer, 10));
	printf("output:\t%s", buffer);
	printf("\t%s\n\n", (ft_read(fd, buffer, 10) == ft_read(fd, buffer, 10) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	
	buffer[0] = '\0';
	printf("\n\n input:\t%s\n  your:\t%zu\n", "ft_read(fd, buffer, 29)\t(buffer[0] = '\\0')", ft_read(fd, buffer, 29));
	printf("output:\t%s\n", buffer);
	printf("   ref:\t%zd\n", read(fd, buffer, 29));
	printf("output:\t%s", buffer);
	printf("\t%s\n\n", (ft_read(fd, buffer, 29) == ft_read(fd, buffer, 29) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	
	buffer[29] = '\0';
	tmp = fd;
	fd = -1;
	printf("\n\n input:\t%s\n  your:\t%zu\n", "ft_read(fd, buffer, 29)\t(fd = -1)", ft_read(fd, buffer, 29));
	printf("output:\t%s\n", buffer);
	printf("   ref:\t%zd\n", read(fd, buffer, 29));
	printf("output:\t%s", buffer);
	printf("\t%s\n\n", (ft_read(fd, buffer, 29) == ft_read(fd, buffer, 29) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	close(tmp);
	
	ft_ps("fd = 0, write something please\n");
	fd = 0;
	printf("\n\n input:\t%s\n  your:\t%zu\n", "ft_read(fd, buffer, 100)\t(fd = 1)", ft_read(fd, buffer, 100));
	printf("output:\t%s\n", buffer);
	printf("   ref:\t%zd\n", read(fd, buffer, 100));
	printf("output:\t%s", buffer);
	printf("\t%s\n\n", (ft_read(fd, buffer, 100) == ft_read(fd, buffer, 100) ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
}

void	t_strdup(void)
{
	char	*str;

	ft_psc("  ~~ ft_strdup ~~\n", IMAG);
	str = STR;
	printf("\ninput:\t\"%s\"\n your:\t%s\n  ref:\t%s\t%s\n\n", str, ft_strdup(str), strdup(str), (ft_strcmp(ft_strdup(str), strdup(str)) == 0 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	str = "";
	printf("\ninput:\t\"%s\"\n your:\t%s\n  ref:\t%s\t%s\n\n", str, ft_strdup(str), strdup(str), (ft_strcmp(ft_strdup(str), strdup(str)) == 0 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
}

int		ft_plist(t_list *list)
{
	ft_ps("\n");
	while (list)
	{
		ft_ps(list->data);
		list = list->next;
		if (list)
			ft_psc("\n -~-~-~-~-~-~-~-\n", SBLU);
	}
	ft_ps("\n");
	return (0);
}

void	t_bonus(void)
{
	t_list	list;
	t_list	list_next;
	t_list	list_last;
	
	list.data = strdup(STR);
	list.next = &list_next;
	list_next.data = strdup("         ,\\\n         \\\\\\,_\n          \\` ,\\\n     __,.-\" =__)\n   .\"        )\n,_/   ,    \\/\\_\n\\_|    )_-\\ \\_-`\n   `-----` `--`");
	list_next.next = &list_last;
	list_last.data = strdup("Rabbits are nice.");
	list_last.next = NULL;
	
	ft_psc("  ~~ ft_list_size ~~\n\n", IMAG);
	ft_ps("input:\n");
	ft_plist(&list);
	printf("\n your:\t%d\n  ref:\t%d\t%s\n\n", ft_list_size(&list), 3, (ft_list_size(&list) == 3 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	printf("input:\t(second of the list)\n your:\t%d\n  ref:\t%d\t%s\n\n", ft_list_size(&list_next), 2, (ft_list_size(&list_next) == 2 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	printf("input:\t(last of the list)\n your:\t%d\n  ref:\t%d\t%s\n\n", ft_list_size(&list_last), 1, (ft_list_size(&list_last) == 1 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	ft_ps("input:\t(NULL)");
	printf("\n your:\t%d\n  ref:\t%d\t%s\n\n", ft_list_size(NULL), 0, (ft_list_size(NULL) == 0 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
	
	ft_psc("  ~~ ft_list_push_front ~~\n", IMAG);
	t_list *push = &list;
	ft_list_push_front(&push, strdup("I want to be the first."));
	ft_ps("\noutput:\n");
	printf("\n input:\t\"%s\"\n  next:\t%p\t%s\n  size:\t%d\t\t%s\n\t\t\t%s\n", push->data, push->next, (push->next == &list ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"), ft_list_size(push), (ft_list_size(push) == 4 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"), (ft_plist(push) == 0 ? "\033[1;32m[OK]\033[0m" : "\033[1;5;31m[KO]\033[0m"));
}

int		main(void)
{
	ft_psc("\n\t---\t Starting\t---\t\n", BIMAG);
	t_strlen();
	t_strcmp();
	t_strcpy();
	t_write();
	t_read();
	t_strdup();
	ft_psc("\n\t---\t  Bonus \t---\t\n\n", BIMAG);
	t_bonus();
	ft_psc("\n\t---\t   Done  \t---\t\n\n", BIMAG);
	return (0);
}
