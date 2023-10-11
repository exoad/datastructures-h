file(GLOB DSHPROJECT_SRC "*.hh" "*.cc")

add_executable(dshprojects ${DSHPROJECT_SRC}
        TimeTracker.cpp)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(dshprojects PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(dshprojects PRIVATE /W4)
endif()
target_include_directories(dshprojects PUBLIC ../)