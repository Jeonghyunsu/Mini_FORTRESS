#include "Map.h"

int Map::s_iMapWidth;

Map::Map(const MapName name)
{
	switch (name) {
		case MapName::SkyBridge :
			m_tMap.loadFromFile("images/map_skybridge.png");
			break;
	}

	s_iMapWidth = m_tMap.getSize().x;
	m_spMap.setTexture(m_tMap);
}

Sprite & Map::GetSpMap()
{
	return m_spMap;
}

int Map::GetMapWidth()
{
	return s_iMapWidth;
}

Map::~Map()
{
}
