cmake_minimum_required(VERSION 3.14)
project(CardGame VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Fetch Catch2 from GitHub
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.10
)
FetchContent_MakeAvailable(catch2)

# Enable testing
enable_testing()

# Source files for the main game
file(GLOB_RECURSE GAME_SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)
add_library(CardGameLib ${GAME_SOURCES})

target_include_directories(CardGameLib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# Main game executable
add_executable(CardGame
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(CardGame PRIVATE
    CardGameLib
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

# Test files
file(GLOB TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/tests/*.cpp
)

# Only add the test executable if we have test sources
if(TEST_SOURCES)
  add_executable(runTests
    ${TEST_SOURCES}
  )
  target_link_libraries(runTests PRIVATE
    CardGameLib
    Catch2::Catch2
  )
  add_test(NAME AllUnitTests COMMAND runTests)
endif()