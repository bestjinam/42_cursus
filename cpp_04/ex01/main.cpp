/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:22:40 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 21:14:16 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

void ft_exit(void)
{
    system("leaks --list Polymorphism");
}

int main(int argc, char** argv)
{
    if (argc != 2)
        return 1;

    const std::string argv_str = argv[1];
    atexit(ft_exit);
    if (argv_str.compare("1") == 0)
    {
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        std::cout << ">> check brain ideas contents (deep copy) <<" << std::endl;
        const std::string str = "I love cookie!";
        for (int i = 0; i != 100; i++)
        {
            ((Dog*)dog)->setIdea(str + std::to_string(i));
            std::cout << "in dog's brain : " + ((Dog*)dog)->getIdea(i) << std::endl;
        }
        Dog cp_dog = *(Dog*)dog;
        std::cout << "dog's brain adress : ";
        std::cout << &((Dog*)dog)->getBrain() << std::endl;
        std::cout << "cp_dog's brain adress : ";
        std::cout << &(cp_dog).getBrain() << std::endl;

        for (int i = 0; i != 100; i++)
        {
            std::cout << "in copy dog's brain : " + ((Dog*)dog)->getIdea(i) << std::endl;
        }

        // delete dog and cat
        std::cout << "delete :dog: and :cat:" << std::endl;
        delete dog;
        delete cat;
    }
    else if (argv_str.compare("2") == 0)
    {
        std::cout << "make an array of Animal objects" << std::endl;
        Animal* ani_arr[10];
        for (int i = 0; i != 10; i++)
        {
            if (i > 4)
                ani_arr[i] = new Dog();
            else
                ani_arr[i] = new Cat();
        }
        std::cout << "delete ani_arr" << std::endl;
        for (int i = 0; i != 10; i++)
        {
            delete ani_arr[i];
        }
    }
    else if (argv_str.compare("3") == 0)
    {
        Dog dog;
        Cat cat;
        Animal meta;
        dog.makeSound();
        cat.makeSound();
        Animal(dog).makeSound();
    }
}
