#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#define DISPLAY_TIME_SPLASH_SCREEN 2.5
#define TRANSITION_TIME 0.5
#define ENEMY_SPAWN_FREQUENCY 1

#define PIPE_GAP 10
#define UPPER_SCREEN_PIPE_THRESHOLD 0.65
#define LOWER_SCREEN_PIPE_THRESHOLD 0.35

#define PIPE_MOVEMENT_SPEED 0.01

#define PLAYER_COLLISION_BITMASK_RED 0x000001
#define PLAYER_COLLISION_BITMASK_BLUE 0x000005
#define BOUND_COLLISION_BITMASK 0x000002
#define ENEMY_COLLISION_BITMASK_RED 0x000003
#define ENEMY_COLLISION_BITMASK_BLUE 0x000004

#define SQUARE_SIZE 30

#define CACHE_MAX_SCORE "cache_max_score"
#define CACHE_CAN_PLAY_MUSIC "cache_can_play_music"

#endif // __DEFINITIONS_H__
