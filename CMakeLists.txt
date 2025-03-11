
cmake_minimum_required(VERSION 3.31)

cmake_policy(SET CMP0048 NEW)

project(Card_Game VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE GAME_SOURCES "src/*.cpp")
#file(GLOB_RECURSE GAME_HEADERS "include/CardGme/*.hpp")

add_library(CardGameLib${GAME_SOURCES})

target_include_directories(CardGameLib PUBLIC include)

add_executable(CardGame src/main.cpp)

target_link_libraries(CardGame PRIVATE CardGameLib)

enable_testing()

file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

if(TEST_SOURCES)
add_executable(runTests ${TEST_SOURCES})

target_link_libraries(runTests PRIVATE CardGameLib)

add_test(NAME CardGameTests COMMAND runTests)
endif()