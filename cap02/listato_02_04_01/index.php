<html>
	<head></head>
	<body>
		<h1>Internet of Things</h1>
		<h2>Il mio primo progetto</h2>
		<p>Oggi &egrave; il <?php echo date("d/m/Y") ?> e sono le <?php echo date("h:i:sa") ?></p>
		<p>La temperatura nella stanza &egrave; di <b><?php echo file_get_contents("temperatura.txt"); ?></b> gradi centigradi.</p>
	</body>
</html>
	