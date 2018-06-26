#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

#include "Tank.h"
#include "CanonTank.h"

#include "Map.h"
#include "StatusBar.h"
#include "Player.h"
#include "Game.h"
#include "Missile.h"

using namespace sf;
using namespace std;

void Drawing(RenderWindow& window, Game& game, bool bomb_stop_flag);
void DrawObjects(RenderWindow& window, Game& game, bool bomb_stop_flag);