/**
* @file: Window.h
* @author: weijie
* @date: 25 feb 2024
* @brief: window wrapper header file
*/

#include "SDL.h"

#ifndef PK_WINDOW_H
#define PK_WINDOW_H
	namespace PonkoEnv
	{
		class PK_Window
		{
		public:
			PK_Window(PK_Window const&) = delete;
			PK_Window& operator= (PK_Window const&) = delete;

			static PK_Window& Get();
			SDL_Window* GetSDLWindow();
			SDL_Renderer* GetSDLRender();

			void ConstructWindow(const char* _title,
				int const& _width, int const& _height);

		private:
			PK_Window() {};
			~PK_Window();

			const char*		m_windowTitle{};
			int				m_windowWidth{};
			int				m_windowHeight{};
			bool			m_fullscreen{};

			SDL_Window*		sdl_Window;
			SDL_Renderer*	m_render;
		};

	}
#endif // !PK_WINDOW_H

