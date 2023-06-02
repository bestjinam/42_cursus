/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:15:19 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 19:02:04 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#define DOG_TYPE std::string("Dog");

class Dog : public Animal
{
private:
    Brain* _brain;

public:
    Dog();
    ~Dog();
    Dog(const Dog& ref);
    Dog& operator=(const Dog& ref);
    void makeSound(void) const;
    std::string getIdea(int idx);
    void setIdea(std::string think);
    Brain& getBrain(void);
};
#endif
