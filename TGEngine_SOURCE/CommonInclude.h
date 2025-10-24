#pragma once
#include <Windows.h>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <functional>
#include <filesystem>
#include <mutex>
#include <thread>
#include <math.h>

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "winmm.lib")

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

#include "tgEnums.h"
#include "tgMath.h"

#define CAST_UINT(value) static_cast<UINT>(value)
#define CAST_FLOAT(value) static_cast<float>(value)