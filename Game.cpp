#include "Game.h"

void Game::StartGame() {
	int x = 1920; int y = 1080;
	sf::RenderWindow window(sf::VideoMode(x, y), "Cyberpunk Card Game");

	Font font; font.loadFromFile("./Grafics/TextFile.ttf");
	Text textLVL("", font, 50), textCost("", font, 20), textMoney("", font, 50), textCost1("", font, 50), textopis("", font, 20);
	SoundBuffer sound, soundcost, soundWin;
	sound.loadFromFile("./Grafics/SoundButton.wav"); soundcost.loadFromFile("./Grafics/SoundMoney.wav"); soundWin.loadFromFile("./Grafics/SoundWin.wav");
	Sound playsound(sound), CostSound(soundcost), WinSound(soundWin); Sound S(soundImplant);

	int hods, freeze, tmp = 1; string str, stringsound; int Menu = 0; int xposHeartsP = 0, xposHeartsD = 0, lvl, tmpInit = 0;
	while (window.isOpen()) {
		Vector2i pixelPos = Mouse::getPosition(window);
		if (Menu == 0) {
			if (tmp == 1) {
				MenuInit(); tmp++;
			}
			sf::Event eventMenu;
			while (window.pollEvent(eventMenu)) {
				if (eventMenu.type == sf::Event::Closed or eventMenu.type == sf::Event::KeyReleased and eventMenu.key.code == sf::Keyboard::Escape) {
					window.close();
				}
				if (b1.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
					b1.LoadChangeTexture("./Grafics/BattonDavid2.png", 50, 200, 0, 0, 678, 198);
					if (eventMenu.type == Event::MouseButtonReleased and eventMenu.key.code == Mouse::Left) {
						Menu = 1; tmp = 1; ChoiceGG = 1; InitDavid(); playsound.play(); TmpUsing1 = 1;
					}
				}
				else b1.LoadChangeTexture("./Grafics/BattonDavid1.png", 50, 200, 0, 0, 678, 198);
				if (b2.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
					b2.LoadChangeTexture("./Grafics/BattonLusy2.png", 1150, 200, 0, 0, 678, 198);
					if (eventMenu.type == Event::MouseButtonReleased and eventMenu.key.code == Mouse::Left) {
						Menu = 1; tmp = 1; ChoiceGG = 2; InitLusy(); playsound.play(); TmpUsing2 = 1;
					}
				}
				else b2.LoadChangeTexture("./Grafics/BattonLusy1.png", 1150, 200, 0, 0, 678, 198);
				if (b3.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
					b3.LoadChangeTexture("./Grafics/Return2.png", 621, 700, 0, 0, 678, 198);
					if (eventMenu.type == Event::MouseButtonReleased and eventMenu.key.code == Mouse::Left) {
						ReturnAll(); playsound.play();
					}
				}
				else b3.LoadChangeTexture("./Grafics/Return1.png", 621, 700, 0, 0, 678, 198);
			}
			window.clear();
			window.draw(background.GetSprite()); window.draw(b1.GetSprite()); window.draw(b2.GetSprite()); window.draw(b3.GetSprite());
		}

		if (Menu == 1) {
			if (tmp == 1) {
				HPPsiho = CyberPsiho.GetHP(); if (ChoiceGG == 1) HPGG = David.GetHP(); else HPGG = Lusy.GetHP();
				freeze = 0; Upgrate(); tmp++;
			}
			sf::Event eventMenu;
			while (window.pollEvent(eventMenu) and Menu == 1) {
				if (eventMenu.type == sf::Event::KeyReleased and eventMenu.key.code == sf::Keyboard::Escape) {
					Menu = 0; tmp = 1; SaveInFile(); playsound.play();
				}
				if (eventMenu.type == Event::MouseButtonReleased and eventMenu.key.code == Mouse::Left) {
					if (money >= implantsGG[0]->GetUpgrate()) {
						if (b1.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
							money -= implantsGG[0]->GetUpgrate();
							implantsGG[0]->SetUpgrate(implantsGG[0]->GetUpgrate() + 100); 
							implantsGG[0]->SetDamage(implantsGG[0]->GetDamage() + 2);
							CostSound.play();
						}
						if (b2.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
							money -= implantsGG[1]->GetUpgrate(); implantsGG[1]->SetUpgrate(implantsGG[1]->GetUpgrate() + 250);
							if (ChoiceGG == 1) implantsGG[1]->SetDamage(implantsGG[1]->GetDamage() + 3);
							if (ChoiceGG == 2) implantsGG[1]->SetHeal(implantsGG[1]->GetHeal() + 3);
							CostSound.play();
						}						
					}
				}
				if (b0.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
					b0.LoadChangeTexture("./Grafics/BattleNext2.png", 600, 800, 0, 0, 678, 198);
					if (eventMenu.type == Event::MouseButtonReleased and eventMenu.key.code == Mouse::Left) {
						Menu = 2; tmp = 1; lvl = level + 1; playsound.play();
					}
				}
				else b0.LoadChangeTexture("./Grafics/BattleNext1.png", 600, 800, 0, 0, 678, 198);
			}
			window.clear();
			ostringstream textmoney, textcost1, textcost2, textOpis[3];
			window.draw(background.GetSprite()); window.draw(texturemoney.GetSprite());
			textmoney << money; textMoney.setString(textmoney.str()); textMoney.setPosition(80, 5); window.draw(textMoney);
			textcost1 << implantsGG[0]->GetUpgrate(); textCost1.setString("Cost: " + textcost1.str()); textCost1.setPosition(120, 555);
			window.draw(textCost1);
			textcost2 << implantsGG[1]->GetUpgrate(); textCost1.setString("Cost: " + textcost2.str()); textCost1.setPosition(820, 555);
			window.draw(textCost1);
			for (int i = 0; i < 3; i++) {
				if (i == 0) textOpis[i] << implantsGG[i]->GetDamage();  if (i == 1 and ChoiceGG == 1) textOpis[i] << implantsGG[i]->GetDamage();
				if (i == 1 and ChoiceGG == 2) textOpis[i] << implantsGG[i]->GetHeal(); if (i == 2) textOpis[i] << implantsGG[i]->GetHods();
			}
			if (b1.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
				textopis.setString("Upgrate damage: +2\nNow Damage: " + textOpis[0].str()); textopis.setPosition(0, 1000);
				window.draw(textopis);
			}
			if (b2.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y) and ChoiceGG == 1) {
				textopis.setString("Upgrate damage: +3\nNow Damage: " + textOpis[1].str()); textopis.setPosition(0, 1000);
				window.draw(textopis);
			}
			if (b2.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y) and ChoiceGG == 2) {
				textopis.setString("Upgrate Heal: +3\nNow Heal: " + textOpis[1].str()); textopis.setPosition(0, 1000);
				window.draw(textopis);
			}
			if (b3.GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
				textopis.setString("You can't upgrate this!\nNow Freeze: " + textOpis[2].str()); textopis.setPosition(0, 1000);
				window.draw(textopis);
			}
			window.draw(b0.GetSprite()); window.draw(b1.GetSprite()); window.draw(b2.GetSprite()); window.draw(b3.GetSprite());
		}

		if (Menu == 2) {
			ostringstream textlvl, hearts, heartsPs, infImplants, inftext, DamagePsiho;
			if (tmp == 1) {
				InitBattle(); hods = 0; xposHeartsP = 200; xposHeartsD = 200; tmp++;
			}
			sf::Event event;
			if (hods == 0) MehanicsRandomCards(hods);
			while (window.pollEvent(event)) {
				if (HPGG <= 0 or HPPsiho <= 0) {
					if (event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Escape) {
						Menu = 1; tmp = 1;
					}
				}
				if (HPGG > 0 or HPPsiho > 0) {
					if (event.type == Event::MouseButtonReleased and event.key.code == Mouse::Left) {
						for (int i = 0; i < implantsUsing.size(); i++) {
							if (implantsUsing[i]->GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
								numberUsing = i; stringsound = implantsUsing[numberUsing]->GetFieldUse();
								soundImplant.loadFromFile(stringsound);
								S.play();
								MehanicsDamage(str, xposHeartsP, xposHeartsD, hods, freeze);
							}
						}
					}
				}
			}

			if (HPGG <= 0 or HPPsiho <= 0) {
				for (int i = 0; i < implantsUsing.size(); i++) implantsUsing.erase(implantsUsing.begin());
				if (implantsUsing.size() == 1) implantsUsing.erase(implantsUsing.begin());
				if (implantsUsing.size() == 2) { implantsUsing.erase(implantsUsing.begin()); implantsUsing.erase(implantsUsing.begin()); }
				WinSound.play();
			}
			if (HPGG <= 0) {
				level = level; Menu = 1; tmp = 1;
			}
			if (HPPsiho <= 0) {
				level++; lvl = level + 1; CyberPsiho.SetHP(CyberPsiho.GetHP() + 2); PsihoImplant.SetDamage(PsihoImplant.GetDamage() + 1);
				if (ChoiceGG == 1) David.SetHP(David.GetHP() + 2); if (ChoiceGG == 2) Lusy.SetHP(Lusy.GetHP() + 2);
				money += 50 * level; Menu = 1; tmp = 1;
			}
			
			//Вывод всего, что есть в игре
			window.clear();
			window.draw(background.GetSprite()); window.draw(heartsGG.GetSprite()); window.draw(heartsPsiho.GetSprite());
			textlvl << level; heartsPs << HPPsiho; hearts << HPGG; DamagePsiho << PsihoImplant.GetDamage();
			textLVL.setString("LVL: " + textlvl.str()); textLVL.setPosition(40, 500); window.draw(textLVL);
			textLVL.setString(hearts.str()); textLVL.setPosition(110, 150); window.draw(textLVL);
			textLVL.setString(heartsPs.str()); textLVL.setPosition(1750, 150); window.draw(textLVL);
			textCost.setString("Damage Psiho: " + DamagePsiho.str()); textCost.setPosition(1680, 900); window.draw(textCost);
			for (int i = 0; i < implantsUsing.size(); i++) {
				if (implantsUsing[i]->GetSprite().getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
					infImplants << implantsUsing[i]->GetName(); inftext << implantsUsing[i]->text;
					textCost.setString(infImplants.str() + inftext.str()); textCost.setPosition(0, 900); window.draw(textCost);
				}
			}
			if (ChoiceGG == 1) window.draw(David.GetSprite()); if (ChoiceGG == 2) window.draw(Lusy.GetSprite());
			window.draw(CyberPsiho.GetSprite());
			for (int i = 0; i < implantsUsing.size(); i++) window.draw(implantsUsing[i]->GetSprite());
		}
		window.display();
	}
}

