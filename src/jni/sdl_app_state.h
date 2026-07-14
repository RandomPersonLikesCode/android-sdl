#pragma once

#include "gl_renderer.h"
#include "sdl_window_context.h"

typedef struct SDLAppState {
  SDLWindowContext win_ctx;
  GLRenderer renderer;
} SDLAppState;
