#pragma once
#include <d3d11.h>

class SwapChain
{
public:
	SwapChain();
	// Initialize Swapchain for a window
	bool init(HWND hwmd, UINT width, UINT height);

	// Release the Swapchain
	bool release();
	~SwapChain();
private:
	IDXGISwapChain *m_swap_chain;
};

