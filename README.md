# Real-Time Image Processing Application

## Overview

This project is a Qt-based image processing application designed to enhance Optical Character Recognition (OCR) accuracy in real-time. The application leverages asynchronous processing to efficiently analyze dark pixels, connected components, and maximum blob areas in parallel, maintaining a frame rate of 60 FPS.

## Features

- **Real-Time Processing**: Utilizes asynchronous processing to handle image data in real-time, ensuring minimal latency and high responsiveness.
- **OCR Enhancement**: Improves OCR accuracy by analyzing key image components such as dark pixels, connected components, and maximum blob areas.
- **High Performance**: Maintains a consistent frame rate of 60 FPS, ensuring smooth and efficient image processing.
- **Qt Framework**: Built using the Qt Framework for robust and cross-platform application development.
- **Efficient Analysis**: Parallel processing techniques enhance the efficiency and speed of image analysis.

## Technologies Used

- **Programming Language**: C++
- **Framework**: Qt Framework (Qt Core, Qt Widgets, Qt Concurrent, Qt Multimedia)
- **Database**: MySQL (modifiable)

## Installation

### Prerequisites

- **Qt Framework**: Ensure that the Qt framework is installed on your system. You can download it from [here](https://www.qt.io/download).
- **C++ Compiler**: Ensure that a C++ compiler is installed on your system.
- **CMake**: Ensure that CMake is installed for building the project.

### Steps

1. **Clone the Repository**:

   ```sh
   git clone https://github.com/Arup-Chauhan/qt-image-processing-app.git
   cd qt-image-processing-app
   ```

2. **Build the Project**:

   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the Application**:

   ```sh
   ./image-processing-app
   ```

## Usage

1. **Launching the Application**:
   - Run the executable file generated after the build process.

2. **Real-Time Processing**:
   - The application will start processing images from the connected camera or video feed in real-time.
   - The frame rate and performance metrics will be displayed on the interface.

3. **Analyzing Images**:
   - The application will analyze dark pixels, connected components, and maximum blob areas in each frame.
   - Results will be used to enhance OCR accuracy in real-time.

## Performance Metrics

- **Frame Rate**: Consistently maintains 60 FPS for smooth real-time processing.
- **OCR Accuracy**: Enhances OCR accuracy by efficiently analyzing image components.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any improvements or bug fixes.
