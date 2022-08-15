cmake_minimum_required(VERSION 3.12)

project(consoleEngine C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

set (INCLUDE_DIRS "")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/**.hpp")
file(GLOB_RECURSE SRC "src/**.cpp")
foreach (_headerFile ${HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES INCLUDE_DIRS)
set(CONTENT colorCube)
add_executable(
    ${PROJECT_NAME}
    ${SRC}
)
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})

file(GLOB_RECURSE MODELS "models/*.obj")
foreach (_model ${MODELS})
    configure_file(${_model} ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
endforeach()


install (FILES ${MODELS} DESTINATION .)
