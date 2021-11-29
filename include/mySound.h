#pragma once
#include "irrKlang/irrKlang.h"
#include<vector>
#include<string>

using namespace irrklang;
using namespace std;

struct Music
{
	double start_time;
	double play_time;
	string path;
};

class mySoundEngline
{
	ISoundEngine* SoundEngine;
	vector<Music>PlayingMusic;

public:
	mySoundEngline();
	~mySoundEngline();
	void play2D(const char[], int isLoop);
	void playFewSecond(const char[], double time);
private:
};

mySoundEngline::mySoundEngline()
{
	SoundEngine = createIrrKlangDevice();
}

//最简单地播放一段音乐 可选择是否循环 背景音乐
void mySoundEngline::play2D(const char musicPath[], int isLoop)
{
	SoundEngine->play2D(musicPath, isLoop);
}

//播放某段音频特定地秒数 期间再次触发本函数不再从头开始播放 脚步声等 可以用此函数
void mySoundEngline::playFewSecond(const char musicPath[], double time)
{
	string nowPath = musicPath;
	int isexist = 0;
	int isovertime = 0;
	for (vector<Music>::iterator it = PlayingMusic.begin(); it != PlayingMusic.end(); ++it)
	{
		if ((*it).path == nowPath)
		{
			isexist = 1;
			if (double(clock()) / 1000.0 - (*it).start_time > (*it).play_time)
			{
				PlayingMusic.erase(it);
				isexist = 0;
			}
			break;
		}
	}
	if (!isexist)
	{
		Music newM = {double(clock()) / 1000.0 ,time,musicPath};
		PlayingMusic.push_back(newM);
		SoundEngine->play2D(musicPath, 0);
	}
}


mySoundEngline::~mySoundEngline()
{
	SoundEngine->drop();
}