import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class MouseEventsDemo extends JFrame {
    private JTextField positionTextField;

    public MouseEventsDemo() {
        super("Mouse Events Demo");

        // Create components
        positionTextField = new JTextField();
        positionTextField.setEditable(false);

        // Set layout
        setLayout(new FlowLayout());

        // Add components to the frame
        add(positionTextField);

        // Add mouse event listeners
        addMouseListener(new MyMouseListener());
        addMouseMotionListener(new MyMouseMotionListener());
    }

    // Inner class to handle mouse events
    private class MyMouseListener implements MouseListener {
        @Override
        public void mouseClicked(MouseEvent e) {
            int x = e.getX();
            int y = e.getY();
            positionTextField.setText("Mouse Clicked at: (" + x + ", " + y + ")");
        }

        // Other mouse event methods (not used in this example)
        @Override
        public void mousePressed(MouseEvent e) {}

        @Override
        public void mouseReleased(MouseEvent e) {}

        @Override
        public void mouseEntered(MouseEvent e) {}

        @Override
        public void mouseExited(MouseEvent e) {}
    }

    // Inner class to handle mouse motion events
    private class MyMouseMotionListener implements MouseMotionListener {
        @Override
        public void mouseMoved(MouseEvent e) {
            int x = e.getX();
            int y = e.getY();
            positionTextField.setText("Mouse Moved at: (" + x + ", " + y + ")");
        }

        // Other mouse motion event methods (not used in this example)
        @Override
        public void mouseDragged(MouseEvent e) {}
    }

    public static void main(String[] args) {
        MouseEventsDemo mouseEventsDemo = new MouseEventsDemo();

        // Set frame properties
        mouseEventsDemo.setSize(300, 150);
        mouseEventsDemo.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mouseEventsDemo.setVisible(true);
    }
}

