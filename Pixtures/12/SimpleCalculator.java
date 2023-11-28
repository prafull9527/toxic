import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleCalculator extends JFrame {
    // Text field to display the result
    private JTextField resultTextField;

    // Constructor
    public SimpleCalculator() {
        super("Simple Calculator");

        // Set layout to GridLayout with 4 rows and 4 columns
        setLayout(new GridLayout(4, 4));

        // Create and add buttons to the frame
        addButton("7");
        addButton("8");
        addButton("9");
        addButton("/");

        addButton("4");
        addButton("5");
        addButton("6");
        addButton("*");

        addButton("1");
        addButton("2");
        addButton("3");
        addButton("-");

        addButton("0");
        addButton("%");
        addButton("+");
        addButton("=");

        // Create the text field
        resultTextField = new JTextField();
        resultTextField.setEditable(false); // Make the text field non-editable
        resultTextField.setHorizontalAlignment(JTextField.RIGHT); // Set text alignment to right
        add(resultTextField);

        // Set frame properties
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); // Center the frame
    }

    // Method to add a button to the frame
    private void addButton(String label) {
        JButton button = new JButton(label);
        button.addActionListener(new ButtonClickListener());
        add(button);
    }

    // ActionListener for button clicks
    private class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JButton source = (JButton) e.getSource();
            String buttonText = source.getText();

            // Handle button clicks
            if (buttonText.equals("=")) {
                calculateResult();
            } else {
                resultTextField.setText(resultTextField.getText() + buttonText);
            }
        }

        // Method to calculate and display the result
        private void calculateResult() {
            String expression = resultTextField.getText();

            try {
                // Use the JavaScript engine to evaluate the expression
                ScriptEngineManager manager = new ScriptEngineManager();
                ScriptEngine engine = manager.getEngineByName("JavaScript");
                Object result = engine.eval(expression);

                // Display the result in the text field
                resultTextField.setText(result.toString());
            } catch (ScriptException ex) {
                // Handle invalid expressions
                resultTextField.setText("Error");
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            SimpleCalculator calculator = new SimpleCalculator();
            calculator.setVisible(true);
        });
    }
}

