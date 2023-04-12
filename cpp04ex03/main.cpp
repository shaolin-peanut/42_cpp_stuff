//
// Created by supersayan on 4/6/23.
//

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	// Creating a MateriaSource and learning two types of materia: Ice and Cure
	MateriaSource materiaSource;
	materiaSource.learnMateria(new Ice());
	materiaSource.learnMateria(new Cure());

	// Creating two characters: Alice and Bob
	Character alice("Alice");
	Character bob("Bob");

	// Equipping Alice with Ice and Cure materias
	alice.equip(materiaSource.createMateria("ice"));
	alice.equip(materiaSource.createMateria("cure"));

	// Alice uses Ice materia to attack Bob
	std::cout << alice.getName() << " attacks " << bob.getName() << " with Ice materia." << std::endl;
	alice.use(0, bob);

	// Alice uses Cure materia to heal Bob
	std::cout << alice.getName() << " heals " << bob.getName() << " with Cure materia." << std::endl;
	alice.use(1, bob);

	// Unequipping Ice materia from Alice
	alice.unequip(0);

	// Alice tries to attack with Ice materia, but it's unequipped
	std::cout << alice.getName() << " tries to attack " << bob.getName() << " with unequipped Ice materia." << std::endl;
	alice.use(0, bob);

	// Equipping Bob with Ice materia
	bob.equip(materiaSource.createMateria("ice"));

	// Bob uses Ice materia to attack Alice
	std::cout << bob.getName() << " attacks " << alice.getName() << " with Ice materia." << std::endl;
	bob.use(0, alice);

	// Creating a new character named Carol, as a copy of Alice
	Character carol(alice);

	// Carol uses Cure materia to heal Alice
	std::cout << carol.getName() << " heals " << alice.getName() << " with Cure materia." << std::endl;
	carol.use(0, alice);

	// The destructors will automatically be called for Alice, Bob, and Carol when the program exits, cleaning up any memory

	return 0;
}
