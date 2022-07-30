#pragma once

#include "../testing.hpp"
#include "interface.hpp"

namespace hal::mock {
/**
 * @addtogroup motor
 * @{
 */
/**
 * @brief Mock motor implementation for use in unit tests and simulations with a
 * spy function for power()
 *
 */
struct motor : public hal::motor
{
  /**
   * @brief Reset spy information for power()
   *
   */
  void reset()
  {
    spy_power.reset();
  }

  /// Spy handler for hal::motor::write()
  spy_handler<percent> spy_power;

private:
  boost::leaf::result<void> driver_power(percent p_power) noexcept override
  {
    return spy_power.record(p_power);
  };
};
/** @} */
}  // namespace hal::mock
