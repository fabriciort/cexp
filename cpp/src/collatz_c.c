#include <SDL2/SDL.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

void draw_sequence(SDL_Renderer *renderer, unsigned long n)
{
    unsigned long i = 0;
    while (n != 1) {
        SDL_SetRenderDrawColor(renderer, i % 256, (i * 3) % 256, (i * 7) % 256, 255);
        SDL_RenderDrawLine(renderer, i, HEIGHT - n / 2, i + 1, HEIGHT - (n % 2 == 0 ? n / 2 : (3 * n + 1) / 2));
        n = n % 2 == 0 ? n / 2 : 3 * n + 1;
        i++;
    }
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Collatz Conjecture",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGHT,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    unsigned long n = 10000;
    unsigned long max_n = 10000000;
    unsigned long iterations = 100;
    unsigned long max_iterations = 1000;
    unsigned long start_time = SDL_GetTicks();

    while (SDL_GetTicks() - start_time < 30000) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        draw_sequence(renderer, n);

        SDL_RenderPresent(renderer);

        n++;
        iterations++;
        if (n > max_n || iterations > max_iterations) {
            n = 1;
            iterations = 0;
        }

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                exit(0);
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

