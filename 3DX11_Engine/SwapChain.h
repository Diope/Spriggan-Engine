#pragma once
#include <d3d11.h>

class DeviceContext;
class SwapChain

{
public:
	SwapChain();
	// Initialize Swapchain for a window
	bool init(HWND hwmd, UINT width, UINT height);

	bool present(bool vsync);

	// Release the Swapchain
	bool release();
	~SwapChain();
private:
	IDXGISwapChain *m_swap_chain;
	ID3D11RenderTargetView *m_rtv;

private:
	friend class DeviceContext;
};

