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

    printf("Position: %.2f %.2f %.2f\n",
        player->camera.position.x,
        player->camera.position.y,
        player->camera.position.z);

    printf("Target: %.2f %.2f %.2f\n",
        player->camera.target.x,
        player->camera.target.y,
        player->camera.target.z);

    printf("Up: %.2f %.2f %.2f\n",
        player->camera.up.x,
        player->camera.up.y,
        player->camera.up.z);

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
