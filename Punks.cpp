#include "Punks.h"

void Carrie::SetSprite(string fileName, int x, int y) {
	image.loadFromFile(fileName);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void PsihoPunk::SetSprite(string fileName, int x, int y) {
	image.loadFromFile(fileName);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

int Punks::GetHP() {
	return HP;
}

void Punks::SetHP(int hp) {
	this->HP = hp;
}

void Punks::SetField(string field) {
	this->field = field;
}

string Punks::GetField() {
	return field;
}

void NetRunner::SetSprite(string fileName, int x, int y) {
	image.loadFromFile(fileName);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}
