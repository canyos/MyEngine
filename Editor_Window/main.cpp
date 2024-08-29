// Editor_Window.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Editor_Window.h"
#include "..\\MyEngin_Source\\pApplication.h"

Application app;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
//wchar 2byte char
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,//프로그램의 인스턴스 핸들 (핸들을 통해서만 윈도우 메모리에 접근)
                     _In_opt_ HINSTANCE hPrevInstance, //바로앞에 실행된 현재 프로그램의 인스턴스 핸들, 없을경우에는 NULL (현재는 사용안함)
                     _In_ LPWSTR    lpCmdLine, //명령행으로 입력된 프로그램 인수(거의 쓸일 없음 argc,argv)
                     _In_ int       nCmdShow)//프로그램이 실행될 형태, 모양 정보 등이 전달됨
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
	app.test();
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);//인스턴스 정보를 설정함

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg;
	//GetMessage(&msg, nullptr, 0, 0)
	// 프로세스에서 발생한 메세지를 메세지 큐에서 가져오는 함수
	// 아무것도 없으면 아무 메시지도 가져오지 않음
	
	//PeekMessage : 메세지큐에 메시지 유무에 없이 함수 리턴
	//              리턴값이 true -> 메세지있음, false ->메세지 없음
	
	while (true) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {//메세지 읽고 지워줘야함
			if (msg.message == WM_QUIT)
				break;
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else {
			//메세지가 없을 경우 여기서 처리
			//게임 로직
		}
	}


    // 기본 메시지 루프입니다:
    //while (GetMessage(&msg, nullptr, 0, 0)) //프로그램이 종료되지않게 함, 메시지 큐를 확인해 메시지 확인함
    //{
    //    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    //    {
    //        TranslateMessage(&msg);
    //        DispatchMessage(&msg);
    //    }
    //}

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOW);
    wcex.lpszClassName  = szWindowClass; //인스턴스 이름 설정
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, //window창을 만들어줌, szWindowClass로 register한 정보 들고와서 설정,
	                                                                           //szTitle이 이름, WS_OVERLAPPEDWINDO는 타입
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);//시작할때 위치xy, 가로세로크기 설정가능

   if (!hWnd) //윈도우에 접근 가능한 핸들 반환
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)//메세지 처리할 함수포인터
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT: //파일 도움말 등 선택하면 나오는거
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

    case WM_PAINT: 
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			//DC 화면에 출력에 필요한 모든 정보를 가지는 데이터 구조
			//GDI 모듈에 의해서 관리
			// 어떤 폰트를 사용할지, 선의 굵기를 정하기, 어떤 색상
			// 화면 출력에 모든 경우는 DC를 통해 작업 진행
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

			HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));//색을 칠할 브러쉬
			

			HBRUSH oldBrush = (HBRUSH) SelectObject(hdc, brush);//dc가 배경을 brush를 사용하도록 함
			Rectangle(hdc, 100, 100, 200, 200);//윈도우마다 dc가 있고 여러개일수 있으므로 dc정확하게 넣어줘야함

			SelectObject(hdc, oldBrush); //기존 흰색 배경이 메모리 낭비하게 되므로 새로운 브러쉬 사용하고 다시 흰색으로 바꿔줌
			DeleteObject(brush);//파랑색 브러쉬 오브젝트 메모리 해제
			
			HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));// 선의 형태, dc, 굵기, 색상
			HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
			Ellipse(hdc, 200, 200, 300, 300);
			SelectObject(hdc, oldPen); 
			DeleteObject(redPen);
			//기본으로 자주사용 되는 GDI오브젝트를 미리 DC안에 만들어둠 -> stockObject
			HBRUSH grayBrush = (HBRUSH) GetStockObject(GRAY_BRUSH); //stockObject사용해 브러쉬 생성
			HBRUSH oldBrush2 = (HBRUSH)SelectObject(hdc, grayBrush);
			Rectangle(hdc, 400, 400, 500, 500);
			SelectObject(hdc, oldBrush2); //default로 돌려두기, delete는 할필요없음

            EndPaint(hWnd, &ps);
        }
        break;
	//case WM_MOVE: //윈도우 창이 움직이면
	//	{
	//	int a = 0;
	//	}
	//	
	//	break;
    case WM_DESTROY://윈도우 종료될때 호출
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
