#include "Implants.h"

void Implants::SetName(string name) {
	this->name = name;
}

string Implants::GetName()
{
	return name;
}

string Implants::GetField() {
	return field;
}

void Implants::SetFieldUse(string str) {
	this->fieldUse = str;
}

int Implants::GetDamage() {
	return Damage;
}

void Implants::SetCoords(int X, int Y) {
	this->x = X;
	this->y = Y;
}

void Implants::SetUpgrate(int cost) {
	this->upgratecost = cost;
}

void Implants::SetDamage(int damage) {
	this->Damage = damage;
}

void Implants::SetHeal(int heal) {
	this->heal = heal;
}

void Implants::SetHods(int hods) {
	this->hods = hods;
}

void Implants::SetField(string field) {
	this->field = field;
}

void Implants::SetSprite(string fileName, int x, int y) {
	image.loadFromFile(fileName);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void DImplants::Use(string& indexstr) {
	indexstr = "Damage";
}

void SImplants::Use(string& indexstr) {
	indexstr = "Special";
}

void HImplants::Use(string& indexstr) {
	indexstr = "Heals";
}