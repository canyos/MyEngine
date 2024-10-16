#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include "CommonInclude.h"


namespace p ::graphics{
	class GraphicDevice
	{
	public:
		GraphicDevice();
		~GraphicDevice();

		void Draw();
		void Initialize();

	private :
		Microsoft::WRL::ComPtr<ID3D11Device> mDevice;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> mContext;

		//GPU도 직접 접근하는게 아니라 hwnd처럼 renderTarget에 접근하는 view
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mRenderTarget;//도화지
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mRenderTargetView;

		Microsoft::WRL::ComPtr<ID3D11Texture2D> mDepthStencil;//깊이를 저장할 공간
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mDepthStencilView;

		Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain;//더블 버퍼링 자동으로 해줌
		//버퍼를 스왑해 가면서 그려주어 깜빡임 없어짐

		//이미지 크기 늘리거나 줄일 때 필요한 보간을 도와줌
		Microsoft::WRL::ComPtr<ID3D11SamplerState> mSamplers;
	};
}


