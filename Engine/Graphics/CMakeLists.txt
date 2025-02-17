file(
        GLOB Sources
        "Objects3D/*.h"
        "Objects3D/*.cpp"
)

add_library(Graphics STATIC ${Sources})
add_library(BondEngine::Graphics ALIAS Graphics)

target_include_directories(Graphics PUBLIC ../)

target_link_libraries(Graphics PUBLIC
        BondEngine::GLWrapper
)

