// MIT License
//
// Copyright (c) 2025 Oleksandr
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "Cube.h"

#include "GLWrapper/ShaderProgram/ShaderProgram.h"
#include "GLWrapper/Vertex/Vertex.h"

#include <glm/gtc/matrix_transform.hpp>

#include <vector>

namespace BondEngine
{
    std::vector<Vertex3D> cubeVertices = { { { -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f } },
                                           { { 0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f, 0.0f } },
                                           { { 0.5f, 0.5f, -0.5f }, { 0.0f, 0.0f, 1.0f } },
                                           { { -0.5f, 0.5f, -0.5f }, { 1.0f, 1.0f, 0.0f } },
                                           { { -0.5f, -0.5f, 0.5f }, { 0.0f, 1.0f, 1.0f } },
                                           { { 0.5f, -0.5f, 0.5f }, { 1.0f, 0.0f, 1.0f } },
                                           { { 0.5f, 0.5f, 0.5f }, { 0.5f, 0.5f, 0.5f } },
                                           { { -0.5f, 0.5f, 0.5f }, { 0.2f, 0.3f, 0.8f } } };

    unsigned int indices[] = { 0, 1, 2, 2, 3, 0, 1, 5, 6, 6, 2, 1, 5, 4, 7, 7, 6, 5,
                               4, 0, 3, 3, 7, 4, 3, 2, 6, 6, 7, 3, 4, 5, 1, 1, 0, 4 };

    Cube::Cube(ShaderProgram* shader)
    {
        _shader = shader;
        setupRenderData();

        glm::mat4 view = glm::lookAt(glm::vec3(1.5f, 1.5f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f),
                                     glm::vec3(0.0f, 1.0f, 0.0f));

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1300.f / 800.f, 0.1f, 100.0f);

        _shader->activate();
        _shader->setMatrix4("view", view);
        _shader->setMatrix4("projection", projection);
    }

    void Cube::render()
    {
        auto model = glm::mat4(1.0f);
        model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));

        _shader->activate();
        _shader->setMatrix4("model", model);
        _vao.bind();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    }

    void Cube::setupRenderData()
    {
        _vbo.init(cubeVertices.data(), cubeVertices.size() * sizeof(Vertex3D));
        VertexBufferLayout layout;
        layout.addElementLayoutFloat(3, false);
        layout.addElementLayoutFloat(3, false);
        _vao.addBuffer(_vbo, layout);
        _ebo.init(indices, sizeof(indices));
        _vao.unbind();
        _ebo.unbind();
    }
} // namespace BondEngine
