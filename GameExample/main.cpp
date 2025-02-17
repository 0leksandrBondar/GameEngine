#include "Window/Window.h"

#include "GLWrapper/ShaderProgram/ShaderProgram.h"
#include "Graphics/Objects3D/Cube.h"

int main()
{
    const auto window = new BondEngine::Window(1300, 800, "BondEngine");
    const auto shader = new BondEngine::ShaderProgram("Assets/Shaders/Vertex3D.vert",
                                                      "Assets/Shaders/Fragment3D.frag");
    const auto cube = new BondEngine::Cube(shader);

    glEnable(GL_DEPTH_TEST);

    while (window->isOpen())
    {
        window->clear(0.2f, 0.3f, 0.3f, 1.0f);

        cube->render();

        window->pollEvents();
        window->swapBuffers();
    }

    return 0;
}
