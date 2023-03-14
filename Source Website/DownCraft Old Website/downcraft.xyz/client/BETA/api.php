<?php
$opts = array(
'http'=>array(
'method'=>"GET",
'header'=>"Accept-language: en\r\n" .
"Cookie: foo=bar\r\n"
)
);
$context = stream_context_create($opts);

$file = file_get_contents('http://192.168.137.3/buzzer.ps3mapi?mode=1', false, $context);
?>