#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

// Screen dimension -- stays as constants
const int SCREEN_WIDTH = 1440;
const int SCREEN_HEIGHT = 900;

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

// These next textures will be used to determine which player owns what provinces

// NORTH AMERICAN BOXES
SDL_Texture* NaBox1 = NULL;
SDL_Texture* NaBox2 = NULL;
SDL_Texture* NaBox3 = NULL;
SDL_Texture* NaBox4 = NULL;
SDL_Texture* NaBox5 = NULL;
SDL_Texture* NaBox6 = NULL;
SDL_Texture* NaBox7 = NULL;
SDL_Texture* NaBox8 = NULL;
SDL_Texture* NaBox9 = NULL;

// SOUTH AMERICAN BOXES
SDL_Texture* SaBox1 = NULL;
SDL_Texture* SaBox2 = NULL;
SDL_Texture* SaBox3 = NULL;
SDL_Texture* SaBox4 = NULL;

// EUROPE BOXES

SDL_Texture* EuBox1 = NULL;
SDL_Texture* EuBox2 = NULL;
SDL_Texture* EuBox3 = NULL;
SDL_Texture* EuBox4 = NULL;
SDL_Texture* EuBox5 = NULL;
SDL_Texture* EuBox6 = NULL;
SDL_Texture* EuBox7 = NULL;

// AFRICA BOXES

SDL_Texture* AfBox1 = NULL;
SDL_Texture* AfBox2 = NULL;
SDL_Texture* AfBox3 = NULL;
SDL_Texture* AfBox4 = NULL;
SDL_Texture* AfBox5 = NULL;
SDL_Texture* AfBox6 = NULL;

// ASIA BOXES

SDL_Texture* AsBox1 = NULL;
SDL_Texture* AsBox2 = NULL;
SDL_Texture* AsBox3 = NULL;
SDL_Texture* AsBox4 = NULL;
SDL_Texture* AsBox5 = NULL;
SDL_Texture* AsBox6 = NULL;
SDL_Texture* AsBox7 = NULL;
SDL_Texture* AsBox8 = NULL;
SDL_Texture* AsBox9 = NULL;
SDL_Texture* AsBox10 = NULL;
SDL_Texture* AsBox11 = NULL;
SDL_Texture* AsBox12 = NULL;

// OCEANIA BOXES

