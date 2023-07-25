#pragma once
#include <iostream>
#include <vector>
#include "Implants.h"
using namespace std;

class Punks {
protected:
	string field, name; 
	sf::Sprite sprite; sf::Image image; sf::Texture texture;
	int HP = 0;
public:
	void SetHP(int hp); int GetHP();
	void SetField(string field); string GetField();
};

class Carrie : public Punks {
public:
	Carrie() {}
	Carrie(string name, string field, int hp) {
		this->name = name;
		this->field = field;
		this->HP = hp;
	}
	void SetSprite(string fileName, int x, int y); sf::Sprite GetSprite() { return sprite; }
};
class NetRunner : public Punks {
public:
	NetRunner() {}
	NetRunner(string name, string field, int hp) {
		this->name = name;
		this->field = field;
		this->HP = hp;
	}
	void SetSprite(string fileName, int x, int y); sf::Sprite GetSprite() { return sprite; }
};

class PsihoPunk : public Punks {
public:
	PsihoPunk() {}
	PsihoPunk(string name, string field, int hp) {
		this->name = name;
		this->field = field;
		this->HP = hp;
	}
	void SetSprite(string fileName, int x, int y); sf::Sprite GetSprite() { return sprite; }
};