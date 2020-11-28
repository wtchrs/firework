add_executable(${OUTPUT_ELF} main.cpp firework.cpp)
target_include_directories(${OUTPUT_ELF} PUBLIC ${CMAKE_SOURCE_DIR}/includes)
