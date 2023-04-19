/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:13:37 by jinam             #+#    #+#             */
/*   Updated: 2023/04/18 20:31:27 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ifile.hpp"

int	main(int argc, char **argv)
{

	if (argc != 4)
		return (1);

	Ifile	input(argv[1]);
	input.read();
	input.replace(argv[2], argv[3]);
}
