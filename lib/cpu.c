#include<cpu.h>
#include<common.h>
#include<bus.h>

cpu_context ctx= {0};

static void fetch_instruction(){
    ctx.current_opcode = bus_read(ctx.regs.pc++);
}

static void fetch_data(){

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