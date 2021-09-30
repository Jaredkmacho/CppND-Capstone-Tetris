#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width),
      screen_height(screen_height) {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

  // Create Window
    sdl_window = SDL_CreateWindow("Tetris Game", SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED, screen_width,
                                    screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

  // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

Renderer::~Renderer() {
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(Tetris const &tetris) {
    //   SDL_Rect block;
    //   block.w = screen_width;
    //   block.h = screen_height;

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render playfield box
    SDL_Point playfield_outbox[5];
    SDL_Point playfield_inbox[5];
    tetris.getPlayfield()->getPlayfieldBox(playfield_outbox, playfield_inbox);
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    SDL_RenderDrawLines(sdl_renderer, playfield_outbox, 5);
    SDL_RenderDrawLines(sdl_renderer, playfield_inbox, 5);

    // Render playfield grid
    int num_of_cells = tetris.getPlayfield()->getNumberOfCells();
    SDL_Rect playfield_cells[num_of_cells];
    SDL_Color cell_colors[num_of_cells];
    tetris.getPlayfield()->getPlayfieldCells(playfield_cells, cell_colors);
    //SDL_RenderDrawRects(sdl_renderer, playfield_cells, num_of_cells);
    for(int i = 0; i < num_of_cells; i++) {
        SDL_SetRenderDrawColor(sdl_renderer, cell_colors[i].r, cell_colors[i].g, cell_colors[i].b, cell_colors[i].a);
        SDL_RenderFillRect(sdl_renderer, &playfield_cells[i]);
    }


    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}


void Renderer::UpdateWindowTitle(int score, int fps) {
    std::string title{"Tetris: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}
