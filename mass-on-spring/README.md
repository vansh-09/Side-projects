# Mass on Spring Physics Simulator

A real-time physics simulation of a mass-spring system with damping, built using [Raylib](https://www.raylib.com/).

## Features

- Visual spring oscillation with realistic physics
- Damping and friction effects
- Real-time FPS display
- Smooth 120 FPS rendering

## Prerequisites

- macOS
- GCC compiler
- Raylib library
- pkg-config

### Installing Raylib

```bash
brew install raylib
```

For more information, visit the [Raylib website](https://www.raylib.com/).

## Build & Run (macOS)

### Compile

```bash
eval cc ./mass-on-spring.c $(pkg-config --libs --cflags raylib) -o mass-on-spring
```

### Run

```bash
./mass-on-spring
```

### Or compile and run in one step

```bash
eval cc ./mass-on-spring.c $(pkg-config --libs --cflags raylib) -o mass-on-spring && ./mass-on-spring
```

## Physics Parameters

The simulation includes the following configurable parameters (in `mass-on-spring.c`):

- Spring constant (K)
- Friction coefficient
- Mass width
- Spring element count
- FPS and window dimensions

## Controls

- Close the window to exit the simulation

---

Built with [Raylib](https://www.raylib.com/)
