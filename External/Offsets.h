#pragma once
#include <vector>

static int base_address = 0x00400000;
static int of_base_address = 0x0010F4F4;
static int player_base = base_address + of_base_address;

// Direct reading
static int entity_base = player_base + 0x4;
static int players_in_map = player_base + 0xC;

// Player / Entities
static int of_health = 0xF8;
static int of_name = { 0x225 };
static int of_posx = { 0x4 };
static int of_posy = { 0x8 };
static int of_posz = { 0xC };
static int of_ang_left_right = { 0x40 };
static int of_ang_up_down = { 0x44 };
static int of_team = 0x32C;
static int of_viewmatrix = 0x501AE8;
static int of_posx_normal = 0x34;
static int of_posy_normal = 0x38;
static int of_posz_normal = 0x3C;