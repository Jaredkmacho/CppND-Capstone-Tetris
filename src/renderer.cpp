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

    // Render sidefield boxes
    SDL_Point nextfield_outbox[5];
    SDL_Point nextfield_inbox[5];
    tetris.getNextfield()->getPlayfieldBox(nextfield_outbox, nextfield_inbox);
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    SDL_RenderDrawLines(sdl_renderer, nextfield_outbox, 5);
    SDL_RenderDrawLines(sdl_renderer, nextfield_inbox, 5);

    SDL_Point savedfield_outbox[5];
    SDL_Point savedfield_inbox[5];
    tetris.getSavedfield()->getPlayfieldBox(savedfield_outbox, savedfield_inbox);
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    SDL_RenderDrawLines(sdl_renderer, savedfield_outbox, 5);
    SDL_RenderDrawLines(sdl_renderer, savedfield_inbox, 5);

    // Render playfield grid
    int num_of_cells = tetris.getPlayfield()->getNumberOfCells();
    SDL_Rect playfield_cells[num_of_cells];
    SDL_Color cell_colors[num_of_cells];
    tetris.getPlayfield()->getPlayfieldCells(playfield_cells, cell_colors);
    for(int i = 0; i < num_of_cells; i++) {
        SDL_SetRenderDrawColor(sdl_renderer, cell_colors[i].r, cell_colors[i].g, cell_colors[i].b, cell_colors[i].a);
        SDL_RenderFillRect(sdl_renderer, &playfield_cells[i]);
    }


    // Render sidefields
    num_of_cells = tetris.getNextfield()->getNumberOfCells();
    SDL_Rect nextfield_cells[num_of_cells];
    SDL_Color next_colors[num_of_cells];
    tetris.getNextfield()->getPlayfieldCells(nextfield_cells, next_colors);
    for(int i = 0; i < num_of_cells; i++) {
        SDL_SetRenderDrawColor(sdl_renderer, next_colors[i].r, next_colors[i].g, next_colors[i].b, next_colors[i].a);
        SDL_RenderFillRect(sdl_renderer, &nextfield_cells[i]);
    }

    num_of_cells = tetris.getSavedfield()->getNumberOfCells();
    SDL_Rect savedfield_cells[num_of_cells];
    SDL_Color saved_colors[num_of_cells];
    tetris.getSavedfield()->getPlayfieldCells(savedfield_cells, saved_colors);
    for(int i = 0; i < num_of_cells; i++) {
        SDL_SetRenderDrawColor(sdl_renderer, saved_colors[i].r, saved_colors[i].g, saved_colors[i].b, saved_colors[i].a);
        SDL_RenderFillRect(sdl_renderer, &savedfield_cells[i]);
    }


    /*
    playfield_outbox_ = {
        {pOrigin.x - out_offset, pOrigin.y - out_offset},
        {pOrigin.x - out_offset, playfield_height + out_offset},
        {playfield_width + out_offset, playfield_height + out_offset},
        {playfield_width + out_offset, pOrigin.y - out_offset},
        {pOrigin.x - out_offset, pOrigin.y - out_offset}
    };
    */

    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);




    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}


void Renderer::UpdateWindowTitle(int score, int fps) {
    std::string title{"Tetris --- Cleared: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}
