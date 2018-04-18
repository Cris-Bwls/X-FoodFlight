#include <crtdbg.h>

#include "Application2D.h"

// Playable BY the 27/04 CB:DATE

#define GAMENAME "Food Flight"

int main() {
	// Memory leak checker
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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