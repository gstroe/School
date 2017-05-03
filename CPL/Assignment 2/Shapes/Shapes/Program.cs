using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shapes
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "";
            List<Shape> shapeList = new List<Shape>(); // the list holding all of the shapes made
            // show welcome text
            Console.WriteLine("\tWelcome to the Shape Generator!");
            while (input != "x")
            {
                // print menu
                Console.WriteLine("\n---------------------------------------");
                Console.WriteLine("Enter the Following:");
                Console.WriteLine("n - to create a new shape");
                Console.WriteLine("e - for editing an existing shape");
                Console.WriteLine("d - for deleting a shape");
                Console.WriteLine("p - for printing an existing shape");
                Console.WriteLine("a - for printing all existing shape");
                Console.WriteLine("x - to exit the program");
                Console.WriteLine("---------------------------------------");

                // get input
                input = Console.ReadKey(true).Key.ToString().ToLower(); // lowercase for ease
                if (input == "n")
                {
                    Console.WriteLine("\n---------------------------------------");
                    Console.WriteLine("Enter the type of shape Following:");
                    Console.WriteLine("a - for an ambigous shape");
                    Console.WriteLine("r - for a rectangle");
                    Console.WriteLine("t - for a triangle");
                    Console.WriteLine("Press any other key to cancel");
                    Console.WriteLine("---------------------------------------");
                    input = Console.ReadKey(true).Key.ToString().ToLower(); // lowercase for ease
                    #region Make shapes
                    // make the shape type
                    if (input == "a")
                    {
                        string tempName;
                        double tempArea, tempPeri;
                        int tempSides = 0;
                        Console.WriteLine("Enter the Shape Name:");
                        tempName = Console.ReadLine(); // get the name
                        Console.WriteLine("Enter the Area:");
                        while (!Double.TryParse(Console.ReadLine(), out tempArea)) // get the area if string can be parsed into a initger
                        {
                            Console.WriteLine("Not a Decimal value! Please try Again!");
                        }
                        Console.WriteLine("Enter the Perimeter:");
                        while (!Double.TryParse(Console.ReadLine(), out tempPeri)) // get the perimeter if the area can be parsed into a string
                        {
                            Console.WriteLine("Not a Decimal value! Please try Again!");
                        }
                        while (tempSides < 5) // set the number of sides
                        {
                            Console.WriteLine("Enter the Number of sides, must be greater then 4");
                            while (!Int32.TryParse(Console.ReadLine(), out tempSides))
                            {
                                Console.WriteLine("Not a intiger value! Please try Again!");
                            }
                        }
                        shapeList.Add(new Shape(tempName, tempArea, tempPeri, tempSides)); // add the shape to the shape list
                    }
                    else if (input == "r") // make a rectangle
                    {
                        string tempName;
                        double tempX, tempY;
                        Console.WriteLine("Enter the Shape Name:");
                        tempName = Console.ReadLine(); // get the name
                        Console.WriteLine("Enter the x length:");
                        while (!Double.TryParse(Console.ReadLine(), out tempX)) // get the  length if string can be parsed into a initger
                        {
                            Console.WriteLine("Not a Decimal value! Please try Again!");
                        }
                        Console.WriteLine("Enter the y length:");
                        while (!Double.TryParse(Console.ReadLine(), out tempY)) // get the  if the area can be parsed into a string
                        {
                            Console.WriteLine("Not a Decimal value! Please try Again!");
                        }
                        shapeList.Add(new Rectangle(tempName, tempX, tempY)); // add the shape to the shape list
                    }
                    else if (input == "t") // make a rectangle
                    {
                        string tempName;
                        double tempA, tempB, tempC;
                        Console.WriteLine("Enter the Shape Name:");
                        tempName = Console.ReadLine(); // get the name
                        Console.WriteLine("Enter the A Length:");
                        while (!Double.TryParse(Console.ReadLine(), out tempA)) // get the  length if string can be parsed into a initger
                        {
                            Console.WriteLine("Not a Decimal value! Please try Again!");
                        }
                        Console.WriteLine("Enter the B Length:");
                        while (!Double.TryParse(Console.ReadLine(), out tempB)) // get the  if the area can be parsed into a string
                        {
                            Console.WriteLine("Not a Decimal value! Please try Again!");
                        }
                        Console.WriteLine("Enter the C Length:");
                        while (!Double.TryParse(Console.ReadLine(), out tempC)) // get the  if the area can be parsed into a string
                        {
                            Console.WriteLine("Not a Decimal value! Please try Again!");
                        }
                        shapeList.Add(new Triangle(tempName, tempA, tempB, tempC)); // add the shape to the shape list
                    }
                    #endregion
                }
                else if (input == "e") // edit shape
                {
                    Console.WriteLine("Enter the name of the shape you would like to edit.");
                    input = Console.ReadLine();
                    Shape tempShape = getShape(input, shapeList);
                    if (tempShape != null) // edit if shape return is not null. It is null if not found.
                    {
                        // list the options
                        Console.WriteLine("\n---------------------------------------");
                        Console.WriteLine("Enter the item you would like to edit");
                        Console.WriteLine("n - to rename");
                        Console.WriteLine("a - set the area");
                        Console.WriteLine("p - set the perimeter");
                        if (tempShape.getType() == "ambiguous") { Console.WriteLine("s - set the number of sides"); }
                        if (tempShape.getType() == "rectangle") { Console.WriteLine("l - set the lengths"); }
                        if (tempShape.getType() == "triangle") { Console.WriteLine("l - set the lengths"); }
                        Console.WriteLine("Press any other key to cancel");
                        Console.WriteLine("---------------------------------------");
                        input = Console.ReadKey(true).Key.ToString().ToLower(); // lowercase for ease

                        if (input == "n")
                        {
                            Console.WriteLine("Please enter the new name");
                            string tempName;
                            tempName = Console.ReadLine();
                            tempShape.setName(tempName);
                        }
                        else if (input == "a")
                        {
                            Console.WriteLine("Please enter the new area");
                            double tempArea;
                            while (!Double.TryParse(Console.ReadLine(), out tempArea)) // get the area if string can be parsed into a decimal
                            {
                                Console.WriteLine("Not a Decimal value! Please try Again!");
                            }
                            tempShape.setArea(tempArea);
                        }
                        else if (input == "p")
                        {
                            Console.WriteLine("Please enter the new perimeter");
                            double tempPeri;
                            while (!Double.TryParse(Console.ReadLine(), out tempPeri)) // get the area if string can be parsed into a decimal
                            {
                                Console.WriteLine("Not a Decimal value! Please try Again!");
                            }
                            tempShape.setPerimeter(tempPeri);
                        }
                        else if (input == "s" && tempShape.getType() == "ambiguous")
                        {
                            Console.WriteLine("Please enter the new number of sides");
                            int tempSides;
                            while (!Int32.TryParse(Console.ReadLine(), out tempSides)) // get the area if string can be parsed into a decimal
                            {
                                Console.WriteLine("Not a intiger value! Please try Again!");
                            }
                            tempShape.setSides(tempSides);
                        }
                        else if (input == "l" && tempShape.getType() == "rectangle")
                        {
                            Console.WriteLine("Please enter the new X value");
                            double tempX;
                            while (!double.TryParse(Console.ReadLine(), out tempX)) // get the area if string can be parsed into a decimal
                            {
                                Console.WriteLine("Not a decimal value! Please try Again!");
                            }
                            Console.WriteLine("Please enter the new Y value");
                            double tempY;
                            while (!double.TryParse(Console.ReadLine(), out tempY)) // get the area if string can be parsed into a decimal
                            {
                                Console.WriteLine("Not a decimal value! Please try Again!");
                            }
                            Rectangle rect = (Rectangle)tempShape; // cast as a retangle
                            rect.setLengths(tempX, tempY); // set the lengths which will reconfigure the other values
                        }
                        else if (input == "l" && tempShape.getType() == "triangle")
                        {
                            Console.WriteLine("Please enter the new A value");
                            double tempA;
                            while (!double.TryParse(Console.ReadLine(), out tempA)) // get the area if string can be parsed into a decimal
                            {
                                Console.WriteLine("Not a decimal value! Please try Again!");
                            }
                            Console.WriteLine("Please enter the new B value");
                            double tempB;
                            while (!double.TryParse(Console.ReadLine(), out tempB)) // get the area if string can be parsed into a decimal
                            {
                                Console.WriteLine("Not a decimal value! Please try Again!");
                            }
                            Console.WriteLine("Please enter the new B value");
                            double tempC;
                            while (!double.TryParse(Console.ReadLine(), out tempC)) // get the area if string can be parsed into a decimal
                            {
                                Console.WriteLine("Not a decimal value! Please try Again!");
                            }
                            Triangle tri = (Triangle)tempShape; // cast as a retangle
                            tri.setLengths(tempA, tempB, tempC); // set the lengths which will reconfigure the other values
                        }
                    }
                    else
                    {
                        Console.WriteLine("Error! Shape not found!");
                    }

                }
                else if (input == "p")
                {
                    Console.WriteLine("Enter the name of the shape you would like to print.");
                    input = Console.ReadLine();
                    if (getShape(input, shapeList) != null) // print the shape results if it exist
                    {
                        getShape(input, shapeList).printAll(); // print
                    }
                    else
                    {
                        Console.WriteLine("Error! Shape not found!");
                    }
                }
                else if (input == "d")
                {
                    Console.WriteLine("Enter the name of the shape you would like to delete.");
                    input = Console.ReadLine();
                    if (getShape(input, shapeList) != null) // check if shape exists
                    {
                        Shape tempShape = getShape(input, shapeList);
                        shapeList.Remove(tempShape);
                        Console.WriteLine(tempShape.getName() + " has been deleted!");
                    }
                    else
                    {
                        Console.WriteLine("Error! Shape not found!");
                    }
                }
                else if (input == "a") // prints all the shapes
                {
                    for (int i = 0; i < shapeList.Count; i++)
                    {
                        Console.Write(i + 1 + ". ");
                        shapeList[i].printAll();
                    }
                }
                else if (input == "e")
                {
                    Console.WriteLine("Exiting program.");
                }
                else
                {
                    Console.WriteLine("Error! Not a valid input!");
                }             
            }
        }

        // gets the shape basted on the name of that shape in the list. Returns null object if not found
        static Shape getShape(string name, List<Shape> shapeList)
        {
                    Shape tempShape = null; // store the loaded shape                  
                    for (int i = 0; i < shapeList.Count; i++) // search for the shape
                    {
                        if (shapeList[i].getName() == name)
                        {
                            tempShape = shapeList[i];
                            break;
                        }
                    }
                    return tempShape;
        }

    }
    

    // The container class from all shapes
    class Shape
    {
        // all variables are protected for this class so that they can be used by inheriting classes
        protected double area = 0;
        protected double perimeter = 0;
        protected int numberOfSides = 0;
        protected string name; // must have a shape name, thats how all shapes are seperated from.
        protected string type = "ambiguous"; // will show the type of sape it is. ambiguos is the default
        
        // basic constructor a shape
        public Shape() { }

        // Create a new shape with a name
        public Shape(string Name)
        {
            name = Name;
        }

        // giving the ambiguous shape area and perimeter.
        public Shape(string Name, double Area, double Perimeter)
        {
            name = Name;
            area = Area;
            perimeter = Perimeter;
        }
        
        // giving the ambiguous shape area and perimeter and a number of sides
        public Shape(string Name, double Area, double Perimeter, int Sides)
        {
            name = Name;
            area = Area;
            perimeter = Perimeter;
            numberOfSides = Sides;
        }

        // return the apropreate values.
        #region getValues
        public double getArea()
        {
            return area;
        }
        public double getPerimeter()
        {
            return perimeter;
        }
        public string getName()
        {
            return name;
        }
        public int getSides()
        {
            return numberOfSides;
        }
        public string getType()
        {
            return type;
        }
        #endregion

        #region setValues
        public virtual void setArea(double Area)
        {
            area = Area;
        }
        public virtual void setPerimeter(double Perimeter)
        {
            perimeter = Perimeter;
        }
        public virtual void setName(string Name)
        {
            name = Name;
        }
        public virtual void setSides(int Sides)
        {
            if (type != "ambiguous")
            { 
                Console.WriteLine("Only Ambigious shapes can have the number of sides changed");
                return;
            }
            if (Sides == 3 || Sides == 4)
            {
                Console.WriteLine("Ambigous shapes cannot have the same number of sides as a trangle or rectangle.");
                return;
            }
            numberOfSides = Sides;
        }
        #endregion

        // Print all values
        public virtual void printAll()
        {
            Console.WriteLine("\tName: " + name 
                            + "\n\tType: " + type 
                            + "\n\tArea: " + area 
                            + "\n\tPerimeter: " + perimeter 
                            + "\n\tSides: " + numberOfSides 
                            + "\n");
        }
    }

    // Retangle class to hold rectangle shapes
    class Rectangle : Shape
    {
        protected double xLen, yLen; // the length of the sides

        // General constructor with a name
        public Rectangle(string Name)
        {
            name = Name;
            type = "rectangle"; // change type to rectangle
            numberOfSides = 4;
        }

        // constructor given a lenght
        public Rectangle(string Name, double Lenght)
        {
            name = Name;
            // set the length to all sides
            xLen = Lenght;
            yLen = Lenght;
            calcArea(); // set the area
            calcPerimeter();
            type = "rectangle"; // change type to rectangle
            numberOfSides = 4;
        }

        // constructor given both lengths
        public Rectangle(string Name, double xLength, double yLength)
        {
            name = Name;
            // set lengths
            xLen = xLength;
            yLen = yLength;
            calcArea(); // set the area
            calcPerimeter(); // set the perimeter
            type = "rectangle"; // change type to rectangle
            numberOfSides = 4;
        }

        #region setValues
        // Set Values
        public void setLengths(double xLength, double yLength)
        {
            xLen = xLength;
            yLen = yLength;
            calcArea(); // set the area
            calcPerimeter(); // set the perimeter
        }
        public override void setArea(double Area)
        {
            base.setArea(Area);
            // change the lengths to match, the shape becomes a square 
            xLen = Math.Sqrt(Area);
            yLen = Math.Sqrt(Area);
            // recalculate the perimeter
            calcPerimeter();
        }
        public override void setPerimeter(double Perimeter)
        {
            base.setPerimeter(Perimeter);
            // change the lengths to match, the shape becomes a square 
            xLen = perimeter / 4;
            yLen = perimeter / 4;
            // recalculate the Area
            calcArea();
        }
        #endregion

        // print all values
        public override void printAll()
        {
            Console.WriteLine("\tName: " + name 
                            + "\n\tType: " + type 
                            + "\n\tArea: " + area 
                            + "\n\tPerimeter: " + perimeter 
                            + "\n\tX Length: " + xLen 
                            + "\n\tY Length: " + yLen 
                            + "\n");
        }

        // Calculate Area
        private void calcArea()
        {
            area = xLen * yLen;
        }

        // Calculate Perimeter
        private void calcPerimeter()
        {
            perimeter = 2 * xLen + 2 * yLen;
        }

       
    }

    // Triangle class to hold triangle shapes
    class  Triangle : Shape
    {
        protected double aLen, bLen, cLen; // the length of the sides

        // General constructor with a name
        public Triangle(string Name)
        {
            name = Name;
            type = "triangle"; // change type to rectangle
            numberOfSides = 3;
        }

        // constructor given a lenght
        public Triangle(string Name, double Lenght)
        {
            name = Name;
            // set the length to all sides
            aLen = Lenght;
            bLen = Lenght;
            cLen = Lenght;
            calcArea(); // set the area
            calcPerimeter();
            type = "triangle"; // change type to rectangle
            numberOfSides = 4;
        }

        // constructor given both lengths
        public Triangle(string Name, double aLength, double bLength, double cLength)
        {
            name = Name;
            // set lengths
            aLen = aLength;
            bLen = bLength;
            cLen = cLength;
            calcArea(); // set the area
            calcPerimeter(); // set the perimeter
            type = "triangle"; // change type to rectangle
            numberOfSides = 4;
        }

        #region setValues
        // Set Values
        public void setLengths(double aLength, double bLength, double cLength)
        {
            aLen = aLength;
            bLen = bLength;
            cLen = cLength;
            calcArea(); // set the area
            calcPerimeter(); // set the perimeter
        }
        public override void setArea(double Area)
        {
            base.setArea(Area);
            // change the lengths to match, the shape becomes a square 
            aLen = Math.Sqrt(4*Area/Math.Sqrt(3));
            bLen = Math.Sqrt(4*Area/Math.Sqrt(3));
            cLen = Math.Sqrt(4 * Area / Math.Sqrt(3));
            // recalculate the perimeter
            calcPerimeter();
        }
        public override void setPerimeter(double Perimeter)
        {
            base.setPerimeter(Perimeter);
            // change the lengths to match, the shape becomes a square 
            aLen = perimeter / 3;
            bLen = perimeter / 3;
            cLen = perimeter / 3;
            // recalculate the Area
            calcArea();
        }
        #endregion

        // print all values
        public override void printAll()
        {
            Console.WriteLine("\tName: " + name 
                            + "\n\tType: " + type 
                            + "\n\tArea: " + area 
                            + "\n\tPerimeter: " + perimeter 
                            + "\n\tA Length: " + aLen 
                            + "\n\tB Length: " + bLen 
                            + "\n\tC Length: " + cLen
                            + "\n");
        }

        // Calculate Area
        private void calcArea()
        {
            area = aLen*aLen*Math.Sqrt(3)/4;
        }

        // Calculate Perimeter
        private void calcPerimeter()
        {
            perimeter = aLen+bLen+cLen;
        }
    }
    
}
