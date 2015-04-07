#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
//testing

// Screen dimension -- stays as constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

// Starts up SDL and creates a window "mainWindow"
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// Loads image as texture
SDL_Texture* loadTexture(std::string path);

// The window that will have textures rendered on it
SDL_Window* mainWindow = NULL;

// The window renderer
SDL_Renderer* windowRenderer = NULL;

// Current displayed texture
SDL_Texture* topTexture = NULL; // top bar texture
SDL_Texture* mapTexture = NULL; // map texture
SDL_Texture* sideTexture = NULL; // sidebar texture

bool init()
{
	// Checks for proper initialization of window
	bool success = true;

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not be initialized. SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	else
	{
		// Set texture filtering to linear
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			std::cout << "Warning: Linear texture filtering not enabled." << std::endl;
		}

		// Create window
		mainWindow = SDL_CreateWindow("Risk: The Game of Global Domination", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if(mainWindow == NULL) // if main window cannot be created for some reason, return an error
		{
			std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl;
			success = false;
		}

		else
		{
			// Create renderer for window

			windowRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);

			if(windowRenderer == NULL) // if renderer for window could not be created, return an error
			{
				std::cout << "Renderer could not be created. SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}

			else
			{
				// Initialize renderer color to default white
				SDL_SetRenderDrawColor(windowRenderer, 0x00, 0x00, 0x00, 0x00);

				// Initialize PNG image loading
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cout << "SDL_image could not initialize. SDL_image Error: " << IMG_GetError() << std::endl;
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	// Checks for proper loading of media/images to be used in main window
	bool success = true;

	//Load textures
	topTexture = loadTexture("images/viewport1.bmp");
    mapTexture = loadTexture("images/risk map.bmp");
    sideTexture = loadTexture("images/viewport3.bmp");

	if(topTexture == NULL)
	{
		std::cout << "Failed to load texture image." << std::endl;
		success = false;
	}

	// Nothing left to load
	return success;
}

void close()
{
	// Free all loaded images/textures from memory
	SDL_DestroyTexture(topTexture);
	topTexture = NULL;

    SDL_DestroyTexture(mapTexture);
	mapTexture = NULL;

	SDL_DestroyTexture(sideTexture);
	sideTexture = NULL;

	// Destroy window
	SDL_DestroyRenderer(windowRenderer);
	SDL_DestroyWindow(mainWindow);

	mainWindow = NULL;
	windowRenderer = NULL;

	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
	// The final texture
	SDL_Texture* newTexture = NULL;

	// Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if(loadedSurface == NULL)
	{
		std::cout << "Unable to load image " << path.c_str() << "\nSDL_image Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		// Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( windowRenderer, loadedSurface );

		if(newTexture == NULL)
		{
			std::cout << "Unable to create texture from " << path.c_str() << "\nSDL Error: " << IMG_GetError() << std::endl;
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

int main(int argc, char* args[])
{
	// Start up SDL and create window
	if(!init())
	{
		std::cout << "Failed to initialize." << std::endl;
	}

	else
	{
		// Load media
		if(!loadMedia())
		{
			std::cout << "Failed to load media." << std::endl;
		}

		else
		{
			// Main loop flag
			bool quit = false;

			// Event handler
			SDL_Event e;

			// While application is running
			while(!quit)
			{
				// Handle events on queue
				while(SDL_PollEvent(&e) != 0)
				{
					// User requests quit
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				// Clear screen
				SDL_SetRenderDrawColor(windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(windowRenderer);

				// Top viewport
				SDL_Rect topViewport;
				topViewport.x = 0;
				topViewport.y = 0;
				topViewport.w = SCREEN_WIDTH;
				topViewport.h = SCREEN_HEIGHT / 3;
				SDL_RenderSetViewport(windowRenderer, &topViewport);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, topTexture, NULL, NULL);

				// right side viewport
				SDL_Rect rightSideViewport;
				rightSideViewport.x = SCREEN_WIDTH / 1.5;
				rightSideViewport.y = SCREEN_HEIGHT / 3;
				rightSideViewport.w = SCREEN_WIDTH / 3;
				rightSideViewport.h = SCREEN_HEIGHT / 1.5;
				SDL_RenderSetViewport(windowRenderer, &rightSideViewport);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, sideTexture, NULL, NULL);

				// Map viewport
				SDL_Rect mapViewport;
				mapViewport.x = 0;
				mapViewport.y = SCREEN_HEIGHT / 3;
				mapViewport.w = SCREEN_WIDTH / 1.5;
				mapViewport.h = SCREEN_HEIGHT - (SCREEN_HEIGHT / 3);
				SDL_RenderSetViewport(windowRenderer, &mapViewport);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, mapTexture, NULL, NULL);

				// Update screen
				SDL_RenderPresent(windowRenderer);
			}
		}
	}

	// Free resources and close SDL
	close();

    return 0;
}
