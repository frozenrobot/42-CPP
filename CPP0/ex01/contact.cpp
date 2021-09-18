#include "contact.class.hpp"

Contact::Contact(void)
{
    this->is_empty = 1;
    clear();
}

void Contact::clear(void)
{
    this->is_empty = 1;
    this->setFirstName("");
    this->setLastName("");
    this->setNickname("");
    this->setPhoneNumber("");
    this->setDarkestSecret("");
}

void Contact::assign_contact(void)
{
    std::string entries;

    this->is_empty = 0;
    std::cout << "FIRST NAME: ";
    std::getline(std::cin, entries, '\n');
    this->setFirstName(entries);
    std::cout << "LAST NAME: ";
    std::getline(std::cin, entries, '\n');
    this->setLastName(entries);
    std::cout << "NICKNAME: ";
    std::getline(std::cin, entries, '\n');
    this->setNickname(entries);
    std::cout << "PHONE NUMBER: ";
    std::getline(std::cin, entries, '\n');
    this->setPhoneNumber(entries);
    std::cout << "DARKEST SECRET: ";
    std::getline(std::cin, entries, '\n');
    this->setDarkestSecret(entries);
    std::cout << "CONTACT ADDED" << std::endl;
}

void Contact::print_contact(void)
{
    std::cout << "-----" << std::endl;
    std::cout << "First Name: " << this->getFirstName() << std::endl;
    std::cout << "Last Name: " << this->getLastName() << std::endl;
    std::cout << "Nickname: " << this->getNickname() << std::endl;
    std::cout << "Phone Number: " << this->getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->getDarkestSecret() << std::endl;
    std::cout << "-----" << std::endl;
}

// SETTERS

void Contact::setFirstName(std::string first_name)
{
    this->_first_name = first_name;
}

void Contact::setLastName(std::string last_name)
{
    this->_last_name = last_name;
}

void Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number)
{
    this->_phone_number = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
    this->_darkest_secret = darkest_secret;
}

// GETTERS

std::string Contact::getFirstName(void)
{
    return this->_first_name;
}

std::string Contact::getLastName(void)
{
    return this->_last_name;
}

std::string Contact::getNickname(void)
{
    return this->_nickname;
}

std::string Contact::getPhoneNumber(void)
{
    return this->_phone_number;
}

std::string Contact::getDarkestSecret(void)
{
    return this->_darkest_secret;
}