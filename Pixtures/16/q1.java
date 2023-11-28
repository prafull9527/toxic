import java.awt.*;
import java.awt.event.*;
interface SquareCalculator {
int calculateSquare(int number);
}
public class q1 {
public static void main(String[] args) {
SquareCalculator squareCalculator = (number) -> number * number;
int inputNumber = 7;
int result = squareCalculator.calculateSquare(inputNumber);
System.out.println("The square of " + inputNumber + " is: " + result);
}
}

