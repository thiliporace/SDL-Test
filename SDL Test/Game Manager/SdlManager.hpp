//
//  SdlManager.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#ifndef SdlManager_hpp
#define SdlManager_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>
#include "SdlManagerProtocol.h"


//Classe Singleton
class SdlManager : public SdlManagerProtocol {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    static SdlManager* instance;

    SdlManager();
    
    //Deleta o copy constructor por ser singleton
    SdlManager(const SdlManager& obj) = delete;

public:
    static SdlManager* getInstance();

    const void initializeSDL() override;
    const void initializeSDLWindow() override;
    const void initializeSDLRenderer() override;

    SDL_Renderer* getRenderer() override;
    SDL_Window* getWindow() override;

    ~SdlManager();
};

#endif /* SdlManager_hpp */
