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

#endif