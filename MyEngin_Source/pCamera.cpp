#include "pCamera.h"
#include "pGameObject.h"
#include "pTransform.h"
#include "pApplication.h"
extern p::Application application;

namespace p {
	Matrix Camera::ViewMatrix = Matrix::Identity;
	Matrix Camera::ProjectionMatrix = Matrix::Identity;

	Camera::Camera()
		:Component(enums::eComponentType::Camera)
		, mProjectionType(eProjectionType::Perspective)
		, mViewMatrix(Matrix::Identity)
		, mProjectionMatrix(Matrix::Identity)
		, mAspectRatio(0.0f)
		, mNear(1.0f)
		, mFar(1000.0f)
		, mSize(1.0f)
	{
	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
		//mResolution.x = (float)application.GetWidth();
		//mResolution.y = (float)application.GetHeight();
	}
	void Camera::Update()
	{
		/*if (mTarget) {
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		else {
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTr->GetPosition();
		}


		mDistance = mLookPosition - (mResolution / 2.0f);*/
	}
	void Camera::LateUpdate()
	{
		CreateViewMatrix();
		CreateProjectionMatrix(mProjectionType);

		ViewMatrix = mViewMatrix;
		ProjectionMatrix = mProjectionMatrix;
	}
	void Camera::Render()
	{
	}
	void Camera::CreateViewMatrix()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		const Vector3 pos = tr->GetPosition();
		const Vector3 up = tr->Up();
		const Vector3 forward = tr->Foward();
		mViewMatrix = Matrix::CreateLookToLH(pos, forward, up);
	}
	void Camera::CreateProjectionMatrix(eProjectionType type)
	{
		RECT winRect;
		GetClientRect(application.GetHwnd(), &winRect);
		float width = (winRect.right - winRect.left);
		float height = (winRect.bottom - winRect.top);
		mAspectRatio = width / height;
		switch (type)
		{
		case eProjectionType::Perspective:
			mProjectionMatrix = Matrix::CreatePerspectiveFieldOfViewLH(XM_2PI / 6.0f, mAspectRatio, mNear, mFar);
			break;
		case eProjectionType::Orthographic:
			mProjectionMatrix = Matrix::CreateOrthographicLH(width / mSize, height / mSize, mNear, mFar);
			break;
		}
	}
}