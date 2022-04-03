//
// Created by berci on 2022. 04. 04..
//

#include <gtest/gtest.h>
#include <instruction/Instruction.h>

TEST(Instruction, Halt) {
    Instruction::Halt halt = Instruction::Halt{};
    MachineState ms = MachineState::fresh();

    halt.execute(ms);

    EXPECT_FALSE(ms.is_running());
}