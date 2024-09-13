add_library(src main.cpp)

add_subdirectory(gui)
add_subdirectory(logging)
target_link_libraries(src PUBLIC gui logging)
target_include_directories(src PUBLIC ${PROJECT_BINARY_DIR}/src ${PROJECT_BINARY_DIR}/src/gui)