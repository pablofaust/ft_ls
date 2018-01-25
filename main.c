/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:24:44 by pfaust            #+#    #+#             */
/*   Updated: 2018/01/25 18:32:01 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

char	*ft_print_type(unsigned char d_type)
{
	char	*type;

	if (d_type == DT_UNKNOWN)
		type = "inconnu";
	if (d_type == DT_REG)
		type = "simple fichier";
	if (d_type == DT_DIR)
		type = "dossier";
	if (d_type == DT_FIFO)
		type = "FIFO";
	if (d_type == DT_SOCK)
		type = "socket";
	if (d_type == DT_CHR)
		type = "character device";
	if (d_type == DT_BLK)
		type = "block device";
	if (d_type == DT_LNK)
		type = "lien symbolique";
	return (type);
}

char	*ft_print_mode(mode_t st_mode)
{
	char	*mode;

	if (st_mode == S_IRWXU)
		mode = "rwx------";
	return (mode);
}

int		main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*dirent;
	struct stat		stattmp;

	if (argc != 2)
	{
		printf("[usage] : filename\n");
		return (0);
	}
	dir = NULL;
	if (!(dir = opendir(argv[1])))
		perror("Error :");
	while ((dirent = readdir(dir)) != NULL)
	{
		printf("Nom : %s\n", dirent->d_name);
		printf("Type : %s\n", ft_print_type(dirent->d_type));
		if (stat((const char*)dirent->d_name, &stattmp) != 0)
			perror("");
		printf("st_mode : %hu\n", stattmp.st_mode);
		//printf("Modes : %s\n", ft_print_mode(stattmp->st_mode));
		printf("\n");
	}
	return (0);
}
