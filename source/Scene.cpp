#include "../include/Scene.h"

Scene::Scene(Camera* camera)
{
	pos = mid;
	//初始化时随机加入三个场景，相机位置处在中间场景中
	mid_model = front_model = back_model =glm::mat4(1.0f);

	Corridor corridor_mid(straightCorridor,zN);
	mid_model = glm::mat4(1.0f);
	mid_if = glm::vec3(0.0f);
	
	Corridor corridor_front(stairsCorridorU, zN);
	front_model = glm::translate(front_model, glm::vec3(0.0f, 0.0f, -10.0f));
	//front_model = glm::rotate(front_model, glm::radians(180.0f), glm::vec3(0.0, 1.0, 0.0));
	front_if = mid_if + glm::vec3(0.0f, 4.8f, -10.0f);
	corridorList.push_back(corridor_front);
	corridorList.push_back(corridor_mid);

	Corridor corridor_back(cornerCorridorL, zP);
	back_model = glm::translate(back_model, glm::vec3(10, 0, 10));
	back_model = glm::rotate(back_model, glm::radians(90.0f),glm::vec3(0, 1.0, 0));
	back_if= mid_if+glm::vec3(10,0,10);
	corridorList.push_back(corridor_back);

	this->camera = camera;
}

void Scene::updateCorridor()
{
	//判断相机位置，生成新的走廊，放在应该放的地方
	cout << getPos() <<' ' << camera->Position.x << ' ' << camera->Position.z << endl;
	pos = getPos();
	if (pos==mid)
		return;

	//corridorType newCorridorType = genNewCorridor(corridorList[0].type);
	corridorType newCorridorType = straightCorridor;
	corridorDir newCorridorDir;
	if (corridorList[0].type == cornerCorridorL)
	{
		int t = corridorList[0].dir - 1;
		if (t < 0)
			t += 4;
		newCorridorDir = corridorDir(t);
	}
	else if (corridorList[0].type == cornerCorridorR)
	{
		int t = (corridorList[0].dir + 1) % 4;
		newCorridorDir = corridorDir(t);
	}
	else
		newCorridorDir = corridorList[0].dir;

	Corridor newCorridor(newCorridorType, newCorridorDir);

	if (pos == front);
	{
		corridorList.pop_back();
		back_if = mid_if;
		back_model = mid_model;
		mid_if = front_if;
		mid_model = front_model;

		if (newCorridorType == straightCorridor)
		{
			front_if = mid_if;
			if (newCorridorDir == xP)
			{
				front_if += glm::vec3(10, 0, 0);
				front_model = glm::translate(glm::mat4(1.0f), mid_if + glm::vec3(0, 0, -10));
				front_model = glm::rotate(front_model, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
			}
			else if(newCorridorDir == xN)
			{
				front_if += glm::vec3(-10, 0, 0);
			}
			else if (newCorridorDir == zP)
			{
				front_if += glm::vec3(0, 0, 10);
			}
			else
			{ 
				front_if += glm::vec3(0, 0, -10);
				front_model=glm::translate(glm::mat4(1.0f), mid_if+ glm::vec3(0, 0, -10));
			}	
		}
		else if(newCorridorType)
		{

		}
	}

	corridorList.insert(corridorList.begin(), newCorridor);
	
}

void Scene::render()
{
	//先渲染中间走廊，再渲染两边
	corridorList[1].render(camera,mid_model);
	corridorList[0].render(camera,front_model);
	corridorList[2].render(camera, back_model);
}

camera_pos Scene::getPos()
{
	if (corridorList[0].dir == corridorList[1].dir)
	{
		if (corridorList[0].dir == xP)
		{
			if (mid_if.x + 10 < camera->Position.x && camera->Position.x < mid_if.x + 20)
				return front;
		}
		if (corridorList[0].dir == xN)
		{
			if (mid_if.x - 20 < camera->Position.x && camera->Position.x < mid_if.x - 10)
				return front;
		}
		if (corridorList[0].dir == zP)
		{
			if (mid_if.z + 10 < camera->Position.z && camera->Position.z < mid_if.z + 20)
				return front;
		}
		if (corridorList[0].dir == zN)
		{
			if (mid_if.z - 20 < camera->Position.z && camera->Position.z < mid_if.z - 10)
				return front;
		}
	}
	else
	{
		if (corridorList[0].dir == xP)
		{
			if (mid_if.x < camera->Position.x && camera->Position.x < mid_if.x + 10)
				return front;
		}
		if (corridorList[0].dir == xN)
		{
			if (mid_if.x - 10 < camera->Position.x && camera->Position.x < mid_if.x)
				return front;
		}
		if (corridorList[0].dir == zP)
		{
			if (mid_if.z < camera->Position.z && camera->Position.z < mid_if.z + 10)
				return front;
		}
		if (corridorList[0].dir == zN)
		{
			if (mid_if.z - 10 < camera->Position.z && camera->Position.z < mid_if.z)
				return front;
		}
	}

	if (corridorList[2].dir == corridorList[1].dir)
	{
		if (corridorList[2].dir == xP)
		{
			if (mid_if.x + 10 < camera->Position.x && camera->Position.x < mid_if.x + 20)
				return front;
		}
		if (corridorList[2].dir == xN)
		{
			if (mid_if.x - 20 < camera->Position.x && camera->Position.x < mid_if.x - 10)
				return front;
		}
		if (corridorList[2].dir == zP)
		{
			if (mid_if.z + 10 < camera->Position.z && camera->Position.z < mid_if.z + 20)
				return front;
		}
		if (corridorList[2].dir == zN)
		{
			if (mid_if.z - 20 < camera->Position.z && camera->Position.z < mid_if.z - 10)
				return front;
		}
	}
	else
	{
		if (corridorList[2].dir == xP)
		{
			if (mid_if.x < camera->Position.x && camera->Position.x < mid_if.x + 10)
				return front;
		}
		if (corridorList[2].dir == xN)
		{
			if (mid_if.x - 10 < camera->Position.x && camera->Position.x < mid_if.x)
				return front;
		}
		if (corridorList[2].dir == zP)
		{
			if (mid_if.z < camera->Position.z && camera->Position.z < mid_if.z + 10)
				return front;
		}
		if (corridorList[2].dir == zN)
		{
			if (mid_if.z - 10 < camera->Position.z && camera->Position.z < mid_if.z)
				return front;
		}
	}
	
	return mid;
}
corridorType Scene::genNewCorridor(corridorType mid)
{
	corridorType list[5] = { cornerCorridorL,cornerCorridorR,stairsCorridorU,stairsCorridorD,straightCorridor };
	if (mid == straightCorridor)
	{
		int rand_num = rand() % 4;
		return list[rand_num];
	}
	else
	{
		int rand_num = rand() % 5;
		return list[rand_num];
	}
}