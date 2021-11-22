#include "../include/Corridor.h"

Corridor::Corridor(corridorType type)
{
	shader = &Shader("./source/shaders/1.model_loading.vs", "./source/shaders/1.model_loading.fs");
	switch (type)
	{
	case straightCorridor:
		_model = &Model(string("resources/objects/straight/straight.obj"));
		break;
	case cornerCorridor:
		break;
	case stairsCorridor:
		break;
	default:
		break;
	}
}

void Corridor::render(Camera* camera)
{
	glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera->GetViewMatrix();
	shader->setMat4("projection", projection);
	shader->setMat4("view", view);

	// render the loaded model
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
	model = glm::scale(model, glm::vec3(0.01f));	// it's a bit too big for our scene, so scale it down
	shader->setMat4("model", model);
	_model->Draw(*shader);
}