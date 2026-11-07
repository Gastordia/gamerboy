#pragma once
#include <common.h>

typdef struct {

    bool paused;
    bool running;
    u64 cycle;
} emu_context;

int emu_run(int argc, char **argv);

emu_context *emu_get_context();
void emu_cyle(int cycle);
