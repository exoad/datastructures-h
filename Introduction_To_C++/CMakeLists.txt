file(GLOB DSHINTRO_SRC "*.hh" "*.cc")

add_executable(dshintro ${DSHINTRO_SRC})
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(dshintro PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(dshintro PRIVATE /W4)
endif()
target_include_directories(dshintro PUBLIC ../)
