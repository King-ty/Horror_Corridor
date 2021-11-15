#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

enum corridorType//走廊类型
{
	straightCorridor,
	cornerCorridor,
	stairsCorridor
};

enum corridorDirection//走廊朝向，xz平面上的4个方向
{
	Px,
	Nx,
	Pz,
	Nz
};

class Corridor
{
	//Model model;模型文件
	corridorType type;
	corridorDirection direction;
	//std::vector<Object> objectList;

public:
	Corridor(corridorType type,corridorDirection direction);
	void render();
};