void Game::MehanicsRandomCards(int& hods) {
	int Usingimplant, xpos = 400, ypos = 650;
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		Usingimplant = rand() % 3;
		if (ChoiceGG == 1) {
			if (Usingimplant == 0 or Usingimplant == 1) {
				implantsUsing.push_back(new DImplants);
				implantsUsing[i]->SetField(implantsGG[Usingimplant]->GetField());
				implantsUsing[i]->SetName(implantsGG[Usingimplant]->GetName());
				implantsUsing[i]->SetDamage(implantsGG[Usingimplant]->GetDamage());
				implantsUsing[i]->x = xpos; implantsUsing[i]->y = ypos; xpos += 450;
				implantsUsing[i]->SetSprite(implantsUsing[i]->GetField(), implantsUsing[i]->x, implantsUsing[i]->y);
				implantsUsing[i]->SetText("\nPsiho get damage");
				implantsUsing[i]->SetFieldUse(implantsGG[Usingimplant]->GetFieldUse());
			}
		}
		if (ChoiceGG == 2) {
			if (Usingimplant == 0) {
				implantsUsing.push_back(new DImplants);
				implantsUsing[i]->SetField(implantsGG[Usingimplant]->GetField());
				implantsUsing[i]->SetName(implantsGG[Usingimplant]->GetName());
				implantsUsing[i]->SetDamage(implantsGG[Usingimplant]->GetDamage());
				implantsUsing[i]->x = xpos; implantsUsing[i]->y = ypos; xpos += 450;
				implantsUsing[i]->SetSprite(implantsUsing[i]->GetField(), implantsUsing[i]->x, implantsUsing[i]->y);
				implantsUsing[i]->SetText("\nPsiho get damage");
				implantsUsing[i]->SetFieldUse(implantsGG[Usingimplant]->GetFieldUse());
			}
			if (Usingimplant == 1) {
				implantsUsing.push_back(new HImplants);
				implantsUsing[i]->SetField(implantsGG[Usingimplant]->GetField());
				implantsUsing[i]->SetName(implantsGG[Usingimplant]->GetName());
				implantsUsing[i]->SetHeal(implantsGG[Usingimplant]->GetHeal());
				implantsUsing[i]->x = xpos; implantsUsing[i]->y = ypos; xpos += 450;
				implantsUsing[i]->SetSprite(implantsUsing[i]->GetField(), implantsUsing[i]->x, implantsUsing[i]->y);
				implantsUsing[i]->SetText("\nCharacter restores HP");
				implantsUsing[i]->SetFieldUse(implantsGG[Usingimplant]->GetFieldUse());
			}
		}
		if (Usingimplant == 2) {
			implantsUsing.push_back(new SImplants);
			implantsUsing[i]->SetField(implantsGG[Usingimplant]->GetField());
			implantsUsing[i]->SetName(implantsGG[Usingimplant]->GetName());
			implantsUsing[i]->SetHods(implantsGG[Usingimplant]->GetHods());
			implantsUsing[i]->x = xpos; implantsUsing[i]->y = ypos; xpos += 450;
			implantsUsing[i]->SetSprite(implantsUsing[i]->GetField(), implantsUsing[i]->x, implantsUsing[i]->y);
			implantsUsing[i]->SetText("\nPsiho don't attack 1 turn");
			implantsUsing[i]->SetFieldUse(implantsGG[Usingimplant]->GetFieldUse());
		}
	}
	hods = 3;
}

