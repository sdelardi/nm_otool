/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:12:12 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/26 13:30:18 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void	print_output(int nsyms, int symoff, int stroff, char *ptr)
{
	int				i;
	char			*stringtable;
	struct nlist_64	*array;

	array = (void *)ptr + symoff;
	stringtable = (void *)ptr + stroff;
	i = 0;
	while (i < nsyms)
	{
		ft_putstr(stringtable + array[i].n_un.n_strx);
		ft_putchar('\n');
		i++;
	}
}

void	handle_64(char *ptr)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	header = (struct mach_header_64 *)ptr;
	ncmds = header->ncmds;
	i = 0;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}

void	ft_nm(char *ptr)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)ptr;
	if (magic_number == MH_MAGIC_64)
		handle_64(ptr);
	else
		ft_putstr("This is not a 64 bit binary\n");
}



int		open_args(int ac, int i, char **av)
{
	int			fd;
	char		*ptr;
	struct stat	buf;

	if ((fd = open(av[i], O_RDONLY)) < 0)
	{
		ft_putstr_fd(2, "ft_nm: ");
		ft_putstr_fd(2, av[i]);
		ft_putstr_fd(2, ": Can't access this file, please verify the file
		exists and you have read rights on it\n");
		return (1);
	}
	if (fstat(fd, &buf) < 0)
		return (1);
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
	== MAP_FAILED)
		return (1);
	if (ac > 2)
	{
		ft_putstr("\n");
		ft_putstr(av[i]);
		ft_putstr("\n");
		return (1);
	}
	ft_nm(ptr);
	if (munmap(ptr, buf.st_size) < 0)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int i;

	if (ac < 2)
	{
		av[1] = ft_strdup("a.out");
		ac = 2;
	}
	i = 1;
	while (i < ac)
	{
		if (!open_memory(ac, i, av))
			break ;
		i++;
	}
	return (0);
}
