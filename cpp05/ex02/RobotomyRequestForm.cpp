/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:31:53 by nuferron          #+#    #+#             */
/*   Updated: 2024/04/16 20:41:17 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm(145, 137) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm(145, 137), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s): AForm(s.getName(), s.getReqSign(), s.getReqExe()) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}
