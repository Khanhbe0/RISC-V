#include "Pipelined_regs.h"
#include <stdint.h>
#include <math.h>

uint32_t ImmExt (uint8_t ImmSrc) {
    switch (ImmSrc) {
        // Target connect the bits and sign extend
        case 0:

            //uint32_t Imm = ;
    }
}

void execute_IF (uint8_t PCSrc, uint8_t StallF, uint32_t PCTarget) {
    uint32_t index = PC / 4;
    uint32_t RD;

    if (index >= MAX) RD = 0;
    else RD = InstrMem[index];

    uint32_t PCPLus4 = PC + 4;                     //modify later as a half adder from in ALU Unit.

    if (StallF) {
        PCNext = PC;
        IF_ID_next = IF_ID_current;
    }
    else {
        IF_ID_next.Instr = RD;
        IF_ID_next.PC = PC;
        IF_ID_next.PCPlus4 = PCPLus4;

        PCNext = (PCSrc) ? PCTarget : PCPLus4;
    }
}

void execute_ID () {
    uint8_t opcode = IF_ID_current.Instr & 0x7F;
    uint8_t rd = (IF_ID_current.Instr >> 7) & 0x1F;
    uint8_t funct3 = (IF_ID_current.Instr >> 12) & 0X07;
    uint8_t rs1 = (IF_ID_current.Instr >> 15) & 0x1F;
    uint8_t rs2 = (IF_ID_current.Instr >> 20) & 0x1F;
    uint8_t funct7 = (IF_ID_current.Instr >> 25) &0x7F;

    
}

void execute_EX () {}

void execute_MEM () {}

void execute_WB () {}