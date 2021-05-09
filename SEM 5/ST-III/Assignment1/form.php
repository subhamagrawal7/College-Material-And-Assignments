<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>FINAL FORM</title>
    <style>
        body {
            color: <?php echo  $_POST["fcolor"]; ?>;
            background-color: <?php echo  $_POST["bgcolor"]; ?>;
            font-size: <?php echo $_POST["fsize"]; ?>;
            font-family: <?php echo $_POST["ffamily"]; ?>;
        }

        #member-section {
            display: block;
            float: left;
            margin-left: 20%;
            position: relative;
        }

        #fill-section {
            display: block;
            margin-left: 40%;
            float: none;
            position: relative;
        }

        .submit {
            /* margin: 0 auto; */
            text-align: center;
            border: 1px solid #fff;
            border-radius: 3px;
            width: 200px;
            padding: 6px 15px;
            /* background: none; */
            margin-left: 15%;
            font-size: 16px;
            margin-top: 50px;
        }
    </style>
</head>

<body>
    <form id="finalForm" class="finalForm" action="success.php" onload="createForm()" method="POST">
        <fieldset>
            <legend style="font-size:40px;"><?php echo $_POST["heading"]; ?></legend>

            <!--  DIVISION FOR NUMBER OF MEMBERS   -->
            <div id="member-section">
                <?php
                $num = $_POST["member"];
                for ($i = 1; $i <= $num; $i++) {
                    echo "" . $_POST["label" . $i] . "<br><br><br>";
                }
                ?>
            </div>

            <div id="fill-section">
                <?php
                $ln = $_POST["member"];
                for ($i = 1; $i <= $ln; $i++) {
                    // echo $i;
                    $typeField = $_POST["field" . $i];
                    if ($typeField == "text") {
                        echo '<input type="text" name="field' . $i . '" required><br><br>';
                    } elseif ($typeField == "date") {
                        echo '<input type="date" name="field' . $i . '" required><br><br>';
                    } elseif ($typeField == "password") {
                        echo '<input type="password" name="field' . $i . '" required><br><br>';
                    } elseif ($typeField == "email") {
                        echo '<input type="email" name="field' . $i . '" required><br><br>';
                    } elseif ($typeField == "select") {
                        echo "<select name='field'" . $i . " required>";
                        $num = $_POST["subnum" . $i];
                        for ($j = 1; $j <= $num; $j++) {
                            $op = $_POST["suboption" . $i . $j];
                            echo "<option value=" . $op . ">" . $op . "</option>";
                        }
                        echo "</select><br><br>";
                    } elseif ($typeField == "radio") {
                        $num = $_POST["subnum" . $i];
                        for ($j = 1; $j <= $num; $j++) {
                            $op = $_POST["suboption" . $i . $j];
                            echo "<input type='radio' name='field'" . $i . " value=" . $op . ">" . $op . "</input>&nbsp&nbsp";
                        }
                        echo "<br><br>";
                    } elseif ($typeField == "checkbox") {
                        $num = $_POST["subnum" . $i];
                        for ($j = 1; $j <= $num; $j++) {
                            $op = $_POST["suboption" . $i . $j];
                            echo "<input type='checkbox' name='field'" . $i . " value=" . $op . ">" . $op . "</input>&nbsp&nbsp";
                        }
                        echo "<br><br>";
                    }
                }
                ?>
            </div>

            <input type="submit" value="submit" class="submit"></input>

        </fieldset>
    </form>
</body>

</html>