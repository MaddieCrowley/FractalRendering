//
// Created by madeline on 9/2/25.
//

#ifndef FRACTALRENDERING_WINDOW_H
#define FRACTALRENDERING_WINDOW_H

#include <SDL3/SDL.h>

class window {
public:
    window(int width,int height);
    ~window();
    void update();

private:
    SDL_Window * win;
    SDL_GLContext con;
};

#endif //FRACTALRENDERING_WINDOW_H