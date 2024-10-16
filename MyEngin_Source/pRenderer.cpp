#include "pRenderer.h"
#include "pCamera.h"
namespace p::renderer{
	Camera* mainCamera = nullptr;

	Vertex vertexes[3] = {};
	ID3D11Buffer* vertexBuffer = nullptr; //vectex를 gpu로 옮기기 위한 버퍼
	ID3DBlob* vsBlob = nullptr; //코드 뭉터기
	ID3D11VertexShader* vsShader = nullptr;//가공할 쉐이더
	ID3DBlob* psBlob = nullptr;
	ID3D11PixelShader* psShader = nullptr;
	ID3D11InputLayout* inputLayouts = nullptr;

}