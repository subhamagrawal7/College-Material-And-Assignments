<html>
<head>
    <meta content="text/html; charset=utf-8">
    <title>AJAX JSON by Javatpoint</title>
    <script type="application/javascript">
        function load()
        {
        //var url = "https://www.w3schools.com";//use any url that have json data
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
                if (request.readyState == 4)
                {
                    console.log("Response received");
                    console.log(request);
                  //  var jsonObj = JSON.parse(request.responseText);//JSON.parse() returns JSON object
                    //document.getElementById("date").innerHTML =  jsonObj.date;
                    //document.getElementById("time").innerHTML = jsonObj.time;
                    document.write(this.responseText);
                }
            }
            request.open("GET","search_name.php?name=" , true);
            request.send();
        }
    </script>
</head>
<body>

<!-- Date: <span id="date"></span><br/> -->
<!-- Time: <span id="time"></span><br/> -->

<button type="button" onclick="load()">Load Information</button>
</body>
</html>
