add_library(src main.cpp)

add_subdirectory(gui)
target_link_libraries(src PUBLIC gui)
target_include_directories(src PUBLIC ${PROJECT_BINARY_DIR}/src ${PROJECT_BINARY_DIR}/src/gui)