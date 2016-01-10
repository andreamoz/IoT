<?php

if ($_SERVER["REQUEST_METHOD"] == "GET" && isset($_GET["temperatura"])) {
  $temperatura = verifica($_GET["temperatura"]);
  aggiornaFile("temperatura.txt", $temperatura);
  echo "OK";
}

function verifica($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

function aggiornaFile($nome_file, $valore) {
	$file_dati = fopen($nome_file, "w");
	fwrite($file_dati, $valore);
	fclose($file_dati);
}
?>