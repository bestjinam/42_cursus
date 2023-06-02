/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:11:31 by jinam             #+#    #+#             */
/*   Updated: 2023/06/02 12:47:22 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>
#define CAT_TYPE std::string("Cat");

class Cat : public Animal
{
private:
public:
    Cat();
    ~Cat();
    Cat(const Cat& ref);
    Cat& operator=(const Cat& ref);
    void makeSound(void) const;
};
#endif
