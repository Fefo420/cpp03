/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:39:34 by fefo              #+#    #+#             */
/*   Updated: 2025/08/12 23:27:31 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << this->name << " is between us!" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("Default FragTrap")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Default FragTrap created with hitpoints = " << this->hitPoints << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " Got vaporised" << std::endl;  
}

void FragTrap::attack(const std::string& target)
{
        if (this->hitPoints <= 0)
        {
            std::cout << this->name << " left this world..." << std::endl;
            return ;
        }
        else if (this->energyPoints <= 0)
        {
            std::cout << this->name << " doesn t have energy to attack..." << std::endl;
            return ;
        }
        else
        {
            std::cout << this->name << " attacks " << target << ", causing "
                    << attackDamage << " points of damage!" << std::endl;
            this->energyPoints -= 1;
            std::cout << "energy points left: " << this->energyPoints << std::endl;
        }
}

void FragTrap::highFivesGuys(void)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
        std::cout << this->name << ": High fives guys!" << std::endl;
    else
        std::cout << this->name << " is \"not able\" to high five anyone..." << std::endl;
}