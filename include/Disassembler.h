//
// Created by berci on 2022. 04. 03..
//

#pragma once

#include "./instruction/Instruction.h"
#include "InstructionBuilder.h"

#include <vector>

std::vector<Instruction::Instruction> disassemble(const std::vector<uint16_t>& program);