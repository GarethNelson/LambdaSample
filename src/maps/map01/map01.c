//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2016 by Gareth Nelson (gareth@garethnelson.com)
//
// This file is part of the Lambda engine.
//
// The Lambda engine is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// The Lambda engine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
//
// $Log:$
//
// DESCRIPTION:
//     Game logic for map01 in the sample game
//
//-----------------------------------------------------------------------------

// The below is mostly standard boilerplate for any map

#include <map01/mapinfo.h>
#include <map01/hotzone.h>
#include <map01/collision.h>
#include <map01/entities.h>
#include <lambda_api.h>

// Called by the hook when the player enters the exit hotzone
void map01_hz_map01exit_handler(void* param) {
     lambda_switch_map("map02");
}

// This function is called when the map is loaded
// It is intended for configuration of hooks, do not put rendering code in here
void map01_init() {
     // The ent_player class is part of the engine, so these handlers are generated automatically
     SET_SINGLE_HOOK(input_up,           &map01_ent_player_up_handler);
     SET_SINGLE_HOOK(input_down,         &map01_ent_player_down_handler);
     SET_SINGLE_HOOK(input_left,         &map01_ent_player_left_handler);
     SET_SINGLE_HOOK(input_right,        &map01_ent_player_right_handler);

     // This hook is generated from the hotzone map, we use it here to call our custom handler
     SET_SINGLE_HOOK(map01_hz_map01exit, &map01_hz_map01exit_handler);
}

// This is a cleanup function called before the next map is loaded
void map01_finish() {
     // this stuff is not strictly necessary, but a good idea
     IMPORT(i_default)
     SET_SINGLE_HOOK(input_up,    &i_default);
     SET_SINGLE_HOOK(input_down,  &i_default);
     SET_SINGLE_HOOK(input_left,  &i_default);
     SET_SINGLE_HOOK(input_right, &i_default);
}

