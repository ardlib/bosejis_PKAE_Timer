# `bosejis_PKAE_Timer` Library

This class is a simple timer implementation that allows you to check if a certain amount of time has passed and optionally reset the timer. It can be useful for various timing-related tasks in embedded systems or other applications.

This library was originally developed by **[PKAE Electronics](https://www.youtube.com/@paulpkae)**.

This library is now maintained under *[@ardlib](https://github.com/ardlib) Organization*.

---

## Video Demonstration of `PKAE_Timer` Library

Direct Link <https://www.youtube.com/watch?v=R7UKZ58vIyc>

[![PKAE_Timer Library by PKAE Electronics](https://img.youtube.com/vi/R7UKZ58vIyc/0.jpg)](https://www.youtube.com/watch?v=R7UKZ58vIyc)

---

## Installing `PKAE_Timer` Library in Arduino IDE

### Using the [Zip File](https://github.com/ardlib/bosejis_PKAE_Timer/archive/refs/heads/main.zip) from this repository

Downloading the Zip file of this repository from :

<https://github.com/ardlib/bosejis_PKAE_Timer/archive/refs/heads/main.zip>

And installing using the Add .ZIP Library feature:

- For Arduino IDE 1.8.19 and above:

    Go to Menu `Sketch -> Include Library -> Add .ZIP Library`

### From Arduino Library Manager

- For Arduino IDE 1.8.19 and above:

    Go to Menu `Tools -> Manage Libraries...`

- Search for `PKAE` or `PKAE Timer` you would see the Library appear.

- Click on Install to get the library.

---

## `PKAE_Timer` Constructor

The constructor initializes the timer with an optional *initial delay*. If no delay is provided, it defaults to 0.

It sets the member variable `_delay` to the specified delay, initializes `nStarted` with the current time using the `millis()` function, and sets `nLastStarted` and `nCount` to 0.

Example:

```c++
PKAE_Timer Flash_LED(500);
```

The above line defines a timer instance called `Flash_LED` and the delay is set to `500 milliseconds`.The count down starts the moment the instance is created.

## `IsTimeUp()` Function

The `IsTimeUp` function checks if the specified time has elapsed since the timer was last started.
It calculates the effective delay to check against as the maximum of the fixed delay `_delay` and a dynamic delay `nDynamicDelay`.
If the **elapsed time is greater than the effective delay**, it returns **true** indicating that the *time is up*.
If `lReset` is true, it increments the count `nCount`, updates `nLastStarted` to the previous start time, and sets `nStarted` to the current time

Example:

```c++
if (Flash_LED.IsTimeUp()) {
    // put code here e.g. toggle the LED state On/Off.
}
```

This will execute the code with in the curly braces whatever the timer (`500m/s` in our example) is reached. The timer automatically resets itself to start again.

You can pass an optional dynamic delay to check if an alternative duration has lapsed or not.

Example:

```c++
if (Flash_LED.IsTimeUp(250)) {
    // put code here to execute if 250m/s has lapsed. 
}
```

You can also pass an optional boolean expression to determine if the timer is reset or not. Handy if you wanted to temporarily stop the flashing for example.

Example:

```c++
if (Flash_LED.IsTimeUp(250,false)) {
    // put code here to execute if 250m/s has lapsed. The timer will not reset.
}
```

## `Reset()` Function

The `Reset` function resets the timer by updating `nLastStarted` to the previous start time and setting `nStarted` to the current time using `millis()``.

Example:

```c++
Flash_LED.Reset();
```

This will effectively restart the timer counter for the Flash_LED timer instance.

## Member Variable `.nCount`

Retains a counter of the number of iterations that the timer instance has triggered. 

Example:

```c++
xCount=Flash_LED.nCount;
```

`xCount` will store the number of times this timer has triggered,


## Member Variable `.nStarted`

Retains the `millis()` reading at the time in `millis` that the timer was started (either by its initial creation or by its last reset).

Example:

```c++
xStarted=Flash_LED.nStarted;
```

`xStarted` will store when the last timer started for this timer instance. i.e. the `millis()` reading at the time it last initiated.


## Member Variable `.nLastStarted`

Retains the `millis()` reading of the previous time timer was started. 

Example:

```c++
xLastStarted=Flash_LED.nLastStarted;
```

`xLastStarted` will store when the previous timer started for this timer instance. i.e. the `millis()` reading at the time it previously initiated.

---

## `RepeatTimer` - Lightweight Arduino Timer Class

**`RepeatTimer`** is a minimal and efficient Arduino library for scheduling periodic callbacks using `millis()`. It is designed to work reliably on memory-constrained boards like the Arduino Uno and Nano.

> Safe for AVR — uses plain function pointers, not `std::function`.

### Features

- Call a function every N milliseconds
- Safe `millis()` wraparound handling
- Tracks trigger count (`nCount`)
- Supports dynamic interval or callback updates
- Minimal RAM and code footprint
- Designed for AVR and other constrained platforms
- **No support for lambdas or captures** — uses plain C-style function pointers.
- Ideal for Arduino Uno, Nano, Pro Mini, ATmega328P-based boards.

### Usage

#### 1. Define your callback

```cpp
void blinkLED() {
  static bool state = LOW;
  state = !state;
  digitalWrite(LED_BUILTIN, state);
}
```

#### 2. Create a timer instance

```cpp
RepeatTimer myTimer(1000, blinkLED); // Fire every 1000ms
```

#### 3. Call `.update()` inside `loop()`

```cpp
void loop() {
  myTimer.update();
}
```

### API Reference

#### `RepeatTimer(uint32_t interval_ms, CallbackFn callback)`
Create a new timer that calls `callback()` every `interval_ms`.

#### `bool update()`
Checks the timer and calls the callback if the interval has elapsed.

#### `void setRate(uint32_t interval_ms)`
Change the timer interval.

#### `void setCallback(CallbackFn callback)`
Set or update the callback function.

#### `void reset()`
Restart the timer countdown from now.

#### `bool isValid()`
Returns true if both callback and interval are set.

#### `uint32_t nCount`
Number of times the callback has been triggered.

---

## Note to Developers

Make sure to run the `clang-format --verbose -i src/*.h src/*.cpp` on the repo.
To clean the Example Sources `clang-format --verbose -i examples/**/*.ino`.

In order to keep the Compatibility make sure to test the *Arduino Compliance*
run `arduino-lint --compliance strict`.

---

## License

This project is released under the MIT License. See the [LICENSE](./LICENSE) file for details.

Sources: <https://github.com/ardlib/bosejis_PKAE_Timer>

`bosejis_PKAE_Timer` - PAKE Timer Library

Copyright (c) 2024 PKAE Electronics
Copyright (C) 2025 by Abhijit Bose (aka. Boseji)

SPDX-License-Identifier: `MIT`

Full Name: `MIT License`

For more details please visit <https://spdx.org/licenses/MIT.html>.
