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
#include "GLWrapper/OpenGL/OpenGL.h"

#include <algorithm>
#include <filesystem>

namespace BondEngine
{
    class Texture2D final : public NonCopyable
    {
    public:
        Texture2D() = default;

        explicit Texture2D(const std::filesystem::path& path);
        Texture2D(GLuint width, GLuint height, const unsigned char* data, size_t channels = 4,
                  GLenum filter = GL_LINEAR, GLenum wrapMode = GL_CLAMP_TO_EDGE);
        ~Texture2D() override { glDeleteTextures(1, &_id); }

        Texture2D(Texture2D&& other) noexcept { *this = std::move(other); }
        Texture2D& operator=(Texture2D&& other) noexcept;

        void setSmooth(bool smooth);

        void bind() const
        {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, _id);
        }
        void unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }

        [[nodiscard]] bool isSmooth() const { return _smooth; }

    private:
        void loadTexture(const std::filesystem::path& path);
        void initialize(const unsigned char* data, const size_t channels = 4,
                        const GLenum filter = GL_LINEAR, const GLenum wrapMode = GL_CLAMP_TO_EDGE);

    private:
        GLenum _mode;
        GLuint _id{ 0 };
        GLenum _format{ GL_RGB };

        bool _smooth{ false };

        int channels{ 0 };
        int _width{ 0 }, _height{ 0 };
    };
} // namespace BondEngine