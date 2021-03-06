#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "World.h"
#include "Territory.h"
#include "Player.h"
#include "Game.h"
#include "Deck.h"

// Screen dimension -- stays as constants
const int SCREEN_WIDTH = 1440;
const int SCREEN_HEIGHT = 900;

std::string player1Name;
std::string player2Name;
std::string player3Name;
std::string player4Name;

// Starts up SDL and creates a window "mainWindow"
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// Loads image as texture
SDL_Texture* loadTexture(std::string path);

// Loads text as a texture, size if font size
SDL_Texture* loadText(std::string text, int size);

// Changes color of map tiles based on owner
SDL_Texture* updateColors(Territory* territory_number);

// Change the dice textures
//void changeDie(int dieNum, int value);

//  Update changes in counts of units
void changeNumTerr(Territory* territory_name, SDL_Texture** currTexture);

// This updates the counts in the upper menus.
void changeNumTop(std::vector<Player>* players);

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

// Here are the boxes that lay over for unit count, denoted with the color texture followed by an n.

// NORTH AMERICAN BOXES
SDL_Texture* NaBox1n = NULL;
SDL_Texture* NaBox2n = NULL;
SDL_Texture* NaBox3n = NULL;
SDL_Texture* NaBox4n = NULL;
SDL_Texture* NaBox5n = NULL;
SDL_Texture* NaBox6n = NULL;
SDL_Texture* NaBox7n = NULL;
SDL_Texture* NaBox8n = NULL;
SDL_Texture* NaBox9n = NULL;

// SOUTH AMERICAN BOXES
SDL_Texture* SaBox1n = NULL;
SDL_Texture* SaBox2n = NULL;
SDL_Texture* SaBox3n = NULL;
SDL_Texture* SaBox4n = NULL;

// EUROPE BOXES

SDL_Texture* EuBox1n = NULL;
SDL_Texture* EuBox2n = NULL;
SDL_Texture* EuBox3n = NULL;
SDL_Texture* EuBox4n = NULL;
SDL_Texture* EuBox5n = NULL;
SDL_Texture* EuBox6n = NULL;
SDL_Texture* EuBox7n = NULL;

// AFRICA BOXES

SDL_Texture* AfBox1n = NULL;
SDL_Texture* AfBox2n = NULL;
SDL_Texture* AfBox3n = NULL;
SDL_Texture* AfBox4n = NULL;
SDL_Texture* AfBox5n = NULL;
SDL_Texture* AfBox6n = NULL;

// ASIA BOXES

SDL_Texture* AsBox1n = NULL;
SDL_Texture* AsBox2n = NULL;
SDL_Texture* AsBox3n = NULL;
SDL_Texture* AsBox4n = NULL;
SDL_Texture* AsBox5n = NULL;
SDL_Texture* AsBox6n = NULL;
SDL_Texture* AsBox7n = NULL;
SDL_Texture* AsBox8n = NULL;
SDL_Texture* AsBox9n = NULL;
SDL_Texture* AsBox10n = NULL;
SDL_Texture* AsBox11n = NULL;
SDL_Texture* AsBox12n = NULL;

// OCEANIA BOXES

SDL_Texture* OcBox1n = NULL;
SDL_Texture* OcBox2n = NULL;
SDL_Texture* OcBox3n = NULL;
SDL_Texture* OcBox4n = NULL;

// Here we begin the menu boxes

// PLAYER 1 BOXES
SDL_Texture* P1_Name = NULL;
SDL_Texture* P1_TerritoryCount = NULL;
SDL_Texture* P1_UnitsPerTurn = NULL;
SDL_Texture* P1_StarCount = NULL;
SDL_Texture* P1_ActiveIndicator = NULL;
SDL_Texture* P1_InstructBox = NULL;

// PLAYER 2 BOXES
SDL_Texture* P2_Name = NULL;
SDL_Texture* P2_TerritoryCount = NULL;
SDL_Texture* P2_UnitsPerTurn = NULL;
SDL_Texture* P2_StarCount = NULL;
SDL_Texture* P2_ActiveIndicator = NULL;
SDL_Texture* P2_InstructBox = NULL;

// PLAYER 3 BOXES
SDL_Texture* P3_Name = NULL;
SDL_Texture* P3_TerritoryCount = NULL;
SDL_Texture* P3_UnitsPerTurn = NULL;
SDL_Texture* P3_StarCount = NULL;
SDL_Texture* P3_ActiveIndicator = NULL;
SDL_Texture* P3_InstructBox = NULL;

// PLAYER 4 BOXES
SDL_Texture* P4_Name = NULL;
SDL_Texture* P4_TerritoryCount = NULL;
SDL_Texture* P4_UnitsPerTurn = NULL;
SDL_Texture* P4_StarCount = NULL;
SDL_Texture* P4_ActiveIndicator = NULL;
SDL_Texture* P4_InstructBox = NULL;

// DICE BOXES
SDL_Texture* A_Die1 = NULL;
SDL_Texture* A_Die2 = NULL;
SDL_Texture* A_Die3 = NULL;
SDL_Texture* D_Die1 = NULL;
SDL_Texture* D_Die2 = NULL;

// Declarations used to keep track of upper menu elements currently displayed
// CANNOT BE PULLED FROM THE UI, as it is displayed all via strings

unsigned int p1tc = 0, p2tc = 0, p3tc = 0, p4tc = 0;
int p1sc = 0, p2sc = 0, p3sc = 0, p4sc = 0;
int p1tpt = 0, p2tpt = 0, p3tpt = 0, p4tpt = 0;
int currPlayer = -1;

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

				// Initialize TTF library
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
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

    // TOP MENU BOXES
    P1_ActiveIndicator = loadTexture("images/nullAct.png");
    //P1_InstructBox = loadText("Ready " + player1Name, 16 );
    //P1_Name = loadText(player1Name, 18);
    P1_StarCount = loadText("0", 16);
    P1_TerritoryCount = loadText("0", 16);
    P1_UnitsPerTurn = loadText("0", 16);

    P2_ActiveIndicator = loadTexture("images/nullAct.png");
    //P2_InstructBox = loadText("Ready " + player2Name, 16 );
    //P2_Name = loadText(player2Name, 18);
    P2_StarCount = loadText("0", 16);
    P2_TerritoryCount = loadText("0", 16);
    P2_UnitsPerTurn = loadText("0", 16);

    P3_ActiveIndicator = loadTexture("images/nullAct.png");
    //P3_InstructBox = loadText("Ready " + player3Name, 16 );
    //P3_Name = loadText(player3Name, 18);
    P3_StarCount = loadText("0", 16);
    P3_TerritoryCount = loadText("0", 16);
    P3_UnitsPerTurn = loadText("0", 16);

    P4_ActiveIndicator = loadTexture("images/nullAct.png");
    //P4_InstructBox = loadText("Ready " + player4Name, 16 );
    //P4_Name = loadText(player4Name, 18);
    P4_StarCount = loadText("0", 16);
    P4_TerritoryCount = loadText("0", 16);
    P4_UnitsPerTurn = loadText("0", 16);

    //Initialize dice with blank image
    A_Die1 = loadTexture("images/nullDie.bmp");
    A_Die2 = loadTexture("images/nullDie.bmp");
    A_Die3 = loadTexture("images/nullDie.bmp");
    D_Die1 = loadTexture("images/nullDie.bmp");
    D_Die2 = loadTexture("images/nullDie.bmp");

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

    SDL_DestroyTexture(P1_Name);
    P1_Name = NULL;

    SDL_DestroyTexture(P1_TerritoryCount);
    P1_TerritoryCount = NULL;

    SDL_DestroyTexture(P1_UnitsPerTurn);
    P1_UnitsPerTurn = NULL;

    SDL_DestroyTexture(P1_StarCount);
    P1_StarCount = NULL;

    SDL_DestroyTexture(P1_ActiveIndicator);
    P1_ActiveIndicator = NULL;

    SDL_DestroyTexture(P1_InstructBox);
    P1_InstructBox = NULL;

    SDL_DestroyTexture(P2_Name);
    P2_Name = NULL;

    SDL_DestroyTexture(P2_TerritoryCount);
    P2_TerritoryCount = NULL;

    SDL_DestroyTexture(P2_UnitsPerTurn);
    P2_UnitsPerTurn = NULL;

    SDL_DestroyTexture(P2_StarCount);
    P2_StarCount = NULL;

    SDL_DestroyTexture(P2_ActiveIndicator);
    P2_ActiveIndicator = NULL;

    SDL_DestroyTexture(P2_InstructBox);
    P2_InstructBox = NULL;

    SDL_DestroyTexture(P3_Name);
    P3_Name = NULL;

    SDL_DestroyTexture(P3_TerritoryCount);
    P3_TerritoryCount = NULL;

    SDL_DestroyTexture(P3_UnitsPerTurn);
    P3_UnitsPerTurn = NULL;

    SDL_DestroyTexture(P3_StarCount);
    P3_StarCount = NULL;

    SDL_DestroyTexture(P3_ActiveIndicator);
    P3_ActiveIndicator = NULL;

    SDL_DestroyTexture(P3_InstructBox);
    P3_InstructBox = NULL;

    SDL_DestroyTexture(P4_Name);
    P4_Name = NULL;

    SDL_DestroyTexture(P4_TerritoryCount);
    P4_TerritoryCount = NULL;

    SDL_DestroyTexture(P4_UnitsPerTurn);
    P4_UnitsPerTurn = NULL;

    SDL_DestroyTexture(P4_StarCount);
    P4_StarCount = NULL;

    SDL_DestroyTexture(P4_ActiveIndicator);
    P4_ActiveIndicator = NULL;

    SDL_DestroyTexture(P4_InstructBox);
    P4_InstructBox = NULL;

    SDL_DestroyTexture(A_Die1);
    A_Die1 = NULL;

    SDL_DestroyTexture(A_Die2);
    A_Die2 = NULL;

    SDL_DestroyTexture(A_Die3);
    A_Die3 = NULL;

    SDL_DestroyTexture(D_Die1);
    D_Die1 = NULL;

    SDL_DestroyTexture(D_Die2);
    D_Die2 = NULL;

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

