#pragma once

#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Player {
  Camera3D camera;

  Vector3 position;

  // for knowing what angles the camera is at
  float yaw;
  float pitch;

  float speed;
} Player;

