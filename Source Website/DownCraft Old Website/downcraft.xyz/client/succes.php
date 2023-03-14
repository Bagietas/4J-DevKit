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
<title>DownCraft Demo Editon - 
</title><link href=assets/images/favicon.ico rel=apple-touch-icon type=image/png sizes=144x144>
<link href=assets/images/favicon.ico rel=apple-touch-icon type=image/png sizes=114x114>
<link href=assets/images/favicon.ico rel=apple-touch-icon type=image/png sizes=72x72>
<link href=assets/images/favicon.ico rel=apple-touch-icon type=image/png>
<link href=assets/images/favicon.ico rel=icon type=image/png>
<link href=assets/images/favicon.ico rel="shortcut icon">
<link type=text/css rel=stylesheet href=assets/fonts/fonts.css>
<link type=text/css rel=stylesheet href=assets/icons/icomoon/icomoon.css>
<link type=text/css rel=stylesheet href=css/animate.min.css>
<link type=text/css rel=stylesheet href=css/bootstrap.css>
<link type=text/css rel=stylesheet href=css/core.css>
<link type=text/css rel=stylesheet href=css/layout.css>
<link type=text/css rel=stylesheet href=css/bootstrap-extended.css>
<link type=text/css rel=stylesheet href=css/components.css>
<link type=text/css rel=stylesheet href=css/plugins.css>
<link type=text/css rel=stylesheet href=css/loaders.css>
<link type=text/css rel=stylesheet href=css/responsive.css>
<link type=text/css rel=stylesheet href=css/color-system.css>
<link type=text/css rel=stylesheet href=css/fancybox/jquery.fancybox.css>
<link href=assets/icons/font-awesome/css/font-awesome.min.css rel=stylesheet type=text/css>
<link type=text/css rel=stylesheet href=css/chat.css>
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
                    Congratulations <?= $_SESSION['account']['username']; ?> !
					<br>
					<br>
					Thanks for have purchase DownCraft Premium<br>Open a ticket support or contact Misaki Dev on discord for make your account Premium in tool
					<br>
					<br>
             </div></center>
            </div>
        </div>
    </body>
</html>