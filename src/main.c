#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool is_running = false;

// pointer to specific place in memory that contains SDL_Window
SDL_Window *window = NULL;
// SDL_Renderer starts as null pointer
SDL_Renderer *renderer = NULL;
// declare a pointer to an array of uint32_t elements
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
  // allocate the required bytes in memory for the color buffer array
  // (cast to uint32_t pointer) manually allocate (how many bytes)
  color_buffer = (uint32_t *) malloc(sizeof(uint32_t) * WINDOW_WIDTH * WINDOW_HEIGHT);
  // set the first pixel to red
  // color_buffer[0] = 0xffff0000;
  // set the second pixel to green
  // color_buffer[1] = 0xff00ff00;
  // ...
  if (!color_buffer) {
    printf("Error while allocating memory for the color buffer!\n");
  }
}

void proccess_input(void) {
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

void update(void) {
  // TODO
}

void render(void) {
  SDL_SetRenderDrawColor(renderer, 255, 100, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

void destroy_window(void) {
  free(color_buffer);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main(void) {
  is_running = initialize_window();

  setup();

  while (is_running) {
    proccess_input();
    update();
    render();
  }

  destroy_window();

  return 0;
}
