#include <common.h>
#include <emu.h>
#include <cpu.h>
#include <cart.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


static emu_context ctx; 
emu_context *emu_get_context(){
    return &ctx;
}
void delay(u32 ms){
    SDL_Delay(ms);
}
int emu_run(int argc, char **argv){
    if (argc < 2) {
        printf("usage: ./emu <ROM>\n");
        return -1;
    }
    if(!cart_load(argv[1])){
        printf("couldnt load the cart\n");
        return -2;
    }
    
    // initializing of services
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    cpu_init();

    ctx.running= true;
    ctx.pause= false;
    ctx.cycle= 0;
    // emulator main loop
    while(ctx.running){
        if(ctx.pause){
            delay(10);
            continue;
        }
        if(!cpu_step()){
            print("cpu failed to work\n");
            return -3;
        }
        ctx.cycle++;

    }
    return 0;
}

void emu_cyle(int cycle){
    
}