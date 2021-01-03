#pragma once
#include <d3d11.h>
#include "Prerequisites.h"
#include "RenderSystem.h"

class GraphicsEngine
{
private:
	// Initialize the engine and DirectX 11 device
	GraphicsEngine();
	// Release loaded resources
	~GraphicsEngine();
public:
	RenderSystem *getRenderSystem();
	
public:
	static GraphicsEngine *get();
	static void create();
	static void release();


private:
	RenderSystem *m_render_system = nullptr;
	static GraphicsEngine * m_engine;
};

