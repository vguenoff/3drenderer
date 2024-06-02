#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

bool is_running = false;

SDL_Window *window =
    NULL; // pointer to specific place in memory that contains SDL_Window
SDL_Renderer *renderer = NULL; // starts as null pointer

bool initialize_window(void) {
  // initialize sdl
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL. \n");
    return false;
  };

  // crate a sdl window
  window =
      SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       800, 600, SDL_WINDOW_BORDERLESS);

  if (!window) {
    fprintf(stderr, "Error creating SDL window. \n");
    return false;
  }

  // crate a sdl renderer
  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer) {
    fprintf(stderr, "Error creating SDL renderer. \n");
    return false;
  }

  return true;
}

void setup() {
  // TODO
}

void proccess_input() {
  SDL_Event event;
  SDL_PollEvent(&event); // passing the reference to `event`

  switch (event.type) {
  case SDL_QUIT:
    is_running = false;
    break;
  case SDL_KEYDOWN:
    if (event.key.keysym.sym == SDLK_ESCAPE) {
      is_running = false;
    }
  default:
    break;
  }
}

void update() {
  // TODO
}

void render() {
  SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

int main(void) {
  is_running = initialize_window();

  setup();

  while (is_running) {
    proccess_input();
    update();
    render();
  }

  return 0;
}
