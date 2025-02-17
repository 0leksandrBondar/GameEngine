file(
        GLOB Sources
        "*.h"
        "*.cpp"
)

add_library(Utils STATIC ${Sources})
add_library(BondEngine::Utils ALIAS Utils)

target_include_directories(Utils PUBLIC ./)

target_link_libraries(Utils PUBLIC
        GLWrapper
)

