cmake_minimum_required(VERSION 3.24)
set(project_name test) ## rename your project here
project(${project_name})

set(CMAKE_CXX_STANDARD 20)

## link libs

find_package(oatpp 1.3.0 REQUIRED)

add_library(${project_name}-lib
        StaticController.hpp
        AppComponent.hpp
        main.cpp)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        )

add_custom_target(copy-public-folder
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/public ${CMAKE_CURRENT_BINARY_DIR}/public
        COMMENT "Copying public folder to build directory")


## add executables

#add_executable(test
#        main.cpp
#        )

#set(CMAKE_CXX_STANDARD 11)

#cmake_minimum_required(VERSION 3.24)
#project(test)
add_executable(${project_name}-exe main.cpp)
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe copy-public-folder)

#find_package(oatpp 1.3.0 REQUIRED)
#target_link_libraries(my_executable
#        PUBLIC oatpp::oatpp
#        PUBLIC oatpp::oatpp-test
#        )
#
#target_include_directories(my_executable PUBLIC src)
#
#set(CMAKE_CXX_STANDARD 20)
#
#add_executable(test main.cpp)
