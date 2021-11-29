#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "../include/shader_m.h"
#include "../include/model.h"
#include "../include/parameter.h"
#include "../include/camera.h"

enum corridorType//��������
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
	//std::vector<Object> objectList;�����������б�

public:
	Corridor(corridorType type, corridorDir dir_);//��������������������
	void render(Camera* camera,glm::mat4 model);//��Ⱦǰ�趨λ��
};

