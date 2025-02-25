cmake_minimum_required(VERSION 3.28)
project(three_in_throw LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0)

FetchContent_MakeAvailable(SFML)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

add_executable(three_in_throw board_element.h game.h game.cpp game_board.h game_board.cpp main.cpp)
target_link_libraries(three_in_throw PRIVATE SFML::Graphics)