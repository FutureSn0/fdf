
# FDF

This is a graphic based project which utilises the minilibx libary. This program recives as input a text file with a map of co ordinates. This map is read by the program and used to display a 3D wireframe model based on the map co ordinates. This is displayed as an image in a window created using minilibx.

# How to use

1. Clone the repository, then enter the cloned directory

```bash
git clone git@github.com:FutureSn0/fdf.git
cd fdf
```

2. Run "make"

```bash
make
```

3. run the program with a map from the "test files directory". You can create your own maps by making a grid of co ordinates.

```bash
./fdf test_maps/42.fdf
```
4. Image will be displayed in the window. To exit press "esc" or click the x at the corner of the window.

Additional makefile rules

`make` - Compile fdf program.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object file) and .a (executable) files.

`make re` - Reblilds project by using rules `fclean` + `all`.

# Subject
### Mandatory

- Program has to represent the model in isometric projection.
- The coordinates of the landscape are stored in a .fdf file passed as a parameter to the program.
    
    - The horizontal position corresponds to its axis.
    - The vertical position corresponds to its ordinate.
    - The value corresponds to its altitude.

- Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing ESC must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
- The use of the images of the MiniLibX is mandatory.

All functions must be fully functioning and well-tested to obtain passing score (100/100).

# Norminette

All projects are written according to a standard implemented by the 42 school known as "Norminette". This standard specifies our files to be formatted in a specific way, limits the amount of functions and varables included in a single file, and also the use of certain statements (for, do.. while, switch.. case, etc).
