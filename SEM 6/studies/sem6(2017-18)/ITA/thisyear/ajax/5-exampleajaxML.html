<!DOCTYPE html>
<html>
<style>
table,th,td {
  border : 1px solid black;
  border-collapse: collapse;
}
th,td {
  padding: 5px;
}
</style>
<body>

<p>Click on a CD to display album information.</p>
<p id='showCD'></p>
<table id="demo"></table>

<script>
var x,xmlhttp,xmlDoc
xmlhttp = new XMLHttpRequest();
xmlhttp.open("GET", "cd_catalog.xml", false);
xmlhttp.send();
xmlDoc = xmlhttp.responseXML;
x = xmlDoc.getElementsByTagName("CD");
table="<tr><th>Artist</th><th>Title</th></tr>";
for (i = 0; i <x.length; i++) {
  table += "<tr onclick='displayCD(" + i + ")'><td>";
  table += x[i].getElementsByTagName("ARTIST")[0].childNodes[0].nodeValue;
  table += "</td><td>";
  table +=  x[i].getElementsByTagName("TITLE")[0].childNodes[0].nodeValue;
  table += "</td></tr>";
}
document.getElementById("demo").innerHTML = table;

function displayCD(i) {
  document.getElementById("showCD").innerHTML =
  "Artist: " +
  x[i].getElementsByTagName("ARTIST")[0].childNodes[0].nodeValue +
  "<br>Title: " +
  x[i].getElementsByTagName("TITLE")[0].childNodes[0].nodeValue +
  "<br>Year: " +
  x[i].getElementsByTagName("YEAR")[0].childNodes[0].nodeValue;
}
</script>

</body>
</html>
