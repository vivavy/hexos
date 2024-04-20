cmake_minimum_required(VERSION 3.28)
project(hexos-x86_64)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(HXEC elf2hxe)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(hexos-x86_64.elf 
  ${SOURCES})


target_include_directories(hexos-x86_64.elf
  PUBLIC
  src/kernel/include
  src/modules/ramdisk/include
)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/hexos-x86_64.hxe
    COMMAND ${HXEC} ${CMAKE_CURRENT_SOURCE_DIR}/hexos-x86_64.elf ${CMAKE_CURRENT_SOURCE_DIR}/hexos-x86_64.hxe
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/hexos-x86_64.elf
)
