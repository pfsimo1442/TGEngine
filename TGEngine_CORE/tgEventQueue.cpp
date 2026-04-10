#include "tgEventQueue.h"

namespace tg
{
	EventQueue::EventQueue()
	{
	}
	EventQueue::~EventQueue()
	{
	}

	void EventQueue::Push(Event* event)
	{
		mQueue.push(event);
	}

	void EventQueue::Process()
	{
		while (!mQueue.empty())
		{
			Event* event = mQueue.front();
			mQueue.pop();

			EventDispatcher dispatcher(*event);

			// 등록된 핸들러 실행
			auto handler = mHandlers.find(event->GetEventType());
			if (handler != mHandlers.end())
			{
				event->Handled != handler->second(*event);
			}

			// 기본 핸들러 실행 (처리되지 않은 경우)
			if (!event->Handled && mCallback)
			{
				mCallback(*event);
			}

			delete event;
			event = nullptr;
		}
	}

	void EventQueue::SetCallback(const EventCallbackFn& callback)
	{
		mCallback = callback;
	}
}