# Geometry-in-C

The program is a C application that handles triangles via a structure called a triangle. The program reads the coordinates of the vertices of a triangle, calculates its perimeter and determines whether the triangle is equilateral, isosceles or scalene. Next, it creates a copy of the triangle and writes the results to a user-specified file.

Definition of the triangle structure: The triangle structure contains the coordinates of the triangle's vertices (coordinates), its perimeter (perimeter) and three Boolean values (isosceles, scalene, equilateral) which indicate whether the triangle is respectively isosceles, scalene or equilateral.

The update function: This function takes a pointer to a triangle structure and reads the coordinates of the triangle's vertices from input. Based on the read coordinates, the program updates the properties of the structure.

The perimeter function: Calculates the perimeter of the triangle using the formula for the distance between points in the plane. It also determines the type of triangle (isosceles, scalene, or equilateral) by comparing the lengths of the sides.

The copy function: This function creates a copy of the triangle structure passed as an argument and returns a pointer to the copy. It is used to keep a copy of the original triangle after updating its properties.

The write file function: Writes the coordinates of the vertices, the perimeter and the information about the type of the triangle to the specified file.

The main function: Initializes a triangle variable called first, reads the coordinates from input and calculates the perimeter. Next, it makes a copy of triangle first, writes it to the specified file, and then returns 0 to indicate successful program execution.
