#include "TextureManager.h"

void TextureManager::LoadTexture(string fileName, int x, int y) {
	image.loadFromFile(fileName);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void ChangeTextures::LoadChangeTexture(string fileName, int xpos, int ypos, int x, int y, int w, int h) {
	image.loadFromFile(fileName);
	image.createMaskFromColor(Color(255, 255, 255));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(x, y, w, h));
	sprite.setPosition(xpos, ypos);
}
