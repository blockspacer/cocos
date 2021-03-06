#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#define DISPLAY_TIME_SPLASH_SCREEN 1.0
#define DISPLAY_TIME_GAME_SCREEN 0
#define TRANSITION_TIME 0.5
#define ENEMY_SPAWN_FREQUENCY 1

#define PIPE_GAP 10
#define UPPER_SCREEN_PIPE_THRESHOLD 0.65
#define LOWER_SCREEN_PIPE_THRESHOLD 0.35

#define PIPE_MOVEMENT_SPEED 0.01

#define PLAYER_COLLISION_BITMASK 0x000001
#define BOUND_COLLISION_BITMASK 0x000002
#define ENEMY_COLLISION_BITMASK 0x000003

#define ENEMY_SPEED 0.15

#define SCORE_FONT_SIZE 0.05

#define CACHE_MAX_SCORE "cache_max_score"
#define CACHE_CAN_PLAY_MUSIC "cache_can_play_music"

#include <string>
#include <sstream>
namespace std
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream ss;
		ss << n;
		return ss.str();
	}
}

//#define IS_DEBUG true
#define IS_DEBUG false

#endif // __DEFINITIONS_H__
