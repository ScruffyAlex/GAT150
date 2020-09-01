#pragma once
#include "Singleton.h"
#include <string>
#include <map>
#include <list>
#include <functional>

namespace nc
{
	class Object;

	struct Event
	{
		std::string type;
		Object* sender;
		Object* reciever;
		void* data;
	};

	class EventManager : public Singleton<EventManager>
	{
	public:
		typedef std::function<void(const Event&)> funciton_t;
		using function_t = std::function<void(const Event&)>;

		struct Observer
		{
			function_t function;
			Object* owner{ nullptr };
		};

	public:
		void Subscribe(const std::string& type, funciton_t function, Object* owner = nullptr);
		void Notify(const Event& event);

	private:
		std::map<std::string, std::list<Observer>> m_observers;
	};
}