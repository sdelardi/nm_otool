/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:30:52 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/25 11:41:36 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include "libft.h"
# include <stdio.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>

/*
**Nm functions
*/
int		main(int ac, char **av);
void	ft_nm(char *ptr);
void	handle_64(char *ptr);
void	print_output(int nsyms, int symoff, int stroff, char *ptr);

#endif
