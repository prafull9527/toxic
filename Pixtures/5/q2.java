import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int choice;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Addition");
            System.out.println("2. Multiplication");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    performMatrixAddition();
                    break;
                case 2:
                    performMatrixMultiplication();
                    break;
                case 3:
                    System.out.println("Exiting the program. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 3);

        scanner.close();
    }

    // Function to perform matrix addition
    private static void performMatrixAddition() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows: ");
        int rows = scanner.nextInt();
        System.out.print("Enter the number of columns: ");
        int columns = scanner.nextInt();

        int[][] matrixA = inputMatrix(rows, columns, "Matrix A");
        int[][] matrixB = inputMatrix(rows, columns, "Matrix B");

        int[][] resultMatrix = new int[rows][columns];

        // Perform matrix addition
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }

        System.out.println("\nResultant Matrix (Addition):");
        displayMatrix(resultMatrix);
    }

    // Function to perform matrix multiplication
    private static void performMatrixMultiplication() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows for Matrix A: ");
        int rowsA = scanner.nextInt();
        System.out.print("Enter the number of columns for Matrix A: ");
        int columnsA = scanner.nextInt();

        System.out.print("Enter the number of columns for Matrix B: ");
        int columnsB = scanner.nextInt();

        int[][] matrixA = inputMatrix(rowsA, columnsA, "Matrix A");
        int[][] matrixB = inputMatrix(columnsA, columnsB, "Matrix B");

        int[][] resultMatrix = new int[rowsA][columnsB];

        // Perform matrix multiplication
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < columnsB; j++) {
                for (int k = 0; k < columnsA; k++) {
                    resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }

        System.out.println("\nResultant Matrix (Multiplication):");
        displayMatrix(resultMatrix);
    }

    // Function to input elements for a matrix
    private static int[][] inputMatrix(int rows, int columns, String matrixName) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter elements for " + matrixName + ":");

        int[][] matrix = new int[rows][columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.print("Enter element at position (" + (i + 1) + "," + (j + 1) + "): ");
                matrix[i][j] = scanner.nextInt();
            }
        }
        return matrix;
    }

    // Function to display a matrix
    private static void displayMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}

