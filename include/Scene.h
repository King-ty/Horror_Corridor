#pragma once
#include "Corridor.h"
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Scene
{
	std::vector<Corridor> corridorList;

public:
	Scene(Camera* camera);
	void updateCorridor();
	void render();
public:
	Camera* camera;
};



