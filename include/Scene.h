#pragma once
#include "Corridor.h"
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum camera_pos
{
	front,
	mid,
	back
};

class Scene
{
	std::vector<Corridor> corridorList;

public:
	Scene(Camera* camera);
	camera_pos getPos();//��ȡ��ǰ����һ������
	corridorType genNewCorridor(corridorType mid);//���ݵ�ǰ�м����� ����һ��������
	void updateCorridor();
	void render();
public:
	Camera* camera;
	camera_pos pos;
	glm::mat4 mid_model;
	glm::mat4 front_model;
	glm::mat4 back_model;
	glm::vec3 mid_if;//�ӿ�����
	glm::vec3 front_if;
	glm::vec3 back_if;
};



