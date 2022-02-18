#include "AMateria.hpp"

int main()
{
    IMateriaSource* msource = new MateriaSource();
    msource->learnMateria(new Ice());
    msource->learnMateria(new Cure());
    msource->learnMateria(new Ice());
    msource->learnMateria(new Cure());
    msource->learnMateria(new Ice());
    msource->learnMateria(new Cure());
    
    ICharacter* alice = new Character("alice");
    ICharacter* bob = new Character("bob");
    
    AMateria* m1 = NULL;
    AMateria* m2 = msource->createMateria("cure");
    m1 = msource->createMateria("ice");
    alice->equip(m1);
    bob->equip(m2);
    std::cout << "Alice's Materia: " << m1->getType() << std::endl;
    std::cout << "Bob's Materia: " << m2->getType() << std::endl;
    
    alice->use(0, *bob);
    bob->use(0, *alice);
    bob->use(1, *alice);
    bob->use(-1, *alice);

    delete alice;
    delete bob;
    delete msource;
}