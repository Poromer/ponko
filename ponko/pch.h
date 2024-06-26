#pragma once

// STD Lib
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <random>

// SDL2
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

// Defines
#include "Defines.h"

// Math
#include "Math/Vec3.h"

// Core
#include "Core/Window.h"
#include "Core/InputHandler.h"
#include "Core/FPSController.h"
#include "Core/TextureManager.h"

// ECS
#include "ECS/ECS.h"
#include "ECS/Components/allComps.h"
// ECS - Utils
#include "ECS/EntityFactory.h"

// GSM
#include "GameState/GameStateManager.h"

// Gameplay
#include "Gameplay/Gacha.h"
