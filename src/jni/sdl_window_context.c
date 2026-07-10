#include "sdl_window_context.h"

#include "utils/sdl_logging.h"

bool sdl_win_ctx_init(void) {
  SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeLeft LandscapeRight");

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_LOG_ERROR();
    return false;
  }

  return true;
}

bool sdl_win_ctx_create_win(SDLWindowContext *win_ctx) {
  if (!win_ctx) {
    SDL_Log("win_ctx is NULL");
    return false;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  win_ctx->win = SDL_CreateWindow(win_ctx->title, win_ctx->width,
    win_ctx->height, SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);

  if (!win_ctx->win) {
    SDL_LOG_ERROR();
    return false;
  }

  return true;
}

bool sdl_win_ctx_create_ctx(SDLWindowContext *win_ctx) {
  if (!win_ctx) {
    SDL_Log("win_ctx is NULL");
    return false;
  }

  win_ctx->ctx = SDL_GL_CreateContext(win_ctx->win);

  if (!win_ctx->ctx) {
    SDL_LOG_ERROR();
    return false;
  }

  #ifndef GL_NO_VSYNC
  SDL_GL_SetSwapInterval(1);
  #endif

  return true;
}

void sdl_win_ctx_uninit(void) {
  SDL_Quit();
}

void sdl_win_ctx_destroy_win(SDLWindowContext *win_ctx) {
  if (!win_ctx) {
    SDL_Log("win_ctx is NULL");
    return;
  }

  SDL_DestroyWindow(win_ctx->win);
}

void sdl_win_ctx_destroy_ctx(SDLWindowContext *win_ctx) {
  if (!win_ctx) {
    SDL_Log("win_ctx is NULL");
    return;
  }

  if (!SDL_GL_DestroyContext(win_ctx->ctx)) {
    SDL_LOG_ERROR();
    return;
  }
}