void Game::MehanicsDamage(string& str, int& xposHeartP, int& xposHeartD, int& hods, int& freeze) {
	implantsUsing[numberUsing]->Use(str);
	if (str == "Damage") {
		HPPsiho -= implantsUsing[numberUsing]->GetDamage();
		if (HPPsiho > 0) {
			if (HPPsiho <= 0.8 * CyberPsiho.GetHP()) xposHeartP = 200;
			if (HPPsiho <= 0.6 * CyberPsiho.GetHP()) xposHeartP = 400;
			if (HPPsiho <= 0.4 * CyberPsiho.GetHP()) xposHeartP = 600;
			if (HPPsiho <= 0.2 * CyberPsiho.GetHP()) xposHeartP = 800;
			if (HPPsiho <= 0) xposHeartP = 1000;
			heartsPsiho.LoadChangeTexture("./Grafics/hearts.png", 1680, 100, xposHeartP, 0, 200, 200);
		}
		freeze--;
	}
	if (str == "Heals") {
		HPGG += implantsUsing[numberUsing]->GetHeal();
		if (HPGG > 0) {
			if (HPGG >= Lusy.GetHP()) xposHeartD = 0;
			if (HPGG <= 0.8 * Lusy.GetHP()) xposHeartD = 200;
			if (HPGG <= 0.6 * Lusy.GetHP()) xposHeartD = 400;
			if (HPGG <= 0.4 * Lusy.GetHP()) xposHeartD = 600;
			if (HPGG <= 0.2 * Lusy.GetHP()) xposHeartD = 800;
			if (HPGG <= 0) xposHeartD = 1000;
			heartsGG.LoadChangeTexture("./Grafics/hearts.png", 40, 100, xposHeartD, 0, 200, 200);
		}
		freeze--;
	}
	if (str == "Special") {
		freeze = implantsUsing[numberUsing]->GetHods();
		HPPsiho = HPPsiho;
		HPGG = HPGG;
	}
	if (HPPsiho > 0 and freeze <= 0) {
		HPGG -= PsihoImplant.GetDamage();
		if (HPGG > 0 and ChoiceGG == 1) {
			if (HPGG <= 0.8 * David.GetHP()) xposHeartD = 200;
			if (HPGG <= 0.6 * David.GetHP()) xposHeartD = 400;
			if (HPGG <= 0.4 * David.GetHP()) xposHeartD = 600;
			if (HPGG <= 0.2 * David.GetHP()) xposHeartD = 800;
			if (HPGG <= 0) xposHeartD = 1000;
			heartsGG.LoadChangeTexture("./Grafics/hearts.png", 40, 100, xposHeartD, 0, 200, 200);
		}
		if (HPGG > 0 and ChoiceGG == 2) {
			if (HPGG <= 0.8 * Lusy.GetHP()) xposHeartD = 200;
			if (HPGG <= 0.6 * Lusy.GetHP()) xposHeartD = 400;
			if (HPGG <= 0.4 * Lusy.GetHP()) xposHeartD = 600;
			if (HPGG <= 0.2 * Lusy.GetHP()) xposHeartD = 800;
			if (HPGG <= 0) xposHeartD = 1000;
			heartsGG.LoadChangeTexture("./Grafics/hearts.png", 40, 100, xposHeartD, 0, 200, 200);
		}
	}
	implantsUsing.erase(implantsUsing.begin() + numberUsing);
	hods--;
}

