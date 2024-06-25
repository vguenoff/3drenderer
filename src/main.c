#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool is_running = false;

// pointer to specific place in memory that contains SDL_Window
SDL_Window *window = NULL;
// starts as null pointer
SDL_Renderer *renderer = NULL;
// pointer to the first position of this array of 32 bit numbers
uint32_t *color_buffer = NULL;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

bool initialize_window(void) {
  // initialize sdl
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL. \n");
    return false;
  };

  // crate a sdl window
  window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                            WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS);

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
  // Manually allocate a certain number of bytes in the memory and casting to
  color_buffer = (uint32_t *) malloc(sizeof(uint32_t) * WINDOW_WIDTH * WINDOW_HEIGHT);
}

void proccess_input() {
  SDL_Event event;
  SDL_PollEvent(&event); // passing the reference to `event`

  switch (event.type) {
  case SDL_QUIT:
    is_running = false;
    break;
  case SDL_KEYDOWN:
    if (event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_q) {
      is_running = false;
    }
    break;
  default:
    break;
  }
}

void update() {
  // TODO
}

void render() {
  SDL_SetRenderDrawColor(renderer, 255, 100, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

int main(void) {
  is_running = initialize_window();

  // printf("%zu\n", sizeof(uint32_t)); // 4 bytes or 32 bits

  setup();

  while (is_running) {
    proccess_input();
    update();
    render();
  }

  return 0;
}
