//
// Created by berci on 2022. 03. 20..
//

#pragma once

#include <array>
#include <cctype>
#include <stack>
#include <optional>

class MachineState {
public:
    using Value = uint16_t;
    using Address = uint16_t;
    using Register = uint16_t;
private:
    std::array<Value, 32767> memory_;
    std::array<Value, 8> registers_;
    std::stack<Value> stack_;

    size_t ip_;

    bool running_;

    MachineState(const std::array<Value, 32767> &memory, const std::array<Value, 8> &registers,
                 std::stack<Value> stack, size_t ip, bool running);

public:

    static MachineState fresh();

    bool is_running() const;

    void halt();

    void push(MachineState::Value value);

    std::optional<MachineState::Value> pop();

    void write_memory(const MachineState::Address& address, MachineState::Value value);

    MachineState::Value read_memory(const MachineState::Address& address);

    void write_register(const MachineState::Register& register_n, MachineState::Value value);

    MachineState::Value read_register(const MachineState::Register& register_n);

    void jump(size_t ip);
};