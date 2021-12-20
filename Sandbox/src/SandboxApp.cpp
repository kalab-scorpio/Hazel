#include <Hazel.h>

class HAZEL_API ExampleLayer : public Hazel::Layer
{
public:
    ExampleLayer() : Layer("Example"){}

    void OnUpdate() override{
        // std::cout<< "ExampleLayer::Update" << std::endl;
    }

    void OnEvent(Hazel::Event& event) override{
        // std::cout<< event << std::endl;  
    } 
};


class HAZEL_API Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Hazel::ImGuiLayer());
    }

    ~Sandbox()
    {
    }
};

Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}