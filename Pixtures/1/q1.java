class Q1{
public void ShowArray(int [] arr,int length){
System.out.println("The array you entered is as below: ");
for(int i=0;i<arr.length;i++)
{
System.out.print(" "+arr[i]);
}
}
public String PrimeNumbers(int [] arr, int length)
{
int num=0;
String primeno ="";
System.out.println("\nHere these no.s from your array are prime numbers: ");
for(int i=1; i<arr.length; i++){
int counter=0;
for (num=i ; num >=1 ; num--){
if(i%num == 0){
counter= counter + 1;
}
}
if( counter ==2){
primeno = primeno + i +" ";
}
}
return primeno;
}
}
public class q1
 {
 public static void main(String[] args) 
 {
int [] arr = {1,2,3,4,5,6,7,8,9,10};
int size=arr.length;
Q1 q = new Q1();
q.ShowArray(arr,size);
System.out.println(q.PrimeNumbers(arr,size));
}
}

