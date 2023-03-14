<?php

require '../global.php';

/* Si l'utilsateur est déconnecté, on le redirige */
$Controller->isDisconnected();

$Controller->Logout();

/* Activer la page dans le header */
$page_open = 'accueil';

?>
<!doctype html>
<html lang=en>
<head>
<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js">
</script>
<script>(adsbygoogle = window.adsbygoogle || []).push({ google_ad_client: "ca-pub-4963033265711496", enable_page_level_ads: true});</script>
<meta charset=UTF-8>
<meta name=viewport content="width=device-width, initial-scale=1, user-scalable=no">
<meta http-equiv=x-ua-compatible content="ie=edge">
<title>
<?= $Controller->Settings('name'); ?> - Dashboard</title>
<link href=assets/images/favicon.ico rel=apple-touch-icon type=image/png sizes=144x144>
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
<link rel="stylesheet" href="vendors/bower_components/material-design-iconic-font/dist/css/material-design-iconic-font.min.css">
<link rel="stylesheet" href="vendors/bower_components/animate.css/animate.min.css">
<link rel="stylesheet" href="vendors/bower_components/jquery.scrollbar/jquery.scrollbar.css">
<link rel="stylesheet" href="vendors/bower_components/fullcalendar/dist/fullcalendar.min.css">
<link rel="icon" href="img/favicon.ico">
<link rel="stylesheet" href="css/app.min.css"
<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.8.1/css/all.css" integrity="sha384-50oBUHEmvpQ+1lW4y57PTFmhCaXp0ML5d60M1M7uH2+nqUivzIebhndOJK28anvf" crossorigin="anonymous">

