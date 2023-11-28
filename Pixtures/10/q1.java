// Functional Interface
interface CubeCalculator {
    int calculateCube(int number);
}

public class q1 {
    public static void main(String[] args) {
        // Using a lambda expression to implement the functional interface
        CubeCalculator cubeCalculator = (int number) -> number * number * number;

        // Test the functional interface by finding the cube of a given number
        int numberToCube = 5;
        int cubeResult = cubeCalculator.calculateCube(numberToCube);

        System.out.println("Cube of " + numberToCube + " is: " + cubeResult);
    }
}

