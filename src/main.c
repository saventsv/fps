#include "../include/game.h"
#include "../include/player.h"
#include <raylib.h>

int main(void) {
  int screenWidth = 800;
  int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "FPS");

  Player *player = init_player();

  SetTargetFPS(60);

  DisableCursor();

  while(!WindowShouldClose()) {
    update_player(player);

    BeginDrawing();

    ClearBackground(WHITE);

    BeginMode3D(player->camera);
    DrawGrid(100, 30);
    EndMode3D();

    EndDrawing();
  }

  EnableCursor();

  CloseWindow();

  return 0;
}
