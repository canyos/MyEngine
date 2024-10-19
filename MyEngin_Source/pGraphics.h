#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#include "CommonInclude.h"

namespace p::graphics
{
	struct Vertex
	{
		math::Vector3 pos;
		math::Vector4 color;
		math::Vector2 uv; //texture coordinate
	};
	enum class eSamplerType
	{
		Anisotropic,
		Point,
		PostProcess,
		End,
	};
	enum class eShaderStage
	{
		VS,		// Vertex Shader
		HS,		// Hull Shader
		DS,		// Domain Shader
		GS,		// Geometry Shader
		PS,		// Pixel Shader
		CS,		// Compute Shader
		All,
		End,
	};
	enum class eTextureType
	{
		Albedo,
		Normal,
		Specular,
		Smoothness,
		Metallic,
		End,
	};
	enum class eCBType
	{
		Transform,
		None,
		End,
	};
	enum class eRenderingMode
	{
		Opaque,
		CutOut,
		Transparent,
		PostProcess,
		End,
	};
	struct GpuBuffer
	{
		Microsoft::WRL::ComPtr<ID3D11Buffer> buffer=nullptr;
		D3D11_BUFFER_DESC desc = {};
		GpuBuffer() = default;
		virtual ~GpuBuffer() = default;
	};
}