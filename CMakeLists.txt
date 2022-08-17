cmake_minimum_required(VERSION 3.12)

project(consoleEngine C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-Wno-multichar -std=c++17")

file(GLOB_RECURSE SRC "src/*.cpp")
add_executable(
    ${PROJECT_NAME}
    ${SRC}
)
target_include_directories(${PROJECT_NAME} PRIVATE "include")

file(GLOB_RECURSE MODELS "models/*.obj")
foreach (_model ${MODELS})
    configure_file(${_model} ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
endforeach()


install (FILES ${MODELS} DESTINATION .)
