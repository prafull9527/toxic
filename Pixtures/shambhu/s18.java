//slip18_q1
import javax.swing.*;
import java.awt.*;
public static void main(String[] args) {
JFrame frame = new JFrame("BorderLayout");
frame.setSize(500,500);
JPanel pane = new JPanel();
JButton nbt = new JButton("North");
JButton ebt = new JButton("East");
JButton wbt = new JButton("west");
JButton sbt = new JButton("south");
pane.setLayout(new BorderLayout());
pane.add(nbt , BorderLayout.NORTH);
pane.add(ebt , BorderLayout.EAST);
pane.add(wbt , BorderLayout.WEST);
pane.add(sbt , BorderLayout.SOUTH);
frame.add(pane);
frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
frame.setVisible(true);
}




//Q 2
import java.util.Arrays;
class CricketPlayer {
String name;
int no_of_innings;
int no_of_times_notout;
int totalruns;
double bat_avg;
public CricketPlayer(String name, int no_of_innings, int no_of_times_notout, int totalruns) {
this.name = name;
this.no_of_innings = no_of_innings;
this.no_of_times_notout = no_of_times_notout;
this.totalruns = totalruns;
this.bat_avg = avg(totalruns, no_of_innings, no_of_times_notout);
}
public static double avg(int totalruns, int no_of_innings, int no_of_times_notout) {
if (no_of_innings == 0) {
return 0.0;
}
return ((double) totalruns / no_of_innings);
}
public static void sort(CricketPlayer[] players) {
Arrays.sort(players, (player1, player2) -> Double.compare(player2.bat_avg, player1.bat_avg));
}
public void displayDetails() {
System.out.println("Player Name: " + name);
System.out.println("Number of Innings: " + no_of_innings);
System.out.println("Number of Times Not Out: " + no_of_times_notout);
System.out.println("Total Runs: " + totalruns);
System.out.println("Batting Average: " + bat_avg);
System.out.println("-----------------------------");
}
}
public class CricketPlayerDemo {
public static void main(String[] args) {
int n = 3; 
CricketPlayer[] players = new CricketPlayer[n];
players[0] = new CricketPlayer("Player1", 50, 5, 2000);
players[1] = new CricketPlayer("Player2", 40, 3, 1500);
players[2] = new CricketPlayer("Player3", 60, 8, 2500);
System.out.println("Player Details Before Sorting:");
for (CricketPlayer player : players) {
player.displayDetails();
}
CricketPlayer.sort(players);
System.out.println("Player Details After Sorting:");
for (CricketPlayer player : players) {
player.displayDetails();
}
}
}
