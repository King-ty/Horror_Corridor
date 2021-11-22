#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "../include/shader_m.h"
#include "../include/model.h"
#include "../include/parameter.h"
#include "../include/camera.h"

enum corridorType//◊ﬂ¿»¿‡–Õ
{
	straightCorridor,
	cornerCorridor,
	stairsCorridor
};

class Corridor
{
	corridorType type;
	Shader* shader;
	Model* _model;
	//std::vector<Object> objectList;

public:
	Corridor(corridorType type);
	void render(Camera* camera);
};

