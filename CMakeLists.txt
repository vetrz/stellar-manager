cmake_minimum_required(VERSION 3.11)

project(StellarManeger LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG        v5.0.0
)

FetchContent_MakeAvailable(ftxui)

add_executable(stellar 
  src/main.cpp
  src/vetor.cpp
  src/constellation.cpp
)

target_link_libraries(stellar
  PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)
