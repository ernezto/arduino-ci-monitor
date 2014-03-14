arduino-ci-monitor
==================

Arduino Continuous integration Monitor System

## Goal

This is a prototype as a proof of concept to demonstrate how to
use Arduino as a continuos integration monitor. With this demo we were
able to connect to an Arduino Board using a raspberrypi device and send
commands to display the CI status.

The circuit is compose by an Arduino Board, a RGB Led, a Buzzer and a
LCD. Each commands is sent to the board using the USB serial connection, with a pattern like:

```
command: <number>, print: <text to display>

```

Where `<number>` is an integer value in range [1..3]:

Number 1 means: __Build Passed Command__

Number 2 means: __Stage Started to Deploy Command__

Number 3: means: __Build is Broken Command__

And `<text to display>` is an string to show on the LCD. We usually sent the name of the stage

For each command, the arduino reacts in a different way:

__Build Passed__: RGB led turns on with a green light and buzzer plays the super mario bros flag pole song
__Stage Started to Deploy Command__: RGB led strobes with a green light and buzzer plays the super mario bros main theme
__Build is Broken Command__: RGB turns on with a red light and buzzer plays super mario bros mario death theme.

Feel free to use and modify this project for your needs or report your bugs or improvements.
