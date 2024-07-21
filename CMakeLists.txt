cmake_minimum_required(VERSION 3.5.0)  # Necessary minimum step
project(npc-man VERSION 0.1.0 LANGUAGES C CXX)  # Necessary minimum step
add_executable(npc-man src/main.cpp)  # Necessary minimum step 

# Add local subdirectories
add_subdirectory(src)
target_link_libraries(npc-man PUBLIC src)
target_include_directories(npc-man PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_BINARY_DIR}/src)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)