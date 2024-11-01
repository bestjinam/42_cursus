/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-2.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jh <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:11:06 by jh                #+#    #+#             */
/*   Updated: 2023/04/13 20:25:02 by jh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef struct s_animal
{
	char	name[30];
	int		age;
	int		health;
	int		food;
	int		clean;
}	t_animal;

void	create_animal(t_animal *animal)
{
	std::cout << "동물의 이름? : ";
	std::cin >> animal->name;
	std::cout << "동물의 나이? : ";
	std::cin >> animal->age;
	animal->health = 100;
	animal->clean = 100;
	animal->food = 100;
}

void	play(t_animal *animal)
{
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void	one_day_pass(t_animal *animal)
{
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void	show_stat(t_animal *animal)
{
	std::cout << animal->name << "의 상태" << std::endl;
	std::cout << "체력 : " << animal->health << std::endl;
	std::cout << "배부름 : " << animal->food << std::endl;
	std::cout << "청결 : " << animal->clean << std::endl;
}

int	main(void)
{
	t_animal	*list[10];
	int			animal_num;

	animal_num = 0;
	while (1)
	{
		std::cout << "1. 동물 추가하기 " << std::endl;
		std::cout << "2. 놀기" << std::endl;
		std::cout << "3. 상태보기" << std::endl;

		int input;

		std::cin >> input;
		switch (input)
		{
			int	play_with;
			case 1:
				list[animal_num] = new t_animal;
				create_animal(list[animal_num]);
				animal_num ++;
				break ;
			case 2:
				std::cout << "누구랑 놀계? : ";
				std::cin >> play_with;
				if (play_with < animal_num)
					play(list[play_with]);
				break ;
			case 3:
				std::cout << "누구껄 보게? : ";
				std::cin >> play_with;
				if (play_with < animal_num)
					show_stat(list[play_with]);
				break ;
		}
		for (int i = 0; i != animal_num; i ++)
		{
			one_day_pass(list[i]);
		}
	}
	for (int i = 0; i != animal_num; i++)
	{
		delete list[i];
	}
	return (0);
}
