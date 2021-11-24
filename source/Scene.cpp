#include "../include/Scene.h"

Scene::Scene(Camera* camera)
{
	//初始化时随机加入三个场景，相机位置处在中间场景中
	Corridor corridor(straightCorridor);
	corridorList.push_back(corridor);
	this->camera = camera;
}

void Scene::updateCorridor()
{
	//判断相机位置，生成新的走廊，放在应该放的地方
}

void Scene::render()
{
	//先渲染中间走廊，再渲染两边
	//corridorList[1].render(camera);
	//corridorList[0].render(camera);
	//corridorList[2].render(camera);
	corridorList.front().render(camera, glm::mat4(1.0f));
}