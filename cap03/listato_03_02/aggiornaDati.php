<?php

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

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["temperatura"])) {
  $temperatura = verifica($_POST["temperatura"]);
  aggiornaFile("temperatura.txt", $temperatura);
  echo "OK";
} else {
  echo "Mi spiace, ci hai provato!";
}

?>
