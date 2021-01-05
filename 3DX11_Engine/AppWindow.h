#pragma once
#include "Window.h"
#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "IndexBuffer.h"
#include "InputListener.h"
#include "Matrix4x4.h"

class AppWindow : public Window, public InputListener
{
public:
	AppWindow();

	void update();

	~AppWindow();

	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
	virtual void onFocus() override;
	virtual void onKillFocus() override;

	virtual void onKeyDown(int key) override;
	virtual void onKeyUp(int key) override;
	virtual void onMouseMove(const Point &mouse_pos) override;

	virtual void onLeftMouseDown(const Point &mouse_pos) override;
	virtual void onLeftMouseUp(const Point &mouse_pos) override;

	virtual void onRightMouseDown(const Point &mouse_pos) override;
	virtual void onRightMouseUp(const Point &mouse_pos) override;


private:
	SwapChainPtr m_swap_chain;
	VertexBufferPtr m_vertbuff;
	VertexShaderPtr m_vs;
	PixelShaderPtr m_ps;
	ConstantBufferPtr m_cb;
	IndexBufferPtr m_ib;
	TexturePtr m_wood_texture;
	MeshPtr m_mesh;

private:

	long m_old_delta;
	long m_new_delta;
	float m_delta_time;

	float m_delta_pos;
	float m_delta_scale;
	float m_delta_rot;

	float m_rotate_x=0.0f;
	float m_rotate_y=0.0f;

	float m_scale_cube = 1;

	float m_forward = 0.0f;
	float m_rightward = 0.0f;

	Matrix4x4 m_world_cam;

};
