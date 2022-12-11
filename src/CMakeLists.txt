# Path definitions.
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR})

# Add overall src library.
file(GLOB_RECURSE src_sources CONFIGURE_DEPENDS ${src_dir}/*.cpp)
add_library(src ${src_sources} djikstra.cpp djikstra.h)
target_include_directories(src PUBLIC ${src_dir})
