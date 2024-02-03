<?php
$dom=new DOMDocument();
$dom->load("movie.xml");

echo"<b>Actor Name</b>";
echo"<br>";

$t=$dom->getElementsByTagName("actor");
foreach($t as $a)
{
print $a->textContent;
echo"<br>";
}

echo"<b>Movie Name</b>";
echo"<br>";

$t=$dom->getElementsByTagName("title");
foreach($t as $b)
{
print $b->textContent;
echo"<br>";
}
?>

<!--
<?php
$xml=simplexml_load_file("movie.xml") or die("cannot load");
echo"<table border=1>";
echo"<tr><th>ID</th><th>Title</th><<th>Actor</th><th>Year</th></tr>";
foreach($xml->movie as $a )
{
echo"<tr><td>".$a["mno"]."</td>";
echo"<td>".$a->title."</td>";
echo"<td>".$a->actor."</td>";
echo"<td>".$a->releaseyear."</td></tr>";
}
echo"</table>";
?>
-->

























































