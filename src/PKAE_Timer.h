/**************************************************************************
 * @file     PKAE_Timer.h
 *
 * License: MIT (see LICENSE)
 *
 *************************************************************************/

#ifndef PKAE_Timer_H
#define PKAE_Timer_H
#include "Arduino.h"

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
  typedef void (*CallbackFn)(); // Plain function pointer

  RepeatTimer(uint32_t repeat_ms = 0, CallbackFn callback = nullptr);

  bool update();                         // Call in loop()
  void setRate(uint32_t repeat_ms);      // Change interval
  void setCallback(CallbackFn callback); // Set new callback
  void reset();                          // Restart timer
  bool isValid() const;                  // Check if usable
  uint32_t nCount;                       // Times callback fired

private:
  uint32_t _interval;
  uint32_t _nextTrigger;
  CallbackFn _callback;
};

#endif