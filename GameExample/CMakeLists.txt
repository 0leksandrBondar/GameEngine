cmake_minimum_required(VERSION 3.20...3.30)

project(GameExample)

set(SOURCES main.cpp)

add_executable(GameExample ${SOURCES})

target_link_libraries(GameExample PRIVATE
        BondEngine::Window
        BondEngine::Graphics
        Vulkan::Headers
        Vulkan::Loader
)

# TODO: move it to engine lib
set_target_properties(GameExample PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_custom_command(TARGET GameExample PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/bin/assets"
        COMMENT "Creating assets directory"
)

add_custom_command(TARGET GameExample POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/Engine/Assets"
        "${CMAKE_BINARY_DIR}/bin/assets"
        COMMENT "Copying assets"
)

