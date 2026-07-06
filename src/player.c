#include "../include/player.h"
#include <raylib.h>
#include <raymath.h>

Player *init_player() {
  Player *player = malloc(sizeof(Player));
  if(player == NULL) abort();

  player->camera = (Camera3D){
    .position = (Vector3){ 0.0f, 2.0f, 0.0f },
    .fovy = 60,
    .projection = CAMERA_PERSPECTIVE,
    .target = (Vector3){ 0.0f, 2.0f, 4.0f },
    .up = (Vector3){ 0.0f, 1.0f, 0.0f },
  };
  player->pitch = 0;
  player->position = (Vector3){ 0.0f, 8.0f, 0.0f };
  player->yaw = 0;
  player->speed = 100;

  return player;
}

// TODO, there is something here that causes the camera to not work
void update_player(Player *player) {

  float deltaTime = GetFrameTime();

  Vector2 mouse = GetMouseDelta();
  float sensitivity = 0.003f;

  player->pitch -= mouse.y * sensitivity;
  player->yaw += mouse.x * sensitivity;

  player->pitch = Clamp(player->pitch, -89.0f, 89.0f);

  Vector3 forward = (Vector3){
    .x = cosf(player->yaw) * cosf(player->pitch),
    .y = sinf(player->pitch),
    .z = sinf(player->yaw) * cosf(player->pitch),
  };

  forward = Vector3Normalize(forward);

  Vector3 right = Vector3CrossProduct(forward, (Vector3){ 0.0f, 1.0f, 0.0f });

  Vector3 movement = (Vector3){ 0.0f, 0.0f, 0.0f };


  if(IsKeyDown(KEY_W)) movement = Vector3Add(movement, forward);
  if(IsKeyDown(KEY_A)) movement = Vector3Subtract(movement, right);
  if(IsKeyDown(KEY_S)) movement = Vector3Subtract(movement, forward);
  if(IsKeyDown(KEY_D)) movement = Vector3Add(movement, right);

  movement = Vector3Normalize(movement);

  movement = Vector3Scale(movement, player->speed * deltaTime);

  player->position = Vector3Add(player->position, movement);

  player->camera.position = player->position;
  player->camera.target = Vector3Add(player->position, forward); 

}
