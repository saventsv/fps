#pragma once

#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

const float GRAVITY = -20.0f;

typedef struct {
  Vector3 position;
  Vector3 rotation;
  Vector3 dimensions;
} Spatial;

typedef struct {
  // acceleration decides how much velocity changes
  Vector3 acceleration;
  Vector3 velocity;
} RigidBody;

typedef struct Player {
  Camera3D camera;

  Vector3 position;

  // for knowing what angles the camera is at
  float yaw;
  float pitch;

  float speed;
} Player;

