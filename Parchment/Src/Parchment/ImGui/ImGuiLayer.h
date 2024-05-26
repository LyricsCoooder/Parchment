#pragma once

#include "Parchment/Core.h"
#include "Parchment/Layer.h"

namespace Parch {

	class PCH_API ImGuiLayer : public Parch::Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:

	};
}