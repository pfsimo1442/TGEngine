#include "tgWindow.h"
#include "tgApplicationEvent.h"
#include "tgMouseEvent.h"

namespace tg
{
	void Window::Initalize()
	{

	}

	void Window::SetWindowResize(UINT width, UINT height)
	{
		mData.Width = width;
		mData.Height = height;

		WindowResizeEvent event(width, height);
		
		if (mData.EventCallback)
			mData.EventCallback(event);
	}

	void Window::SetCursorPos(double x, double y)
	{
		MouseMovedEvent event(static_cast<float>(x), static_cast<float>(y));
		
		if (mData.EventCallback)
			mData.EventCallback(event);
	}
}