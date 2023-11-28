//s10 q1
import java.util.Scanner;
interface cube{
int calculate(int a);
}
public class q1 {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.println("Enter any no: ");
int aa = sc.nextInt();
cube c = (int a) -> a*a*a;
System.out.println(c.calculate(aa));
}
}
