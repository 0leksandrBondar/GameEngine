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

#pragma once

#include "BaseTypes/NonCopyable/NonCopyable.h"
#include "glad/glad.h"

#include "GLWrapper/VAO/VertexBufferLayout.h"
#include "GLWrapper/VBO/VBO.h"
namespace BondEngine
{
    class VAO final : public NonCopyable
    {
    public:
        VAO();
        VAO(VAO&& other) noexcept;
        VAO& operator=(VAO&& other) noexcept;
        ~VAO() override;

        void addBuffer(const VBO& vertexBuffer, const VertexBufferLayout& layout);

        void bind() const;
        void unbind() const;

    private:
        GLuint _id{ 0 };
        unsigned int _elementsCount{ 0 };
    };

} // namespace BondEngine