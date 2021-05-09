<?php

$data = json_decode($HTTP_RAW_POST_DATA);

if($data->username =='Desai' && $data->password == 'Hardi')
{
    echo "success";
}else{
  echo "failed";
  header("HTTP/1.1 401");
}

?>
