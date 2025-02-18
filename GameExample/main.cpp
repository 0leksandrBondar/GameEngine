#define GLFW_INCLUDE_VULKAN

#include "Window/Window.h"

#include "GLWrapper/ShaderProgram/ShaderProgram.h"
#include "Graphics/Objects3D/Cube.h"

#include <iostream>

int main()
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    const auto window = new BondEngine::Window(1300, 800, "BondEngine");
    const auto shader = new BondEngine::ShaderProgram("Assets/Shaders/Vertex3D.vert",
                                                      "Assets/Shaders/Fragment3D.frag");
    const auto cube = new BondEngine::Cube(shader);

    VkInstance instance;
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan App";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
    {
        return -1;
    }

    std::cout << (const char*)glGetString(GL_RENDERER);

    glEnable(GL_DEPTH_TEST);

    while (window->isOpen())
    {
        window->clear(0.2f, 0.3f, 0.3f, 1.0f);

        cube->render();

        window->pollEvents();
        window->swapBuffers();
    }

    vkDestroyInstance(instance, nullptr);

    return 0;
}
