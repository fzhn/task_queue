# Task Queue

The Task Queue project is an implementation of a queue designed to pass tasks from one thread to another. It provides a thread-safe mechanism for a single producer and a single consumer thread. If you wish to involve more threads, adjustments to the code will be necessary.

## Features

- **Thread Safety**: The current version is thread-safe for one thread adding to the queue and one thread popping from the queue.
- **C Integration**: The structure allows for easy integration with C code.

## Requirements

- CMake (minimum version 3.8)
- C++17

## Building the Project

1. Create a build directory:
   ```bash
   mkdir build && cd build
   ```

2. Run CMake:
   ```bash
   cmake ..
   ```

3. Build the unit tests:
   ```bash
   make unittest
   ```

## Usage

To use the Task Queue in your project, include the necessary headers from the `include` directory.

## Limitations

- The current implementation is designed for a single producer and a single consumer thread. If you need support for multiple threads, you'll need to modify the code to ensure thread safety.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License.

