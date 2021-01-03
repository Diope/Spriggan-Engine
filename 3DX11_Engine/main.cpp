#include "AppWindow.h"



int main()
{
	try
	{
		GraphicsEngine::create();
	}
	catch (...)
	{
		return -1;
	}
	
	{
		AppWindow app;
		if (app.init())
		{
			while (app.isRunning())
			{
				app.broadcast();
			}
		}
	}

	GraphicsEngine::release();

	return 0;
}