void Game::InitDavid() {
	srand(time(NULL));
	int tmp, tmphp; int cost;
	ifstream file("Game.txt");
	//Установка лвл и денег
	file >> level; file >> money;
	//Установка показателей Дэвида
	string tmpstr;
	file >> tmpstr;
	string Name, Field; int Damage, xpos = 400;
	if (tmpstr == "David") {
		file >> tmphp; David.SetHP(tmphp); David.SetField("./Grafics/David.png");
		//Установка показателей имплантов
		implantsGG.push_back(new DImplants); implantsGG.push_back(new DImplants); implantsGG.push_back(new SImplants);
		for (int i = 0; i < implantsGG.size() - 1; i++) {
			file >> Name; file >> Field; file >> tmpstr; file >> Damage; file >> cost;
			implantsGG[i]->SetName(Name); implantsGG[i]->SetField(Field); implantsGG[i]->SetFieldUse(tmpstr); implantsGG[i]->SetDamage(Damage); implantsGG[i]->SetUpgrate(cost);
		}
		file >> Name; file >> Field; file >> tmpstr; file >> Damage;
		implantsGG[2]->SetName(Name); implantsGG[2]->SetField(Field); implantsGG[2]->SetFieldUse(tmpstr); implantsGG[2]->SetHods(Damage);
	}
	//Установка показателей Психа
	file >> tmpstr;
	file >> tmphp; CyberPsiho.SetHP(tmphp); HPPsiho = CyberPsiho.GetHP();
	file >> Damage; file >> Name;
	PsihoImplant.SetDamage(Damage); PsihoImplant.SetName(Name);
	file.close();
}

