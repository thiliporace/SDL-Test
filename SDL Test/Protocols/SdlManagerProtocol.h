//
//  SdlManagerProtocol.h
//  SDL Test
//
//  Created by Thiago Liporace on 06/01/25.
//

#ifndef SdlManagerProtocol_h
#define SdlManagerProtocol_h

class SdlManagerProtocol{
public:
    const virtual void initializeSDL() = 0;
    const virtual void initializeSDLWindow() = 0;
    const virtual void initializeSDLRenderer() = 0;
    
    const virtual SDL_Renderer* getRenderer() = 0;
    const virtual SDL_Window* getWindow() = 0;
    
    ~SdlManagerProtocol() {};
};

#endif /* SdlManagerProtocol_h */
