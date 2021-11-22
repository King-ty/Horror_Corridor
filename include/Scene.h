#pragma once
#include "Corridor.h"
#include <vector>

class Scene
{
	std::vector<Corridor> corridorList;

public:
	Scene();
	void updateCorridor();
	void render();
};



