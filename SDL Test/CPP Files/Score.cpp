//
//  Score.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 20/12/24.
//

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include <sstream>

#include "SdlManager.hpp"
#include "Score.hpp"

using namespace std;

Score::Score(int xPos, int yPos, int initialScore) {
    if (TTF_Init() == -1) {
        cout << "Erro ao inicializar TTF: " << TTF_GetError() << endl;
        return;
    }
    
    font = TTF_OpenFont("NewYork.ttf", 24);
    if (!font) {
        cout << "Erro na fonte: " << TTF_GetError() << endl;
        return;
    }
    
    color = {255, 255, 255, 255};
    rect.x = xPos;
    rect.y = yPos;
    
    // Inicializa o texto com o valor inicial do score
    setScore(initialScore);
}

Score::~Score() {
    if (textTexture) SDL_DestroyTexture(textTexture);
    if (font) TTF_CloseFont(font);
}

void Score::setScore(int score) {
    
    if (textTexture) {
        SDL_DestroyTexture(textTexture);
        textTexture = nullptr;
    }
    
    std::ostringstream oss;
    oss << "Score: " << score;
    std::string scoreText = oss.str();
    
    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreText.c_str(), color);
    if (!surface) {
        cout << "Erro na surface: " << TTF_GetError() << endl;
        return;
    }
    
    SdlManager* sdlManager = SdlManager::getInstance();
    textTexture = SDL_CreateTextureFromSurface(sdlManager->getRenderer(), surface);
    if (!textTexture) {
        cout << "Erro na textura: " << SDL_GetError() << endl;
    }
    
    rect.w = surface->w;
    rect.h = surface->h;
    
    SDL_FreeSurface(surface);
}