<noscript>
<META http-equiv=refresh content="0; URL=/nojs/">
</noscript>
</head>
<body class=material-menu id=top>
<?php require 'templates/header.tpl'; ?>
<?php require 'templates/navigator.tpl'; ?>
<section class=main-container2>
<div class=header>
</div>
<div class="container-fluid page-content">
<?php if($_SESSION['account']['rank'] == 1) { ?>
<div class=col-md-12>
<?= $StingCMS->PubVIP(); ?>
</div>
<?php } ?>
<div class=col-md-8>
<div class="panel panel-primary">
<div class=panel-heading>
<h5 class=panel-title>
<i class="fa fa-comments">
</i> Shoutbox</h5>
</div>
<div class=panel-body>
<form method=post action="/core/action/action.php?to=sendmsgshoutbox" id=shoutbox-form>
<div class=form-group>
<div class=input-group>
<input type=text class=form-control id=message name=message placeholder=Write a text ...>
<span class=input-group-btn>
<button class="btn btn-primary">Send</button>
<img id=Smileys src=/smileys/44.svg height=30 style=margin-left:5px>
</span>
</div>
</div>
</form>
<div id=SmileysA style=display:none align=center>
<img onclick="ajout_smiley(':) ')" src=/smileys/40.svg height=20>
<img onclick="ajout_smiley(';) ')" src=/smileys/10.svg height=20>
<img onclick="ajout_smiley(':( ')" src=/smileys/41.svg height=20>
<img onclick="ajout_smiley(':mad:')" src=/smileys/22.svg height=20>
<img onclick="ajout_smiley(':/ ')" src=/smileys/16.svg height=20>
<img onclick="ajout_smiley(':cool: ')" src=/smileys/42.svg height=20>
<img onclick="ajout_smiley(':p ')" src=/smileys/44.svg height=20>
<img onclick="ajout_smiley(':D ')" src=/smileys/4.svg height=20>
<img onclick="ajout_smiley(':\') ')" src=/smileys/3.svg height=20>
<img onclick="ajout_smiley(':\'( ')" src=/smileys/23.svg height=20>
<img onclick="ajout_smiley('-_- ')" src=/smileys/12.svg height=20>
<img onclick="ajout_smiley(':* ')" src=/smileys/19.svg height=20>
<img onclick="ajout_smiley('xD ')" src=/smileys/7.svg height=20>
<img onclick="ajout_smiley(':o ')" src=/smileys/33.svg height=20>
<img onclick="ajout_smiley('--\' ')" src=/smileys/14.svg height=20>
<img onclick="ajout_smiley(':| ')" src=/smileys/11.svg height=20>
<img onclick="ajout_smiley(':s ')" src=/smileys/17.svg height=20>
<img onclick="ajout_smiley(':love: ')" src=/smileys/43.svg height=20>
<img onclick="ajout_smiley('cat')" src=/smileys/cat.gif height=20>
<img onclick="ajout_smiley('special1')" src=/smileys/special1.png height=20>
<img onclick="ajout_smiley('special2')" src=/smileys/special2.gif height=20>
<img onclick="ajout_smiley('my')" src=/smileys/cat2.gif height=20>
<img onclick="ajout_smiley('bonk')" src=/smileys/bonk.png height=20>
<img onclick="ajout_smiley('cry')" src=/smileys/cryy.gif height=20>
</div>
<section class=shoutboxyh>
<?php if($Controller->Settings('shoutbox') == 1) { ?>
<ul class=chat id=shoutbox><center>
<i class="fa fa-spinner fa-pulse fa-fw">
</i> Loading...</center>
</ul>
<?php } elseif($Controller->Settings('shoutbox') == 2) { ?>
<center><i style=color:red class="fa fa-warning"></i> shoutbox is disabled</center>
<?php } elseif($Controller->Settings('shoutbox') == 3) { ?>
<center><i class="fa fa-spinner fa-spin fa-fw"></i> shoutbox is in maintenance</center>
<?php } ?>
</section>
</div>
</div>
</div>
<div class=col-md-4>
<div class="panel panel-primary">
<div class=panel-heading>
<h5 class=panel-title>
<i class="fa fa-bullhorn">
</i> Advertising</h5>
</div>
<div class=panel-body>
<section class=annonceyh>
<?= $StingCMS->Annonce(); ?>
</section>
</div>
</div>
<div id=usersonline><div class="panel panel-primary"><div class=panel-heading>
<h5 class=panel-title>
<i class="fa fa-user">
</i> Members Online</h5>
</div>
<div class=panel-body><i class="fa fa-spinner fa-pulse fa-fw">
</i> Loading</div>
</div>
</div>
<div class="panel panel-primary">
<div class=panel-heading>
<h5 class=panel-title>
<i class="fa fa-info">
</i> Infos</h5>
</div>
<div class=panel-body align=center>
<b>Your Status: </><?php echo $Controller->Rank($_SESSION['account']['rank']); ?></b>
<br>
<b>Members Free: <b style="color:red"><?= $StingCMS->ADMNbClient(); ?></b>
<br>
<b>Members Premium: <b style="color:red"><?= $StingCMS->ADMNbRetroActif(); ?></b>
<br>
<b>Free RTM Attach Logs: <b style="color:red"><?= $StingCMS->logs_attach_free(); ?></b>
<br>
<b>Premium RTM Attach Logs: <b style="color:red"><?= $StingCMS->logs_attach_premium(); ?></b>
<br>
<b>Server is:</b> <b style="color:green">ONLINE</b>
<br>
<br>
<b>Join our official Discord server</b>
<br>
<iframe src="https://discordapp.com/widget?id=511241984090963978&theme=dark" width="350" height="500" allowtransparency="true" frameborder="0" sandbox="allow-popups allow-popups-to-escape-sandbox allow-same-origin allow-scripts"></iframe>
</div>
</div>
<? ?>
</div>
</div>
<center>
<footer class=footer-container>
<div class=container-fluid>
<div class=row>
<div class="col-md-12 col-sm-12">
<div class=footer-center align=center><span>© <?= date('Y'); ?> <?= $Controller->Settings('name'); ?>&nbsp;&nbsp;&nbsp;&bull;&nbsp;&nbsp;&nbspAll rights reserved Developed by <a href=https://downcraft.xyz>Misaki Dev</a>&nbsp;&nbsp;&nbsp;&bull;&nbsp;&nbsp;&nbsp;Version 2.0</span></div></div></div></div></footer></section><a id=scrollTop href=page_empty.htm#top><i class=icon-arrow-up12></i></a><script src=js/jquery.js></script><script src=js/bootstrap.js></script> <script src=js/jquery.ui.js></script><script src=js/nav.accordion.js></script> <script src=js/hammerjs.js></script><script src=js/jquery.hammer.js></script> <script src=js/scrollup.js></script><script src=js/jquery.slimscroll.js></script> <script src=js/smart-resize.js></script><script src=js/blockui.min.js></script> <script src=js/wow.min.js></script><script src=js/fancybox.min.js></script> <script src=js/venobox.js></script><script src=js/forms/uniform.min.js></script> <script src=js/forms/switchery.js></script><script src=js/forms/select2.min.js></script> <script src=js/core.js></script><script src=js/pnotify.min.js></script> <script src=js/index.js></script><script src=js/notifications.js></script><?= $StingCMS->SuiviGoogle(); ?>
</body> 
</body>
<script src="http://downcraft.pw/client/snow.js"></script>
  <script src="vendors/bower_components/jquery/dist/jquery.min.js"></script>
        <script src="vendors/bower_components/tether/dist/js/tether.min.js"></script>
        <script src="vendors/bower_components/bootstrap/dist/js/bootstrap.min.js"></script>
        <script src="vendors/bower_components/Waves/dist/waves.min.js"></script>
        <script src="vendors/bower_components/jquery.scrollbar/jquery.scrollbar.min.js"></script>
        <script src="vendors/bower_components/jquery-scrollLock/jquery-scrollLock.min.js"></script>
        <script src="vendors/bower_components/Waves/dist/waves.min.js"></script>

        <script src="vendors/bower_components/flot/jquery.flot.js"></script>
        <script src="vendors/bower_components/flot/jquery.flot.resize.js"></script>
        <script src="vendors/bower_components/flot.curvedlines/curvedLines.js"></script>
        <script src="vendors/bower_components/jqvmap/dist/jquery.vmap.min.js"></script>
        <script src="vendors/bower_components/jqvmap/dist/maps/jquery.vmap.world.js"></script>
        <script src="vendors/bower_components/jquery.easy-pie-chart/dist/jquery.easypiechart.min.js"></script>
        <script src="vendors/bower_components/salvattore/dist/salvattore.min.js"></script>
        <script src="vendors/jquery.sparkline/jquery.sparkline.min.js"></script>
        <script src="vendors/bower_components/moment/min/moment.min.js"></script>
        <script src="vendors/bower_components/fullcalendar/dist/fullcalendar.min.js"></script>

        <script src="demo/js/flot-charts/curved-line.js"></script>
        <script src="demo/js/flot-charts/line.js"></script>
        <script src="demo/js/flot-charts/chart-tooltips.js"></script>
        <script src="demo/js/other-charts.js"></script>
        <script src="demo/js/jqvmap.js"></script>

        <script src="js/app.min.js"></script>
        <script src="snowfinish.js"></script>
</html></html>