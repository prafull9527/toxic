//slip 5 Q1

import java.util.Scanner;
class Continent {
String continentName;
public Continent(String continentName) {
this.continentName = continentName;
}
public void displayContinent() {
System.out.println("Continent: " + continentName);
}
}
class Country extends Continent {
String countryName;
public Country(String continentName, String countryName) {
super(continentName);
this.countryName = countryName;
}
public void displayCountry() {
System.out.println("Country: " + countryName);
}
}
class State extends Country {
String stateName;
public State(String continentName, String countryName, String stateName) {
super(continentName, countryName);
this.stateName = stateName;
}
public void displayState() {
System.out.println("State: " + stateName);
}
}
public class main6 {
public static void main(String[] args) {
State myState = new State("Asia", "India", "Maharashtra");
myState.displayState();
myState.displayCountry();
myState.displayContinent();
}
}



//q2
import java.util.*;
Scanner sc = new Scanner(System.in);
void addition(){
int [][]a = new int[50][50];
int [][]b = new int[50][50];
int [][]sum = new int[50][50];
int row , col;
System.out.println("Enter the row and column \n");
row = sc.nextInt();
col = sc.nextInt();
System.out.println("Enter Element in array [A] \n\n");
for(int i = 0; i < row; i++){
for(int j = 0; j < col; j++){
System.out.print(i + " " + j + " --> \t");
a[i][j] = sc.nextInt();
}
}
System.out.println("Enter Element in array [B] \n\n");
for(int i = 0; i < row; i++){
for(int j = 0; j < col; j++){
System.out.print(i + " " + j + " --> \t");
b[i][j] = sc.nextInt();
}
}
for(int i = 0; i < row; i++){
for(int j = 0; j < col; j++){
sum[i][j] = a[i][j] + b[i][j];
}
}
System.out.println("Addition of Matrix");
for(int i = 0; i < row; i++){
System.out.println("");
for(int j = 0; j < col; j++){
System.out.print(sum[i][j]);
}
}
}
void Multiplication(){
int [][]a = new int[50][50];
int [][]b = new int[50][50];
int [][]multi = new int[50][50];
int row , col;
System.out.println("Enter the row and column \n");
row = sc.nextInt();
col = sc.nextInt();
System.out.println("Enter Element in array [A] \n\n");
for(int i = 0; i < row; i++){
for(int j = 0; j < col; j++){
System.out.print(i + " " + j + " --> \t");
a[i][j] = sc.nextInt();
}
}
System.out.println("Enter Element in array [B] \n\n");
for(int i = 0; i < row; i++){
for(int j = 0; j < col; j++){
System.out.print(i + " " + j + " --> \t");
b[i][j] = sc.nextInt();
}
}
for(int i = 0; i < row; i++){
for(int j = 0; j < col; j++){
multi[i][j] += a[i][j] * b[i][j];
}
}
System.out.println("Addition of Matrix");
for(int i = 0; i < row; i++){
System.out.println("");
for(int j = 0; j < col; j++){
System.out.print(multi[i][j] + " ");
}
}
}
public static void main(String[] args) {
Scanner scan = new Scanner(System.in);
System.out.println("Select choice");
System.out.println("1 : Addition");
System.out.println("2 : Multiplication");
int choice = scan.nextInt();
switch(choice)
{
case 1 : s.addition(); break;
case 2 : s.Multiplication(); break;
case 3 : System.exit(0);
}
scan.close();
}