void Game::InitLusy() {
	srand(time(NULL));
	int tmp, tmphp; int cost;
	ifstream file("GameLusy.txt");
	//Установка лвл и денег
	file >> level; file >> money;
	//Установка показателей Люси
	string tmpstr;
	file >> tmpstr;
	string Name, Field; int Damage, xpos = 400;
	if (tmpstr == "Lusy") {
		file >> tmphp; Lusy.SetHP(tmphp); Lusy.SetField("./Grafics/Lusy.png");
		//Установка показателей имплантов
		implantsGG.push_back(new DImplants); implantsGG.push_back(new HImplants); implantsGG.push_back(new SImplants);
		file >> Name; file >> Field; file >> tmpstr; file >> Damage; file >> cost;
		implantsGG[0]->SetName(Name); implantsGG[0]->SetField(Field); implantsGG[0]->SetFieldUse(tmpstr); implantsGG[0]->SetDamage(Damage); implantsGG[0]->SetUpgrate(cost);
		file >> Name; file >> Field; file >> tmpstr; file >> Damage; file >> cost;
		implantsGG[1]->SetName(Name); implantsGG[1]->SetField(Field); implantsGG[1]->SetFieldUse(tmpstr); implantsGG[1]->SetHeal(Damage); implantsGG[1]->SetUpgrate(cost);
		file >> Name; file >> Field; file >> tmpstr; file >> Damage;
		implantsGG[2]->SetName(Name); implantsGG[2]->SetField(Field); implantsGG[2]->SetFieldUse(tmpstr); implantsGG[2]->SetHods(Damage);
	}
	//Установка показателей Психа
	file >> tmpstr;
	file >> tmphp; CyberPsiho.SetHP(tmphp); HPPsiho = CyberPsiho.GetHP();
	file >> Damage; file >> Name;
	PsihoImplant.SetDamage(Damage); PsihoImplant.SetName(Name);
	file.close();
}

