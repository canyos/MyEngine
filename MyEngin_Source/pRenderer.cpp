#include "pRenderer.h"
#include "pCamera.h"
#include "pResources.h"
#include "pShader.h"

namespace p::renderer{
	Camera* mainCamera = nullptr;

	Mesh* mesh = nullptr;
	graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End] = {};

	ID3D11Buffer* constantBuffer = nullptr;
	ID3D11InputLayout* inputLayouts = nullptr;

	void LoadShaders()
	{
		p::Resources::Load<graphics::Shader>(L"TriangleShader", L"..\\Shaders_SOURCE\\Triangle");
		p::Resources::Load<graphics::Shader>(L"SpriteShader", L"..\\Shaders_SOURCE\\Sprite");
	}

	void LoadConstantBuffers()
	{
		constantBuffers[(UINT)eCBType::Transform].Create(eCBType::Transform, sizeof(Vector4));
	}

	void LoadTriangleMesh()
	{
		mesh = new Mesh();
		std::vector<graphics::Vertex> vertexes = {};
		std::vector<UINT> indices = {};

		vertexes.resize(3);
		vertexes[0].pos = Vector3(0.0f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		//0 1 2 순서로 그려줘
		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);

		mesh->CreateVB(vertexes);
		mesh->CreateIB(indices);
	}
	void LoadRectMesh()
	{
		mesh = new Mesh();
		std::vector<graphics::Vertex> vertexes = {};
		std::vector<UINT> indices = {};
		vertexes.resize(4);
		vertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[0].uv = Vector2(0.0f, 0.0f);
		vertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[1].uv = Vector2(1.0f, 0.0f);
		vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[2].uv = Vector2(1.0f, 1.0f);
		vertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[3].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[3].uv = Vector2(0.0f, 1.0f);
		indices.push_back(0);
		indices.push_back(2);
		indices.push_back(3);
		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);
		mesh->CreateVB(vertexes);
		mesh->CreateIB(indices);
	}
	void LoadMeshes()
	{
		LoadTriangleMesh();
		LoadRectMesh();
	}

	void Initialize()
	{
		LoadMeshes();
		LoadShaders();
		LoadConstantBuffers();
	}

	void Release()
	{
		inputLayouts->Release();
		delete mesh;
	}

}