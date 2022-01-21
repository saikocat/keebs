/* Copyright (C) 2021 @saikocat
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include QMK_KEYBOARD_H

#include "definitions.h"
#include "combos/combos.h"
#include "features/caps_word.h"
#include "layouts/wrappers.h"
#include "behaviours/callbacks.h"
#include "behaviours/power_management.h"
#include "behaviours/process_records.h"
#include "behaviours/matrix_scan.h"

#ifdef OLED_ENABLE
#    include "features/oled.h"
#endif
#ifdef ENCODER_ENABLE
#    include "features/encoder.h"
#endif
#ifdef PIMORONI_TRACKBALL_ENABLE
#    include "features/pimoroni_trackball.h"
#endif
#ifdef SPLIT_KEYBOARD
#    include "transports/split_transport_sync.h"
#endif
