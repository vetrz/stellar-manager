cmake_minimum_required(VERSION 3.11)

project(StellarManeger LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

set(FTXUI_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(FTXUI_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(FTXUI_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG        v5.0.0
)

FetchContent_MakeAvailable(ftxui)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(stellar ${SOURCES})

add_definitions(-DDATA_PATH="${CMAKE_SOURCE_DIR}/data/constellation.csv")

target_include_directories(stellar
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_precompile_headers(stellar
  PRIVATE
    <ftxui/dom/elements.hpp>
    <ftxui/component/component.hpp>
    <ftxui/screen/screen.hpp>
)

target_link_libraries(stellar
  PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)
