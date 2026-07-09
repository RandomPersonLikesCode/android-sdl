/* SPDX-License-Identifier: MIT */

#define SDL_MAIN_USE_CALLBACKS

#include "sdl_app_state.h"
#include "sdl_window_context.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <GLES3/gl32.h>

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
  SDLAppState *sdl_state = (SDLAppState*)SDL_calloc(1, sizeof(SDLAppState));

  if (!sdl_state) {
    SDL_Log("Allocation failed");
    return SDL_APP_FAILURE;
  }

  sdl_state->win_ctx.title = "SDL Demo";
  sdl_state->win_ctx.width = 800;
  sdl_state->win_ctx.height = 600;

  if (!sdl_win_ctx_init()) return SDL_APP_FAILURE;
  if (!sdl_win_ctx_create_win(&sdl_state->win_ctx)) return SDL_APP_FAILURE;
  if (!sdl_win_ctx_create_ctx(&sdl_state->win_ctx)) return SDL_APP_FAILURE;

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  *appstate = sdl_state;
  return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
  switch (event->type) {
    case SDL_EVENT_QUIT:
      return SDL_APP_SUCCESS;

      break;
  }

  return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
  SDLAppState *sdl_state = (SDLAppState*)appstate;

  glClear(GL_COLOR_BUFFER_BIT);

  SDL_GL_SwapWindow(sdl_state->win_ctx.win);
  return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
  if (appstate) {
    SDLAppState *sdl_state = (SDLAppState*)appstate;

    sdl_win_ctx_destroy_ctx(&sdl_state->win_ctx);
    sdl_win_ctx_destroy_win(&sdl_state->win_ctx);
    sdl_win_ctx_uninit();
  }
}
