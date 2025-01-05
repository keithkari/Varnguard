#pragma once
#include <wrl.h>
#include "Log.h"

using namespace Microsoft;
using namespace WRL;

namespace Varnguard
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void swap_buffer();
		void init(HWND handle);
		void clear_buffer(float r, float g, float b, float a);
	private:
		ComPtr<ID3D11Device> device;
		ComPtr<ID3D11DeviceContext> device_context;
		ComPtr<IDXGISwapChain> swap_chain;
		ComPtr<ID3D11RenderTargetView> target; 
	};

	
}

