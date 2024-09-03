#pragma once
#include "pEntity.h"
namespace p {
	class Resource:public Entity
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;//bool�̶� ����
		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }
	private:
		std::wstring mPath;
		const enums::eResourceType mType;

	};
	//���ҽ��� ����ؼ� ����� �߻�Ŭ������ ����
	//�޸� �Ҵ� �Ұ���
}


