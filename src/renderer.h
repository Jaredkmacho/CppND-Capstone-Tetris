#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#undef main
#include "tetris.h"


class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render(Tetris const &tetris);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif /* RENDERER_H */