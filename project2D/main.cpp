#include "Application2D.h"

// Playable BY the 27/04 CB:DATE

#define GAMENAME "Food Flight"

int main() {
	
	// allocation
	auto app = new Application2D();

	// Get Resolution
	float fX, fY;
	bool bIsFullscreen;
	app->GetRes(fX, fY, bIsFullscreen);

	// initialise and loop
	app->run(GAMENAME, fX, fY, bIsFullscreen);

	// deallocation
	delete app;

	return 0;
}