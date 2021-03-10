/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:51:44 by adelille          #+#    #+#             */
/*   Updated: 2021/03/10 16:41:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAG		"\033[35m"
#define BMAG	"\033[0;35m"
#define DEF		"\033[0m"

int		ft_ps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

void	t_strlen(void)
{
	
}

int		main(void)
{
	ft_psc("BMAG\n\t---\tStarting\t---\t\nDEF");
	/*t_strlen();
	t_strcmp();
	t_strcpy();
	t_write();
	t_read();
	t_strdup();*/
	ft_psc("\n\t---\t  Done  \t---\t\n");
	return (0);
}
