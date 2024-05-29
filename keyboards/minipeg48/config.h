/*
Copyright 2022 sporewoh

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* pin-out for PCB */
#define MATRIX_ROW_PINS { F0, F1, F4, F5 }
#define MATRIX_COL_PINS { B5, B4, D6, D7, D4, D5, D3, D2, D1, D0, B6, C6 }


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

/* マウス設定 */
#define MOUSEKEY_INERTIA // 慣性モード有効

#define MOUSEKEY_FRICTION      24  // キーを離した後、カーソルが停止する速さ

#define MOUSEKEY_DELAY          5   // 遅延をなくす（反応速度を上げる）
#define MOUSEKEY_INTERVAL       8   // 更新間隔を短くしてスムーズに（値を小さく）
#define MOUSEKEY_MAX_SPEED      7   //　最大速度
#define MOUSEKEY_TIME_TO_MAX    15  // 最大速度に達するまでの時間を長くして滑らかに

#define MOUSEKEY_WHEEL_DELAY    20      // ホイール遅延をなくす
#define MOUSEKEY_WHEEL_INTERVAL 100     // ホイールの更新間隔を短く
#define MOUSEKEY_WHEEL_MAX_SPEED 20     //　ホイール最大速度
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40   // ホイールの加速時間を長く
