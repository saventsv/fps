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
  Vector3 position;
  Vector3 dimensions;
  float yaw;
  float pitch;
} PlayerSpatial;

typedef struct {
  // acceleration decides how much velocity changes
  Vector3 acceleration;
  Vector3 velocity;
} RigidBody;

typedef struct {
  Spatial spatial;
  RigidBody rigidBody;
} Object;

typedef struct {
  PlayerSpatial spatial;
  RigidBody rigidBody;
} PlayerObject;

typedef struct Player {
  Camera3D camera;
  PlayerObject object;
  float speed;
} Player;

