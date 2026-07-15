/* SPDX-License-Identifier: MIT */

#pragma once

#include <SDL3/SDL.h>

#include <stdbool.h>

typedef struct SDLWindowContext {
  SDL_Window *win;
  SDL_GLContext ctx;

  const char *title;
  int width;
  int height;
} SDLWindowContext;

bool sdl_win_ctx_init(void);
bool sdl_win_ctx_create_win(SDLWindowContext *win_ctx);
bool sdl_win_ctx_create_ctx(SDLWindowContext *win_ctx);

void sdl_win_ctx_uninit(void);
void sdl_win_ctx_destroy_win(SDLWindowContext *win_ctx);
void sdl_win_ctx_destroy_ctx(SDLWindowContext *win_ctx);
