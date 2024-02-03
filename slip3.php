<html>
<body>
<form method=POST action ="<?php echo $_SERVER['PHP_SELF']?>">
Enter user name:<input type=text name=user><br><br>
Enter user password:<input type=text name=pass><br><br>
<input type=submit name=submit value="Log In">
</form>
<?php
session_start();
if(isset($_POST['submit']))
{
$user=$_POST['user']
$user=$_POST['pass']
if(isset($_SESSION['count']))
{
$count=$_SESSION['count'];
}
else
{
$count=0;
$count++;
$_SESSION['count']=$count;
if(isset{$user) && isset($pass) && $count<=3 && $user===$pass)
{
echo"Welcome.... Login Successful";
}
if($count>3)
{
echo"3 Attempt are Over";
}
}
?>
</body>
</html>

