/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:38:40 by jinam             #+#    #+#             */
/*   Updated: 2023/06/04 01:26:03 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "string"
class Brain
{
private:
    std::string _ideas[100];
    int _idx;

public:
    Brain();
    ~Brain();
    Brain(const Brain& ref);
    Brain& operator=(const Brain& ref);
    std::string getIdea(int idx);
    void setIdea(std::string think);
};

#endif
