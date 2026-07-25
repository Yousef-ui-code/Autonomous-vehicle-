# Autonomous Obstacle-Avoidance Car

A simulation-based autonomous vehicle project that detects obstacles and dynamically adjusts its path in real time, inspired by structured-road obstacle avoidance research. Built and validated entirely in simulation (Wokwi) as part of a mechatronics engineering portfolio.

![Wokwi Simulation](./images/wokwi_simulation.png)

## Demo Video

Watch the full simulation running: [https://youtu.be/RUuFZ0P9Yqw](https://youtu.be/RUuFZ0P9Yqw)

## Overview

This project implements a small-scale autonomous car that uses distance/IR sensing to detect obstacles ahead and reactively steers and adjusts motor speed to avoid collisions, before returning toward its original path. It is a simplified, hardware-in-simulation exploration of the obstacle-avoidance concepts discussed in the reference research paper below, translated into an achievable Arduino-class embedded system.

**Core capabilities:**
- Real-time obstacle detection using IR/distance sensors
- Reactive steering via servo motor
- Speed modulation as the car approaches an obstacle (slow down instead of hard stop)
- Visual status indication via onboard LEDs
- Fully simulated using Wokwi (Seeed XIAO-based circuit)

## Motivation & Research Basis

This project is inspired by the paper:

> Li, G.; Li, S.; Peng, Y. *"Obstacle Avoidance Trajectory Planning for Autonomous Vehicles on Structured Roads."* World Electric Vehicle Journal, 2024, 15(4), 168.
> Paper link: https://www.mdpi.com/2032-6653/15/4/168

The referenced paper proposes an obstacle avoidance trajectory planning method combining an improved Artificial Potential Field (APF) with speed planning over an S-T (station-time) graph, validated on a full-scale autonomous vehicle platform (ROS-based) in the Panosim simulation environment.

This project does **not** implement the full mathematical APF model or S-T graph planning from the paper — it is a simplified embedded-systems interpretation built for an accessible microcontroller platform (Seeed XIAO) in Wokwi. What it borrows conceptually from the paper:
- The idea that a vehicle should gradually slow as it nears an obstacle rather than react abruptly (analogous to the repulsive force behavior in APF)
- The idea that after avoiding an obstacle, the vehicle should tend back toward its original path (analogous to the attractive force pulling the vehicle toward its goal trajectory)

This distinction — what was replicated conceptually versus what was simplified — is stated explicitly and intentionally, to keep the project description accurate rather than overstated.

## System Concept Diagram

The diagram below illustrates a full-scale reference architecture (Lidar, Jetson Nano, STM32, camera-based sensor fusion) representative of how obstacle-avoidance systems are structured in real autonomous vehicles. It is included here as conceptual/architectural context for how this simplified project's sensor → controller → actuator pipeline maps to a real-world system.

![System Architecture Reference](./images/system_architecture.png)

*Note: this project's actual implementation uses the simplified Wokwi circuit shown above (Seeed XIAO + IR sensors + servo + DC motor + LEDs), not the full Lidar/Jetson Nano/STM32 stack shown in this reference diagram.*

## Hardware / Simulation Components (Wokwi)

| Component | Role |
|---|---|
| Seeed XIAO (microcontroller) | Main controller — reads sensors, runs avoidance logic, drives outputs |
| IR distance sensors (x2) | Detect obstacles ahead / to the sides |
| Servo motor | Steering actuation |
| DC motor | Drive/propulsion |
| LEDs (x4) | Status indication (turning direction / obstacle detected) |
| Resistor | Sensor/LED circuit protection |

## How It Works

1. IR sensors continuously measure distance to obstacles in front of the vehicle.
2. As the measured distance decreases, drive motor speed is reduced proportionally rather than cutting off instantly.
3. When an obstacle is detected within the avoidance threshold, the controller commands the steering servo to turn away from the obstacle.
4. Status LEDs indicate the current maneuver (e.g., turning left/right, obstacle detected).
5. Once clear of the obstacle, the vehicle steers back toward its original heading.

## Repository Contents

```
├── README.md              # This file
├── src/                   # Arduino/Wokwi source code (.ino)
├── images/
│   ├── wokwi_simulation.png       # Wokwi circuit simulation screenshot
│   └── system_architecture.png    # Reference system architecture diagram
└── docs/
    └── project_report.pdf # Short technical write-up (problem, design rationale, limitations)
```

## Limitations & Honest Scope

To keep this project academically honest:
- No formal Artificial Potential Field mathematics or S-T graph speed planning is implemented — only the conceptual behavior (gradual slowdown, return-to-path) is replicated in simplified logic.
- Testing was performed entirely in the Wokwi circuit simulator; no physical hardware was built due to budget constraints.
- Sensing is limited to short-range IR distance sensors, not Lidar or camera-based perception as in full-scale research/production systems.

## Reference

Li, G.; Li, S.; Peng, Y. Obstacle Avoidance Trajectory Planning for Autonomous Vehicles on Structured Roads. *World Electric Vehicle Journal* 2024, 15(4), 168. https://doi.org/10.3390/wevj15040168

## Author

Part of an ongoing mechatronics engineering portfolio built for undergraduate program applications, focused on simulation-based robotics and control projects (Webots, Wokwi).
