//
//  ShapeAssetManager.hpp
//  SDL Test
//
//  Created by Thiago Liporace on 07/01/25.
//

#ifndef ShapeAssetManager_hpp
#define ShapeAssetManager_hpp

#include <stdio.h>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_filesystem.h>
#include <SDL2_image/SDL_image.h>

class ShapeAssetManager {
private:
    //Precisamos receber o renderer para criar a textura da forma
    SDL_Renderer* renderer;
    //Vetor com referencia as texturas ja criadas
    std::vector <SDL_Texture*> textureNames;
    //Vetor com os nomes ja usados para texturas
    std::vector <char*> assetNames;
    
    //Instancia unica da classe singleton
    static ShapeAssetManager* instance;
    
    ShapeAssetManager(const ShapeAssetManager& obj) = delete;
    
    ShapeAssetManager(SDL_Renderer* renderer);
public:
    static ShapeAssetManager* getInstance(SDL_Renderer* renderer);
    
    SDL_Texture* getAsset(char* assetName);
    
    ~ShapeAssetManager();
};


#endif /* ShapeAssetManager_hpp */
