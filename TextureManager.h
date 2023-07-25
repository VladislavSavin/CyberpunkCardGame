#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std; using namespace sf;

class TextureManager {
protected:
	Sprite sprite; Image image; Texture texture;

public:
	void LoadTexture(string fileName, int x, int y);
	Sprite GetSprite() { return sprite; }
};

class ChangeTextures : public TextureManager {
public:
	void LoadChangeTexture(string fileName, int xpos, int ypos, int x, int y, int w, int h);
};