SDL_Texture* loadText(std::string text, int size)
{
    // The final texture
    SDL_Texture* newTexture = NULL;
    SDL_Color color = { 0, 0, 0 };

    // Generate some text
    SDL_Surface* textSurface = TTF_RenderText_Solid(  TTF_OpenFont( "DejaVuSerif.ttf", size), text.c_str(), color);

    if(textSurface == NULL)
        {
            printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( windowRenderer, textSurface );

        if(newTexture == NULL)
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
/*        else
        {
            //Get image dimensions
            width = textSurface->w;
            height = textSurface->h;
        }
*/
        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return newTexture;
}

SDL_Texture* updateColors(Territory* territory_number)
{
    switch(territory_number->getOwner()){

        case 0:
            return loadTexture("images/ownerBoxR.bmp");
            break;

        case 1:
            return loadTexture("images/ownerBoxY.bmp");
            break;

        case 2:
            return loadTexture("images/ownerBoxG.bmp");
            break;

        case 3:
            return loadTexture("images/ownerBoxB.bmp");
            break;

        default:
            return loadTexture("images/ownerBoxN.bmp");
            break;
    }
}

void changeDie(int* diceArray)
{

    for(int dieNum=1; dieNum<6; dieNum++)
    {
        int value = std::abs( diceArray[dieNum-1]);

        switch(dieNum){

            case 1:
                SDL_DestroyTexture(A_Die1);

                switch(value){

                    case 1:
                        A_Die1 = loadTexture("images/Die1.bmp");
                        break;

                    case 2:
                        A_Die1 = loadTexture("images/Die2.bmp");
                        break;

                    case 3:
                        A_Die1 = loadTexture("images/Die3.bmp");
                        break;

                    case 4:
                        A_Die1 = loadTexture("images/Die4.bmp");
                        break;

                    case 5:
                        A_Die1 = loadTexture("images/Die5.bmp");
                        break;

                    case 6:
                        A_Die1 = loadTexture("images/Die6.bmp");
                        break;

                    default:
                        A_Die1 = loadTexture("images/nullDie.bmp");
                        break;
                }

                break;

            case 2:
                SDL_DestroyTexture(A_Die2);

                switch(value){

                    case 1:
                        A_Die2 = loadTexture("images/Die1.bmp");
                        break;

                    case 2:
                        A_Die2 = loadTexture("images/Die2.bmp");
                        break;

                    case 3:
                        A_Die2 = loadTexture("images/Die3.bmp");
                        break;

                    case 4:
                        A_Die2 = loadTexture("images/Die4.bmp");
                        break;

                    case 5:
                        A_Die2 = loadTexture("images/Die5.bmp");
                        break;

                    case 6:
                        A_Die2 = loadTexture("images/Die6.bmp");
                        break;

                    default:
                        A_Die2 = loadTexture("images/nullDie.bmp");
                        break;
                }

                break;

            case 3:
                SDL_DestroyTexture(A_Die3);

                switch(value){

                    case 1:
                        A_Die3 = loadTexture("images/Die1.bmp");
                        break;

                    case 2:
                        A_Die3 = loadTexture("images/Die2.bmp");
                        break;

                    case 3:
                        A_Die3 = loadTexture("images/Die3.bmp");
                        break;

                    case 4:
                        A_Die3 = loadTexture("images/Die4.bmp");
                        break;

                    case 5:
                        A_Die3 = loadTexture("images/Die5.bmp");
                        break;

                    case 6:
                        A_Die3 = loadTexture("images/Die6.bmp");
                        break;

                    default:
                        A_Die3 = loadTexture("images/nullDie.bmp");
                        break;
                }

                break;

            case 4:
                SDL_DestroyTexture(D_Die1);

                switch(value){

                    case 1:
                        D_Die1 = loadTexture("images/Die1.bmp");
                        break;

                    case 2:
                        D_Die1 = loadTexture("images/Die2.bmp");
                        break;

                    case 3:
                        D_Die1 = loadTexture("images/Die3.bmp");
                        break;

                    case 4:
                        D_Die1 = loadTexture("images/Die4.bmp");
                        break;

                    case 5:
                        D_Die1 = loadTexture("images/Die5.bmp");
                        break;

                    case 6:
                        D_Die1 = loadTexture("images/Die6.bmp");
                        break;

                    default:
                        D_Die1 = loadTexture("images/nullDie.bmp");
                        break;
                }

                break;

            case 5:
                SDL_DestroyTexture(D_Die2);

                switch(value){

                    case 1:
                        D_Die2 = loadTexture("images/Die1.bmp");
                        break;

                    case 2:
                        D_Die2 = loadTexture("images/Die2.bmp");
                        break;

                    case 3:
                        D_Die2 = loadTexture("images/Die3.bmp");
                        break;

                    case 4:
                        D_Die2 = loadTexture("images/Die4.bmp");
                        break;

                    case 5:
                        D_Die2 = loadTexture("images/Die5.bmp");
                        break;

                    case 6:
                        D_Die2 = loadTexture("images/Die6.bmp");
                        break;

                    default:
                        D_Die2 = loadTexture("images/nullDie.bmp");
                        break;
                }

                break;
        }
    }
}

void changeNumTerr(Territory* territory_name, SDL_Texture** currTexture)
{
    stringstream ss;

    // Updates the tiles for each
    if(territory_name->troopsChanged){

        territory_name->troopsChanged = false;
        ss << territory_name->getTroops();

        SDL_DestroyTexture(*currTexture);

        *currTexture = loadText(ss.str(), 10);


    }
}

void changeNumTop(std::vector<Player>* players)
{
    Player tempPlayer = players->at(0);

 //   std::cout << (tempPlayer.getControlledTerritories()).size() << std::endl;

    if((players->at(0).getControlledTerritories()).size() != p1tc)
    {
        stringstream ss;

        p1tc = (players->at(0).getControlledTerritories()).size();

        ss << p1tc;

        SDL_DestroyTexture(P1_TerritoryCount);

        P1_TerritoryCount = loadText(ss.str(),16);
    }

    if(players->at(0).getStars() != p1sc)
    {
        stringstream ss;

        p1sc = players->at(0).getStars();

        ss << p1sc;

        SDL_DestroyTexture(P1_StarCount);

        P1_StarCount = loadText(ss.str(),16);
    }

    if(players->at(0).getTroopsPerTurn() != p1tpt)
    {
        stringstream ss;

        p1tpt = players->at(0).getTroopsPerTurn();

        ss << p1tpt;

        SDL_DestroyTexture(P1_UnitsPerTurn);

        P1_UnitsPerTurn = loadText(ss.str(),16);
    }

    tempPlayer = players->at(1);

    if((tempPlayer.getControlledTerritories()).size() != p2tc)
    {
        stringstream ss;

        p2tc = (tempPlayer.getControlledTerritories()).size();

        ss << p2tc;

        SDL_DestroyTexture(P2_TerritoryCount);

        P2_TerritoryCount = loadText(ss.str(),16);
    }

    if(tempPlayer.getStars() != p2sc)
    {
        stringstream ss;

        p1sc = tempPlayer.getStars();

        ss << p2sc;

        SDL_DestroyTexture(P2_StarCount);

        P2_StarCount = loadText(ss.str(),16);
    }

    if(tempPlayer.getTroopsPerTurn() != p2tpt)
    {
        stringstream ss;

        p2tpt = tempPlayer.getTroopsPerTurn();

        ss << p2tpt;

        SDL_DestroyTexture(P2_UnitsPerTurn);

        P2_UnitsPerTurn = loadText(ss.str(),16);
    }

    tempPlayer = players->at(2);

        if((tempPlayer.getControlledTerritories()).size() != p3tc)
    {
        stringstream ss;

        p3tc = (tempPlayer.getControlledTerritories()).size();

        ss << p3tc;

        SDL_DestroyTexture(P3_TerritoryCount);

        P3_TerritoryCount = loadText(ss.str(),16);
    }

    if(tempPlayer.getStars() != p3sc)
    {
        stringstream ss;

        p3sc = tempPlayer.getStars();

        ss << p3sc;

        SDL_DestroyTexture(P3_StarCount);

        P3_StarCount = loadText(ss.str(),16);
    }

    if(tempPlayer.getTroopsPerTurn() != p3tpt)
    {
        stringstream ss;

        p3tpt = tempPlayer.getTroopsPerTurn();

        ss << p3tpt;

        SDL_DestroyTexture(P3_UnitsPerTurn);

        P3_UnitsPerTurn = loadText(ss.str(),16);
    }

    tempPlayer = players->at(3);

    if((tempPlayer.getControlledTerritories()).size() != p4tc)
    {
        stringstream ss;

        p4tc = (tempPlayer.getControlledTerritories()).size();

        ss << p4tc;

        SDL_DestroyTexture(P4_TerritoryCount);

        P4_TerritoryCount = loadText(ss.str(),16);
    }

    if(tempPlayer.getStars() != p4sc)
    {
        stringstream ss;

        p4sc = tempPlayer.getStars();

        ss << p4sc;

        SDL_DestroyTexture(P4_StarCount);

        P4_StarCount = loadText(ss.str(),16);
    }

    if(tempPlayer.getTroopsPerTurn() != p4tpt)
    {
        stringstream ss;

        p4tpt = tempPlayer.getTroopsPerTurn();

        ss << p4tpt;

        SDL_DestroyTexture(P4_UnitsPerTurn);

        P4_UnitsPerTurn = loadText(ss.str(),16);
    }

}

void changeActivePlayer(Game* play)
{
    if(play->getCurrentPlayer() != currPlayer )
    {
        SDL_DestroyTexture(P1_ActiveIndicator);
//        SDL_DestroyTexture(P1_InstructBox);
        SDL_DestroyTexture(P2_ActiveIndicator);
//        SDL_DestroyTexture(P2_InstructBox);
        SDL_DestroyTexture(P3_ActiveIndicator);
//        SDL_DestroyTexture(P3_InstructBox);
        SDL_DestroyTexture(P4_ActiveIndicator);
//        SDL_DestroyTexture(P4_ActiveIndicator);

        switch(play->getCurrentPlayer())
        {
            case 0:
                P1_ActiveIndicator = loadTexture("images/attackAct.png");
//                P1_InstructBox = loadText("It is your turn.", 16);

                P2_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P2_InstructBox = loadText("You are defending.", 16);

                P3_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P3_InstructBox = loadText("You are defending.", 16);

                P4_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P4_InstructBox = loadText("You are defending.", 16);

                currPlayer = 0;
                break;

            case 1:
                P1_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P1_InstructBox = loadText("You are defending.", 16);

                P2_ActiveIndicator = loadTexture("images/attackAct.png");
//                P2_InstructBox = loadText("It is your turn.", 16);

                P3_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P3_InstructBox = loadText("You are defending.", 16);

                P4_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P4_InstructBox = loadText("You are defending.", 16);

                currPlayer = 1;
                break;

            case 2:
                P1_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P1_InstructBox = loadText("You are defending.", 16);

                P2_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P2_InstructBox = loadText("You are defending.", 16);

                P3_ActiveIndicator = loadTexture("images/attackAct.png");
//                P3_InstructBox = loadText("It is your turn.", 16);

                P4_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P4_InstructBox = loadText("You are defending.", 16);

                currPlayer = 2;
                break;

            case 3:
                P1_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P1_InstructBox = loadText("You are defending.", 16);

                P2_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P2_InstructBox = loadText("You are defending.", 16);

                P3_ActiveIndicator = loadTexture("images/defenseAct.png");
//                P3_InstructBox = loadText("You are defending.", 16);

                P4_ActiveIndicator = loadTexture("images/attackAct.png");
//                P4_InstructBox = loadText("It is your turn.", 16);

                currPlayer = 3;
                break;

            default:
                break;
        }
    }
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

            int x, y; // mouse pointer position x and y

            bool isClicked = false;
            /*
                INITIALIZING PLAYERS
                Take in string values
            */
            cout << "Enter Player 1's Name: " << endl;
            string temp;
            cin >> temp;
            while (temp.length() > 20) {
                cout << "Choose a nickname, buddy!" << endl;
                cin >> temp;
            }
            player1Name = temp;

            cout << "Enter Player 2's Name: " << endl;
            cin >> temp;
            while (temp.length() > 20) {
                cout << "Choose a nickname, buddy!" << endl;
                cin >> temp;
            }
            player2Name = temp;

            cout << "Enter Player 3's Name: " << endl;
            cin >> temp;
            while (temp.length() > 20) {
                cout << "Choose a nickname, buddy!" << endl;
                cin >> temp;
            }
            player3Name = temp;

            cout << "Enter Player 4's Name: " << endl;
            cin >> temp;
            while (temp.length() > 20) {
                cout << "Choose a nickname, buddy!" << endl;
                cin >> temp;
            }
            player4Name = temp;
            /*
                INITIALIZING TERRITORIES
                Allocated by pointers to make it easier to access subfields of each Territory
            */

            //AUSTRALIA
            string western_australia_borders[3] = {"New Guinea", "Indonesia", "Eastern Australia"};
            Territory *western_australia_4 = new Territory(4, "Western Australia", 3, western_australia_borders);

            string new_guinea_borders[3] = {"Eastern Australia", "Indonesia", "Western Australia"};
            Territory *new_guinea_3 = new Territory(3, "New Guinea", 3, new_guinea_borders);

            string indonesia_borders[2] = {"New Guinea", "Siam"};
            Territory *indonesia_2 = new Territory(2, "Indonesia", 2, indonesia_borders);

            string eastern_australia_borders[2] = {"New Guinea", "Western Australia"};
            Territory *eastern_australia_1 = new Territory(1, "Eastern Australia", 2, eastern_australia_borders);
            //Initialize Australia array
            Territory* australia[4] = {western_australia_4, new_guinea_3, indonesia_2, eastern_australia_1};

            //ASIA
            string afghanistan_borders[5] = {"Middle East", "India", "China", "Ural", "Ukraine"};
            Territory *afghanistan_1 = new Territory(1, "Afghanistan", 5, afghanistan_borders);

            string china_borders[6] = {"Siam", "India", "Afghanistan", "Ural", "Siberia", "Mongolia"};
            Territory *china_2 = new Territory(2, "China", 6, china_borders);

            string india_borders[4] = {"Siam", "China", "Afghanistan", "Middle East"};
            Territory *india_3 = new Territory(3, "India", 4, india_borders);

            string irkutsk_borders[4] = {"Siberia", "Mongolia", "Kamchatka", "Yakutsk"};
            Territory *irkutsk_4 = new Territory(4, "Irkutsk", 4, irkutsk_borders);

            string japan_borders[2] = {"Mongolia", "Kamchatka"};
            Territory *japan_5 = new Territory(5, "Japan", 2, japan_borders);

            string kamchatka_borders[5] = {"Yakutsk", "Irkutsk" ,"Mongolia", "Japan", "Alaska"};
            Territory *kamchatka_6 = new Territory(6, "Kamchatka", 5, kamchatka_borders);

            string middle_east_borders[6] = {"Southern Europe", "Egypt", "East Africa", "India", "Afghanistan", "Ukraine"};
            Territory *middle_east_7 = new Territory(7, "Middle East", 6, middle_east_borders);

            string mongolia_borders[6] = {"Japan", "Kamchatka", "Irkutsk", "Siberia", "Ural", "China"};
            Territory *mongolia_8 = new Territory(8, "Mongolia", 6, mongolia_borders);

            string siam_borders[3] = {"India", "China", "Indonesia"};
            Territory *siam_9 = new Territory(9, "Siam", 3, siam_borders);

            string siberia_borders[5] = {"Ural", "Yakutsk", "Irkutsk", "Mongolia", "China"};
            Territory *siberia_10 = new Territory(10, "Siberia", 5, siberia_borders);

            string ural_borders[4] = {"Ukraine", "Afghanistan" , "China", "Siberia"};
            Territory *ural_11 = new Territory(11, "Ural", 4, ural_borders);

            string yakutsk_borders[3] = {"Siberia", "Irkutsk", "Kamchatka"};
            Territory *yakutsk_12 = new Territory(12, "Yakutsk", 3, yakutsk_borders);
            //Initialize Asia array
            Territory* asia[12] = {afghanistan_1, china_2, india_3, irkutsk_4, japan_5, kamchatka_6, middle_east_7, mongolia_8, siam_9, siberia_10, ural_11, yakutsk_12};

            //EUROPE
            string great_britain_borders[4] = {"Iceland", "Western Europe", "Northern Europe", "Scandinavia"};
            Territory* great_britain_1 = new Territory(1, "Great Britain", 4, great_britain_borders);

            string iceland_borders[3] = {"Greenland", "Great Britain", "Scandinavia"};
            Territory* iceland_2 = new Territory(2, "Iceland", 3, iceland_borders);

            string northern_europe_borders[5] = {"Great Britain", "Western Europe", "Southern Europe", "Ukraine", "Scandinavia"};
            Territory* northern_europe_3 = new Territory(3, "Northern Europe", 5, northern_europe_borders);

            string scandinavia_borders[4] = {"Iceland", "Great Britain", "Northern Europe", "Ukraine"};
            Territory* scandinavia_4 = new Territory(4, "Scandinavia", 4, scandinavia_borders);

            string southern_europe_borders[6] = {"North Africa", "Egypt", "Middle East", "Ukraine", "Northern Europe", "Western Europe"};
            Territory* southern_europe_5 = new Territory(5, "Southern Europe", 6, southern_europe_borders);

            string ukraine_borders[6] = {"Afghanistan", "Middle East", "Ural", "Scandinavia", "Northern Europe", "Southern Europe"};
            Territory* ukraine_6 = new Territory(6, "Ukraine", 6, ukraine_borders);

            string western_europe_borders[4] = {"North Africa", "Southern Europe", "Northern Europe", "Great Britain"};
            Territory* western_europe_7 = new Territory(7, "Western Europe", 4, western_europe_borders);
            //Initialize Europe Array
            Territory* europe[7] = {great_britain_1, iceland_2, northern_europe_3, scandinavia_4, southern_europe_5, ukraine_6, western_europe_7};

            //AFRICA
            string south_africa_borders[3] = {"Madagascar", "East Africa", "Congo"};
            Territory* south_africa_6 = new Territory(6, "South Africa", 3, south_africa_borders);

            string north_africa_borders[6] = {"Brazil", "Congo", "East Africa", "Egypt", "Southern Europe", "Western Europe"};
            Territory* north_africa_5 = new Territory(5, "North Africa", 6, north_africa_borders);

            string madagascar_borders[2] = {"East Africa", "South Africa"};
            Territory* madagascar_4 = new Territory(4, "Madagascar", 2, madagascar_borders);

            string egypt_borders[4] = {"North Africa", "East Africa", "Middle East", "Southern Europe"};
            Territory* egypt_3 = new Territory(3, "Egypt", 4, egypt_borders);

            string east_africa_borders[6] = {"Middle East", "Egypt", "North Africa", "Congo", "Madagascar", "South Africa"};
            Territory* east_africa_2 = new Territory(2, "East Africa", 6, east_africa_borders);

            string congo_bordrs[3] = {"North Africa", "East Africa", "South Africa"};
            Territory* congo_1 = new Territory(1, "Congo", 3, congo_bordrs);
            //Initialize Africa Array
            Territory* africa[6] = {south_africa_6, north_africa_5, madagascar_4, egypt_3, east_africa_2, congo_1};

            //South America
            string venezuela_borders[3] = {"Central America", "Peru", "Brazil"};
            Territory* venezuela_4 = new Territory(4, "Venezuela", 3, venezuela_borders);

            string peru_borders[3] = {"Argentina", "Brazil", "Venezuela"};
            Territory* peru_3 = new Territory(3, "Peru", 3, peru_borders);

            string brazil_borders[4] = {"North Africa", "Venezuela", "Peru", "Argentina"};
            Territory* brazil_2 = new Territory(2, "Brazil", 4, brazil_borders);

            string argentina_borders[2] = {"Brazil", "Peru"};
            Territory* argentina_1 = new Territory(1, "Argentina", 2, argentina_borders);
            //Initialize South America Array
            Territory* south_america[4] = {venezuela_4, peru_3, brazil_2, argentina_1};

            //North America
            string western_united_states_borders[4] = {"Central America", "Eastern United States", "Ontario", "Alberta"};
            Territory* western_united_states_9 = new Territory(9, "Western United States", 4, western_united_states_borders);

            string quebec_borders[3] = {"Greenland", "Ontario", "Eastern United States"};
            Territory* quebec_8 = new Territory(8, "Quebec", 3, quebec_borders);

            string ontario_borders[6] = {"Greenland", "Quebec", "Eastern United States", "Western United States", "Alberta", "Northwest Territory"};
            Territory* ontario_7 = new Territory(7, "Ontario", 6, ontario_borders);

            string northwest_territory_borders[4] = {"Alaska", "Alberta", "Ontario", "Greenland"};
            Territory* northwest_territory_6 = new Territory(6, "Northwest Territory", 4, northwest_territory_borders);

            string greenland_borders[4] = {"Northwest Territory", "Ontario", "Quebec", "Iceland"};
            Territory* greenland_5 = new Territory(5, "Greenland", 4, greenland_borders);

            string eastern_united_states_borders[4] = {"Quebec", "Ontario", "Western United States", "Central America"};
            Territory* eastern_united_states_4 = new Territory(4, "Eastern United States", 4, eastern_united_states_borders);

            string central_america_borders[3] = {"Eastern United States", "Western United States", "Venezuela"};
            Territory* central_america_3 = new Territory(3, "Central America", 3, central_america_borders);

            string albera_borders[5] = {"Alaska", "Northwest Territory", "Ontario", "Eastern United States", "Western United States"};
            Territory* alberta_2 = new Territory(2, "Alberta", 5, albera_borders);

            string alaska_borders[3] = {"Northwest Territory", "Alberta", "Kamchatka"};
            Territory* alaska_1 = new Territory(1, "Alaska", 3, alaska_borders);

            //Initialize North America Array
            Territory* north_america[9] = {western_united_states_9, quebec_8, ontario_7, northwest_territory_6, greenland_5, eastern_united_states_4, central_america_3, alberta_2, alaska_1};

            World earth = World(north_america, south_america, europe, africa, asia, australia);

            std::vector<Player> players;
            Player doug = Player(player1Name, 0);
            Player rosemond = Player(player2Name, 1);
            Player chris = Player(player3Name, 2);
            Player kevin = Player(player4Name, 3);
            players.push_back(doug);
            players.push_back(rosemond);
            players.push_back(chris);
            players.push_back(kevin);

            Deck playDeck = Deck();
            Game play(players, earth, playDeck);

            play.init_game();

            Territory* terr1 = NULL;
            Territory* terr2 = NULL;

            //set name in game
            P1_InstructBox = loadText("Ready " + player1Name, 16 );
            P1_Name = loadText(player1Name, 18);

            P2_InstructBox = loadText("Ready " + player2Name, 16 );
            P2_Name = loadText(player2Name, 18);

            P3_InstructBox = loadText("Ready " + player3Name, 16 );
            P3_Name = loadText(player3Name, 18);

            P4_InstructBox = loadText("Ready " + player4Name, 16 );
            P4_Name = loadText(player4Name, 18);

			// While application is running
			while(!quit && !play.isGameOver())
			{
                // Update top menu
                changeNumTop(play.getPlayers());
                changeActivePlayer(&play);
                changeDie(play.getDie());

			    SDL_GetMouseState(&x, &y); // get position of mouse at each frame the program is running

                isClicked = false;

				// Handle events on queue
				while(SDL_PollEvent(&e) != 0)
				{
					// User requests quit
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}

                    if(e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        // If the left button was pressed
                        if (e.button.button == SDL_BUTTON_LEFT)
                        {
                            isClicked = true;
                        }
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

                // mouse over exchange stars
                if((x >= SCREEN_WIDTH - 264 && x <= SCREEN_WIDTH) && (y >= 198 && y <= 300))
                {
                        if(isClicked == true)
                        {
                            play.exchangeStars();
                        }
                }

                // mouse over allocate troops

                if((x >= SCREEN_WIDTH - 264 && x <= SCREEN_WIDTH) && (y >= 301 && y <= 500))
                {
                        if(isClicked == true)
                        {
                            if(terr2 == NULL && terr1 != NULL)
                            {
                                play.allocate_Troops(terr1);
                                terr1 = NULL;
                            }

                            if(terr2 != NULL)
                            {
                                std::cout << "Territory 2 is not null, resetting inputs." << std::endl;
                                terr2 = NULL;
                                terr1 = NULL;
                            }

                        }
                }

                // mouse over attack/move troops

                if((x >= SCREEN_WIDTH - 264 && x <= SCREEN_WIDTH) && (y >= 501 && y <= 700))
                {
                        if(isClicked == true)
                        {
                            if(terr1 == NULL || terr2 == NULL)
                            {
                                    std::cout << "One or more territory is NULL, move/attack aborted, territories reset." << std::endl;
                                    terr1 = NULL;
                                    terr2 = NULL;
                            }
                            else
                            {
                                play.moveAttack(terr1, terr2);
                                terr1 = NULL;
                                terr2 = NULL;
                            }
                        }
                }

                // mouse over redeploy troops

                if((x >= SCREEN_WIDTH - 264 && x <= SCREEN_WIDTH) && (y >= 701 && y <= 800))
                {
                        if(isClicked == true)
                        {
                            if(terr1 == NULL || terr2 == NULL)
                            {
                                    std::cout << "One or more territory is NULL, redeploy aborted, territories reset." << std::endl;
                                    terr1 = NULL;
                                    terr2 = NULL;
                            }
                            else
                            {
                                play.redeploy(terr1, terr2);
                                terr1 = NULL;
                                terr2 = NULL;
                            }
                        }
                }

                // mouse over end turn button

                if((x >= SCREEN_WIDTH - 264 && x <= SCREEN_WIDTH) && (y >= 801 && y <= SCREEN_HEIGHT))
                {
                        if(isClicked == true)
                        {
                            play.nextTurn();
                        }
                }

				// Map viewport, map is 1175x600
				SDL_Rect mapViewport;
				mapViewport.x = 0;
				mapViewport.y = 300;
				mapViewport.w = 1175;
				mapViewport.h = 600;
				SDL_RenderSetViewport(windowRenderer, &mapViewport);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, mapTexture, NULL, NULL);

                // NaBox3
				SDL_Rect NaBox3ViewPort;
				NaBox3ViewPort.x = 130;
				NaBox3ViewPort.y = 555;
				NaBox3ViewPort.w = 22;
				NaBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox3ViewPort);

                SDL_DestroyTexture(NaBox3);
                NaBox3 = updateColors(central_america_3);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox3, NULL, NULL);

				changeNumTerr(central_america_3, &NaBox3n);
				SDL_RenderCopy(windowRenderer, NaBox3n, NULL, NULL);

                if((x >= 130 && x <= 130 + 22) && (y >= 555 && y <= 555 + 16))
                {
                        NaBox3ViewPort.w = 33;
                        NaBox3ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = central_america_3;
                            }
                            else if(terr2 == NULL && terr1 != central_america_3)
                            {
                                terr2 = central_america_3;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &NaBox3ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox3, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, NaBox3n, NULL, NULL);
                }

                // NaBox4
				SDL_Rect NaBox4ViewPort;
				NaBox4ViewPort.x = 190;
				NaBox4ViewPort.y = 490;
				NaBox4ViewPort.w = 22;
				NaBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox4ViewPort);

                SDL_DestroyTexture(NaBox4);
                NaBox4 = updateColors(eastern_united_states_4);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox4, NULL, NULL);

				changeNumTerr(eastern_united_states_4, &NaBox4n);
				SDL_RenderCopy(windowRenderer, NaBox4n, NULL, NULL);

                if((x >= 190 && x <= 190 + 22) && (y >= 490 && y <= 490 + 16))
                {
                        NaBox4ViewPort.w = 33;
                        NaBox4ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = eastern_united_states_4;
                            }
                            else if(terr2 == NULL && terr1 != eastern_united_states_4)
                            {
                                terr2 = eastern_united_states_4;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &NaBox4ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox4, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, NaBox4n, NULL, NULL);
                }

                // NaBox5
				SDL_Rect NaBox5ViewPort;
				NaBox5ViewPort.x = 420;
				NaBox5ViewPort.y = 340;
				NaBox5ViewPort.w = 22;
				NaBox5ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox5ViewPort);

                SDL_DestroyTexture(NaBox5);
                NaBox5 = updateColors(greenland_5);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox5, NULL, NULL);

				changeNumTerr(greenland_5, &NaBox5n);
				SDL_RenderCopy(windowRenderer, NaBox5n, NULL, NULL);

                if((x >= 420 && x <= 420 + 22) && (y >= 340 && y <= 340 + 16))
                {
                        NaBox5ViewPort.w = 33;
                        NaBox5ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = greenland_5;
                            }
                            else if(terr2 == NULL && terr1 != greenland_5)
                            {
                                terr2 = greenland_5;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &NaBox5ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox5, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, NaBox5n, NULL, NULL);
                }

                // NaBox6
				SDL_Rect NaBox6ViewPort;
				NaBox6ViewPort.x = 163;
				NaBox6ViewPort.y = 368;
				NaBox6ViewPort.w = 22;
				NaBox6ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox6ViewPort);

                SDL_DestroyTexture(NaBox6);
                NaBox6 = updateColors(northwest_territory_6);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox6, NULL, NULL);

				changeNumTerr(northwest_territory_6, &NaBox6n);
				SDL_RenderCopy(windowRenderer, NaBox6n, NULL, NULL);

                if((x >= 163 && x <= 163 + 22) && (y >= 368 && y <= 368 + 16))
                {
                        NaBox6ViewPort.w = 33;
                        NaBox6ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = northwest_territory_6;
                            }
                            else if(terr2 == NULL && terr1 != northwest_territory_6)
                            {
                                terr2 = northwest_territory_6;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &NaBox6ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox6, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, NaBox6n, NULL, NULL);
                }

                // NaBox7
				SDL_Rect NaBox7ViewPort;
				NaBox7ViewPort.x = 230;
				NaBox7ViewPort.y = 405;
				NaBox7ViewPort.w = 22;
				NaBox7ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox7ViewPort);

                SDL_DestroyTexture(NaBox7);
                NaBox7 = updateColors(ontario_7);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox7, NULL, NULL);

				changeNumTerr(ontario_7, &NaBox7n);
				SDL_RenderCopy(windowRenderer, NaBox7n, NULL, NULL);

                if((x >= 230 && x <= 230 + 22) && (y >= 405 && y <= 405 + 16))
                {
                        NaBox7ViewPort.w = 33;
                        NaBox7ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = ontario_7;
                            }
                            else if(terr2 == NULL && terr1 != ontario_7)
                            {
                                terr2 = ontario_7;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &NaBox7ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox7, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, NaBox7n, NULL, NULL);
                }

                // NaBox8
				SDL_Rect NaBox8ViewPort;
				NaBox8ViewPort.x = 310;
				NaBox8ViewPort.y = 405;
				NaBox8ViewPort.w = 22;
				NaBox8ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox8ViewPort);

                SDL_DestroyTexture(NaBox8);
                NaBox8 = updateColors(quebec_8);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox8, NULL, NULL);

				changeNumTerr(quebec_8, &NaBox8n);
				SDL_RenderCopy(windowRenderer, NaBox8n, NULL, NULL);

                if((x >= 310 && x <= 310 + 22) && (y >= 405 && y <= 405 + 16))
                {
                        NaBox8ViewPort.w = 33;
                        NaBox8ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = quebec_8;
                            }
                            else if(terr2 == NULL && terr1 != quebec_8)
                            {
                                terr2 = quebec_8;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &NaBox8ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox8, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, NaBox8n, NULL, NULL);
                }

                // NaBox9
				SDL_Rect NaBox9ViewPort;
				NaBox9ViewPort.x = 130;
				NaBox9ViewPort.y = 455;
				NaBox9ViewPort.w = 22;
				NaBox9ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox9ViewPort);

                SDL_DestroyTexture(NaBox9);
                NaBox9 = updateColors(western_united_states_9);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox9, NULL, NULL);

				changeNumTerr(western_united_states_9, &NaBox9n);
				SDL_RenderCopy(windowRenderer, NaBox9n, NULL, NULL);

                if((x >= 130 && x <= 130 + 22) && (y >= 455 && y <= 455 + 16))
                {
                        NaBox9ViewPort.w = 33;
                        NaBox9ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = western_united_states_9;
                            }
                            else if(terr2 == NULL && terr1 != western_united_states_9)
                            {
                                terr2 = western_united_states_9;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &NaBox9ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox9, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, NaBox9n, NULL, NULL);
                }

                // SaBox1
				SDL_Rect SaBox1ViewPort;
				SaBox1ViewPort.x = 295;
				SaBox1ViewPort.y = 790;
				SaBox1ViewPort.w = 22;
				SaBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &SaBox1ViewPort);

                SDL_DestroyTexture(SaBox1);
                SaBox1 = updateColors(argentina_1);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, SaBox1, NULL, NULL);

				changeNumTerr(argentina_1, &SaBox1n);
				SDL_RenderCopy(windowRenderer, SaBox1n, NULL, NULL);

                if((x >= 295 && x <= 295 + 22) && (y >= 790 && y <= 790 + 16))
                {
                        SaBox1ViewPort.w = 33;
                        SaBox1ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = argentina_1;
                            }
                            else if(terr2 == NULL && terr1 != argentina_1)
                            {
                                terr2 = argentina_1;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &SaBox1ViewPort);

                        SDL_RenderCopy(windowRenderer, SaBox1, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, SaBox1n, NULL, NULL);
                }

                // SaBox2
				SDL_Rect SaBox2ViewPort;
				SaBox2ViewPort.x = 345;
				SaBox2ViewPort.y = 695;
				SaBox2ViewPort.w = 22;
				SaBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &SaBox2ViewPort);

                SDL_DestroyTexture(SaBox2);
                SaBox2 = updateColors(brazil_2);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, SaBox2, NULL, NULL);

				changeNumTerr(brazil_2, &SaBox2n);
				SDL_RenderCopy(windowRenderer, SaBox2n, NULL, NULL);

                if((x >= 345 && x <= 345 + 22) && (y >= 695 && y <= 695 + 16))
                {
                        SaBox2ViewPort.w = 33;
                        SaBox2ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = brazil_2;
                            }
                            else if(terr2 == NULL && terr1 != brazil_2)
                            {
                                terr2 = brazil_2;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &SaBox2ViewPort);

                        SDL_RenderCopy(windowRenderer, SaBox2, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, SaBox2n, NULL, NULL);
                }

                // SaBox3
				SDL_Rect SaBox3ViewPort;
				SaBox3ViewPort.x = 285;
				SaBox3ViewPort.y = 725;
				SaBox3ViewPort.w = 22;
				SaBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &SaBox3ViewPort);

                SDL_DestroyTexture(SaBox3);
                SaBox3 = updateColors(peru_3);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, SaBox3, NULL, NULL);

				changeNumTerr(peru_3, &SaBox3n);
				SDL_RenderCopy(windowRenderer, SaBox3n, NULL, NULL);

                if((x >= 285 && x <= 285 + 22) && (y >= 725 && y <= 725 + 16))
                {
                        SaBox3ViewPort.w = 33;
                        SaBox3ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = peru_3;
                            }
                            else if(terr2 == NULL && terr1 != peru_3)
                            {
                                terr2 = peru_3;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &SaBox3ViewPort);

                        SDL_RenderCopy(windowRenderer, SaBox3, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, SaBox3n, NULL, NULL);
                }

                // SaBox4
				SDL_Rect SaBox4ViewPort;
				SaBox4ViewPort.x = 275;
				SaBox4ViewPort.y = 615;
				SaBox4ViewPort.w = 22;
				SaBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &SaBox4ViewPort);

                SDL_DestroyTexture(SaBox4);
                SaBox4 = updateColors(venezuela_4);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, SaBox4, NULL, NULL);

				changeNumTerr(venezuela_4, &SaBox4n);
				SDL_RenderCopy(windowRenderer, SaBox4n, NULL, NULL);

                if((x >= 275 && x <= 275 + 22) && (y >= 615 && y <= 615 + 16))
                {
                        SaBox4ViewPort.w = 33;
                        SaBox4ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = venezuela_4;
                            }
                            else if(terr2 == NULL && terr1 != venezuela_4)
                            {
                                terr2 = venezuela_4;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &SaBox4ViewPort);

                        SDL_RenderCopy(windowRenderer, SaBox4, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, SaBox4n, NULL, NULL);
                }

                // EuBox1
				SDL_Rect EuBox1ViewPort;
				EuBox1ViewPort.x = 500;
				EuBox1ViewPort.y = 420;
				EuBox1ViewPort.w = 22;
				EuBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox1ViewPort);

                SDL_DestroyTexture(EuBox1);
                EuBox1 = updateColors(great_britain_1);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox1, NULL, NULL);

				changeNumTerr(great_britain_1, &EuBox1n);
				SDL_RenderCopy(windowRenderer, EuBox1n, NULL, NULL);

                if((x >= 500 && x <= 500 + 22) && (y >= 420 && y <= 420 + 16))
                {
                        EuBox1ViewPort.w = 33;
                        EuBox1ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = great_britain_1;
                            }
                            else if(terr2 == NULL && terr1 != great_britain_1)
                            {
                                terr2 = great_britain_1;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &EuBox1ViewPort);

                        SDL_RenderCopy(windowRenderer, EuBox1, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, EuBox1n, NULL, NULL);
                }

                // EuBox2
				SDL_Rect EuBox2ViewPort;
                EuBox2ViewPort.x = 480;
                EuBox2ViewPort.y = 385;
				EuBox2ViewPort.w = 22;
				EuBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox2ViewPort);

                SDL_DestroyTexture(EuBox2);
                EuBox2 = updateColors(iceland_2);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox2, NULL, NULL);

				changeNumTerr(iceland_2, &EuBox2n);
				SDL_RenderCopy(windowRenderer, EuBox2n, NULL, NULL);

                if((x >= 480 && x <= 480 + 22) && (y >= 385 && y <= 385 + 16))
                {
                        EuBox2ViewPort.w = 33;
                        EuBox2ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = iceland_2;
                            }
                            else if(terr2 == NULL && terr1 != iceland_2)
                            {
                                terr2 = iceland_2;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &EuBox2ViewPort);

                        SDL_RenderCopy(windowRenderer, EuBox2, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, EuBox2n, NULL, NULL);
                }

                // EuBox3
				SDL_Rect
				EuBox3ViewPort;
				EuBox3ViewPort.x = 610;
				EuBox3ViewPort.y = 415;
				EuBox3ViewPort.w = 22;
				EuBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox3ViewPort);

                SDL_DestroyTexture(EuBox3);
                EuBox3 = updateColors(northern_europe_3);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox3, NULL, NULL);

				changeNumTerr(northern_europe_3, &EuBox3n);
				SDL_RenderCopy(windowRenderer, EuBox3n, NULL, NULL);

                if((x >= 610 && x <= 610 + 22) && (y >= 415 && y <= 415 + 16))
                {
                        EuBox3ViewPort.w = 33;
                        EuBox3ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = northern_europe_3;
                            }
                            else if(terr2 == NULL && terr1 != northern_europe_3)
                            {
                                terr2 = northern_europe_3;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &EuBox3ViewPort);

                        SDL_RenderCopy(windowRenderer, EuBox3, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, EuBox3n, NULL, NULL);
                }

                // EuBox4
				SDL_Rect EuBox4ViewPort;
				EuBox4ViewPort.x = 595;
				EuBox4ViewPort.y = 385;
				EuBox4ViewPort.w = 22;
				EuBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox4ViewPort);

                SDL_DestroyTexture(EuBox4);
                EuBox4 = updateColors(scandinavia_4);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox4, NULL, NULL);

				changeNumTerr(scandinavia_4, &EuBox4n);
				SDL_RenderCopy(windowRenderer, EuBox4n, NULL, NULL);

                if((x >= 595 && x <= 595 + 22) && (y >= 385 && y <= 385 + 16))
                {
                        EuBox4ViewPort.w = 33;
                        EuBox4ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = scandinavia_4;
                            }
                            else if(terr2 == NULL && terr1 != scandinavia_4)
                            {
                                terr2 = scandinavia_4;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &EuBox4ViewPort);

                        SDL_RenderCopy(windowRenderer, EuBox4, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, EuBox4n, NULL, NULL);
                }

                // EuBox5
				SDL_Rect EuBox5ViewPort;
				EuBox5ViewPort.x = 640;
				EuBox5ViewPort.y = 450;
				EuBox5ViewPort.w = 22;
				EuBox5ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox5ViewPort);

                SDL_DestroyTexture(EuBox5);
                EuBox5 = updateColors(southern_europe_5);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox5, NULL, NULL);

				changeNumTerr(southern_europe_5, &EuBox5n);
				SDL_RenderCopy(windowRenderer, EuBox5n, NULL, NULL);

                if((x >= 640 && x <= 640 + 22) && (y >= 450 && y <= 450 + 16))
                {
                        EuBox5ViewPort.w = 33;
                        EuBox5ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = southern_europe_5;
                            }
                            else if(terr2 == NULL && terr1 != southern_europe_5)
                            {
                                terr2 = southern_europe_5;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &EuBox5ViewPort);

                        SDL_RenderCopy(windowRenderer, EuBox5, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, EuBox5n, NULL, NULL);
                }

                // EuBox6
				SDL_Rect EuBox6ViewPort;
				EuBox6ViewPort.x = 690;
				EuBox6ViewPort.y = 400;
				EuBox6ViewPort.w = 22;
				EuBox6ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox6ViewPort);

                SDL_DestroyTexture(EuBox6);
                EuBox6 = updateColors(ukraine_6);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox6, NULL, NULL);

				changeNumTerr(ukraine_6, &EuBox6n);
				SDL_RenderCopy(windowRenderer, EuBox6n, NULL, NULL);

                if((x >= 690 && x <= 690 + 22) && (y >= 400 && y <= 400 + 16))
                {
                        EuBox6ViewPort.w = 33;
                        EuBox6ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = ukraine_6;
                            }
                            else if(terr2 == NULL && terr1 != ukraine_6)
                            {
                                terr2 = ukraine_6;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &EuBox6ViewPort);

                        SDL_RenderCopy(windowRenderer, EuBox6, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, EuBox6n, NULL, NULL);
                }

				// EuBox7
				SDL_Rect EuBox7ViewPort;
				EuBox7ViewPort.x = 525;
				EuBox7ViewPort.y = 465;
				EuBox7ViewPort.w = 22;
				EuBox7ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &EuBox7ViewPort);

                SDL_DestroyTexture(EuBox7);
                EuBox7 = updateColors(western_europe_7);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, EuBox7, NULL, NULL);

				changeNumTerr(western_europe_7, &EuBox7n);
				SDL_RenderCopy(windowRenderer, EuBox7n, NULL, NULL);

                if((x >= 525 && x <= 525 + 22) && (y >= 465 && y <= 465 + 16))
                {
                        EuBox7ViewPort.w = 33;
                        EuBox7ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = western_europe_7;
                            }
                            else if(terr2 == NULL && terr1 != western_europe_7)
                            {
                                terr2 = western_europe_7;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &EuBox7ViewPort);

                        SDL_RenderCopy(windowRenderer, EuBox7, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, EuBox7n, NULL, NULL);
                }

				// AfBox1
				SDL_Rect AfBox1ViewPort;
				AfBox1ViewPort.x = 645;
				AfBox1ViewPort.y = 645;
				AfBox1ViewPort.w = 22;
				AfBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox1ViewPort);

                SDL_DestroyTexture(AfBox1);
                AfBox1 = updateColors(congo_1);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox1, NULL, NULL);

				changeNumTerr(congo_1, &AfBox1n);
				SDL_RenderCopy(windowRenderer, AfBox1n, NULL, NULL);

                if((x >= 645 && x <= 645 + 22) && (y >= 645 && y <= 645 + 16))
                {
                        AfBox1ViewPort.w = 33;
                        AfBox1ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = congo_1;
                            }
                            else if(terr2 == NULL && terr1 != congo_1)
                            {
                                terr2 = congo_1;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AfBox1ViewPort);

                        SDL_RenderCopy(windowRenderer, AfBox1, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AfBox1n, NULL, NULL);
                }

				// AfBox2
				SDL_Rect AfBox2ViewPort;
				AfBox2ViewPort.x = 675;
				AfBox2ViewPort.y = 610;
				AfBox2ViewPort.w = 22;
				AfBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox2ViewPort);

                SDL_DestroyTexture(AfBox2);
                AfBox2 = updateColors(east_africa_2);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox2, NULL, NULL);

				changeNumTerr(east_africa_2, &AfBox2n);
				SDL_RenderCopy(windowRenderer, AfBox2n, NULL, NULL);

                if((x >= 675 && x <= 675 + 22) && (y >= 610 && y <= 610 + 16))
                {
                        AfBox2ViewPort.w = 33;
                        AfBox2ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = east_africa_2;
                            }
                            else if(terr2 == NULL && terr1 != east_africa_2)
                            {
                                terr2 = east_africa_2;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AfBox2ViewPort);

                        SDL_RenderCopy(windowRenderer, AfBox2, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AfBox2n, NULL, NULL);
                }

				// AfBox3
				SDL_Rect AfBox3ViewPort;
				AfBox3ViewPort.x = 650;
				AfBox3ViewPort.y = 525;
				AfBox3ViewPort.w = 22;
				AfBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox3ViewPort);

                SDL_DestroyTexture(AfBox3);
                AfBox3 = updateColors(egypt_3);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox3, NULL, NULL);

				changeNumTerr(egypt_3, &AfBox3n);
				SDL_RenderCopy(windowRenderer, AfBox3n, NULL, NULL);

                if((x >= 650 && x <= 650 + 22) && (y >= 525 && y <= 525 + 16))
                {
                        AfBox3ViewPort.w = 33;
                        AfBox3ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = egypt_3;
                            }
                            else if(terr2 == NULL && terr1 != egypt_3)
                            {
                                terr2 = egypt_3;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AfBox3ViewPort);

                        SDL_RenderCopy(windowRenderer, AfBox3, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AfBox3n, NULL, NULL);
                }

				// AfBox4
				SDL_Rect AfBox4ViewPort;
				AfBox4ViewPort.x = 730;
				AfBox4ViewPort.y = 755;
				AfBox4ViewPort.w = 22;
				AfBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox4ViewPort);

                SDL_DestroyTexture(AfBox4);
                AfBox4 = updateColors(madagascar_4);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox4, NULL, NULL);

				changeNumTerr(madagascar_4, &AfBox4n);
				SDL_RenderCopy(windowRenderer, AfBox4n, NULL, NULL);

                if((x >= 730 && x <= 730 + 22) && (y >= 755 && y <= 755 + 16))
                {
                        AfBox4ViewPort.w = 33;
                        AfBox4ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = madagascar_4;
                            }
                            else if(terr2 == NULL && terr1 != madagascar_4)
                            {
                                terr2 = madagascar_4;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AfBox4ViewPort);

                        SDL_RenderCopy(windowRenderer, AfBox4, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AfBox4n, NULL, NULL);
                }

				// AfBox5
				SDL_Rect AfBox5ViewPort;
				AfBox5ViewPort.x = 555;
				AfBox5ViewPort.y = 565;
				AfBox5ViewPort.w = 22;
				AfBox5ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox5ViewPort);

                SDL_DestroyTexture(AfBox5);
                AfBox5 = updateColors(north_africa_5);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox5, NULL, NULL);

				changeNumTerr(north_africa_5, &AfBox5n);
				SDL_RenderCopy(windowRenderer, AfBox5n, NULL, NULL);

                if((x >= 555 && x <= 555 + 22) && (y >= 565 && y <= 565 + 16))
                {
                        AfBox5ViewPort.w = 33;
                        AfBox5ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = north_africa_5;
                            }
                            else if(terr2 == NULL && terr1 != north_africa_5)
                            {
                                terr2 = north_africa_5;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AfBox5ViewPort);

                        SDL_RenderCopy(windowRenderer, AfBox5, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AfBox5n, NULL, NULL);
                }

                // AfBox6
				SDL_Rect AfBox6ViewPort;
				AfBox6ViewPort.x = 650;
				AfBox6ViewPort.y = 735;
				AfBox6ViewPort.w = 22;
				AfBox6ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AfBox6ViewPort);

                SDL_DestroyTexture(AfBox6);
                AfBox6 = updateColors(south_africa_6);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AfBox6, NULL, NULL);

                changeNumTerr(south_africa_6, &AfBox6n);
				SDL_RenderCopy(windowRenderer, AfBox6n, NULL, NULL);

                if((x >= 650 && x <= 650 + 22) && (y >= 735 && y <= 735 + 16))
                {
                        AfBox6ViewPort.w = 33;
                        AfBox6ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = south_africa_6;
                            }
                            else if(terr2 == NULL && terr1 != south_africa_6)
                            {
                                terr2 = south_africa_6;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AfBox6ViewPort);

                        SDL_RenderCopy(windowRenderer, AfBox6, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AfBox6n, NULL, NULL);
                }

                // AsBox1
				SDL_Rect AsBox1ViewPort;
				AsBox1ViewPort.x = 800;
				AsBox1ViewPort.y = 443;
				AsBox1ViewPort.w = 22;
				AsBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox1ViewPort);

                SDL_DestroyTexture(AsBox1);
                AsBox1 = updateColors(afghanistan_1);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox1, NULL, NULL);

				changeNumTerr(afghanistan_1, &AsBox1n);
				SDL_RenderCopy(windowRenderer, AsBox1n, NULL, NULL);

                if((x >= 800 && x <= 800 + 22) && (y >= 443 && y <= 443 + 16))
                {
                        AsBox1ViewPort.w = 33;
                        AsBox1ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = afghanistan_1;
                            }
                            else if(terr2 == NULL && terr1 != afghanistan_1)
                            {
                                terr2 = afghanistan_1;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox1ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox1, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox1n, NULL, NULL);
                }

				// AsBox2
				SDL_Rect AsBox2ViewPort;
				AsBox2ViewPort.x = 955;
				AsBox2ViewPort.y = 495;
				AsBox2ViewPort.w = 22;
				AsBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox2ViewPort);

                SDL_DestroyTexture(AsBox2);
                AsBox2 = updateColors(china_2);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox2, NULL, NULL);

				changeNumTerr(china_2, &AsBox2n);
				SDL_RenderCopy(windowRenderer, AsBox2n, NULL, NULL);

                if((x >= 955 && x <= 955 + 22) && (y >= 495 && y <= 495 + 16))
                {
                        AsBox2ViewPort.w = 33;
                        AsBox2ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = china_2;
                            }
                            else if(terr2 == NULL && terr1 != china_2)
                            {
                                terr2 = china_2;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox2ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox2, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox2n, NULL, NULL);
                }

				// AsBox3
				SDL_Rect AsBox3ViewPort;
				AsBox3ViewPort.x = 875;
				AsBox3ViewPort.y = 540;
				AsBox3ViewPort.w = 22;
				AsBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox3ViewPort);

                SDL_DestroyTexture(AsBox3);
                AsBox3 = updateColors(india_3);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox3, NULL, NULL);

				changeNumTerr(india_3, &AsBox3n);
				SDL_RenderCopy(windowRenderer, AsBox3n, NULL, NULL);

                if((x >= 875 && x <= 875 + 22) && (y >= 540 && y <= 540 + 16))
                {
                        AsBox3ViewPort.w = 33;
                        AsBox3ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = india_3;
                            }
                            else if(terr2 == NULL && terr1 != india_3)
                            {
                                terr2 = india_3;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox3ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox3, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox3n, NULL, NULL);
                }

				// AsBox4
				SDL_Rect AsBox4ViewPort;
				AsBox4ViewPort.x = 915;
				AsBox4ViewPort.y = 400;
				AsBox4ViewPort.w = 22;
				AsBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox4ViewPort);

                SDL_DestroyTexture(AsBox4);
                AsBox4 = updateColors(irkutsk_4);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox4, NULL, NULL);

				changeNumTerr(irkutsk_4, &AsBox4n);
				SDL_RenderCopy(windowRenderer, AsBox4n, NULL, NULL);

                if((x >= 915 && x <= 915 + 22) && (y >= 400 && y <= 400 + 16))
                {
                        AsBox4ViewPort.w = 33;
                        AsBox4ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = irkutsk_4;
                            }
                            else if(terr2 == NULL && terr1 != irkutsk_4)
                            {
                                terr2 = irkutsk_4;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox4ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox4, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox4n, NULL, NULL);
                }

				// AsBox5
				SDL_Rect AsBox5ViewPort;
				AsBox5ViewPort.x = 1090;
				AsBox5ViewPort.y = 500;
				AsBox5ViewPort.w = 22;
				AsBox5ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox5ViewPort);

                SDL_DestroyTexture(AsBox5);
                AsBox5 = updateColors(japan_5);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox5, NULL, NULL);

				changeNumTerr(japan_5, &AsBox5n);
				SDL_RenderCopy(windowRenderer, AsBox5n, NULL, NULL);

                if((x >= 1090 && x <= 1090 + 22) && (y >= 500 && y <= 500 + 16))
                {
                        AsBox5ViewPort.w = 33;
                        AsBox5ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = japan_5;
                            }
                            else if(terr2 == NULL && terr1 != japan_5)
                            {
                                terr2 = japan_5;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox5ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox5, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox5n, NULL, NULL);
                }

				// AsBox6
				SDL_Rect AsBox6ViewPort;
				AsBox6ViewPort.x = 1075;
				AsBox6ViewPort.y = 360;
				AsBox6ViewPort.w = 22;
				AsBox6ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox6ViewPort);

                SDL_DestroyTexture(AsBox6);
                AsBox6 = updateColors(kamchatka_6);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox6, NULL, NULL);

				changeNumTerr(kamchatka_6, &AsBox6n);
				SDL_RenderCopy(windowRenderer, AsBox6n, NULL, NULL);

                if((x >= 1075 && x <= 1075 + 22) && (y >= 360 && y <= 360 + 16))
                {
                        AsBox6ViewPort.w = 33;
                        AsBox6ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = kamchatka_6;
                            }
                            else if(terr2 == NULL && terr1 != kamchatka_6)
                            {
                                terr2 = kamchatka_6;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox6ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox6, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox6n, NULL, NULL);
                }

				// AsBox7
				SDL_Rect AsBox7ViewPort;
				AsBox7ViewPort.x = 725;
				AsBox7ViewPort.y = 495;
				AsBox7ViewPort.w = 22;
				AsBox7ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox7ViewPort);

                SDL_DestroyTexture(AsBox7);
                AsBox7 = updateColors(middle_east_7);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox7, NULL, NULL);

				changeNumTerr(middle_east_7, &AsBox7n);
				SDL_RenderCopy(windowRenderer, AsBox7n, NULL, NULL);

                if((x >= 725 && x <= 725 + 22) && (y >= 495 && y <= 495 + 16))
                {
                        AsBox7ViewPort.w = 33;
                        AsBox7ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = middle_east_7;
                            }
                            else if(terr2 == NULL && terr1 != middle_east_7)
                            {
                                terr2 = middle_east_7;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox7ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox7, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox7n, NULL, NULL);
                }

				// AsBox8
				SDL_Rect AsBox8ViewPort;
				AsBox8ViewPort.x = 965;
                AsBox8ViewPort.y = 440;
				AsBox8ViewPort.w = 22;
                AsBox8ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox8ViewPort);

                SDL_DestroyTexture(AsBox8);
                AsBox8 = updateColors(mongolia_8);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox8, NULL, NULL);

				changeNumTerr(mongolia_8, &AsBox8n);
				SDL_RenderCopy(windowRenderer, AsBox8n, NULL, NULL);

                if((x >= 965 && x <= 965 + 22) && (y >= 440 && y <= 440 + 16))
                {
                        AsBox8ViewPort.w = 33;
                        AsBox8ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = mongolia_8;
                            }
                            else if(terr2 == NULL && terr1 != mongolia_8)
                            {
                                terr2 = mongolia_8;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox8ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox8, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox8n, NULL, NULL);
                }

				// AsBox9
				SDL_Rect AsBox9ViewPort;
				AsBox9ViewPort.x = 940;
				AsBox9ViewPort.y = 560;
				AsBox9ViewPort.w = 22;
				AsBox9ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox9ViewPort);

                SDL_DestroyTexture(AsBox9);
                AsBox9 = updateColors(siam_9);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox9, NULL, NULL);

				changeNumTerr(siam_9, &AsBox9n);
				SDL_RenderCopy(windowRenderer, AsBox9n, NULL, NULL);

                if((x >= 940 && x <= 940 + 22) && (y >= 560 && y <= 560 + 16))
                {
                        AsBox9ViewPort.w = 33;
                        AsBox9ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = siam_9;
                            }
                            else if(terr2 == NULL && terr1 != siam_9)
                            {
                                terr2 = siam_9;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox9ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox9, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox9n, NULL, NULL);
                }

				// AsBox10
				SDL_Rect AsBox10ViewPort;
				AsBox10ViewPort.x = 870;
				AsBox10ViewPort.y = 360;
				AsBox10ViewPort.w = 22;
				AsBox10ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox10ViewPort);

                SDL_DestroyTexture(AsBox10);
                AsBox10 = updateColors(siberia_10);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox10, NULL, NULL);

				changeNumTerr(siberia_10, &AsBox10n);
				SDL_RenderCopy(windowRenderer, AsBox10n, NULL, NULL);

                if((x >= 870 && x <= 870 + 22) && (y >= 360 && y <= 360 + 16))
                {
                        AsBox10ViewPort.w = 33;
                        AsBox10ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = siberia_10;
                            }
                            else if(terr2 == NULL && terr1 != siberia_10)
                            {
                                terr2 = siberia_10;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox10ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox10, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox10n, NULL, NULL);
                }

				// AsBox11
				SDL_Rect AsBox11ViewPort;
				AsBox11ViewPort.x = 800;
				AsBox11ViewPort.y = 380;
				AsBox11ViewPort.w = 22;
				AsBox11ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox11ViewPort);

                SDL_DestroyTexture(AsBox11);
                AsBox11 = updateColors(ural_11);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox11, NULL, NULL);

				changeNumTerr(ural_11, &AsBox11n);
				SDL_RenderCopy(windowRenderer, AsBox11n, NULL, NULL);

                if((x >= 800 && x <= 800 + 22) && (y >= 380 && y <= 380 + 16))
                {
                        AsBox11ViewPort.w = 33;
                        AsBox11ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = ural_11;
                            }
                            else if(terr2 == NULL && terr1 != ural_11)
                            {
                                terr2 = ural_11;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox11ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox11, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox11n, NULL, NULL);
                }

				// AsBox12
				SDL_Rect AsBox12ViewPort;
				AsBox12ViewPort.x = 970;
				AsBox12ViewPort.y = 358;
				AsBox12ViewPort.w = 22;
				AsBox12ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &AsBox12ViewPort);

                SDL_DestroyTexture(AsBox12);
                AsBox12 = updateColors(yakutsk_12);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, AsBox12, NULL, NULL);

				changeNumTerr(yakutsk_12, &AsBox12n);
				SDL_RenderCopy(windowRenderer, AsBox12n, NULL, NULL);

                if((x >= 970 && x <= 970 + 22) && (y >= 358 && y <= 358 + 16))
                {
                        AsBox12ViewPort.w = 33;
                        AsBox12ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = yakutsk_12;
                            }
                            else if(terr2 == NULL && terr1 != yakutsk_12)
                            {
                                terr2 = yakutsk_12;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &AsBox12ViewPort);

                        SDL_RenderCopy(windowRenderer, AsBox12, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, AsBox12n, NULL, NULL);
                }

				// OcBox1
				SDL_Rect OcBox1ViewPort;
				OcBox1ViewPort.x = 1125;
				OcBox1ViewPort.y = 780;
				OcBox1ViewPort.w = 22;
				OcBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &OcBox1ViewPort);

                SDL_DestroyTexture(OcBox1);
                OcBox1 = updateColors(eastern_australia_1);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, OcBox1, NULL, NULL);

				changeNumTerr(eastern_australia_1, &OcBox1n);
				SDL_RenderCopy(windowRenderer, OcBox1n, NULL, NULL);

                if((x >= 1125 && x <= 1125 + 22) && (y >= 780 && y <= 780 + 16))
                {
                        OcBox1ViewPort.w = 33;
                        OcBox1ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = eastern_australia_1;
                            }
                            else if(terr2 == NULL && terr1 != eastern_australia_1)
                            {
                                terr2 = eastern_australia_1;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &OcBox1ViewPort);

                        SDL_RenderCopy(windowRenderer, OcBox1, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, OcBox1n, NULL, NULL);
                }

				// OcBox2
				SDL_Rect OcBox2ViewPort;
				OcBox2ViewPort.x = 1005;
				OcBox2ViewPort.y = 665;
				OcBox2ViewPort.w = 22;
				OcBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &OcBox2ViewPort);

                SDL_DestroyTexture(OcBox2);
                OcBox2 = updateColors(indonesia_2);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, OcBox2, NULL, NULL);

				changeNumTerr(indonesia_2, &OcBox2n);
				SDL_RenderCopy(windowRenderer, OcBox2n, NULL, NULL);

                if((x >= 1005 && x <= 1005 + 22) && (y >= 665 && y <= 665 + 16))
                {
                        OcBox2ViewPort.w = 33;
                        OcBox2ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = indonesia_2;
                            }
                            else if(terr2 == NULL && terr1 != indonesia_2)
                            {
                                terr2 = indonesia_2;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &OcBox2ViewPort);

                        SDL_RenderCopy(windowRenderer, OcBox2, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, OcBox2n, NULL, NULL);
                }

                // OcBox3
				SDL_Rect OcBox3ViewPort;
				OcBox3ViewPort.x = 1145;
				OcBox3ViewPort.y = 675;
				OcBox3ViewPort.w = 22;
				OcBox3ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &OcBox3ViewPort);

                SDL_DestroyTexture(OcBox3);
                OcBox3 = updateColors(new_guinea_3);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, OcBox3, NULL, NULL);

				changeNumTerr(new_guinea_3, &OcBox3n);
				SDL_RenderCopy(windowRenderer, OcBox3n, NULL, NULL);

                if((x >= 1145 && x <= 1145 + 22) && (y >= 675 && y <= 675 + 16))
                {
                        OcBox3ViewPort.w = 33;
                        OcBox3ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = new_guinea_3;
                            }
                            else if(terr2 == NULL && terr1 != new_guinea_3)
                            {
                                terr2 = new_guinea_3;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &OcBox3ViewPort);

                        SDL_RenderCopy(windowRenderer, OcBox3, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, OcBox3n, NULL, NULL);
                }

				// OcBox4
				SDL_Rect OcBox4ViewPort;
				OcBox4ViewPort.x = 1045;
				OcBox4ViewPort.y = 775;
				OcBox4ViewPort.w = 22;
				OcBox4ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &OcBox4ViewPort);

                SDL_DestroyTexture(OcBox4);
                OcBox4 = updateColors(western_australia_4);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, OcBox4, NULL, NULL);

				changeNumTerr(western_australia_4, &OcBox4n);
				SDL_RenderCopy(windowRenderer, OcBox4n, NULL, NULL);

                if((x >= 1045 && x <= 1045 + 22) && (y >= 775 && y <= 775 + 16))
                {
                        OcBox4ViewPort.w = 33;
                        OcBox4ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = western_australia_4;
                            }
                            else if(terr2 == NULL && terr1 != western_australia_4)
                            {
                                terr2 = western_australia_4;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &OcBox4ViewPort);

                        SDL_RenderCopy(windowRenderer, OcBox4, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, OcBox4n, NULL, NULL);
                }

                // NaBox1
				SDL_Rect NaBox1ViewPort;
				NaBox1ViewPort.x = 83;
				NaBox1ViewPort.y = 353;
				NaBox1ViewPort.w = 22;
				NaBox1ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox1ViewPort);

                SDL_DestroyTexture(NaBox1);
                NaBox1 = updateColors(alaska_1);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox1, NULL, NULL);

				changeNumTerr(alaska_1, &NaBox1n);
				SDL_RenderCopy(windowRenderer, NaBox1n, NULL, NULL);

				if((x >= 83 && x <= 83 + 22) && (y >= 353 && y <= 353 + 16)) // if mouse is inside NaBox1, increase the size of NaBox1 to indicate selection
                {
                        NaBox1ViewPort.w = 33;
                        NaBox1ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = alaska_1;
                            }
                            else if(terr2 == NULL && terr1 != alaska_1)
                            {
                                terr2 = alaska_1;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &NaBox1ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox1, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, NaBox1n, NULL, NULL);
                }

                // NaBox2
				SDL_Rect NaBox2ViewPort;
				NaBox2ViewPort.x = 150;
				NaBox2ViewPort.y = 400;
				NaBox2ViewPort.w = 22;
				NaBox2ViewPort.h = 16;
				SDL_RenderSetViewport(windowRenderer, &NaBox2ViewPort);

                SDL_DestroyTexture(NaBox2);
                NaBox2 = updateColors(alberta_2);

				// Render texture to screen
				SDL_RenderCopy(windowRenderer, NaBox2, NULL, NULL);

				changeNumTerr(alberta_2, &NaBox2n);
				SDL_RenderCopy(windowRenderer, NaBox2n, NULL, NULL);

                if((x >= 150 && x <= 150 + 22) && (y >= 400 && y <= 400 + 16))
                {
                        NaBox2ViewPort.w = 33;
                        NaBox2ViewPort.h = 24;

                        if(isClicked == true)
                        {
                            if(terr1 == NULL)
                            {
                                terr1 = alberta_2;
                            }
                            else if(terr2 == NULL && terr1 != alberta_2)
                            {
                                terr2 = alberta_2;
                            }
                        }

                        SDL_RenderSetViewport(windowRenderer, &NaBox2ViewPort);

                        SDL_RenderCopy(windowRenderer, NaBox2, NULL, NULL);
                        SDL_RenderCopy(windowRenderer, NaBox2n, NULL, NULL);
                }

                // BEGIN
                // MENU BOXES
				SDL_Rect P1_Active_VPort;
				P1_Active_VPort.x = 437;
				P1_Active_VPort.y = 0;
				P1_Active_VPort.w = 150;
				P1_Active_VPort.h = 150;
				SDL_RenderSetViewport(windowRenderer, &P1_Active_VPort);
				SDL_RenderCopy(windowRenderer, P1_ActiveIndicator, NULL, NULL);

				SDL_Rect P2_Active_VPort;
				P2_Active_VPort.x = 1025;
				P2_Active_VPort.y = 0;
				P2_Active_VPort.w = 150;
				P2_Active_VPort.h = 150;
				SDL_RenderSetViewport(windowRenderer, &P2_Active_VPort);
				SDL_RenderCopy(windowRenderer, P2_ActiveIndicator, NULL, NULL);

				SDL_Rect P3_Active_VPort;
				P3_Active_VPort.x = 437;
				P3_Active_VPort.y = 150;
				P3_Active_VPort.w = 150;
				P3_Active_VPort.h = 150;
				SDL_RenderSetViewport(windowRenderer, &P3_Active_VPort);
				SDL_RenderCopy(windowRenderer, P3_ActiveIndicator, NULL, NULL);

				SDL_Rect P4_Active_VPort;
				P4_Active_VPort.x = 1025;
				P4_Active_VPort.y = 150;
				P4_Active_VPort.w = 150;
				P4_Active_VPort.h = 150;
				SDL_RenderSetViewport(windowRenderer, &P4_Active_VPort);
				SDL_RenderCopy(windowRenderer, P4_ActiveIndicator, NULL, NULL);

				SDL_Rect P1_Name_VPort;
                P1_Name_VPort.x = 0;
				P1_Name_VPort.y = 0;
				P1_Name_VPort.w = 300;
				P1_Name_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P1_Name_VPort);
				SDL_RenderCopy(windowRenderer, P1_Name, NULL, NULL);

				SDL_Rect P2_Name_VPort;
                P2_Name_VPort.x = 587;
				P2_Name_VPort.y = 0;
				P2_Name_VPort.w = 300;
				P2_Name_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P2_Name_VPort);
				SDL_RenderCopy(windowRenderer, P2_Name, NULL, NULL);

				SDL_Rect P3_Name_VPort;
                P3_Name_VPort.x = 0;
				P3_Name_VPort.y = 150;
				P3_Name_VPort.w = 300;
				P3_Name_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P3_Name_VPort);
				SDL_RenderCopy(windowRenderer, P3_Name, NULL, NULL);

				SDL_Rect P4_Name_VPort;
                P4_Name_VPort.x = 587;
				P4_Name_VPort.y = 150;
				P4_Name_VPort.w = 300;
				P4_Name_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P4_Name_VPort);
				SDL_RenderCopy(windowRenderer, P4_Name, NULL, NULL);

                SDL_Rect P1_TerritoryCount_VPort;
                P1_TerritoryCount_VPort.x = 375;
				P1_TerritoryCount_VPort.y = 0;
				P1_TerritoryCount_VPort.w = 50;
				P1_TerritoryCount_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P1_TerritoryCount_VPort);
				SDL_RenderCopy(windowRenderer, P1_TerritoryCount, NULL, NULL);

                SDL_Rect P2_TerritoryCount_VPort;
                P2_TerritoryCount_VPort.x = 965;
				P2_TerritoryCount_VPort.y = 0;
				P2_TerritoryCount_VPort.w = 50;
				P2_TerritoryCount_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P2_TerritoryCount_VPort);
				SDL_RenderCopy(windowRenderer, P2_TerritoryCount, NULL, NULL);

                SDL_Rect P3_TerritoryCount_VPort;
                P3_TerritoryCount_VPort.x = 375;
				P3_TerritoryCount_VPort.y = 150;
				P3_TerritoryCount_VPort.w = 50;
				P3_TerritoryCount_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P3_TerritoryCount_VPort);
				SDL_RenderCopy(windowRenderer, P3_TerritoryCount, NULL, NULL);

                SDL_Rect P4_TerritoryCount_VPort;
                P4_TerritoryCount_VPort.x = 965;
				P4_TerritoryCount_VPort.y = 150;
				P4_TerritoryCount_VPort.w = 50;
				P4_TerritoryCount_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P4_TerritoryCount_VPort);
				SDL_RenderCopy(windowRenderer, P4_TerritoryCount, NULL, NULL);

                SDL_Rect P1_InstructBox_VPort;
                P1_InstructBox_VPort.x = 0;
				P1_InstructBox_VPort.y = 50;
				P1_InstructBox_VPort.w = 300;
				P1_InstructBox_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P1_InstructBox_VPort);
				SDL_RenderCopy(windowRenderer, P1_InstructBox, NULL, NULL);

                SDL_Rect P2_InstructBox_VPort;
                P2_InstructBox_VPort.x = 587;
				P2_InstructBox_VPort.y = 50;
				P2_InstructBox_VPort.w = 300;
				P2_InstructBox_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P2_InstructBox_VPort);
				SDL_RenderCopy(windowRenderer, P2_InstructBox, NULL, NULL);

                SDL_Rect P3_InstructBox_VPort;
                P3_InstructBox_VPort.x = 0;
				P3_InstructBox_VPort.y = 200;
				P3_InstructBox_VPort.w = 300;
				P3_InstructBox_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P3_InstructBox_VPort);
				SDL_RenderCopy(windowRenderer, P3_InstructBox, NULL, NULL);

                SDL_Rect P4_InstructBox_VPort;
                P4_InstructBox_VPort.x = 587;
				P4_InstructBox_VPort.y = 200;
				P4_InstructBox_VPort.w = 300;
				P4_InstructBox_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P4_InstructBox_VPort);
				SDL_RenderCopy(windowRenderer, P4_InstructBox, NULL, NULL);

                SDL_Rect P1_StarCount_VPort;
                P1_StarCount_VPort.x = 375;
				P1_StarCount_VPort.y = 50;
				P1_StarCount_VPort.w = 50;
				P1_StarCount_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P1_StarCount_VPort);
				SDL_RenderCopy(windowRenderer, P1_StarCount, NULL, NULL);

                SDL_Rect P2_StarCount_VPort;
                P2_StarCount_VPort.x = 965;
				P2_StarCount_VPort.y = 50;
				P2_StarCount_VPort.w = 50;
				P2_StarCount_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P2_StarCount_VPort);
				SDL_RenderCopy(windowRenderer, P2_StarCount, NULL, NULL);

                SDL_Rect P3_StarCount_VPort;
                P3_StarCount_VPort.x = 375;
				P3_StarCount_VPort.y = 200;
				P3_StarCount_VPort.w = 50;
				P3_StarCount_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P3_StarCount_VPort);
				SDL_RenderCopy(windowRenderer, P3_StarCount, NULL, NULL);

                SDL_Rect P4_StarCount_VPort;
                P4_StarCount_VPort.x = 965;
				P4_StarCount_VPort.y = 200;
				P4_StarCount_VPort.w = 50;
				P4_StarCount_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P4_StarCount_VPort);
				SDL_RenderCopy(windowRenderer, P4_StarCount, NULL, NULL);

                SDL_Rect P1_UnitsPerTurn_VPort;
                P1_UnitsPerTurn_VPort.x = 375;
				P1_UnitsPerTurn_VPort.y = 100;
				P1_UnitsPerTurn_VPort.w = 50;
				P1_UnitsPerTurn_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P1_UnitsPerTurn_VPort);
				SDL_RenderCopy(windowRenderer, P1_UnitsPerTurn, NULL, NULL);

                SDL_Rect P2_UnitsPerTurn_VPort;
                P2_UnitsPerTurn_VPort.x = 965;
				P2_UnitsPerTurn_VPort.y = 100;
				P2_UnitsPerTurn_VPort.w = 50;
				P2_UnitsPerTurn_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P2_UnitsPerTurn_VPort);
				SDL_RenderCopy(windowRenderer, P2_UnitsPerTurn, NULL, NULL);

                SDL_Rect P3_UnitsPerTurn_VPort;
                P3_UnitsPerTurn_VPort.x = 375;
				P3_UnitsPerTurn_VPort.y = 250;
				P3_UnitsPerTurn_VPort.w = 50;
				P3_UnitsPerTurn_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P3_UnitsPerTurn_VPort);
				SDL_RenderCopy(windowRenderer, P3_UnitsPerTurn, NULL, NULL);

                SDL_Rect P4_UnitsPerTurn_VPort;
                P4_UnitsPerTurn_VPort.x = 965;
				P4_UnitsPerTurn_VPort.y = 250;
				P4_UnitsPerTurn_VPort.w = 50;
				P4_UnitsPerTurn_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &P4_UnitsPerTurn_VPort);
				SDL_RenderCopy(windowRenderer, P4_UnitsPerTurn, NULL, NULL);

                //BEGIN RIGHT MENU BOX
                SDL_Rect A_Die1_VPort;
                A_Die1_VPort.x = 1200;
				A_Die1_VPort.y = 25;
				A_Die1_VPort.w = 50;
				A_Die1_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &A_Die1_VPort);
				SDL_RenderCopy(windowRenderer, A_Die1, NULL, NULL);

                SDL_Rect A_Die2_VPort;
                A_Die2_VPort.x = 1275;
				A_Die2_VPort.y = 25;
				A_Die2_VPort.w = 50;
				A_Die2_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &A_Die2_VPort);
				SDL_RenderCopy(windowRenderer, A_Die2, NULL, NULL);

                SDL_Rect A_Die3_VPort;
                A_Die3_VPort.x = 1350;
				A_Die3_VPort.y = 25;
				A_Die3_VPort.w = 50;
				A_Die3_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &A_Die3_VPort);
				SDL_RenderCopy(windowRenderer, A_Die3, NULL, NULL);

                SDL_Rect D_Die1_VPort;
                D_Die1_VPort.x = 1240;
				D_Die1_VPort.y = 142;
				D_Die1_VPort.w = 50;
				D_Die1_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &D_Die1_VPort);
				SDL_RenderCopy(windowRenderer, D_Die1, NULL, NULL);

				SDL_Rect D_Die2_VPort;
                D_Die2_VPort.x = 1325;
				D_Die2_VPort.y = 142;
				D_Die2_VPort.w = 50;
				D_Die2_VPort.h = 50;
				SDL_RenderSetViewport(windowRenderer, &D_Die2_VPort);
				SDL_RenderCopy(windowRenderer, D_Die2, NULL, NULL);

				// Update screen
				SDL_RenderPresent(windowRenderer);
				SDL_Delay(10);
			}
		}
	}

	// Free resources and close SDL
	close();

    return 0;
}
//3533 Lines. Nice.
