//
// Created by berci on 2022. 03. 20..
//

#pragma once

#include "MachineState.h"
#include "./instruction/Instruction.h"

#include <memory>

class InstructionBuilder {
public:

    Instruction::Instruction halt() const;

    Instruction::Instruction set(MachineState::Register register_n, MachineState::Register value) const;

    // push <a> onto the stack
    Instruction::Instruction push(MachineState::Value a) const;

    // remove the top element from the stack and write it into <a>; empty stack = error
    Instruction::Instruction pop(MachineState::Register a) const;

    // set <a> to 1 if <b> is equal to <c>; set it to 0 otherwise
    Instruction::Instruction eq(MachineState::Address a, MachineState::Value b, MachineState::Value c) const;

    // set <a> to 1 if <b> is greater than <c>; set it to 0 otherwise
    Instruction::Instruction gt(MachineState::Address a, MachineState::Value b, MachineState::Value c) const;

    // if <a> is nonzero, jump to <b>
    Instruction::Instruction jmp(MachineState::Value a, MachineState::Address b) const;

    // if <a> is nonzero, jump to <b>
    Instruction::Instruction jt(MachineState::Value a, MachineState::Address b) const;

    // if <a> is zero, jump to <b>
    Instruction::Instruction jf(MachineState::Value a, MachineState::Address b) const;

    // assign into <a> the sum of <b> and <c> (modulo 32768)
    Instruction::Instruction add(MachineState::Address a, MachineState::Value b, MachineState::Value c) const;

    // store into <a> the product of <b> and <c> (modulo 32768)
    Instruction::Instruction mult(MachineState::Address a, MachineState::Value b, MachineState::Value c) const;

    // store into <a> the remainder of <b> divided by <c>
    Instruction::Instruction mod(MachineState::Address a, MachineState::Value b, MachineState::Value c) const;

    // stores into <a> the bitwise and of <b> and <c>
    Instruction::Instruction bitwise_and(MachineState::Address a, MachineState::Value b, MachineState::Value c) const;

    // stores into <a> the bitwise or of <b> and <c>
    Instruction::Instruction bitwise_or(MachineState::Address a, MachineState::Value b, MachineState::Value c) const;

    // stores 15-bit bitwise inverse of <b> in <a>
    Instruction::Instruction bitwise_not(MachineState::Address a, MachineState::Value b, MachineState::Value c) const;

    // read memory at address <b> and write it to <a>
    Instruction::Instruction rmem(MachineState::Address a, MachineState::Address b) const;

    // write the value from <b> into memory at address <a>
    Instruction::Instruction wmem(MachineState::Address a, MachineState::Address b) const;

    // write the address of the next instruction to the stack and jump to <a>
    Instruction::Instruction call(MachineState::Address a, MachineState::Address b) const;

    // remove the top element from the stack and jump to it; empty stack = halt
    Instruction::Instruction ret() const;

    // write the character represented by ascii code <a> to the terminal
    Instruction::Instruction out(MachineState::Value a) const;

    // read a character from the terminal and write its ascii code to <a>; it can be assumed that once input starts, it will continue until a newline is encountered; this means that you can safely read whole lines from the keyboard and trust that they will be fully read
    Instruction::Instruction in(MachineState::Address a) const;

    // no operation
    Instruction::Instruction noop();
};