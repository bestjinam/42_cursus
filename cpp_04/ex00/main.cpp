/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:22:40 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 14:17:37 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << std::endl;
    std::cout << ">> cat sound << " << std::endl;
    i->makeSound(); // will output the cat sound! j->makeSound();
    std::cout << ">> animal sound << " << std::endl;
    meta->makeSound();
    std::cout << std::endl;
    {
        std::cout << std::endl;
        std::cout << ">> WRONG ANIMAL SOUNDS << " << std::endl;
        WrongAnimal* w_meta = new WrongAnimal();
        WrongAnimal* w_cat = new WrongCat();

        std::cout << ">> wrong cat sound << " << std::endl;
        w_cat->makeSound();
        std::cout << ">> wrong animal sound <<" << std::endl;
        w_meta->makeSound();
        std::cout << std::endl;

        delete w_meta;
        delete w_cat;

        std::cout << std::endl;
    }
    delete meta;
    delete j;
    delete i;
}