void Game::Upgrate() {
	background.LoadTexture("./Grafics/Menu.png", 0, 0);
	texturemoney.LoadTexture("./Grafics/IconMoney.png", 0, 0); b0.LoadChangeTexture("./Grafics/BattleNext1.png", 600, 800, 0, 0, 678, 198);
	if (ChoiceGG == 1) {
		b1.LoadChangeTexture("./Grafics/UpgrateImplantDavid1.png", 100, 100, 0, 0, 275, 450);
		b2.LoadChangeTexture("./Grafics/UpgrateImplantDavid2.png", 800, 100, 0, 0, 275, 450); b3.LoadChangeTexture("./Grafics/UpgrateImplantDavid3.png", 1500, 100, 0, 0, 275, 450);
	}
	if (ChoiceGG == 2) {
		b1.LoadChangeTexture("./Grafics/UpgrateImplantLusy1.png", 100, 100, 0, 0, 275, 450);
		b2.LoadChangeTexture("./Grafics/UpgrateImplantLusy2.png", 800, 100, 0, 0, 275, 450); b3.LoadChangeTexture("./Grafics/UpgrateImplantLusy3.png", 1500, 100, 0, 0, 275, 450);
	}
}


void Game::MenuInit() {
	background.LoadTexture("./Grafics/Menu.png", 0, 0); b1.LoadChangeTexture("./Grafics/BattonDavid1.png", 50, 200, 0, 0, 678, 198); b2.LoadChangeTexture("./Grafics/BattonLusy1.png", 1150, 200, 0, 0, 678, 198);
	b3.LoadChangeTexture("./Grafics/Return1.png", 621, 700, 0, 0, 678, 198);
}

void Game::ReturnAll() {
	int Damage = 2;
	ofstream file("Game.txt");
	file << 1 << "\n" << 100 << "\n";
	file << "David" << "\n" << 10 << "\n";
	file << "Pistol" << "\n" << "./Grafics/DavidImplant1.png" << "\n" << "./Grafics/SoundPistol.wav" << "\n" << Damage << "\n" <<
		150 << endl; Damage += 2;
	file << "Prototipe" << "\n" << "./Grafics/DavidImplant2.png" << "\n" << "./Grafics/SoundPrototipe.wav" << "\n" << Damage << "\n" <<
		150 << endl;
	file << "Sandevistan" << "\n" << "./Grafics/DavidImplant3.png" << "\n" << "./Grafics/SoundSandevistan.wav" << "\n" << 2 << "\n";
	file << "CyberPsiho" << "\n" << 10 << "\n";
	file << 2 << "\n" << "Implant";
	file.close();

	ofstream fil("GameLusy.txt");
	fil << 1 << "\n" << 100 << "\n";
	fil << "Lusy" << "\n" << 10 << "\n";
	fil << "Threads" << "\n" << "./Grafics/LusyImplant1.png" << "\n" << "./Grafics/SoundShreads.wav" << "\n" << 2 << "\n" <<
		150 << "\n";
	fil << "Cyberspace" << "\n" << "./Grafics/LusyImplant2.png" << "\n" << "./Grafics/SoundCyberSpace.wav" << "\n" << 2 << "\n" <<
		150 << "\n";
	fil << "Hucking" << "\n" << "./Grafics/LusyImplant3.png" << "\n" << "./Grafics/SoundHucking.wav" << "\n" << 2 << "\n";
	fil << "CyberPsiho" << "\n" << 10 << "\n";
	fil << 2 << "\n" << "Implant";
	fil.close();
}

