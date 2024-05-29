#pragma once

#include <boost/locale.hpp>
#include <inputtino/input.hpp>
#include <libevdev/libevdev.h>

#include "src/platform/common.h"

#include "inputtino_common.h"

using namespace std::literals;

namespace platf::gamepad {

  enum ControllerType {
    XboxOneWired,
    DualSenseWired,
    SwitchProWired
  };

  int
  alloc(input_raw_t *raw, const gamepad_id_t &id, const gamepad_arrival_t &metadata, feedback_queue_t feedback_queue);

  void
  free(input_raw_t *raw, int nr);

  void
  update(input_raw_t *raw, int nr, const gamepad_state_t &gamepad_state);

  void
  touch(input_raw_t *raw, const gamepad_touch_t &touch);

  void
  motion(input_raw_t *raw, const gamepad_motion_t &motion);

  void
  battery(input_raw_t *raw, const gamepad_battery_t &battery);

  std::vector<std::string_view> &
  supported_gamepads();
}  // namespace platf::gamepad