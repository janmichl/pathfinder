# top-level targets

file(GLOB SOURCES "*.cpp")

foreach(SOURCE ${SOURCES})
  get_filename_component(TGT ${SOURCE} NAME_WE)
  add_executable(${TGT} ${SOURCE})
  target_link_libraries(${TGT} yaml-cpp)
  add_dependencies(${TGT} TGT_build_libraries)
endforeach()
