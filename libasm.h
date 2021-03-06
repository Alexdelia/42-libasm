/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:05:16 by adelille          #+#    #+#             */
/*   Updated: 2021/03/06 13:04:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

	/* Help to understand ASM: https://en.wikibooks.org/wiki/X86_Assembly */
# include <stdio.h>

size_t	ft_strlen(char *str);
size_t	ft_write(int fd, char *str, int n);
size_t	ft_read(int fd, char *str, int n);
int		ft_strcmp(char *s1, char *s2);

#endif
