add_library(gui 
            GuiFactory.h GuiFactory.cpp
            GtkUI.h GtkUI.cpp
            WindowSystem.h WindowSystem.cpp)# Window.h Window.cpp) # Widgets.h Widgets.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

target_link_libraries(gui PkgConfig::GTK4)
link_directories(${GTK_LIBRARY_DIRS})
include_directories(${GTK_INCLUDE_DIRS})