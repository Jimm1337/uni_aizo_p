add_executable(uni_aizo_p main.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Compile options
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(uni_aizo_p INTERFACE -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic)
    if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
        target_compile_options(uni_aizo_p INTERFACE -g -O0)
    elseif (CMAKE_BUILD_TYPE EQUAL "RELEASE")
        target_compile_options(uni_aizo_p INTERFACE -O3)
    endif ()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(uni_aizo_p PUBLIC /W4 /w14640 /permissive- /Zc:preprocessor)
    if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
        target_compile_options(uni_aizo_p INTERFACE /Zi)
    elseif (CMAKE_BUILD_TYPE EQUAL "RELEASE")
        target_compile_options(uni_aizo_p INTERFACE /O2)
    endif ()
endif ()

# Libraries
target_link_libraries(uni_aizo_p PUBLIC fmt::fmt scn::scn)
target_include_directories(uni_aizo_p PUBLIC ${fmt_INCLUDE_DIRS} ${gsl_SOURCE_DIR}/include ${scn_INCLUDE_DIRS})
