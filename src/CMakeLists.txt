# top-level target
set(tgt main)
add_executable(${tgt} main.cpp)
target_link_libraries(${tgt} yaml-cpp)
add_dependencies(${tgt} TGT_build_libraries)
