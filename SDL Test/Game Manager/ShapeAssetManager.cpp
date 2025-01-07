//
//  ShapeAssetManager.cpp
//  SDL Test
//
//  Created by Thiago Liporace on 07/01/25.
//

#include "ShapeAssetManager.hpp"
#include <iostream>

ShapeAssetManager* ShapeAssetManager::instance = nullptr;

ShapeAssetManager* ShapeAssetManager::getInstance(SDL_Renderer* renderer = nullptr) {
    if (!instance) {
        instance = new ShapeAssetManager(renderer);
    }
    return instance;
}

ShapeAssetManager::ShapeAssetManager(SDL_Renderer* renderer): renderer(renderer) {}

//Checa para ver se ja existe uma textura inicializada com o nome, se sim apenas retorna ela
SDL_Texture* ShapeAssetManager::getAsset(char* assetName){
    for (size_t i = 0; i < assetNames.size(); ++i) {
        if (assetNames[i] == assetName) {
            return textureNames[i];
        }
    }
    
    SDL_Surface* sprite = IMG_Load(assetName);
    if (!sprite) {
        std::cerr << "Error loading surface: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* shapeTexture = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_FreeSurface(sprite);

    if (!shapeTexture) {
        std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    assetNames.push_back(assetName);
    textureNames.push_back(shapeTexture);

    return shapeTexture;

}

ShapeAssetManager::~ShapeAssetManager() {
    for (SDL_Texture* texture : textureNames) {
        SDL_DestroyTexture(texture);
    }
}
