<?php

require '../global.php';

/* Si l'utilsateur est déconnecté, on le redirige */
$Controller->isDisconnected();

/* Fonction de déconnexion*/
$Controller->Logout();

/* Activer la page dans le header */
$page_open = 'maj';

?><!doctype html>
<html lang=en>
<head><meta charset=UTF-8>
<meta name=viewport content="width=device-width, initial-scale=1, user-scalable=no">
<meta http-equiv=x-ua-compatible content="ie=edge">
<title>DownCraft Premium Screen - 
</title><link href=assets/images/favicon.ico rel=apple-touch-icon type=image/png sizes=144x144>
</head>
<body data-ma-theme="blue">
        <div class="login">

            <div class="login__block active">
                <div class="login__block__header">
				<br>
				<br>
				<br>
				<br>
				<br>
				<br>
                    <center><img src="<?= $_SESSION['account']['avatar']; ?>" height="80px" width="80px" alt=""><br>
                    Welcome <?= $_SESSION['account']['username']; ?> !
					<br>
					<br>
					Here you can see all options available in Premium Version
					<br>
					<br>
                    <img src="pic/1.png" alt="Smiley face" height="500" width="800">
					<br>
					<img src="pic/2.png" alt="Smiley face" height="500" width="800">
					<br>
					<img src="pic/3.png" alt="Smiley face" height="500" width="800">
					<br>
					<img src="pic/4.png" alt="Smiley face" height="500" width="800">
					<br>
					<img src="pic/5.png" alt="Smiley face" height="500" width="800">
					<br>
					<img src="pic/6.png" alt="Smiley face" height="500" width="800">
					<br>
					<img src="pic/7.png" alt="Smiley face" height="500" width="800">
					<br>
					<img src="pic/8.png" alt="Smiley face" height="500" width="800">
					<br>
					<img src="pic/9.png" alt="Smiley face" height="500" width="800">
             </div></center>
            </div>
        </div>
    </body>
</html>