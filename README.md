# Sculptor

Construction of a C ++ tool for making block sculptures represented by digital matrices.
Pass the information of the figures to be implemented in a (.txt) file, then open the .off file in a visualization program.

## Goals:

- [x] Creation .off file
- [x] Converter .txt file to .off
- [x] Interface

## Tools of project

<p align="center">
<img src="https://user-images.githubusercontent.com/48501389/69596980-2d496900-0fe3-11ea-8d1f-02ea530564ac.png">
</p>
Through the classes already developed in Sculptor, it is possible to generate the functionality in the interface.

### PutVoxel
<p align="center">
<img src="https://user-images.githubusercontent.com/48501389/69596721-53223e00-0fe2-11ea-9999-5bbd25e6f28d.PNG">
</p>
Paint a pixel at the desired position of the drawing sheet

### CutVoxel
<p align="center">
<img src="https://user-images.githubusercontent.com/48501389/69596794-92e92580-0fe2-11ea-975a-80d3bdcfb897.PNG">
</p>
Erase a pixel at the desired position of the drawing sheet

### PutBox
<p align="center">
<img src="https://user-images.githubusercontent.com/48501389/69596821-abf1d680-0fe2-11ea-811a-e224ddd221bf.PNG">
</p>
Paints box-size pixels, being their size is set in the interface.

### CutBox
<p align="center">
<img src="https://user-images.githubusercontent.com/48501389/69596830-b6ac6b80-0fe2-11ea-8b70-8f566a76ebf4.PNG">
</p>
Erase box-size pixels, being their size is set in the interface.

### PutSphere
<p align="center">
<img src="https://user-images.githubusercontent.com/48501389/69596854-d80d5780-0fe2-11ea-99e1-8d6df0cab718.PNG">
</p>
Paints sphere-shaped pixels, being their radius is set in the interface.

### CutSphere
<p align="center">
<img src="https://user-images.githubusercontent.com/48501389/69596870-e0659280-0fe2-11ea-949c-e29ccea6fd24.PNG">
</p>
Erase sphere-shaped pixels, being their radius is set in the interface.

### PutEllipsoid
<p align="center">
<img src="https://user-images.githubusercontent.com/48501389/69596904-fb380700-0fe2-11ea-9a0b-6cba777dde0e.PNG">
</p>
Paints ellipse-shaped pixels, being its radii defined at the interface.

### CutEllipsoid
<p align="center">
<img src="https://user-images.githubusercontent.com/48501389/69596917-02f7ab80-0fe3-11ea-88cd-93ee845b6ee0.PNG">
</p>
Erase ellipse-shaped pixels, being its radii defined at the interface.

### Colors
<p align="center">
<img src="https://user-images.githubusercontent.com/48501389/69597037-59fd8080-0fe3-11ea-9200-be82a84399d2.png">
</p>
The colors are in rgb format, being the user's choice if they want to make any changes to the coloring of the drawing.

## Contributors:

- **Fernando Felipe**: http://github.com/fernando427
- **Rafael Vinicius**: http://github.com/rafaelvini123
