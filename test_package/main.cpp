#include <cstdio>

#include <libhal/pwm/interface.hpp>
#include <libhal/servo/rc.hpp>

class test_pwm : public hal::pwm
{
private:
  virtual hal::status driver_frequency(hal::hertz p_frequency) noexcept
  {
    std::printf("frequency = %f Hz\n", p_frequency);
    return {};
  }
  virtual hal::status driver_duty_cycle(float p_position) noexcept
  {
    std::printf("duty cycle = %f %%\n", p_position);
    return {};
  }
};

int main()
{
  test_pwm pwm;
  auto rc_servo = hal::rc_servo::create(pwm).value();
  rc_servo.position(0.25).value();
  rc_servo.position(0.50).value();
  rc_servo.position(-0.25).value();
  rc_servo.position(-1.0).value();
  return 0;
}