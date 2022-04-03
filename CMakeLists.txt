cmake_minimum_required(VERSION 3.20)
project(synacor)

set(CMAKE_CXX_STANDARD 23)

include_directories(synacor include)

add_library(synacor SHARED src/MachineState.cpp src/InstructionBuilder.cpp src/instruction/Instruction.cpp src/Disassembler.cpp)

enable_testing()
add_subdirectory(test)
