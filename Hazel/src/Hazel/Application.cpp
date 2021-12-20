#include "hzpch.h"
#include "Application.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Hazel
{   
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        s_Instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application(){}

    void Application::PushLayer(Layer* layer){
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer){
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach(); 
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(0.1, 0.1, 0.1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for(Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(HZ_BIND_EVENT_FN(Application::OnWindowClose));
        // std::cout << e << std::endl;
        
        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ){
            (*--it)->OnEvent(e);
            if(e.Handled())
                break;
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e){
        m_Running = false;
        return true;
    }
} // namespace Hazel
