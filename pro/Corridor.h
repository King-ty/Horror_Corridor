#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

enum corridorType//��������
{
	straightCorridor,
	cornerCorridor,
	stairsCorridor
};

enum corridorDirection//���ȳ���xzƽ���ϵ�4������
{
	Px,
	Nx,
	Pz,
	Nz
};

class Corridor
{
	//Model model;ģ���ļ�
	corridorType type;
	corridorDirection direction;
	//std::vector<Object> objectList;

public:
	Corridor(corridorType type,corridorDirection direction);
	void render();
};

