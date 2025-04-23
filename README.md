# FreeRTOS Demonstration on Arduino Due

## Project Overview
This project showcases the use of FreeRTOS (Free Real-Time Operating System) on an Arduino Due development board. The primary goal is to demonstrate the functionality of tasks, timers, and messaging within FreeRTOS, while promoting **de-coupling** and **cohesion** between application layer modules. 

## Features
- **Tasks**: Creation and management of multiple tasks to handle different functionalities.
- **Timers**: Usage of software timers for efficient scheduling and time-based events.
- **Messaging**: Implementation of inter-task communication mechanisms to enable seamless data exchange between modules.

## Objectives
1. Highlight the modular design capabilities of FreeRTOS.
2. Demonstrate how de-coupling enhances system maintainability.
3. Showcase cohesive interactions between application layer modules.

## My code contributions
See the following files for code that I wrote to make this project work:
- main.c - application entry point that calls into mcu.c to initialize hardware, sets up the LED application module (led_controller.c), then starts the scheduler
- Application/led_controller.c (.h) - application module that toggles an LED using a FreeRTOS timer
- System/scheduler.c (.h) - wrapper for FreeRTOS task, timer, and messaging
- Hardware/mcu.c (.h) - microcontroller hardware resources initialization

## Hardware Requirements
- Arduino Due development board.
- USB cable (for basic power and initial setup).
- Atmel-ICE programmer/debugger (for flashing and debugging).

## Software Requirements
- [FreeRTOS Kernel](https://www.freertos.org/): Real-time operating system for microcontrollers.
- [Atmel Studio](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio): IDE for programming and debugging microcontroller-based applications.
- FreeRTOS library (integrated with your Atmel Studio project).

## Setup and Installation
1. **Install Atmel Studio:**
   - Download and install Atmel Studio from the [Microchip website](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio).
2. **Clone or Download the Project:**
   - Clone this repository or download the source files to your local machine.
3. **Configure FreeRTOS in Atmel Studio:**
   - Create a new project for the Arduino Due in Atmel Studio.
   - Add the FreeRTOS library to your project.
4. **Connect Your Hardware:**
   - Connect the Atmel-ICE programmer/debugger to your Arduino Due board.
   - Ensure the programmer is connected to your PC and properly configured within Atmel Studio.

## Usage
1. Open the project in Atmel Studio.
2. Compile the code using the Atmel Studio build tools.
3. Flash the compiled binary to the Arduino Due board using the Atmel-ICE programmer.
4. Use the debugging features in Atmel Studio to observe task execution, timer behavior, and messaging functionality.

## License
This project is licensed under the [MIT License](https://opensource.org/licenses/MIT) - feel free to use, modify, and distribute as needed.

## Acknowledgments
- The FreeRTOS community for providing an excellent real-time operating system.
- Arduino for an accessible and versatile development platform.
- Microchip for Atmel Studio and Atmel-ICE programmer/debugger tools that simplify embedded development.

---

Let me know if you have any questions about this project!
-Jonathon
