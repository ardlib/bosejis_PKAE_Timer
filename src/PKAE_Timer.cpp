/**************************************************************************
 * @file     PKAE_Timer.c
 *
 * License: MIT (see LICENSE)
 *
 *************************************************************************/

#include "PKAE_Timer.h"

PKAE_Timer::PKAE_Timer(uint32_t delay = 0) {
  _delay = delay;
  nStarted = millis();
  nLastStarted = 0;
  nCount = 0;
}

void PKAE_Timer::Reset() {
  nLastStarted = nStarted;
  nStarted = millis();
}

boolean PKAE_Timer::IsTimeUp(uint32_t nDynamicDelay, boolean lReset) {
  boolean lTimeUp = false;
  uint32_t nDelayCheck = max(_delay, nDynamicDelay);

  if ((millis() - nStarted) > nDelayCheck) {

    lTimeUp = true;
    if (lReset) {
      nCount++;
      nLastStarted = nStarted;
      nStarted = millis();
    }
  }

  return (lTimeUp);
}

RepeatTimer::RepeatTimer(uin32_t repeat_ms, void (*callback)(void)) {
  nCount = 0;
  _interval = repeat_ms;
  _nextTrigger = millis() + repeat_ms;
  _callback = callback;
}

bool RepeatTimer::update() {
  unsigned long ms = millis();
  // Avoid Zero Interval
  if ((ms >= _nextTrigger) && _interval) {
    _nextTrigger = ms + _interval;
    _callback();
    ++nCount;
    return true;
  }
  return false;
}

void RepeatTimer::setRate(uin32_t repeat_ms) { _interval = repeat_ms; }

void RepeatTimer::reset() {
  _nextTrigger = millis() + _interval;
  nCount = 0;
}