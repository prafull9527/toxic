//s14 q1
import java.util.Scanner;
import java.lang.*;
class ZeroNotAllowedException extends Exception{
public String toString(){
return "the no zero is not allowed!!";
}
}
public class s14 {
public static void main(String[] args)throws ZeroNotAllowedException {
boolean flag = false;
Scanner sc = new Scanner(System.in);
System.out.println("Enter any no: ");
int no = sc.nextInt();
try {
if (no == 0) {
throw new ZeroNotAllowedException();
} else {
for (int i = 2; i < no / 2; i++) {
if (no % i == 0) {
flag = true;
break;
}
}
if (flag) {
System.out.println(no + "is prime no!!");
} else {
System.out.println(no + "is not prime no!!");
}
}
}catch (ZeroNotAllowedException e){
System.out.println(new ZeroNotAllowedException());
}
}
}
