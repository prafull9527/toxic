<?php
session_start();
$eno=$_GET['eno'];
$ename=$_GET['ename'];
$eadd=$_GET['eadd'];
$_SESSION['eno']=$eno;
$_SESSION['ename']=$ename;
$_SESSION['eadd']=$eadd;
?>
<html>
<body>
<form action="display.php" method="post">
<center>
<h2>Enter Earnings of employee:</h2>
Basic:<input type="text" name="e1"><br>
DA:<input type="text" name="e2"><br>
HAR:<input type="text" name="e3"><br>
<input type="submit" value= Next>
</center>
</form>
</body>
</html>
