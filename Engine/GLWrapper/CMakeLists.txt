file(
        GLOB Sources
        "VAO/*.h"
        "VBO/*.h"
        "EBO/*.h"
        "OpenGL/*.h"
        "Vertex/*.h"
        "ShaderProgram/*.h"

        "VAO/*.cpp"
        "VBO/*.cpp"
        "EBO/*.cpp"
        "ShaderProgram/*.cpp"
)

add_library(GLWrapper STATIC ${Sources})
add_library(BondEngine::GLWrapper ALIAS GLWrapper)

target_include_directories(GLWrapper PUBLIC ../)

target_link_libraries(GLWrapper PUBLIC
        glm
        glfw
        glad
        BondEngine::BaseTypes
)

