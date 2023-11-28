import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class DivisionCalculator extends JFrame {
    private JTextField number1Field, number2Field, resultField;

    public DivisionCalculator() {
        // Set the title of the JFrame
        super("Division Calculator");

        // Create components
        JLabel number1Label = new JLabel("Number 1:");
        number1Field = new JTextField(10);

        JLabel number2Label = new JLabel("Number 2:");
        number2Field = new JTextField(10);

        JButton divideButton = new JButton("Divide");
        resultField = new JTextField(10);
        resultField.setEditable(false); // Make the result field read-only

        // Set the layout manager for the content pane
        setLayout(new FlowLayout());

        // Create a JPanel to group components
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(3, 2, 5, 5)); // 3 rows, 2 columns, with gaps

        // Add components to the panel
        panel.add(number1Label);
        panel.add(number1Field);
        panel.add(number2Label);
        panel.add(number2Field);
        panel.add(divideButton);
        panel.add(resultField);

        // Add action listener to the divide button
        divideButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                performDivision();
            }
        });

        // Add the panel to the content pane
        add(panel);

        // Set frame properties
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 150);
        setLocationRelativeTo(null); // Center the frame
        setVisible(true);
    }

    private void performDivision() {
        try {
            // Get user input
            int number1 = Integer.parseInt(number1Field.getText());
            int number2 = Integer.parseInt(number2Field.getText());

            // Perform division
            int result = number1 / number2;

            // Display the result
            resultField.setText(String.valueOf(result));
        } catch (NumberFormatException ex) {
            // Display a message dialog for NumberFormatException
            JOptionPane.showMessageDialog(this, "Please enter valid integers for Number 1 and Number 2.", "Error", JOptionPane.ERROR_MESSAGE);
        } catch (ArithmeticException ex) {
            // Display a message dialog for ArithmeticException (division by zero)
            JOptionPane.showMessageDialog(this, "Cannot divide by zero.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new DivisionCalculator();
            }
        });
    }
}

