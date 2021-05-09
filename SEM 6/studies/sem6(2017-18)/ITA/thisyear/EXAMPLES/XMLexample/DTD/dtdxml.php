<?php

$xml=new DOMDOcument;
$xml->load("entity.xml");

if($xml->validate()){
	echo "Correct";
}
else{
	echo "Not Correct";
}?>


	