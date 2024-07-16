# Real-time Image Processor

This is a image processing application developed using the Qt framework. It allows you to open and analyze images. The application can calculate the percentage of dark pixels, find the number of connected components (blobs), and determine the maximum blob area in the image.

## Prerequisites

Before you get started, make sure you have the following:

- [Qt](https://www.qt.io/download) installed on your system.

## Getting Started

Follow these steps to run the application:

1. Clone or download the repository to your local machine.

2. Open the project in Qt Creator or your preferred IDE.

3. Build and run the application.

## Usage

1. Click the "Open Image" button to select an image file from your system.

2. The application will display information about the image, including its dimensions, occupancy percentage, number of blobs, and maximum blob area.

3. Analyze the image to see its occupancy percentage, number of blobs, and maximum blob area.

4. You can save the binary representation of the image to a text file using the "Save" option.

## Troubleshooting

Here are some common problems you may encounter and their solutions:

1. **Problem:** The application doesn't run.
   - **Solution:** Ensure that you have Qt installed and that the project is set up correctly in your development environment.

2. **Problem:** The image does not load.
   - **Solution:** Check the file format and path of the image. Supported formats are PNG, XPM, and JPG.

3. **Problem:** The occupancy percentage is not calculated correctly.
   - **Solution:** Verify the image and ensure that it contains dark pixels. The calculation is based on pixel color values.

