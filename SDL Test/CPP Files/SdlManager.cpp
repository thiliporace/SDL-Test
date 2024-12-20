//
//  SdlManager.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#include "SdlManager.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>
#include "SdlManager.hpp"

using namespace std;

// Inicialização do ponteiro estático
SdlManager* SdlManager::instance = nullptr;

SdlManager::SdlManager() {
    initializeSDL();
}

const void SdlManager::initializeSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "Error Init: " << SDL_GetError() << endl;
        return;
    }

    initializeSDLWindow();
    initializeSDLRenderer();
}

const void SdlManager::initializeSDLWindow() {
    window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

    if (!window) {
        cout << "Error Window: " << SDL_GetError() << endl;
        return;
    }
}

const void SdlManager::initializeSDLRenderer() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        cout << "Error Renderer: " << SDL_GetError() << endl;
        return;
    }
}

SdlManager* SdlManager::getInstance() {
    if (!instance) {
        instance = new SdlManager();
    }
    return instance;
}

SDL_Renderer* SdlManager::getRenderer() {
    return renderer;
}

SDL_Window* SdlManager::getWindow() {
    return window;
}

SdlManager::~SdlManager() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
