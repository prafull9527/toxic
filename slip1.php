<?php
session_start();
if(!isset($COOKIE['count'])
{
setcookie('count',0);
}
else
{
$count=$_COOKIE['count'];
setcookie('count',++$count);
echo"This page is accessed",$_COOKIE['count']"times";
}
?>
