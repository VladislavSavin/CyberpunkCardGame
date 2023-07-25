#pragma once
#include "Punks.h"
#include "Functions.h"
#include <fstream>
#include <sstream>
#include <Windows.h>

class Game {
private:
	Carrie David; NetRunner Lusy; vector<Implants*> implantsGG;
	PsihoPunk CyberPsiho; DImplants PsihoImplant;
	vector<Implants*> implantsUsing; SoundBuffer soundImplant; 
	TextureManager background; ChangeTextures heartsGG, heartsPsiho, b0, b1, b2, b3, texturemoney;
	int HPGG, HPPsiho; int numberUsing;
	int level, money ,ChoiceGG, TmpUsing1 = 0, TmpUsing2 = 0;
	Punks* GG;
public:
	Game() {}
	void StartGame();
	void MehanicsRandomCards(int& hods);
	void MehanicsDamage(string &str, int &xposHeartP, int &xposHeartD, int &hods, int& freeze);
	void InitDavid();
	void InitLusy();
	void Upgrate();
	void MenuInit();
	void ReturnAll();
	void InitBattle();
	void SaveInFile();
};

