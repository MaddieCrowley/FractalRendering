//
// Created by madeline on 9/2/25.
//

#include "gpu/gpu.h"
#include "window/window.h"

bool done = false;

bool update = false;

int main(int argc, char *argv[]) {
    window mainWindow(1920,1080);
    gpu compute("../mandle.glsl");
    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type==SDL_EVENT_QUIT) {
                done = true;
            }
        }
        compute.comp();
    }
    return 0;
}
