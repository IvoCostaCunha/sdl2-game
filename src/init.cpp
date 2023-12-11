#include <iostream>
#include "SDL2/SDL.h"

int main(int argc, char *argv[]) {

  int r = SDL_Init(SDL_INIT_VIDEO);

  if(r<0) {
    printf("Cannot SDL_Init() (%s)\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  SDL_Window *window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);

  if(window == nullptr) {
    printf("Cannot window nullptr (%s)\n", SDL_GetError());
    SDL_Quit();
    return EXIT_FAILURE;
  }

  char a[10];
  scanf("%s", a);
  printf("Hello world\n");
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}