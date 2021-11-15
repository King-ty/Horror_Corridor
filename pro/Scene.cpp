#include "Scene.h"

void Scene::render()
{
	for(int i=0;i<3;i++)
		this->corridorList.at(0).render();
}