void Game::InitBattle() {
	int tmp;
	if (ChoiceGG == 1) David.SetSprite(David.GetField(), 450, 100); if (ChoiceGG == 2) Lusy.SetSprite(Lusy.GetField(), 450, 100);
	tmp = rand() % 3;
	if (tmp == 1) CyberPsiho.SetField("./Grafics/CyberPsiho1.png");
	else if (tmp == 2) CyberPsiho.SetField("./Grafics/CyberPsiho2.png");
	else CyberPsiho.SetField("./Grafics/CyberPsiho3.png");
	CyberPsiho.SetSprite(CyberPsiho.GetField(), 1200, 100);
	for (int i = 0; i < implantsGG.size(); i++) implantsGG[i]->SetSprite(implantsGG[i]->GetField(), implantsGG[i]->x, implantsGG[i]->y);
	
	heartsGG.LoadChangeTexture("./Grafics/hearts.png", 40, 100, 0, 0, 200, 200); heartsPsiho.LoadChangeTexture("./Grafics/hearts.png", 1680, 100, 0, 0, 200, 200);
	background.LoadTexture("./Grafics/BattleField.png", 0, 0);
}

void Game::SaveInFile() {
	string tmp;
	if (ChoiceGG == 1) {
		ofstream file("Game.txt");
		file << level << "\n" << money << "\n";
		file << "David" << "\n" << David.GetHP() << "\n";
		for (int i = 0; i < implantsGG.size() - 1; i++) {
			file << implantsGG[i]->GetName() << "\n" << implantsGG[i]->GetField() << "\n" << implantsGG[i]->GetFieldUse() << "\n" << implantsGG[i]->GetDamage() << "\n" <<
				implantsGG[i]->GetUpgrate() << endl;
		}
		file << implantsGG[2]->GetName() << "\n" << implantsGG[2]->GetField() << "\n" << implantsGG[2]->GetFieldUse() << "\n" << implantsGG[2]->GetHods() << "\n";
		file << "CyberPsiho" << "\n" << CyberPsiho.GetHP() << "\n";
		file << PsihoImplant.GetDamage() << "\n" << PsihoImplant.GetName();
		file.close();
	}
	if (ChoiceGG == 2) {
		ofstream file("GameLusy.txt");
		file << level << "\n" << money << "\n";
		file << "Lusy" << "\n" << Lusy.GetHP() << "\n";
		file << implantsGG[0]->GetName() << "\n" << implantsGG[0]->GetField() << "\n" << implantsGG[0]->GetFieldUse() << "\n" << implantsGG[0]->GetDamage() << "\n" <<
			implantsGG[0]->GetUpgrate() << "\n";
		file << implantsGG[1]->GetName() << "\n" << implantsGG[1]->GetField() << "\n" << implantsGG[1]->GetFieldUse() << "\n" << implantsGG[1]->GetHeal() << "\n" <<
			implantsGG[1]->GetUpgrate() << "\n";
		file << implantsGG[2]->GetName() << "\n" << implantsGG[2]->GetField() << "\n" << implantsGG[2]->GetFieldUse() << "\n" << implantsGG[2]->GetHods() << "\n";
		file << "CyberPsiho" << "\n" << CyberPsiho.GetHP() << "\n";
		file << PsihoImplant.GetDamage() << "\n" << PsihoImplant.GetName();
		file.close();
	}
}
