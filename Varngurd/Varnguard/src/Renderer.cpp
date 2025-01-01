#include "VG_PCH.h"
#include "Renderer.h"

namespace Varnguard
{
	Renderer::Renderer()
	{
	
	}

	Renderer::~Renderer()
	{
		
	}

	void Renderer::swap_buffer()
	{
		//if(swap_chain != nullptr)
		swap_chain->Present(1, 0);
	}

	void Renderer::init(HWND handle)
	{
		DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
		swapChainDesc.BufferDesc.Width = 0;
		swapChainDesc.BufferDesc.Height = 0;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 2;
		swapChainDesc.OutputWindow = handle;  // Ensure hWnd is a valid window handle
		swapChainDesc.Windowed = TRUE;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapChainDesc.Flags = 0;

		HRESULT hr = S_OK;

		hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, &swapChainDesc, &swap_chain, &device, nullptr, &device_context);

		if (hr != S_OK)
		{
			std::cout << "Error!\n";
			exit(0);
		}

		ComPtr<ID3D11Resource> back_buffer;
		swap_chain->GetBuffer(0, IID_PPV_ARGS(&back_buffer));
		device->CreateRenderTargetView(back_buffer.Get(), nullptr, &target);

	}
	void Renderer::clear_buffer(float r, float g, float b, float a)
	{
		float color[4] = { r, g, b, a };

		device_context->ClearRenderTargetView(target.Get(), color);
	}
	
}
