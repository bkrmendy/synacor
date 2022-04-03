//
// Created by berci on 2022. 04. 03..
//

#include "../include/Disassembler.h"

#include <tuple>

using DisassembleOneResult = std::pair<Instruction::Instruction, size_t>;

DisassembleOneResult disassemble_one(const std::vector<uint16_t>& program, size_t cursor) {
    InstructionBuilder builder = InstructionBuilder{};
    uint16_t opcode = program.at(cursor);
    if (opcode == 0) {
        return { builder.halt(), cursor + 1 };
    }

    if (opcode == 1) {
        uint16_t a = program.at(cursor + 1);
        uint16_t b = program.at(cursor + 2);
        return { builder.set(a, b), cursor + 3};
    }

    if (opcode == 3) {
        uint16_t a = program.at(cursor + 1);
        return { builder.push(a), cursor + 2 };
    }
}

std::vector<Instruction::Instruction> disassemble(const std::vector<uint16_t>& program) {
    std::vector<Instruction::Instruction> instructions{};

    size_t cursor = 0;
    while (cursor < program.size()) {

    }

    return instructions;
}
