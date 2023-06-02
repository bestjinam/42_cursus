/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:11:31 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 19:01:15 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#define CAT_TYPE std::string("Cat");

class Cat : public Animal
{
private:
    Brain* _brain;

public:
    Cat();
    ~Cat();
    Cat(const Cat& ref);
    Cat& operator=(const Cat& ref);
    void makeSound(void) const;
    std::string getIdea(int idx);
    void setIdea(std::string think);
    Brain& getBrain(void);
};
#endif
