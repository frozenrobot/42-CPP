#include <iostream>
#include "contact.class.hpp"
#include <iomanip>

Phonebook phonebook;

std::string format_string(std::string str)
{
    if (str.length() <= 10)
    {
        while (str.length() < 10)
            str = str.insert(0, " ");
    }
    else
        str = str.insert(9, ".");
        str = str.substr(0, 10);
    return str;
}

void display_contacts(void)
{
    int i;

    i = 0;
    std::cout << "     Index|First Name| Last Name|  Nickname" <<std::endl;
    while (phonebook.list[i].is_empty == 0 && i < 8)
    {
        std::cout << std::setfill (' ') << std::setw (10);
        std::cout << i+1 << "|";
        std::cout << format_string(phonebook.list[i].getFirstName()) << "|";
        std::cout << format_string(phonebook.list[i].getLastName()) << "|";
        std::cout << format_string(phonebook.list[i].getNickname()) << std::endl;
        i++;
    }
}

void move_contacts(void)
{
    int i;

    i = 0;
    while (i < 7)
    {
        phonebook.list[i].setFirstName(phonebook.list[i+1].getFirstName());
        phonebook.list[i].setLastName(phonebook.list[i+1].getLastName());
        phonebook.list[i].setNickname(phonebook.list[i+1].getNickname());
        phonebook.list[i].setPhoneNumber(phonebook.list[i+1].getPhoneNumber());
        phonebook.list[i].setDarkestSecret(phonebook.list[i+1].getDarkestSecret());
        i++;
    }
}

void search(int contact_count)
{
    int i;
    std::string str;

    display_contacts();
    while (1)
    {
        std::cout << "Enter index: ";
        std::getline(std::cin, str, '\n');
        i = atoi(str.c_str());
        if (str.size() == 1 && str.at(0) >= '1' && str.at(0)+1 <= contact_count+'1')
            break;
        else
            std::cout << "Invalid index, try again" << std::endl;
    }
    phonebook.list[i-1].print_contact();
    return ;
}

void add(int contact_count)
{
    int i;

    if (contact_count == 8)
    {
        move_contacts();
        i = 7;
    }
    else
        i = contact_count;
    phonebook.list[i].assign_contact();
}

int set_command(void)
{
    int command;
    std::string input;

    command = 0;
    std::cout << "Enter command: ";
    std::getline(std::cin, input, '\n');
    if (input.compare("ADD") == 0)
        command = 1;
    else if (input.compare("SEARCH") == 0)
        command = 2;
    else if (input.compare("EXIT") == 0)
        command = 3;
    return (command);
}

int main(void)
{
    int command;
    int contact_count;

    command = 0;
    contact_count = 0;
    std::cout << "************** PHONEBOOK **************\n";
    std::cout << "Available actions: ADD, SEARCH, EXIT\n";
    std::cout << "=======================================\n";
    while (command != 3)
    {
        command = set_command();
        if (command == 1)
        {
            add(contact_count);
            if (contact_count < 8)
                contact_count++;
        }
        else if (command == 2)
        {
            if (contact_count == 0)
                std::cout << "No Contacts" << std::endl;
            else
                search(contact_count);
        }
    }
}