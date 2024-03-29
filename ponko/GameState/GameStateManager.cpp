/**
* @file: GameStateManager.cpp
* @author: weijie
* @date: 24 feb 2024
* @brief: gamestate manager
*/

#include "pch.h"
#include "../Core/Window.h"
#include "Scenes/AllScenes.h"


PonkoEnv::GameStateManager& PonkoEnv::GameStateManager::Get()
{
	static GameStateManager s_Instance;
	return s_Instance;
}

void PonkoEnv::GameStateManager::Init()
{
	// Init Scene
	GSM_STATES StartScene = SCENE_SPLASHSCREEN;
	GameStateManager::SetCurrent()  = GameStateManager::SetPrevious()
									= GameStateManager::SetNext()
									= StartScene;

	GameStateManager::ScenePtr() = new TestScene;
}

void PonkoEnv::GameStateManager::Update()
{
	// game loop here
	while (GameStateManager::GetCurrent() != GSM_QUIT)
	{
		if (GameStateManager::GetCurrent() != GSM_RESTART)
		{
			GameStateManager::ScenePtr()->Load();
		}
		else
		{
			GameStateManager::SetCurrent() = GameStateManager::GetPrevious();
			GameStateManager::SetNext() = GameStateManager::GetPrevious();
		}

		GameStateManager::ScenePtr()->Init();

		while (GameStateManager::GetNext() == GameStateManager::GetCurrent())
		{
			// Input
			GameStateManager::ScenePtr()->Update();
			GameStateManager::ScenePtr()->Render();
		}

		GameStateManager::ScenePtr()->Free();
		if (GameStateManager::GetNext() != GSM_RESTART)
		{
			GameStateManager::ScenePtr()->Unload();
		}

		GameStateManager::SetPrevious() = GameStateManager::GetCurrent();
		GameStateManager::SetCurrent() = GameStateManager::GetNext();
	}
}

void PonkoEnv::GameStateManager::Terminate()
{
	delete GameStateManager::ScenePtr();
}

void PonkoEnv::GameStateManager::SetNextScene(GSM_STATES _state) // this is horrible
{
	delete GameStateManager::ScenePtr();
	switch (_state)
	{
	case SCENE_SPLASHSCREEN:
		GameStateManager::ScenePtr() = new SplashScreenScene;
		break;
	case SCENE_TEST:
		GameStateManager::ScenePtr() = new TestScene;
		break;
	default:
		break;
	}
}

void PonkoEnv::GameStateManager::Quit() // this is horrible
{
	SetNext() = GSM_QUIT;
}
