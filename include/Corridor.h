#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "../include/shader_m.h"
#include "../include/model.h"
#include "../include/parameter.h"
#include "../include/camera.h"

enum corridorType//走廊类型
{
	straightCorridor,
	cornerCorridorL,
	cornerCorridorR,
	stairsCorridorU,
	stairsCorridorD
};

enum corridorDir
{
	xP,
	zP,
	xN,
	zN
};

class Corridor
{
public:
	corridorType type;
	corridorDir dir;
	Shader* shader;
	Model* _model;
	//std::vector<Object> objectList;走廊中物体列表

public:
	Corridor(corridorType type, corridorDir dir_);//根据走廊类型生成走廊
	void render(Camera* camera,glm::mat4 model);//渲染前设定位置
};

