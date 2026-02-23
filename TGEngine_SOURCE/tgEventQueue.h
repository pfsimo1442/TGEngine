#pragma once
#include "tgEvent.h"

namespace tg
{
	class EventQueue
	{
	public:
		EventQueue();
		~EventQueue();
		
		template <typename T>
		void RegisterHandler(std::function<bool(T&)> handler)
		{
			mHandlers[T::GetStaticType()] = [handler](Event& e) -> bool {
				return handler(static_cast<T&>(e));
				};
		}

		void Push(Event* event);
		void Process();
		void SetCallback(const EventCallbackFn& callback);

	private:
		std::queue<Event*> mQueue;
		EventCallbackFn mCallback;
		std::unordered_map<eEventType, HandlerCallbackFn> mHandlers;
	};	
}