SDL_Texture* OcBox1 = NULL;
SDL_Texture* OcBox2 = NULL;
SDL_Texture* OcBox3 = NULL;
SDL_Texture* OcBox4 = NULL;

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
		mainWindow = SDL_CreateWindow("The Conquest of the World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

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

	// Map/Info Panels
	topTexture = loadTexture("images/viewport1.bmp");
    mapTexture = loadTexture("images/risk map.bmp");
    sideTexture = loadTexture("images/viewport3.bmp");

    // NORTH AMERICAN BOXES
    NaBox1 = loadTexture("images/ownerBoxN.bmp");
    NaBox2 = loadTexture("images/ownerBoxN.bmp");
    NaBox3 = loadTexture("images/ownerBoxN.bmp");
    NaBox4 = loadTexture("images/ownerBoxN.bmp");
    NaBox5 = loadTexture("images/ownerBoxN.bmp");
    NaBox6 = loadTexture("images/ownerBoxN.bmp");
    NaBox7 = loadTexture("images/ownerBoxN.bmp");
    NaBox8 = loadTexture("images/ownerBoxN.bmp");
    NaBox9 = loadTexture("images/ownerBoxN.bmp");

    // SOUTH AMERICAN BOXES
    SaBox1 = loadTexture("images/ownerBoxN.bmp");
    SaBox2 = loadTexture("images/ownerBoxN.bmp");
    SaBox3 = loadTexture("images/ownerBoxN.bmp");
    SaBox4 = loadTexture("images/ownerBoxN.bmp");

    // EUROPE BOXES

    EuBox1 = loadTexture("images/ownerBoxN.bmp");
    EuBox2 = loadTexture("images/ownerBoxN.bmp");
    EuBox3 = loadTexture("images/ownerBoxN.bmp");
    EuBox4 = loadTexture("images/ownerBoxN.bmp");
    EuBox5 = loadTexture("images/ownerBoxN.bmp");
    EuBox6 = loadTexture("images/ownerBoxN.bmp");
    EuBox7 = loadTexture("images/ownerBoxN.bmp");

    // AFRICA BOXES

    AfBox1 = loadTexture("images/ownerBoxN.bmp");
    AfBox2 = loadTexture("images/ownerBoxN.bmp");
    AfBox3 = loadTexture("images/ownerBoxN.bmp");
    AfBox4 = loadTexture("images/ownerBoxN.bmp");
    AfBox5 = loadTexture("images/ownerBoxN.bmp");
    AfBox6 = loadTexture("images/ownerBoxN.bmp");

    // ASIA BOXES

    AsBox1 = loadTexture("images/ownerBoxN.bmp");
    AsBox2 = loadTexture("images/ownerBoxN.bmp");
    AsBox3 = loadTexture("images/ownerBoxN.bmp");
    AsBox4 = loadTexture("images/ownerBoxN.bmp");
    AsBox5 = loadTexture("images/ownerBoxN.bmp");
    AsBox6 = loadTexture("images/ownerBoxN.bmp");
    AsBox7 = loadTexture("images/ownerBoxN.bmp");
    AsBox8 = loadTexture("images/ownerBoxN.bmp");
    AsBox9 = loadTexture("images/ownerBoxN.bmp");
    AsBox10 = loadTexture("images/ownerBoxN.bmp");
    AsBox11 = loadTexture("images/ownerBoxN.bmp");
    AsBox12 = loadTexture("images/ownerBoxN.bmp");

    // OCEANIA BOXES

    OcBox1 = loadTexture("images/ownerBoxN.bmp");
    OcBox2 = loadTexture("images/ownerBoxN.bmp");
    OcBox3 = loadTexture("images/ownerBoxN.bmp");
    OcBox4 = loadTexture("images/ownerBoxN.bmp");

	if(topTexture == NULL) // checks to make sure correct folder is being used for images
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

	SDL_DestroyTexture(NaBox1);
	NaBox1 = NULL;

    SDL_DestroyTexture(NaBox2);
	NaBox2 = NULL;

	SDL_DestroyTexture(NaBox3);
	NaBox3 = NULL;

	SDL_DestroyTexture(NaBox4);
	NaBox4 = NULL;

	SDL_DestroyTexture(NaBox5);
	NaBox5 = NULL;

    SDL_DestroyTexture(NaBox6);
	NaBox6 = NULL;

	SDL_DestroyTexture(NaBox7);
	NaBox7 = NULL;

    SDL_DestroyTexture(NaBox8);
	NaBox8 = NULL;

    SDL_DestroyTexture(NaBox9);
	NaBox9 = NULL;

    SDL_DestroyTexture(SaBox1);
	SaBox1 = NULL;

    SDL_DestroyTexture(SaBox2);
	SaBox2 = NULL;

	SDL_DestroyTexture(SaBox3);
	SaBox3 = NULL;

	SDL_DestroyTexture(SaBox4);
	SaBox4 = NULL;

    SDL_DestroyTexture(EuBox1);
	EuBox1 = NULL;

    SDL_DestroyTexture(EuBox2);
	EuBox2 = NULL;

	SDL_DestroyTexture(EuBox3);
	EuBox3 = NULL;

	SDL_DestroyTexture(EuBox4);
    EuBox4 = NULL;

	SDL_DestroyTexture(EuBox5);
	EuBox5 = NULL;

    SDL_DestroyTexture(EuBox6);
	EuBox6 = NULL;

	SDL_DestroyTexture(EuBox7);
	EuBox7 = NULL;

    SDL_DestroyTexture(AfBox1);
	AfBox1 = NULL;

    SDL_DestroyTexture(AfBox2);
	AfBox2 = NULL;

	SDL_DestroyTexture(AfBox3);
	AfBox3 = NULL;

	SDL_DestroyTexture(AfBox4);
	AfBox4 = NULL;

	SDL_DestroyTexture(AfBox5);
	AfBox5 = NULL;

    SDL_DestroyTexture(AfBox6);
	AfBox6 = NULL;

    SDL_DestroyTexture(AsBox1);
	AsBox1 = NULL;

    SDL_DestroyTexture(AsBox2);
	AsBox2 = NULL;

	SDL_DestroyTexture(AsBox3);
	AsBox3 = NULL;

	SDL_DestroyTexture(AsBox4);
	AsBox4 = NULL;

	SDL_DestroyTexture(AsBox5);
	AsBox5 = NULL;

    SDL_DestroyTexture(AsBox6);
	AsBox6 = NULL;

    SDL_DestroyTexture(AsBox7);
	AsBox7 = NULL;

    SDL_DestroyTexture(AsBox8);
	AsBox8 = NULL;

	SDL_DestroyTexture(AsBox9);
	AsBox9 = NULL;

	SDL_DestroyTexture(AsBox10);
	AsBox10 = NULL;

	SDL_DestroyTexture(AsBox11);
	AsBox11 = NULL;

    SDL_DestroyTexture(AsBox12);
	AsBox12 = NULL;

	SDL_DestroyTexture(OcBox1);
	OcBox1 = NULL;

    SDL_DestroyTexture(OcBox2);
	OcBox2 = NULL;

	SDL_DestroyTexture(OcBox3);
	OcBox3 = NULL;

	SDL_DestroyTexture(OcBox4);
	OcBox4 = NULL;

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
				topViewport.w = SCREEN_WIDTH - (1440 - 1175);
				topViewport.h = 300;
				SDL_RenderSetViewport(windowRenderer, &topViewport);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, topTexture, NULL, NULL);

				// right side viewport
				SDL_Rect rightSideViewport;
				rightSideViewport.x = 1175;
				rightSideViewport.y = 0;
				rightSideViewport.w = 1440 - 1175;
				rightSideViewport.h = SCREEN_HEIGHT;
				SDL_RenderSetViewport(windowRenderer, &rightSideViewport);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, sideTexture, NULL, NULL);

				// Map viewport, map is 1175x600
				SDL_Rect mapViewport;
				mapViewport.x = 0;
				mapViewport.y = 300;
				mapViewport.w = 1175;
				mapViewport.h = 600;
				SDL_RenderSetViewport(windowRenderer, &mapViewport);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, mapTexture, NULL, NULL);

                // NaBox1
				SDL_Rect NaBox1ViewPort;
				NaBox1ViewPort.x = 83;
				NaBox1ViewPort.y = 353;
				NaBox1ViewPort.w = 22;
				NaBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox1ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox1, NULL, NULL);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox1, NULL, NULL);

                // NaBox2
				SDL_Rect NaBox2ViewPort;
				NaBox2ViewPort.x = 150;
				NaBox2ViewPort.y = 400;
				NaBox2ViewPort.w = 22;
				NaBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox2ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox2, NULL, NULL);

                // NaBox3
				SDL_Rect NaBox3ViewPort;
				NaBox3ViewPort.x = 130;
				NaBox3ViewPort.y = 555;
				NaBox3ViewPort.w = 22;
				NaBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox3ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox3, NULL, NULL);

                // NaBox4
				SDL_Rect NaBox4ViewPort;
				NaBox4ViewPort.x = 190;
				NaBox4ViewPort.y = 490;
				NaBox4ViewPort.w = 22;
				NaBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox4ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox4, NULL, NULL);

                // NaBox5
				SDL_Rect NaBox5ViewPort;
				NaBox5ViewPort.x = 420;
				NaBox5ViewPort.y = 340;
				NaBox5ViewPort.w = 22;
				NaBox5ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox5ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox5, NULL, NULL);

                // NaBox6
				SDL_Rect NaBox6ViewPort;
				NaBox6ViewPort.x = 163;
				NaBox6ViewPort.y = 368;
				NaBox6ViewPort.w = 22;
				NaBox6ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox6ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox6, NULL, NULL);

                // NaBox7
				SDL_Rect NaBox7ViewPort;
				NaBox7ViewPort.x = 230;
				NaBox7ViewPort.y = 405;
				NaBox7ViewPort.w = 22;
				NaBox7ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox7ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox7, NULL, NULL);

                // NaBox8
				SDL_Rect NaBox8ViewPort;
				NaBox8ViewPort.x = 310;
				NaBox8ViewPort.y = 405;
				NaBox8ViewPort.w = 22;
				NaBox8ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox8ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox8, NULL, NULL);

                // NaBox9
				SDL_Rect NaBox9ViewPort;
				NaBox9ViewPort.x = 130;
				NaBox9ViewPort.y = 455;
				NaBox9ViewPort.w = 22;
				NaBox9ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox9ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox9, NULL, NULL);

                // SaBox1
				SDL_Rect SaBox1ViewPort;
				SaBox1ViewPort.x = 295;
				SaBox1ViewPort.y = 790;
				SaBox1ViewPort.w = 22;
				SaBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &SaBox1ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, SaBox1, NULL, NULL);

                // SaBox2
				SDL_Rect SaBox2ViewPort;
				SaBox2ViewPort.x = 345;
				SaBox2ViewPort.y = 695;
				SaBox2ViewPort.w = 22;
				SaBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &SaBox2ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, SaBox2, NULL, NULL);

                // SaBox3
				SDL_Rect SaBox3ViewPort;
				SaBox3ViewPort.x = 285;
				SaBox3ViewPort.y = 725;
				SaBox3ViewPort.w = 22;
				SaBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &SaBox3ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, SaBox3, NULL, NULL);

                // SaBox4
				SDL_Rect SaBox4ViewPort;
				SaBox4ViewPort.x = 275;
				SaBox4ViewPort.y = 615;
				SaBox4ViewPort.w = 22;
				SaBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &SaBox4ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, SaBox4, NULL, NULL);

                // EuBox1
				SDL_Rect EuBox1ViewPort;
				EuBox1ViewPort.x = 500;
				EuBox1ViewPort.y = 420;
				EuBox1ViewPort.w = 22;
				EuBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox1ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox1, NULL, NULL);

                // EuBox2
				SDL_Rect EuBox2ViewPort;
                EuBox2ViewPort.x = 480;
                EuBox2ViewPort.y = 385;
				EuBox2ViewPort.w = 22;
				EuBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox2ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox2, NULL, NULL);

                // EuBox3
				SDL_Rect EuBox3ViewPort;
				EuBox3ViewPort.x = 610;
				EuBox3ViewPort.y = 415;
				EuBox3ViewPort.w = 22;
				EuBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox3ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox3, NULL, NULL);

                // EuBox4
				SDL_Rect EuBox4ViewPort;
				EuBox4ViewPort.x = 595;
				EuBox4ViewPort.y = 385;
				EuBox4ViewPort.w = 22;
				EuBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox4ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox4, NULL, NULL);

                // EuBox5
				SDL_Rect EuBox5ViewPort;
				EuBox5ViewPort.x = 640;
				EuBox5ViewPort.y = 450;
				EuBox5ViewPort.w = 22;
				EuBox5ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox5ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox5, NULL, NULL);

                // EuBox6
				SDL_Rect EuBox6ViewPort;
				EuBox6ViewPort.x = 690;
				EuBox6ViewPort.y = 400;
				EuBox6ViewPort.w = 22;
				EuBox6ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox6ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox6, NULL, NULL);

				// EuBox7
				SDL_Rect EuBox7ViewPort;
				EuBox7ViewPort.x = 525;
				EuBox7ViewPort.y = 465;
				EuBox7ViewPort.w = 22;
				EuBox7ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox7ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox7, NULL, NULL);

				// AfBox1
				SDL_Rect AfBox1ViewPort;
				AfBox1ViewPort.x = 645;
				AfBox1ViewPort.y = 645;
				AfBox1ViewPort.w = 22;
				AfBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox1ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox1, NULL, NULL);

				// AfBox2
				SDL_Rect AfBox2ViewPort;
				AfBox2ViewPort.x = 675;
				AfBox2ViewPort.y = 610;
				AfBox2ViewPort.w = 22;
				AfBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox2ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox2, NULL, NULL);

				// AfBox3
				SDL_Rect AfBox3ViewPort;
				AfBox3ViewPort.x = 650;
				AfBox3ViewPort.y = 525;
				AfBox3ViewPort.w = 22;
				AfBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox3ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox3, NULL, NULL);

				// AfBox4
				SDL_Rect AfBox4ViewPort;
				AfBox4ViewPort.x = 730;
				AfBox4ViewPort.y = 755;
				AfBox4ViewPort.w = 22;
				AfBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox4ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox4, NULL, NULL);

				// AfBox5
				SDL_Rect AfBox5ViewPort;
				AfBox5ViewPort.x = 555;
				AfBox5ViewPort.y = 565;
				AfBox5ViewPort.w = 22;
				AfBox5ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox5ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox5, NULL, NULL);

                // AfBox6
				SDL_Rect AfBox6ViewPort;
				AfBox6ViewPort.x = 650;
				AfBox6ViewPort.y = 735;
				AfBox6ViewPort.w = 22;
				AfBox6ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox6ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox6, NULL, NULL);

                // AsBox1
				SDL_Rect AsBox1ViewPort;
				AsBox1ViewPort.x = 800;
				AsBox1ViewPort.y = 443;
				AsBox1ViewPort.w = 22;
				AsBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox1ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox1, NULL, NULL);

				// AsBox2
				SDL_Rect AsBox2ViewPort;
				AsBox2ViewPort.x = 955;
				AsBox2ViewPort.y = 495;
				AsBox2ViewPort.w = 22;
				AsBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox2ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox2, NULL, NULL);

				// AsBox3
				SDL_Rect AsBox3ViewPort;
				AsBox3ViewPort.x = 875;
				AsBox3ViewPort.y = 540;
				AsBox3ViewPort.w = 22;
				AsBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox3ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox3, NULL, NULL);

				// AsBox4
				SDL_Rect AsBox4ViewPort;
				AsBox4ViewPort.x = 915;
				AsBox4ViewPort.y = 400;
				AsBox4ViewPort.w = 22;
				AsBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox4ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox4, NULL, NULL);

				// AsBox5
				SDL_Rect AsBox5ViewPort;
				AsBox5ViewPort.x = 1090;
				AsBox5ViewPort.y = 500;
				AsBox5ViewPort.w = 22;
				AsBox5ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox5ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox5, NULL, NULL);

				// AsBox6
				SDL_Rect AsBox6ViewPort;
				AsBox6ViewPort.x = 1075;
				AsBox6ViewPort.y = 360;
				AsBox6ViewPort.w = 22;
				AsBox6ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox6ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox6, NULL, NULL);

				// AsBox7
				SDL_Rect AsBox7ViewPort;
				AsBox7ViewPort.x = 725;
				AsBox7ViewPort.y = 495;
				AsBox7ViewPort.w = 22;
				AsBox7ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox7ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox7, NULL, NULL);

				// AsBox8
				SDL_Rect AsBox8ViewPort;
				AsBox8ViewPort.x = 965;
                AsBox8ViewPort.y = 440;
				AsBox8ViewPort.w = 22;
                AsBox8ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox8ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox8, NULL, NULL);

				// AsBox9
				SDL_Rect AsBox9ViewPort;
				AsBox9ViewPort.x = 940;
				AsBox9ViewPort.y = 560;
				AsBox9ViewPort.w = 22;
				AsBox9ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox9ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox9, NULL, NULL);

				// AsBox10
				SDL_Rect AsBox10ViewPort;
				AsBox10ViewPort.x = 870;
				AsBox10ViewPort.y = 360;
				AsBox10ViewPort.w = 22;
				AsBox10ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox10ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox10, NULL, NULL);

				// AsBox11
				SDL_Rect AsBox11ViewPort;
				AsBox11ViewPort.x = 800;
				AsBox11ViewPort.y = 380;
				AsBox11ViewPort.w = 22;
				AsBox11ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox11ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox11, NULL, NULL);

				// AsBox12
				SDL_Rect AsBox12ViewPort;
				AsBox12ViewPort.x = 970;
				AsBox12ViewPort.y = 358;
				AsBox12ViewPort.w = 22;
				AsBox12ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox12ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox12, NULL, NULL);

				// OcBox1
				SDL_Rect OcBox1ViewPort;
				OcBox1ViewPort.x = 1125;
				OcBox1ViewPort.y = 780;
				OcBox1ViewPort.w = 22;
				OcBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &OcBox1ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, OcBox1, NULL, NULL);

				// OcBox2
				SDL_Rect OcBox2ViewPort;
				OcBox2ViewPort.x = 1005;
				OcBox2ViewPort.y = 665;
				OcBox2ViewPort.w = 22;
				OcBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &OcBox2ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, OcBox2, NULL, NULL);

                // OcBox3
				SDL_Rect OcBox3ViewPort;
				OcBox3ViewPort.x = 1145;
				OcBox3ViewPort.y = 675;
				OcBox3ViewPort.w = 22;
				OcBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &OcBox3ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, OcBox3, NULL, NULL);

				// OcBox4
				SDL_Rect OcBox4ViewPort;
				OcBox4ViewPort.x = 1045;
				OcBox4ViewPort.y = 775;
				OcBox4ViewPort.w = 22;
				OcBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &OcBox4ViewPort);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, OcBox4, NULL, NULL);


                // testing changing box color/viewport size
/*
				int num = 3;

				if(num == 4) // just changes a box color
                {
                        NaBox1 = loadTexture("images/ownerBoxR.bmp");
                }

                if(num == 3) // changes box colors and viewport size
                {
                        NaBox1 = loadTexture("images/ownerBoxG.bmp");

                        NaBox1ViewPort.w = 33;
                        NaBox1ViewPort.h = 24;

                        SDL_RenderSetViewport(windowRenderer, &NaBox1ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox1, NULL, NULL);

                        NaBox5 = loadTexture("images/ownerBoxY.bmp");

                        NaBox5ViewPort.w = 33;
                        NaBox5ViewPort.h = 24;

                        SDL_RenderSetViewport(windowRenderer, &NaBox5ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox5, NULL, NULL);
                }*/

				// Update screen
				SDL_RenderPresent(windowRenderer);
			}
		}
	}

	// Free resources and close SDL
	close();

    return 0;
}
