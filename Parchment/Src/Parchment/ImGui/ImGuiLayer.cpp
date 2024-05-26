#include "Pchpch.h"
#include "Parchment/ImGui/ImGuiLayer.h"
#include "Parchment/Application.h"

#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

namespace Parch {
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{

	}
	ImGuiLayer::~ImGuiLayer()
	{

	}
	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();

		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();

		ImGui_ImplOpenGL3_Init("#version 410");

	}
	void ImGuiLayer::OnDetach()
	{

	}
	void ImGuiLayer::OnUpdate()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		bool state = true;
		ImGui::ShowDemoWindow(&state);

		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	void ImGuiLayer::OnEvent(Event& event)
	{

	}
}