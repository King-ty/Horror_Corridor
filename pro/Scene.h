#pragma once
#include "Corridor.h"
#include <vector>

class Scene
{
	std::vector<Corridor> corridorList;
	glm::vec3 viewerPos;

public:
	Scene();
	void undateCorridor();
	void render();
};



