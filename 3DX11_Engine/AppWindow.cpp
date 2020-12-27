#include "AppWindow.h"

struct vec3d
{
	float x, y, z;
};

struct vertex
{
	vec3d position;
};

AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();
	GraphicsEngine::get()->init();
	m_swap_chain = GraphicsEngine::get()->createSwapChain();

	RECT rc = this->getClientWindowRect();
	m_swap_chain->init(this->m_hwnd, rc.right - rc.left, rc.bottom - rc.top);

	vertex list[]=
	{
		// X - Y -Z
		{-0.5f, -0.5f, 0.0f }, // POS1
		{-0.5f, 0.5f, 0.0f }, // POS2
		{0.5f, -0.5f, 0.0f }, // POS3
		{0.5f, 0.5f, 0.0f }
	};

	m_vertbuff = GraphicsEngine::get()->createVertexBuffer();

	UINT size_list = ARRAYSIZE(list);

	GraphicsEngine::get()->createShaders();

	void *shader_byte_code = nullptr;
	size_t size_shader = 0;

	GraphicsEngine::get()->compileVertexShader(L"VertexShader.hlsl", "vsmain", &shader_byte_code, &size_shader);

	m_vs = GraphicsEngine::get()->createVertexShader(shader_byte_code, size_shader);
	m_vertbuff->load(list, sizeof(vertex),size_list, shader_byte_code, size_shader);

	GraphicsEngine::get()->releaseCompiledShader();

}

void AppWindow::onUpdate()
{
	Window::onUpdate();

	// Clear the render target
	GraphicsEngine::get()->getImmediateDeviceContext()->clearRenderTarget(this->m_swap_chain, 0, 0.3f, 0.4f, 1);

	// Set viewpoint of render target 
	RECT rc = this->getClientWindowRect();
	GraphicsEngine::get()->getImmediateDeviceContext()->setViewportSize(rc.right - rc.left, rc.bottom - rc.top);

	//Set default shader in the graphics pipeline
	GraphicsEngine::get()->setShaders();
	GraphicsEngine::get()->getImmediateDeviceContext()->setVertexShader(m_vs);


	// Set triangle vertices that will be drawn
	GraphicsEngine::get()->getImmediateDeviceContext()->setVertexBuffer(m_vertbuff);

	// Draw the triangle
	GraphicsEngine::get()->getImmediateDeviceContext()->drawTriangleStrip(m_vertbuff->getSizeVertexList(), 0);

	m_swap_chain->present(true);
}

void AppWindow::onDestroy()
{
	Window::onDestroy();

	m_vertbuff->release();
	m_swap_chain->release();
	GraphicsEngine::get()->release();
}
