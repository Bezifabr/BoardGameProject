#pragma once

#include "Language.h"
#include "Utilities.h"
#include <string>

#define WINDOW_SIZE sf::Vector2i(1280,768)
#define WINDOW_TITLE "The board game project v.0.0.2 pre alpha"
#define WINDOW_FRAME_RATE_LIMIT 60

#define MAX_LAYER_NUMBER 8

#define GAME_TESTS true
#define RENDERING_LOCATION_TEST false
#define CHARACTER_AND_TEXTURES_LOADING_TEST false
#define GRAPHIC_OBJECT_AND_TEXTURES_LOADING_TEST false
#define INTERFACE_OBJECT_AND_TEXTURES_LOADING_TEST false
#define CUSTOM_TEXTS_AND_TEXTURES_LOADING_TEST false
#define INTERFACE_EVENT_TEST false
#define INTERFACE_KEYBOARD_TEST false
#define INTERFACE_KEYBOARD_EVENT_TYPE false
#define INTERFACE_MOUSE_TEST false
#define INTERFACE_MOUSE_POSITION_TEST false
#define MAP_LOADING_TEST false

#define TESTING_GRAPHIC_SOURCE "Graphics/Test.png"
#define DEFAULT_FONT_SOURCE "Graphics/Font.ttf"

#define SAVE_SLOT_EMPTY "Graphics/SavingSlot.png"

#include <assert.h>