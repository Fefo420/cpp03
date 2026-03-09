/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 22:21:16 by fefo              #+#    #+#             */
/*   Updated: 2025/08/12 23:37:30 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " created." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target)
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
        std::cout << this->name << " energy points left: " << this->energyPoints << std::endl;
    }
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints > 0)
    {
        if (this->hitPoints < amount)
            this->hitPoints = 0;
        else
            this->hitPoints -= amount;
    }
    std::cout << this->name << " hp: " << this->hitPoints << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount)
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
        this->hitPoints += amount;
        this->energyPoints -= 1;
        std::cout << this->name << " Healed himself by " << amount 
            << "! New Health: " << this->hitPoints << std::endl;
        std::cout << this->name << " energy points left: " << this->energyPoints << std::endl;
    }
}
