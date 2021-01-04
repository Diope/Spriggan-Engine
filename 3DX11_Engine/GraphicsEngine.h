#pragma once
#include <d3d11.h>
#include "Prerequisites.h"
#include "RenderSystem.h"
#include "TextureManager.h"

class GraphicsEngine
{
private:
	// Initialize the engine and DirectX 11 device
	GraphicsEngine();
	// Release loaded resources
	~GraphicsEngine();
public:
	RenderSystem *getRenderSystem();
	TextureManager *getTextureManager();
public:
	static GraphicsEngine *get();
	static void create();
	static void release();


private:
	RenderSystem *m_render_system = nullptr;
	TextureManager * m_tex_manager = nullptr;
	static GraphicsEngine * m_engine;
};

