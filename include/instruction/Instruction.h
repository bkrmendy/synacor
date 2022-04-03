//
// Created by berci on 2022. 03. 23..
//

#pragma once

#include "../MachineState.h"

#include <ostream>
#include <utility>
#include <variant>

namespace Instruction {
    class IInstruction {
    public:
        virtual void execute(MachineState& machine) const = 0;
        virtual const char* documentation() const = 0;
        virtual std::ostream& display(std::ostream& os) const = 0;
    };

    struct Halt : IInstruction {
        void execute(MachineState& machine) const;

        const char *documentation() const final;

        std::ostream &display(std::ostream &os) const final;
    };

    struct Set : IInstruction {
        const MachineState::Register a;
        const MachineState::Register b;

        Set(MachineState::Register a, MachineState::Register b) : a(std::move(a)), b(std::move(b)) {}

        void execute(MachineState& machine) const final;

        const char *documentation() const final;

        std::ostream &display(std::ostream &os) const final;
    };

    struct Push : IInstruction {
        const MachineState::Value a;

        Push(const unsigned short a) : a(a) {}

        void execute(MachineState &machine) const final {
            machine.push(this->a);
        }

        const char *documentation() const override {
            return "push <a> onto the stack";
        }

        std::ostream &display(std::ostream &os) const override {
            os << "push " << this->a;
            return os;
        }
    };

    struct Pop : IInstruction {
        const MachineState::Register a;

        explicit Pop(MachineState::Register a) : a(std::move(a)) {}

        void execute(MachineState &machine) const final;

        const char *documentation() const final;

        std::ostream &display(std::ostream &os) const final;
    };

    struct Eq : IInstruction {
        const MachineState::Register a;
        const MachineState::Value b;
        const MachineState::Value c;

        Eq(MachineState::Register a, MachineState::Value b, MachineState::Value c);

        void execute(MachineState &machine) const final;

        const char *documentation() const final;

        std::ostream &display(std::ostream &os) const final;
    };

    struct Gt : IInstruction {
        const MachineState::Register a;
        const MachineState::Value b;
        const MachineState::Value c;

        Gt(MachineState::Register a, MachineState::Value b, MachineState::Value c);

        void execute(MachineState &machine) const final;

        const char *documentation() const final;

        std::ostream &display(std::ostream &os) const final;
    };

    struct Jmp : IInstruction {
        const size_t target;

        explicit Jmp(size_t target);

        void execute(MachineState &machine) const final;

        const char *documentation() const final;

        std::ostream &display(std::ostream &os) const final;
    };

    using Instruction = std::variant<
        Halt,
        Set,
        Push,
        Pop,
        Eq,
        Gt,
        Jmp
    >;
}

