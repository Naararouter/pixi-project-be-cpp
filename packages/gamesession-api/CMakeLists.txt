cmake_minimum_required(VERSION 3.24)
set(project_name test) ## rename your project here
project(${project_name})

set(CMAKE_CXX_STANDARD 20)
#add_compile_options(-O0)

## link libs
find_package(oatpp 1.3.0 REQUIRED)
find_package(oatpp-websocket 1.3.0 REQUIRED)

add_library(${project_name}-lib
        websocket/WSListener.cpp
        websocket/WSListener.hpp
        StaticController.hpp
        AppComponent.hpp
        main.cpp)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-websocket
        )

## add executables

add_executable(${project_name}-exe main.cpp)
target_link_libraries(${project_name}-exe ${project_name}-lib)

add_custom_command(TARGET ${project_name}-exe POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/frontend/public $<TARGET_FILE_DIR:${project_name}-exe>/public)