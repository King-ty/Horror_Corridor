#include "../include/Scene.h"

Scene::Scene(Camera* camera)
{
	//��ʼ��ʱ��������������������λ�ô����м䳡����
	Corridor corridor(straightCorridor);
	corridorList.push_back(corridor);
	this->camera = camera;
}

void Scene::updateCorridor()
{
	//�ж����λ�ã������µ����ȣ�����Ӧ�÷ŵĵط�
}

void Scene::render()
{
	//����Ⱦ�м����ȣ�����Ⱦ����
	//corridorList[1].render(camera);
	//corridorList[0].render(camera);
	//corridorList[2].render(camera);
	corridorList.front().render(camera, glm::mat4(1.0f));
}