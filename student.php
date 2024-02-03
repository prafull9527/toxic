<?php
$xml=simplexml_load_file("student.xml") or die("cannot load");
$course=$_POST['course'];
echo"<table border=1>";
echo"<tr><th>Roll No.</th><th>Student Name</th><th>Address</th><th>College</th><th>Course</th></tr>";
foreach($xml->stud as $s)
{
if($s->course==$course)
{
echo"<tr><td>".$s['rollno']."</td>";
echo"<td>".$s->name."</td>";
echo"<td>".$s->add."</td>";
echo"<td>".$s->college."</td>";
echo"<td>".$s->course."</td></tr>";
}
}
echo"</table>";
?>
















