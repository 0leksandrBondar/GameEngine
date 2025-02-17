file(
        GLOB Sources
        "*.h"
        "*.cpp"
)

add_library(Window STATIC ${Sources})
add_library(BondEngine::Window ALIAS Window)

target_include_directories(Window PUBLIC ../)

target_link_libraries(Window PUBLIC BondEngine::Utils)

