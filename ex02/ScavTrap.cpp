/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:39:34 by fefo              #+#    #+#             */
/*   Updated: 2025/08/12 22:54:49 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " was created" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "Default ScavTrap created." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " Got vaporised" << std::endl;  
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0)
        {
            std::cout << this->name << " left this world..." << std::endl;
            return ;
        }
        else if (this->energyPoints == 0)
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

void ScavTrap::guardGate()
{
    std::cout << this->name << ": Gate keeper mode. Activated!" << std::endl;
}