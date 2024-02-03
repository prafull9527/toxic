<?php
$xml=simplexml_load_file("book.xml") or die("cannot load");
echo"<table border=1>";
echo"<tr><th>Book Id</th><<th>Book Title</th><th>Author</th><th>Year</th></tr>";
foreach($xml->book as $a )
{
echo"<tr><td>".$a["id"]."</td>";
echo"<td>".$a->title."</td>";
echo"<td>".$a->author."</td>";
echo"<td>".$a->year."</td></tr>";
}
echo"</table>";
?>






























