# Fract-ol

## Project Description

Fract-ol is a visually project that delves into the world of fractals, specifically the Julia set and the Mandelbrot set. Utilizing the MiniLibX library, this project demonstrates the infinite complexity of fractals, allowing users to zoom in and out to explore the fine details of these mathematical beauties. With customizability through command-line parameters and dynamic, colorful rendering, Fract-ol offers an immersive exploration of fractal geometry.

### Features

- **Dynamic Fractals**: Offers the Julia set and the Mandelbrot set.
- **Zoom**: Utilize the mouse wheel to zoom in and out.
- **Customizable Julia Sets**: Pass different parameters to the program to generate unique Julia sets, allowing for a personalized fractal experience.
- **Colorful Rendering**: Uses a variety of colors to represent the depth of the fractals, with optional psychedelic effects for a more vibrant display.
- **Interactive Navigation**: Move the view smoothly using arrow keys, enhancing the exploration experience.
- **Graphics Management**: Ensures smooth window management, including minimizing and changing windows, with an easy exit option through the ESC key or window cross.

## Getting Started

### Prerequisites

- A Linux operating system.
- Installation of the MiniLibX library.
- A C compiler such as GCC or Clang.

### Installation

1. Clone the repository to your local machine:
git clone https://github.com/Beata12/fract-ol.git

2. Navigate to the project directory:
cd fract-ol

3. Compile the project using the Makefile:
make

4. Usage
Execute the program with the name of the desired fractal as a parameter. If no parameter is provided or the parameter is invalid, the program will display a list of available options and exit.


./fractol <fractal_name>
./fractol <fractal_name> <Julia_coordinates>
Valid <fractal_name> values are Julia, Mandelbrot.
Valid <Julia_coordinates> are valid Julia sets.
exapmle: 
- ./fractol Julia
- ./fractol Julia  -1.77029598415682387070596815828735774662104581 -0.005852576008784477443909236300355828076899285495 (This command allows you to zoom into a specific part of the Julia set, revealing intricate and endlessly repeating patterns)
- ./fractol Mandelbrot
