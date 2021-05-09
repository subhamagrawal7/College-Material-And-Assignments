<html>
<head>
    <meta content="text/html; charset=utf-8">
    <title>AJAX JSON by Javatpoint</title>

<script>
function showHint(str) {

    if (str.length == 0) {
        document.getElementById("txtHint").innerHTML = "";
        return;
    } else {
        console.log("First");
        var request = new XMLHttpRequest();

            function load()
            {
                //var url = "http://date.jsontest.com/";//use any url that have json data
                var request;

                if(window.XMLHttpRequest){
                    request=new XMLHttpRequest();//for Chrome, mozilla etc
                }
                else if(window.ActiveXObject){
                    request=new ActiveXObject("Microsoft.XMLHTTP");//for IE only
                }
                request.onreadystatechange  = function(){

                    if(request.readyState == 0){
                        console.log("Request initiated");
                    }
                    if(request.readyState == 1){
                        console.log("Request send");
                    }
                    if(request.readyState == 2){
                        console.log("Request prepare");
                    }
                    if(request.readyState == 3){
                        console.log("Request sent");
                    }


            if (request.readyState == 4 && this.status == 200) {
                document.getElementById("txtHint").innerHTML = this.responseText;

                console.log("Second");
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
