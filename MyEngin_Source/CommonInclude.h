#pragma once
#include <Windows.h>
#include <assert.h>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <filesystem>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include "pMath.h"
#include "pEnum.h"
#include <mutex>
#include <thread>

#include <mmsystem.h>
#include <wingdi.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "winmm.lib")

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

#define CAST_UINT(value) static_cast<UINT>(value)
#define CAST_FLOAT(value) static_cast<float>(value)

