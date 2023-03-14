<?php

require '../global.php';

/* Si l'utilsateur est déconnecté, on le redirige */
$Controller->isDisconnected();

/* Fonction de déconnexion*/
$Controller->Logout();

/* Activer la page dans le header */
$page_open = 'Buy Premium';

header('Refresh: 30; URL=https://shoppy.gg/product/296nCp0');

?><!doctype html>
<html lang=en>
<head>
	<meta charset=UTF-8>
	<meta name=viewport content="width=device-width, initial-scale=1, user-scalable=no">
	<meta http-equiv=x-ua-compatible content="ie=edge">
	<title>Buy Premium - <?= $Controller->Settings('name'); ?>
		
	</title>
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
	<link type=text/css rel=stylesheet href=css/sweetalert.css>
</head>
<body class=material-menu id=top>
	<?php require 'templates/header.tpl'; ?>
	<?php require 'templates/navigator.tpl'; ?>
	<section class=main-container2><div class=header>
		
					<div class="panel panel-primary">
						<div class=panel-heading>
							<h5 class=panel-title>
								<i class="fa fa-info-circle">
									
								</i> Some infos</h5>
							</div>
							<div class=panel-body><p>1. What is <b>RTM Premium</b> ? <br>- RTM Premium is a RTM (Real Time Modding) with +500 mods for host / non host. Lifetime and with a good supports for any problems.</p><p>2. How active my RTM when i purchase it ?<br>- you will be redirected on the website "shoppy" for purchase your login access. After have buy it, look on your e-mail you will have your account DownCraft Premium for login in the RTM. Contact Misaki Dev on discord for get the rank Premium Member on the website !</b>
								<br>
								<br>
							<center><h4><b><div id="countdown"></div><b></b></h4></center>
							<br>
							<br>
							<center><b>Or press this button for buy now<b></center>
								<br>
								<center><button data-shoppy-product="296nCp0">Pay</button></center>
							</div> 
						</div>
					</div>
				</div>
				<footer class=footer-container>
					<div class=container-fluid>
						<div class=row>
							<div class="col-md-12 col-sm-12">
								<div class=footer-center align=center>
									<span>© 2018 - <?= date('Y'); ?> <?= $Controller->Settings('name'); ?>&nbsp;&nbsp;&nbsp;&bull;&nbsp;&nbsp;&nbsp;All rights reserved&nbsp;&nbsp;&nbsp;&bull;&nbsp;&nbsp;&nbsp;devs by <a href=http://downcraft.pw>Misaki Dev</a>&nbsp;&nbsp;&nbsp;&bull;&nbsp;&nbsp;&nbsp;Version 2.2</span>
								</div>
							</div>
						</div>
					</div>
				</footer>
			</section>
			<a id=scrollTop href=#top><i class=icon-arrow-up12></i>
			</a>
			<script src=js/jquery.js></script>
			<script src=js/bootstrap.js></script> 
			<script src=js/jquery.ui.js></script>
			<script src=js/nav.accordion.js></script>
			 <script src=js/hammerjs.js></script>
			 <script src=js/jquery.hammer.js></script>
			  <script src=js/scrollup.js></script>
			  <script src=js/jquery.slimscroll.js></script>
			   <script src=js/smart-resize.js></script>
			   <script src=js/blockui.min.js></script>
			    <script src=js/wow.min.js></script>
			    <script src=js/fancybox.min.js></script> 
			    <script src=js/venobox.js></script>
			    <script src=js/forms/uniform.min.js></script> 
			    <script src=js/forms/switchery.js></script>
			    <script src=js/forms/select2.min.js></script>
			     <script src=js/core.js></script>
			     <script src=js/pnotify.min.js></script>
			      <script src=js/sweetalert-dev.js></script>
			      <script src=js/kdo.js></script> 
			      <?php if(isset($_SESSION['payment'])) { echo $_SESSION['payment']; unset($_SESSION['payment']); } ?>
			      <script src=//api.dedipass.com/v1/pay.js></script>
			       <script src=js/notifications.js></script>
			       <script src="https://shoppy.gg/api/embed.js"></script>
			       <script>
			       var timeleft = 30;
var downloadTimer = setInterval(function(){
  if(timeleft <= 0){
    clearInterval(downloadTimer);
    document.getElementById("countdown").innerHTML = "Redirected...";
  } else {
    document.getElementById("countdown").innerHTML = timeleft + " seconds before being redirected to purchase page";
  }
  timeleft -= 1;
}, 1000);
			       </script>
			       <?= $StingCMS->SuiviGoogle(); ?>
			   </body>
			   </html>