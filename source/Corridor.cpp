#include "../include/Corridor.h"

Corridor::Corridor(corridorType type_, corridorDir dir_)
{
	shader =new Shader("./source/shaders/1.model_loading.vs", "./source/shaders/1.model_loading.fs");

	switch (type_)
	{
	case straightCorridor:
		_model = new Model(string("resources/objects/straight/straight.obj"));
		type = type_;
		dir = dir_;
		break;
	case cornerCorridorL:
		_model = new Model(string("resources/objects/corner/corner.obj"));
		type = type_;
		dir = dir_;
		break;
	case cornerCorridorR:
		_model = new Model(string("resources/objects/corner/corner.obj"));
		type = type_;
		dir = dir_;
		break;
	case stairsCorridorU:
		_model = new Model(string("resources/objects/stair/stair.obj"));
		type = type_;
		dir = dir_;
		break;
	case stairsCorridorD:
		_model = new Model(string("resources/objects/stair/stair.obj"));
		type = type_;
		dir = dir_;
		break;
	}
}

void Corridor::render(Camera* camera,glm::mat4 model_)
{
	/*
	把走廊中的所有物体渲染一遍
	*/

	//渲染走廊
	shader->use();
	glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera->GetViewMatrix();
	shader->setMat4("projection", projection);
	shader->setMat4("view", view);

	shader->setMat4("model", model_);
	_model->Draw(*shader);
}