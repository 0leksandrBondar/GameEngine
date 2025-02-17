file(
        GLOB Sources
        "NonCopyable/*.h"
        "NonCopyable/*.cpp"
        "NonMoveable/*.h"
        "NonMoveable/*.cpp"
        "Transformable/*.h"
        "Transformable/*.cpp"
        "Singleton/*.h"
)

add_library(BaseTypes STATIC ${Sources})
add_library(BondEngine::BaseTypes ALIAS BaseTypes)

target_include_directories(BaseTypes PUBLIC ../)

target_link_libraries(BaseTypes PUBLIC
)

