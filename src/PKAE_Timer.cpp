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

RepeatTimer::RepeatTimer(uint32_t repeat_ms, std::function<void(void)> callback)
  : _interval(repeat_ms), _callback(callback), nCount(0) {
  if (isValid()) {
    _nextTrigger = millis() + _interval;
  } else {
    _nextTrigger = 0;
  }
}

bool RepeatTimer::update() {
  if (!isValid()) {
    return false;  // Don't trigger if invalid
  }

  uint32_t now = millis();
  if ((int32_t)(now - _nextTrigger) >= 0) {
    _callback();       // Execute callback
    nCount++;          // Only increment if executed
    _nextTrigger += _interval;
    return true;
  }
  return false;
}

void RepeatTimer::setRate(uint32_t repeat_ms) {
  _interval = repeat_ms;
  if (isValid()) {
    _nextTrigger = millis() + _interval;
  }
}

void RepeatTimer::setCallback(std::function<void(void)> callback) {
  _callback = callback;
  if (isValid()) {
    _nextTrigger = millis() + _interval;
  }
}

void RepeatTimer::reset() {
  if (isValid()) {
    _nextTrigger = millis() + _interval;
  }
}

bool RepeatTimer::isValid() const {
  return _interval > 0 && static_cast<bool>(_callback);
}