#include <common.h>
// all the supported instuctions of the game boy
typedef enum {
    IN_NONE,
    IN_NOP,
    IN_LD,
    IN_INC,
    IN_DEC,
    IN_RLCA,
    IN_ADD,
    IN_RRCA,
    IN_STOP,
    IN_RLA,
    IN_JR,
    IN_RRA,
    IN_DAA,
    IN_CPL,
    IN_SCF,
    IN_CCF,
    IN_HALT,
    IN_ADC,
    IN_SUB,
    IN_SBC,
    IN_AND,
    IN_XOR,
    IN_OR,
    IN_CP,
    IN_POP,
    IN_JP,
    IN_PUSH,
    IN_RET,
    IN_CB,
    IN_CALL,
    IN_RETI,
    IN_LDH,
    IN_JPHL,
    IN_DI,
    IN_EI,
    IN_RST,
    IN_ERR,
    IN_RLC, 
    IN_RRC,
    IN_RL, 
    IN_RR,
    IN_SLA, 
    IN_SRA,
    IN_SWAP, 
    IN_SRL,
    IN_BIT, 
    IN_RES, 
    IN_SET
} in_type;

// the registers (each one will change accordingly to the instruction so it should be put in here)
typedef enum {
    RT_NONE,
    RT_A,
    RT_F,
    RT_B,
    RT_C,
    RT_D,
    RT_E,
    RT_H,
    RT_L,
    RT_AF,
    RT_BC,
    RT_DE,
    RT_HL,
    RT_SP,
    RT_PC
} reg_type;

// the addressing mode 

typedef enum {
    AM_IMP,      // implied addressing, no explicit operand
    AM_R_D16,    // load 16-bit immediate value into register
    AM_R_R,      // register to register
    AM_MR_R,     // register to memory address pointed to by register
    AM_R,        // single register operand
    AM_R_D8,     // load 8-bit immediate value into register
    AM_R_MR,     // memory address pointed to by register to register
    AM_R_HLI,    // memory at hl to register, then increment hl
    AM_R_HLD,    // memory at hl to register, then decrement hl
    AM_HLI_R,    // register to memory at hl, then increment hl
    AM_HLD_R,    // register to memory at hl, then decrement hl
    AM_R_A8,     // load from address 0xff00 + 8-bit offset into register
    AM_A8_R,     // store register into address 0xff00 + 8-bit offset
    AM_HL_SPR,   // add signed 8-bit offset to sp and store result in hl
    AM_D16,      // direct 16-bit immediate operand
    AM_D8,       // direct 8-bit immediate operand
    AM_D16_R,    // store register into memory at 16-bit immediate address
    AM_MR_D8,    // store 8-bit immediate value into memory pointed to by register
    AM_MR,       // memory address pointed to by register
    AM_A16_R,    // store register into memory at 16-bit immediate address
    AM_R_A16     // load from memory at 16-bit immediate address into register
} addr_mode;