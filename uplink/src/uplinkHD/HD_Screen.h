//=========================================
// The meat of the MOD.
// Contains the Renderer and main loop,
// the screen, its properties and functions
// for manipulating its layout.
//
// Started on: 22:02.2015
// By: Tudor Stamate
//=========================================

#ifndef HD_SCREEN_H
#define HD_SCREEN_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "UI_Layouts/HD_UI_Layout.h"

class HD_Screen
{
private:

	//screen anchors
	struct HD_ANCHORS
	{
		int tl[2];		//top-left
		int tc[2];		//top-center
		int tr[2];		//top-right
		int bl[2];		//bottom-left
		int bc[2];		//bottom-center
		int br[2];		//bottom-right

		int lc[2];		//left-center
		int c[2];		//center
		int rc[2];		//right-center

		int w13;		//width 1/3
		int w23;		//width 2/3

		int h13;		//height 1/3
		int h23;		//height 2/3
	};

	//screen
	ALLEGRO_DISPLAY *hdDisplay;
	static HD_Screen* screen;	//singleton

	//update/render fps
	int fps;

	//current layout to update
	HD_UI_Layout *currentLayout;	//the current layout to update

	//Allegro Inits. Called on start of game
	void HD_Init_Allegro();
	void HD_Init_Allegro_Modules();

	//The Main Loop
	int  HD_Main_Loop();

	//construction/destruction
	HD_Screen();
	~HD_Screen();

public:

	//screen info
	int  nScreenW;
	int  nScreenH;
	bool bFullscreen;
	ALLEGRO_DISPLAY_MODE display_modes;

	HD_ANCHORS hd_screenAnchor;

	//construction/destruction
	//HD_Screen();
	//~HD_Screen();

	static HD_Screen* HD_GetScreen();
	void HD_Dispose();	//used to uninstall Allegro and destroy the display

	//screen functions
	void hd_setResolution(int width, int height);
	void hd_setFullscreen(bool bIsFullscreen);
	void hd_initAnchors();

	//scaling functions
	void hd_scaleByWidth(float &value);		//scales a value by the Width difference
	void hd_scaleByHeight(float &value);	//scales a value by the Height difference

	//layout functions
	void hd_setNewLayout(HD_UI_Layout *newLayout);		//set a layout for the screen
	HD_UI_Layout* hd_getCurrentLayout();
};

//extern HD_Screen *UplinkHDScreen;

#endif