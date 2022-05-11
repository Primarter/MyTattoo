cmake_minimum_required(VERSION 3.9)
project(tattoo DESCRIPTION "Tattoo test project")

set(PROJECT_ROOT ./)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

include(GNUInstallDirs)

##############################
# 3DDungeon executable
##############################
set(SRC_FILES
    ${PROJECT_ROOT}/src/main.cpp
    ${PROJECT_ROOT}/src/utils.cpp
)

add_executable(tattdisp
    ${SRC_FILES}
)

target_include_directories(tattdisp
    PRIVATE
        ${PROJECT_ROOT}/include/
)

target_link_libraries(tattdisp sfml-window sfml-audio sfml-graphics sfml-system m)
