#include "renderer.h"
#include "snake.h"
#include "asteriod.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, screen_width,
                                  screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window)
    {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer)
    {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

Renderer::~Renderer()
{
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(Snake *snake, Asteriod *asteriod, SDL_Point const &food)
{
    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render food
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    block.x = food.x * block.w;
    block.y = food.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);

    // Render snake's body
    Color *snakeBodyColor = snake->GetBodyColor();
    SDL_SetRenderDrawColor(sdl_renderer,
                           snakeBodyColor->r,
                           snakeBodyColor->g,
                           snakeBodyColor->b,
                           snakeBodyColor->a);
    for (SDL_Point const &point : snake->body)
    {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    Color *snakeHeadColor = snake->GetHeadColor();
    block.x = static_cast<int>(snake->head_x) * block.w;
    block.y = static_cast<int>(snake->head_y) * block.h;
    SDL_SetRenderDrawColor(sdl_renderer,
                           snakeHeadColor->r,
                           snakeHeadColor->g,
                           snakeHeadColor->b,
                           snakeHeadColor->a);
    SDL_RenderFillRect(sdl_renderer, &block);

    // Render asteriod
    Color *asteriodColor = asteriod->GetBodyColor();
    for (SDL_Point const &point : asteriod->body)
    {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_SetRenderDrawColor(sdl_renderer,
                           asteriodColor->r,
                           asteriodColor->g,
                           asteriodColor->b,
                           asteriodColor->a);
        SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps)
{
    std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}
