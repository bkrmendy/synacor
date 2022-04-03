//
// Created by berci on 2022. 03. 29..
//

#include "../include/MachineState.h"

#include <utility>

void MachineState::halt() {
    this->running_ = false;
}

void MachineState::push(MachineState::Value value) {
    this->stack_.push(value);
}

std::optional<MachineState::Value> MachineState::pop() {
    if (this->stack_.empty()) {
        return std::nullopt;
    }

    const auto top = this->stack_.top();
    this->stack_.pop();
    return top;
}

void MachineState::write_memory(const MachineState::Address& address, MachineState::Value value) {
    this->memory_[address] = value;
}

MachineState::Value MachineState::read_memory(const MachineState::Address& address) {
    return this->memory_[address];
}

void MachineState::write_register(const MachineState::Register& register_n, MachineState::Value value) {
    this->registers_[register_n] = value;
}

MachineState::Value MachineState::read_register(const MachineState::Register& register_n) {
    return this->registers_[register_n];
}

void MachineState::jump(size_t ip) {
    this->ip_ = ip;
}

MachineState::MachineState(
        const std::array<Value, 32767> &memory,
        const std::array<Value, 8> &registers,
        std::stack<Value> stack,
        size_t ip,
        bool running
        ) : memory_(memory), registers_(registers), stack_(std::move(stack)), ip_(ip), running_(running) {}

MachineState MachineState::fresh() {
    return MachineState(std::array<Value, 32767>{}, std::array<Value, 8>{}, std::stack<Value>{}, 0, true);
}

bool MachineState::is_running() const {
    return this->running_;
}

