#include<cpu.h>
#include<common.h>
#include<bus.h>
#include<cpu_util.c>
#include<emu.h>

cpu_context ctx= {0};

static void fetch_instruction(){
    ctx.current_opcode = bus_read(ctx.regs.pc++);
    ctx.current_instruction= instruction_by_opcode(ctx.current_opcode);
}

static void fetch_data(){
    ctx.mem_dest = 0;
    ctx.dest_is_mem = false;
    switch(ctx.current_instruction->mode){
        case AM_IMP: return;
        case AM_R: 
            ctx.fetched_data = cpu_read_reg(ctx.current_instruction->reg1);
            return;
        case AM_R_D8:
            ctx.fetched_data = bus_read(ctx.regs.pc);
            emu_cycles(1);
            ctx.regs.pc++;
            return;
        case AM_D16: {
            u16 lo = bus_read(ctx.regs.pc);
            emu_cycles(1);

            u16 hi = bus_read(ctx.regs.pc + 1);
            emu_cycles(1);

            ctx.fetched_data = lo | (hi << 8);

            ctx.regs.pc += 2;
            return;
        }
        default:
            printf("unkown addressing mode %d (%02X)\n", ctx.cur_inst->mode, ctx.cur_opcode);
            exit(-7);
            return;
    }
}

static void execute(){

}

void cpu_init(){
    printf("to be implemented\n");
}

boot cpu_step(){
    if (!ctx.halted){
        fetch_instruction();
        fetch_data();
        execute();
    }
    return false;
}