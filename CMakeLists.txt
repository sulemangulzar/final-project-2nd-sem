cmake_minimum_required(VERSION 3.16)
project(final_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Support Homebrew-installed Qt6 on macOS.
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH
        /opt/homebrew/Cellar/qtbase/6.11.0/lib/cmake
        /opt/homebrew/Cellar/qt/6.11.0/lib/cmake
        /opt/homebrew/opt/qt/lib/cmake
        /usr/local/opt/qt/lib/cmake
    )
endif()

find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(QT_MODULES Qt6::Widgets)

add_executable(final_project
    main.cpp
    MainWindow.cpp
    Planner.cpp
    Task.cpp
)

target_link_libraries(final_project PRIVATE ${QT_MODULES})
