#include "VG_PCH.h"
#include "Renderer.h"

namespace Varnguard
{
	Renderer::Renderer()
	{
		VG_LOG_CORE_INFO("Renderer created");
	}

	Renderer::~Renderer()
	{
		VG_LOG_CLIENT_INFO("Renderer destroyed");
	}

	void Renderer::swap_buffer()
	{
		//if(swap_chain != nullptr)
		swap_chain->Present(1, 0);
	}

	void Renderer::init(HWND handle)
	{
		D3D_FEATURE_LEVEL featureLevels[] = {
	   D3D_FEATURE_LEVEL_11_0, // Try for Direct3D 11.0 feature level
	   D3D_FEATURE_LEVEL_10_1, // Fall back to Direct3D 10.1 feature level if 11.0 is not supported
	   D3D_FEATURE_LEVEL_10_0, // Fall back to Direct3D 10.0 feature level
	   D3D_FEATURE_LEVEL_9_3   // Fall back to Direct3D 9.3 feature level if nothing higher is supported
		};

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

		hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, featureLevels, ARRAYSIZE(featureLevels), D3D11_SDK_VERSION, &swapChainDesc, &swap_chain, &device, nullptr, &device_context);

		if (hr != S_OK)
		{
			VG_LOG_CORE_ERROR("Error creating DirectX3D 11 device and swap chain");
			system("pause");
			//exit(0);
		}
		else
			VG_LOG_CORE_INFO("DirectX3D 11 device and swap chain created");

		ComPtr<ID3D11Resource> back_buffer;
		swap_chain->GetBuffer(0, IID_PPV_ARGS(&back_buffer));
		VG_LOG_CORE_INFO("Gotten the Back buffer");
		device->CreateRenderTargetView(back_buffer.Get(), nullptr, &target);
		VG_LOG_CORE_INFO("Created render target view");
		
	}
	void Renderer::clear_buffer(float r, float g, float b, float a)
	{
		float color[4] = { r, g, b, a };

		device_context->ClearRenderTargetView(target.Get(), color);
		VG_LOG_CORE_INFO("Cleared render target view");
	}
	
}
