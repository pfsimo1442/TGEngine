#pragma once
#include <Windows.h>
#include <assert.h>
#include <memory>

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
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#include <ostream>
#include <sstream>

#include "tgEnums.h"
#include "tgMath.h"

#define BIT(x) (1 << x)
#define CAST_UINT(value) static_cast<UINT>(value)
#define CAST_FLOAT(value) static_cast<float>(value)

#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if (p) { delete[] p; p = nullptr; }
#define SAFE_RELEASE(p) if (p) { p->Release(); p = nullptr; }

#define TG_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }