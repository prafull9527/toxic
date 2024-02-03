<?php
$style=$_POST['style'];
$size=$_POST['size'];
$color=$_POST['color'];
$bg=$_POST['bg'];

echo"<br>style is:".$style;
echo"<br>size is:".$size;
echo"<br>color is:".$color;
echo"<br>background color is:".$bg;

setcookie("c1",$style,time()+3600);
setcookie("c2",$size,time()+3600);
setcookie("c3",$color,time()+3600);
setcookie("c4",$bg,time()+3600);
?>

