/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Galley.hpp
   Description: Class header for Galley room.*/

#pragma once

#include "Room.hpp"

class Galley : Room {
public:
	std::string getName();
	std::string getLongDescrip();
	std::string getShortDescrip();
	std::string getExitLong();
	std::string getExitShort();
	bool getFeatureOneHap();
	bool getFeatureTwoHap();
	void featureOne();
	void featureTwo();
	void setRoom();
	void itemsInRoom();
	void addItem(Item*);
	void removeItem(Item*);
	void displayDescrip();
	void displayExits();
};
