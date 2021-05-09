<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Form Maker</title>

    <script type="text/javascript">
        function addOptions(i) {
            var n = document.getElementById("subnum" + i).value;
            var c3 = document.getElementById("subsubdiv" + i);
            c3.innerHTML = "";
            for (var j = 1; j <= n; j++) {
                c3.innerHTML = c3.innerHTML + '<input type="text" class="suboptions" name="suboption' + i + j + '" id="suboption' + i + j + '" placeholder="Enter the value to be placed">';
            }
        }

        function addSubfield(i) {
            var a1 = document.getElementById("field" + i).value;
            //console.log(a1);
            var c2 = document.getElementById("subdiv" + i);
            if (a1 == "checkbox" || a1 == "radio" || a1 == "select") {
                c2.innerHTML = '<input type="number" class="subnums" name="subnum' + i + '" placeholder="Enter the Number Of Items" id ="subnum' + i + '" onkeyup="addOptions(' + i + ');" onchange="addOptions(' + i + ');"><div class="subsubdivs" id="subsubdiv' + i + '" />';
            } else {
                c2.innerHTML = "";
            }
        }

        function addFields() {
            var num = document.getElementById("member").value;
            var c1 = document.getElementById("container");
            c1.innerHTML = "";
            var i;
            for (i = 1; i <= num; i++) {
                c1.innerHTML = c1.innerHTML + '<span style="padding-top: 5px;">Field' + i + '</span>';
                c1.innerHTML = c1.innerHTML + '<div class="g1"><input type="text" name="label' + i + '" class="labels" id="label' + i + '" placeholder="label' + i + '">' +
                    '<select onchange="addSubfield(' + i + ');" name="field' + i + '"class="fields" id="field' + i +
                    '"><option style="color:#3e3d3d" value="text">Text</option><option style="color:#3e3d3d" value="radio">Radio</option><option style="color:#3e3d3d" value="select">Select</option><option style="color:#3e3d3d" value="date">Date</option><option style="color:#3e3d3d" value="email">Email</option><option style="color:#3e3d3d" value="password">Password</option><option style="color:#3e3d3d" value="checkbox">Check box</option></select><div id="subdiv' + i + '"/>';
            }
        }
    </script>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>
    <form class="form-wrap" name="formmaker" action="form.php" method="POST">
        <h1>Make Forms!!</h1>
        <div class="fill">
            <span>Heading</span><input type="text" placeholder="Heading" class="input-general" name="heading" id="heading" required />
            <span style="padding-top:20px;">Font Color</span><input type="color" name="fcolor" id="fcolor">
            <span style="margin-right:30%;padding-top:18px;">Font Size</span><input type="number" name="fsize" min="10" max="36" id="fsize">
            <span style="padding-top:30px;">Font-family</span><select class="input-general" name="ffamily" id="ffamily">
                <option style="color:#3e3d3d" value="sans-serif">Sans-Serif</option>
                <option style="color:#3e3d3d" value="Times New Roman">Times New Roman</option>
                <option style="color:#3e3d3d" value="calibri">Calibri</option>
                <option style="color:#3e3d3d" value="Impact">Impact</option>
            </select>
            <span style="padding-top:5px;">Background Color</span><input type="color" name="bgcolor" id="bgcolor">
            <span style="margin-right: 20%;padding-top:18px;">Number of fields</span><input onkeyup="addFields()" onchange="addFields()" type="number" min="0" max="5" name="member" id="member">
            <div id="container" />

        </div>

        <input type="submit" name="Submit" id="submit">

    </form>
</body>

</html>