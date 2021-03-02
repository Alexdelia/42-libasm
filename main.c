/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:51:44 by adelille          #+#    #+#             */
/*   Updated: 2021/03/02 14:15:54 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int ac, char **av)
{
	int		i;
	char	s1[256];
	char	s2[0];
	char	s3[3] = "oui";
	char	s4[10] = "0123456789";

	if (ac > 1)
		s1 = av[1];
	 else
	 {
		 i = 0;
		 while (s1[i])
		 {
			s1[i] = (char)(i + 0);
		 }
	 }
	 printf("\tStart:");

	 printf("ft_strlen:\n");
	 printf("Me\t%d\tLibc%d\tInput:%.10s (cut at 10 char)\n", ft_strlen(s1), strlen(s1), s1);
	 printf("Me\t%d\tLibc%d\tInput:%s\n", ft_strlen(s2), strlen(s2), s2);
	 printf("Me\t%d\tLibc%d\tInput:%s\n", ft_strlen(s3), strlen(s3), s3);
	 printf("Me\t%d\tLibc%d\tInput:%s\n", ft_strlen(s4), strlen(s4), s4);
	 
	 return (0);
}
