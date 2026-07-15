/* SPDX-License-Identifier: MIT */

#pragma once

#include <SDL3/SDL.h>

#define SDL_LOG_ERROR()                                         \
  do {                                                          \
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL error: %s", \
      SDL_GetError());                                          \
  } while (0)
