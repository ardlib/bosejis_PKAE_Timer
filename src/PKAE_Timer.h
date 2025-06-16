/**************************************************************************
 * @file     PKAE_Timer.h
 *
 * License: MIT (see LICENSE)
 *
 *************************************************************************/

#ifndef PKAE_Timer_H
#define PKAE_Timer_H
#include "Arduino.h"
#include <functional>

class PKAE_Timer {
public:
  PKAE_Timer(uint32_t delay);
  void Reset();
  boolean IsTimeUp(uint32_t nDynamicDelay = 0, boolean lReset = true);
  uint32_t nStarted;
  uint32_t nLastStarted;
  uint32_t nCount;

private:
  uint32_t _delay;
};

class RepeatTimer {
public:
  RepeatTimer(uint32_t repeat_ms = 0, std::function<void(void)> callback = nullptr);

  bool update();                             // Call in loop()
  void setRate(uint32_t repeat_ms);          // Change interval
  void setCallback(std::function<void(void)> callback); // Set new callback
  void reset();                              // Restart timer
  bool isValid() const;                      // Check if interval + callback are valid
  uint32_t nCount;                           // Number of times triggered

private:
  uint32_t _interval;                        // Interval in ms
  uint32_t _nextTrigger;                     // Next scheduled trigger
  std::function<void(void)> _callback;       // User callback
};

#endif