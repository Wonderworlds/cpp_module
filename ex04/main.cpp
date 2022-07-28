/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:04:25 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 21:22:36 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define BUFFER_SIZE 4096

void	error_arg(void)
{
	std::cerr << "error: invalid arg" << std::endl;
	return ;
}

void	error_file(void)
{
	std::cerr << "error: unable to open file" << std::endl;
	return ;
}

void	error_read(void)
{
	std::cerr << "error: read" << std::endl;
	return ;
}

void	__sed(const char *from, const char *to, std::string *str)
{
	std::size_t	found;
	std::string	needle = from;
	std::string	replaceWith = to;

	if (needle.size() == 0)
		return ;
	while ((found = str->find(needle)) != std::string::npos)
	{
		str->erase(found, needle.size());
		str->insert(found, replaceWith);
	}
}

int	__sed_file(const char *name, const char *from, const char *to, std::ifstream *file)
{
	std::ofstream ofs;
	std::string	str;
	std::string	output = name;
	char		buffer[BUFFER_SIZE];
	bool		loop = true;

	output.append(".replace", 8);
	ofs.open(output.c_str(), std::ofstream::out);
	if (!ofs.is_open())
		return (error_file(), 1);
	while (loop)
	{
		file->read(buffer, BUFFER_SIZE - 1);
		if (file->rdstate() != 0)
			loop = false;
		if (file->gcount() == 0)
			return (ofs.close(), error_read(), 1);
		str.assign(buffer, buffer + file->gcount());
		__sed(from, to, &str);
		ofs << str;
	}
	ofs.close();
	return (0);
}

int	main(int ac, const char **av)
{
	std::ifstream	ifs;

	if (ac != 4)
		return (error_arg(), 1);
	ifs.open(av[1], std::ifstream::in);
	if (!ifs.is_open())
		return (error_file(), 1);
	if (__sed_file(av[1], av[2], av[3], &ifs))
		return (ifs.close(), 1);
	ifs.close();
	return (0);
}