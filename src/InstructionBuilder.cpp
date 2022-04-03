//
// Created by berci on 2022. 03. 29..
//

#include "../include/InstructionBuilder.h"

Instruction::Instruction InstructionBuilder::halt() const {
    return Instruction::Halt{};
}

Instruction::Instruction InstructionBuilder::set(MachineState::Register register_n, MachineState::Register value) const {
    return Instruction::Set{register_n, value};
}

Instruction::Instruction InstructionBuilder::push(MachineState::Value a) const {
    return Instruction::Push{a};
}

Instruction::Instruction InstructionBuilder::pop(MachineState::Register a) const {
    return Instruction::Pop{a};
}

Instruction::Instruction
InstructionBuilder::eq(MachineState::Register a, MachineState::Value b, MachineState::Value c) const {
    return Instruction::Eq{a, b, c};
}

Instruction::Instruction
InstructionBuilder::gt(MachineState::Register a, MachineState::Value b, MachineState::Value c) const {
    return Instruction::Gt{a, b, c};
}
