#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

/*#include "Room.hpp"*/
#include "Item.hpp"


/*#include "Macready.hpp"*/
/*#include "Hallway1.hpp"*/

class Player
{
private:
	int grit;
	int alive;
	int victory;
	int gameEnd;
	int needBearings;
	int deathWish;
	int dumbIdea;
	std::vector<Item> inventory;
	
	int drOutcome;

	

public:
	Player();


	void useItem(std::string item);
	/*altered line*/
	/*void setGrit(Item* powerup);*/
	void setGrit(std::string powerup);

	int getGrit();
	void setAlive(int dead);

	int getAlive();

	/*altered line*/
	/*void setInventory(Item* newItem);*/
	void setInventory(Item newItem);
	void getInventory();

	int getVictory();
	void setVictory(int victory);

	/*Function for checking if player has necessary item*/
	bool checkInventory(std::string itemNeeded);

	void usePowerUp(std::string powerUp);

	void setGameEnd(int ending);
	int getGameEnd();
	
	void deletePlayerItem(std::string itemNeeded);

	Item transferItem(std::string itemNeeded);

	int getIndex(std::string itemToCheck);

	void decrementGrit();

	void gritWarning();

	int getBearings();

	void setBearings(int);	

	void gritHit(int damage);

	void setGritSave(int gritLevel);

	int inventoryNumber();
	Item* returnItem(int);
	void clearInventory();
	
	void setDeathWish(int desire);

	int getDeathWish();

	void setDumbIdea(int idea);
	
	int getDumbIdea();
	
	int getDrOutcome();
	void setDrOutcome(int val);

};





