/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:13:37 by jinam             #+#    #+#             */
/*   Updated: 2023/04/19 16:46:33 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ifile.hpp"

void	ft_exit(void)
{
	system("leaks Sed");
}

int	main(int argc, char **argv)
{
	Ifile	input(argv[1]);

	if (argc != 4)
		return (1);

	input.read();
	input.replace(argv[2], argv[3]);
	input.write(argv[1]);
	return (0);
}