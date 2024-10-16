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

		//GPU�� ���� �����ϴ°� �ƴ϶� hwndó�� renderTarget�� �����ϴ� view
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mRenderTarget;//��ȭ��
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mRenderTargetView;

		Microsoft::WRL::ComPtr<ID3D11Texture2D> mDepthStencil;//���̸� ������ ����
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mDepthStencilView;

		Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain;//���� ���۸� �ڵ����� ����
		//���۸� ������ ���鼭 �׷��־� ������ ������

		//�̹��� ũ�� �ø��ų� ���� �� �ʿ��� ������ ������
		Microsoft::WRL::ComPtr<ID3D11SamplerState> mSamplers;
	};
}


