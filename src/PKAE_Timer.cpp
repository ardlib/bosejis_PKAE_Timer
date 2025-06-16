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
