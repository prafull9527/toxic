import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Frame;

public class q1 {
    public static void main(String[] args) {
        // Create a frame
        Frame frame = new Frame("BorderLayout Example");

        // Create buttons for each area
        Button btnNorth = new Button("North");
        Button btnSouth = new Button("South");
        Button btnEast = new Button("East");
        Button btnWest = new Button("West");
        Button btnCenter = new Button("Center");

        // Set the layout manager to BorderLayout
        frame.setLayout(new BorderLayout());

        // Add buttons to the frame with specific areas
        frame.add(btnNorth, BorderLayout.NORTH);
        frame.add(btnSouth, BorderLayout.SOUTH);
        frame.add(btnEast, BorderLayout.EAST);
        frame.add(btnWest, BorderLayout.WEST);
        frame.add(btnCenter, BorderLayout.CENTER);

        // Set the frame size and make it visible
        frame.setSize(400, 300);
        frame.setVisible(true);
    }
}

