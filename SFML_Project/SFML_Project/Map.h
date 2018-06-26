#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

enum MapName {
	SkyBridge = 1
};

class Map {
private:
	Sprite m_spMap;
	Texture m_tMap;
	static int s_iMapWidth;
public:
	Map(const MapName name);
	Sprite &GetSpMap();
	static int GetMapWidth();
	~Map();
};