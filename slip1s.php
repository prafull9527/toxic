<?php
session_start();
if(!isset($_SESSION['count']=0))
{
else
$_SESSION['count']=$_SESSION['count']+1;
echo"This page is accessed",$_SESSION['count']"times";
}
?>
