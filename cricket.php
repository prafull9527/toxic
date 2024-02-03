<?php
$xmlstr=<<<str
<CricketTeam>
<Team country="Australia">
<player>David Warner</player>
<runs>50000</runs>
<wicket>30</wicket>
</Team>
</CricketTeam>
str;

$xml=new SimpleXMLElement($xmlstr);
$cricket=$xml->addChild("Team");
$cricket->addAttribute('country','India');
$cricket->addChild('player','Sachin');
$cricket->addChild('runs','50000');
$cricket->addChild('wicket','20');

header('content-type:text/xml');
echo $xml->asXML();
?>
