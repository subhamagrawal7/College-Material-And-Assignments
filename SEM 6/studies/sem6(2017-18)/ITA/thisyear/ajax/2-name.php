<html>
<head>
<script>
function showHint(str) {

    if (str.length == 0) {
        document.getElementById("txtHint").innerHTML = "";
        return;
    } else {
        console.log("First");
        var xmlhttp = new XMLHttpRequest();

        xmlhttp.onreadystatechange = function() {
          console.log("ReadySTate:"+this.readyState);
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("txtHint").innerHTML = this.responseText;

                console.log("Second");
                console.log(this.readyState);
            }
        };
        xmlhttp.open("GET", "search_name.php?name=" + str, true);
        xmlhttp.send();
        console.log("Third");

    }
}
</script>
</head>
<body>

<p><b>Start typing a name in the input field below:</b></p>
<form>
First name: <input type="text" onkeyup="showHint(this.value)">
</form>
<p>Suggestions: <span id="txtHint"></span></p>
</body>
</html>
