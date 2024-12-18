//
//  main.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 18/12/24.
//

#include "main.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_filesystem.h>

using namespace std;

class SdlManager;

class SdlManagerProtocol{
public:
    const virtual void initializeSDL() = 0;
    const virtual void initializeSDLWindow() = 0;
    const virtual void initializeSDLRenderer() = 0;
    
    const virtual SDL_Renderer* getRenderer() = 0;
    const virtual SDL_Window* getWindow() = 0;
    
    ~SdlManagerProtocol() {};
};

//Classe singleton
class SdlManager: public SdlManagerProtocol{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    static SdlManager* instance;
    
    SdlManager(){
        initializeSDL();
    }
    
    const void initializeSDL() override {
        
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
            cout << "Error Init: " << SDL_GetError() << endl;
            return;
        }
        
        initializeSDLWindow();
        initializeSDLRenderer();
    }
    
    const void initializeSDLWindow() override {
        window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
        
        if (!window){
            cout << "Error Window: " << SDL_GetError() << endl;
            return;
        }
    }
    
    const void initializeSDLRenderer() override {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        
        if (!renderer){
            cout << "Error Renderer: " << SDL_GetError() << endl;
            return;
        }
    }
    
public:
    
    static SdlManager* getInstance() {
        if (!instance) {
            instance = new SdlManager();
        }
        return instance;
    }
    
    SDL_Renderer* getRenderer() override{
        return renderer;
    }
    
    SDL_Window* getWindow() override{
        return window;
    }
    
    ~SdlManager() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
    };
};

// Inicialização do ponteiro estático
SdlManager* SdlManager::instance = nullptr;

class Circle {
private:
    int startXPos {};
    int startYPos {};
    int zPos = 1;
public:
    
    SDL_Surface *sprite = IMG_Load("circle.png");

    SDL_Texture *texture = NULL;
    
    SDL_Rect pos; //Deixa a gente poder controlar sua posicao
    
    Circle(int xPos, int yPos): startXPos(xPos), startYPos(yPos){
        
        SdlManager* sdlManager = SdlManager::getInstance();
        
        if (!sprite){
            cout << "Error Surface: " << SDL_GetError() << endl;
            return;
        }
        
        texture = SDL_CreateTextureFromSurface(sdlManager->getRenderer(), sprite);
        
        if (!texture) {
            cout << "Error Texture: " << SDL_GetError() << endl;
            return;
        }
        
        SDL_FreeSurface(sprite); //Limpa memoria
        
        SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h); //Conecta textura com posicao
        
        setStartPosition(xPos, yPos);
    }
    
    const void setStartPosition(int& xPos, int& yPos) {
        pos.x = xPos;
        pos.y = yPos;
        
        pos.w *= 0.33;
        pos.h *= 0.33;
    };
    
    ~Circle() {
        SDL_DestroyTexture(texture);
    }
};

int main(){
    //Pega mesma instancia de SDLManager que foi usada ate agora
    SdlManager* sdlManager = SdlManager::getInstance();
    
    Circle circle(400,400);
    
    SDL_Event event;
    bool quit = false;
    
    while (!quit){
        // events handling
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
        }
        
        // rendering
        SDL_RenderClear(sdlManager->getRenderer()); //Limpa a tela
        SDL_RenderCopy(sdlManager->getRenderer(), circle.texture, NULL, &circle.pos);
        
        SDL_RenderPresent(sdlManager->getRenderer());
        
        // update
    }
    
    SDL_Quit();
    return 0;
}
