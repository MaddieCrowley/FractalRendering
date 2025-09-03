//
// Created by madeline on 9/2/25.
//

#include "window.h"

window::window(int width,int height) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,6);
    win = SDL_CreateWindow("test",width,height,SDL_WINDOW_OPENGL);
    con = SDL_GL_CreateContext(win);
    SDL_GL_SetSwapInterval(1);
}

window::~window() {
    SDL_GL_DestroyContext(con);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void window::update() {
    SDL_GL_SwapWindow(win);
}


