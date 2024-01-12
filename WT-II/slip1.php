<!--Slip No.1
Q. 1) Write a PHP script to keep track of number of times the web page has been accessed
(Use Session Tracking).-->
<?php
if(!isset($_COOKIE['count']))
{
setcookie('count',0);
}
else
{
$count=$_COOKIE['count'];
setcookie('count',++$count);
echo"This page is accessed" .$_COOKIE['count']. "times";
}
?>
<?php
session_start();
if(!isset($_SESSION['count']))
{
$_SESSION['count']=0;
}
else
{
$_SESSION['count']=$_SESSION['count']+1;
e cho"This page is accessed" .$_SESSION['count']. "times";
}
?>
