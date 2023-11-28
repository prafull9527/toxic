import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UserInfoGUI extends JFrame {
    private JTextField nameField, classField;
    private JCheckBox readingCheckBox, writingCheckBox, sportsCheckBox, musicCheckBox;
    private JTextArea displayArea;

    public UserInfoGUI() {
        // Set the title of the JFrame
        super("User Information");

        // Create components
        JLabel nameLabel = new JLabel("Name:");
        nameField = new JTextField(20);

        JLabel classLabel = new JLabel("Class:");
        classField = new JTextField(20);

        JLabel hobbiesLabel = new JLabel("Hobbies:");

        readingCheckBox = new JCheckBox("Reading");
        writingCheckBox = new JCheckBox("Writing");
        sportsCheckBox = new JCheckBox("Sports");
        musicCheckBox = new JCheckBox("Music");

        JButton submitButton = new JButton("Submit");

        displayArea = new JTextArea(10, 30);
        displayArea.setEditable(false); // Make the display area read-only

        // Set the layout manager for the content pane
        setLayout(new FlowLayout());

        // Create a JPanel to group components
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(6, 2, 5, 5)); // 6 rows, 2 columns, with gaps

        // Add components to the panel
        panel.add(nameLabel);
        panel.add(nameField);
        panel.add(classLabel);
        panel.add(classField);
        panel.add(hobbiesLabel);
        panel.add(new JLabel()); // Empty label for alignment
        panel.add(readingCheckBox);
        panel.add(writingCheckBox);
        panel.add(sportsCheckBox);
        panel.add(musicCheckBox);
        panel.add(new JLabel()); // Empty label for alignment
        panel.add(submitButton);

        // Add action listener to the submit button
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                displaySelectedOptions();
            }
        });

        // Add the panel and display area to the content pane
        add(panel);
        add(new JScrollPane(displayArea));

        // Set frame properties
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);
        setLocationRelativeTo(null); // Center the frame
        setVisible(true);
    }

    private void displaySelectedOptions() {
        // Get user input
        String name = nameField.getText();
        String userClass = classField.getText();
        String hobbies = "";

        // Check which checkboxes are selected
        if (readingCheckBox.isSelected()) {
            hobbies += "Reading ";
        }
        if (writingCheckBox.isSelected()) {
            hobbies += "Writing ";
        }
        if (sportsCheckBox.isSelected()) {
            hobbies += "Sports ";
        }
        if (musicCheckBox.isSelected()) {
            hobbies += "Music ";
        }

        // Display the selected options in the text area
        displayArea.setText("Name: " + name + "\nClass: " + userClass + "\nHobbies: " + hobbies);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new UserInfoGUI();
            }
        });
    }
}

