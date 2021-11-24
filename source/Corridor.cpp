#include "../include/Corridor.h"

Corridor::Corridor(corridorType type)
{
	shader =new Shader("./source/shaders/1.model_loading.vs", "./source/shaders/1.model_loading.fs");
	_model = new Model(string("resources/objects/straight/straight.obj"));
	/*
	switch (type)
	{
	case straightCorridor:
		Model model_(string("resources/objects/straight/straight.obj"));
		_model = &model_;
		break;
	case cornerCorridor:
		Model model_(string("resources/objects/straight/straight.obj"));
		_model = &model_;
		break;
	case stairsCorridor:
		Model model_(string("resources/objects/straight/straight.obj"));
		_model = &model_;
		break;
	default:
		Model model_(string("resources/objects/straight/straight.obj"));
		_model = &model_;
		break;
	}
	*/
}

void Corridor::render(Camera* camera,glm::mat4 model_)
{
	/*
	把走廊中的所有物体渲染一边
	*/

	//渲染走廊
	shader->use();
	glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera->GetViewMatrix();
	shader->setMat4("projection", projection);
	shader->setMat4("view", view);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
	model = glm::scale(model, glm::vec3(0.001f));	// it's a bit too big for our scene, so scale it down
	shader->setMat4("model", model);
	_model->Draw(*shader);
}