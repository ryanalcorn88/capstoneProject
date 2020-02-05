/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: SickBay.cpp
   Description: Class implementation for SickBay room.*/

#include "SickBay.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void SickBay::setRoom()
{
	name = "sickBay";
	longDes = "You enter the sick bay. This is not an area of the base you want to be in on a regular basis.\n"
		"The crew has luckily not had too many members stay here for long.\nYou notice that the room contains medical supplies for the base."
		"\nThere is also a member of the crew currently laying on the bed. You can't tell their condition from this distance.\n";
	shortDes = "You return to the sick bay. This is the room where the sick or injured are cared for.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and radio room is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int SickBay::featureOne(Player* user)
{
	int outcome = 3;

	std::cout << "You decide to use the medical kit on the table to patch up your wounds.\n"
		"There are not many items to heal wounds in the base so you are lucky to find it.\n"
		"You gain one health!\n"<< std::endl;

	//Return outcome 3 which heals the player or calls function to heal player

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room. Player can gain the scapel in this feature.*/
int SickBay::featureTwo(Player* user)
{
	int outcome = 0;
	int number = 0;
	int index = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You approach the member of the crew laying on the bed. It's Jack!\n"
		"He is one of the younger members of the crew. You haven't had a chance to get to know him yet.\n"
		"He currently has a huge, bloody bandage wrapped around his body.\n"
		"He attempts to speak, but can't. He seems heavily sedated.\n\n"
		"His body begins to shake violently!\n"
		"Through these motions he takes a swing at you!\n"
		"What do you do?\n\n"
		"1. Defend yourself\n"
		"2. Dodge the attack"<< std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You grab a nearby scapel to defend yourself!\n" << std::endl;

			//Finds the index of the scapel in the room inventory and then uses the index to remove it from the room inventory while adding it to the player's inventory.
			index = findItemIndex("scapel");
			removeItem(items[index], user);

			number = rand() % 100 + 1;

			if (number > 70)
			{
				std::cout << "You successfully fend off the attack with the scapel!\n"
					"He groans in pain as you slash his arm and slumps over after the attempt. You think 'What the hell is going on here?!?'\n"
					"You gain a scapel!"<< std::endl;
			}
			else
			{
				std::cout << "You do not fend off his attack and he scrathes you in the process! The wound is pretty deep.\n"
					"He slumps over after hitting you. You grimace in pain.\n"
					"You lose 1 health and gain a scapel!"<< std::endl;
			}

			//Outcome set to 1 to call function to lose health
			outcome = 1;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You attempt to dodge his attack!\n" << std::endl;

			number = rand() % 100 + 1;

			if (number > 40)
			{
				std::cout << "You successfully dodge the attack!\n"
					"He slumps over after the attempt. You think 'What the hell is going on here?!?'" << std::endl;
			}
			else
			{
				std::cout << "You don't get out of the way in time! He scratches your back. The wound is pretty deep.\n"
					"He slumps over after hitting you. You grimace in pain.\n"
					"You lose 1 health!"<< std::endl;

				//Outcome set to 1 to call function to lose health
				outcome = 1;
			}

			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			std::cin >> choice;
		}
	}

	++fTwoHappened;

	return outcome;
}
