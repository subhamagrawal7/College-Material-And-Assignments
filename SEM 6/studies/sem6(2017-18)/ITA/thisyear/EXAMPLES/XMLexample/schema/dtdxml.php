<?php

$xml=new DOMDOcument();
$xml->load("data.xml");

if($xml->schemaValidate('data.xsd')){
	echo "Cogratulations";
}
else{
	echo "Not Correct";
}
?>


	