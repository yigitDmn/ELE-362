# Main Program Body for STM32 Microcontroller

## Description

This software controls an STM32 microcontroller setup to handle multiple tasks including UART communication, LED control, and displaying messages on a Nokia 5110 LCD. The program uses a circular buffer to manage incoming UART data which is processed to control various peripherals based on the received commands.

## Features

- **UART Communication**: Handles asynchronous reception of data using UART interrupt.
- **LED Control**: Manipulates multiple GPIO pins to control LEDs based on received commands.
- **Display on Nokia 5110 LCD**: Outputs text or clears the display based on the commands parsed from the UART.
- **Circular Buffer Management**: Utilizes a circular buffer to store incoming data for processing.
- **Error Handling**: Robust error management to handle any interruptions or failures in execution.

## Hardware Setup

- **STM32 Microcontroller**
- **Nokia 5110 LCD**
- **LEDs connected to various GPIO pins**
- **UART communication interface**

## Software Components

- `main.h`: Header file for main program body.
- `dwt_delay.h`: Delays using the DWT component.
- `Nokia_5110.h`: Controls for the Nokia 5110 LCD.
- `circular_buffer.h`: Circular buffer implementation.

## Getting Started

### Prerequisites

- STM32CubeIDE or similar IDE for development and flashing the microcontroller.
- Basic understanding of microcontroller programming and peripherals.

### Installation

1. Clone the repository or download the source code.
2. Open the project in STM32CubeIDE.
3. Build the project and flash it to your STM32 microcontroller.

### Usage

- The device begins listening for UART data at startup.
- Send commands via UART to control LEDs or display messages on the Nokia 5110 LCD.
- Use predefined command formats for different operations:

  - `0xAB`: Header byte to start a new command.
  - `0xBA`: Footer byte to finish the command.
  - Command-specific bytes to perform operations like toggling LEDs or printing to the LCD.

## License

This project is licensed under the terms of the MIT license.

## Acknowledgments

Thanks to STM32 and the community for supporting the development of this project.
