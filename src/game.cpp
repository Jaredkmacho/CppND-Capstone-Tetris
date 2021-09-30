#include "game.h"

Game::Game() : engine(dev()), rdm_orientation(0, 3), rdm_piece(0,6) {
    tetris.spawnPiece();
}

void Game::Run(Controller &controller, Renderer &renderer,
                std::size_t target_frame_duration) {
    uint32_t title_timestamp = SDL_GetTicks();
    uint32_t frame_start;
    uint32_t frame_end;
    uint32_t frame_duration;
    int frame_count;
    bool running = true;

    while (running) {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(running, tetris);
        Update();
        renderer.Render(tetris);

        frame_end = SDL_GetTicks();

        frame_count++;
        frame_duration = frame_end - frame_start;

        if (frame_end - title_timestamp >= 1000) {
            renderer.UpdateWindowTitle(0, frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        if(frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
        }

    }
}

void Game::Update() {
    tetris.Update();
}