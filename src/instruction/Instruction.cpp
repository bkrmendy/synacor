//
// Created by berci on 2022. 03. 30..
//


#include "instruction/Instruction.h"

#include <utility>

Instruction::Eq::Eq(
        MachineState::Register a,
        const MachineState::Value b,
        const MachineState::Value c) : a(a), b(b), c(c) {}

void Instruction::Eq::execute(MachineState &machine) const {
    const auto val = b == c ? 1 : 0;
    machine.write_register(a, val);
}

const char* Instruction::Eq::documentation() const {
    return "set <a> to 1 if <b> is equal to <c>; set it to 0 otherwise";
}

std::ostream &Instruction::Eq::display(std::ostream &os) const {
    os << "eq " << a << " " << b << " " << c;
    return os;
}

Instruction::Gt::Gt(MachineState::Register a, const MachineState::Value b, const MachineState::Value c) : a(std::move(a)), b(b), c(c) {}

void Instruction::Gt::execute(MachineState &machine) const {
    const auto val = b > c ? 1 : 0;
    machine.write_register(a, val);
}

const char *Instruction::Gt::documentation() const {
    return "set <a> to 1 if <b> is greater than <c>; set it to 0 otherwise";
}

std::ostream &Instruction::Gt::display(std::ostream &os) const {
    os << "gt " << a << " " << b << " " << c;
    return os;
}

Instruction::Jmp::Jmp(const size_t target) : target(target) {}

void Instruction::Jmp::execute(MachineState &machine) const {
    machine.jump(target);
}

const char *Instruction::Jmp::documentation() const {
    return "jump to <a>";
}

std::ostream &Instruction::Jmp::display(std::ostream &os) const {
    os << "jmp " << target;
    return os;
}

void Instruction::Halt::execute(MachineState& machine) const {
    machine.halt();
}

const char* Instruction::Halt::documentation() const {
    return "stop execution and terminate the program";
}

std::ostream& Instruction::Halt::display(std::ostream &os) const {
    os << "halt";
    return os;
}

void Instruction::Set::execute(MachineState& machine) const {
    const auto valueOfB = machine.read_register(this->b);
    machine.write_register(this->a, valueOfB);
}

const char* Instruction::Set::documentation() const {
    return "set register <a> to the value of <b>";
}

std::ostream& Instruction::Set::display(std::ostream &os) const {
    os << "set" << " " << this->a << " " << this->b;
    return os;
}

void Instruction::Pop::execute(MachineState &machine) const {
    const auto value = machine.pop();
    machine.write_register(this->a, value.value());
}

const char* Instruction::Pop::documentation() const {
    return "remove the top element from the stack and write it into <a>; empty stack = error";
}

std::ostream& Instruction::Pop::display(std::ostream &os) const {
    os << "pop " << this->a;
    return os;
}

