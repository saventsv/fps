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
  player->object.spatial.pitch = 0;
  player->object.spatial.position = (Vector3){ 0.0f, 8.0f, 0.0f };
  player->object.spatial.yaw = 0;
  player->speed = 100;

  return player;
}

void update_player(Player *player) {

  float deltaTime = GetFrameTime();

  Vector2 mouse = GetMouseDelta();
  float sensitivity = 0.003f;

  player->object.spatial.pitch -= mouse.y * sensitivity;
  player->object.spatial.yaw += mouse.x * sensitivity;

  player->object.spatial.pitch = Clamp(player->object.spatial.pitch, -89.0f, 89.0f);

  Vector3 forward = (Vector3){
    .x = cosf(player->object.spatial.yaw) * cosf(player->object.spatial.pitch),
    .y = sinf(player->object.spatial.pitch),
    .z = sinf(player->object.spatial.yaw) * cosf(player->object.spatial.pitch),
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

  player->object.spatial.position = Vector3Add(player->object.spatial.position, movement);

  player->camera.position = player->object.spatial.position;
  player->camera.target = Vector3Add(player->object.spatial.position, forward); 

}
