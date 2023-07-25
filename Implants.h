#pragma once
#include <iostream>
#include <string>
#include "TextureManager.h"
using namespace std;

class Implants {
protected:
	string name, field, fieldUse;
	int Damage, heal, hods, upgratecost; 
	sf::Sprite sprite; sf::Image image; sf::Texture texture;
public:
	string text; int x, y;
	void SetText(string text) { this->text = text; }
	virtual void Use(string& indexstr) = 0;
	void SetName(string name); string GetName();
	void SetField(string field); string GetField();
	void SetFieldUse(string str); string GetFieldUse() { return fieldUse; }
	void SetDamage(int damage); int GetDamage();
	void SetHeal(int heal); int GetHeal() { return heal; }
	void SetCoords(int X, int Y); int GetX() { return x;} int GetY() { return y;}
	void SetHods(int hods); int GetHods() { return hods; }
	void SetUpgrate(int cost); int GetUpgrate() { return upgratecost; }
	void SetSprite(string fileName, int x, int y); sf::Sprite GetSprite() { return sprite; }
};

class DImplants : public Implants {
public:
	DImplants() {}
	DImplants(string name, string field, int Damage) {
		this->name = name;
		this->field = field;
		this->Damage = Damage;
	}
	void Use(string& indexstr) override;
};

class SImplants : public Implants {
public:
	SImplants() {}
	SImplants(string name, string field, int hods) {
		this->name = name;
		this->field = field;
		this->hods = hods;
	}
	void Use(string& indexstr) override;
};

class HImplants : public Implants {
public:
	HImplants() {}
	HImplants(string name, string field, int hods) {
		this->name = name;
		this->field = field;
		this->hods = hods;
	}
	void Use(string& indexstr) override;
};