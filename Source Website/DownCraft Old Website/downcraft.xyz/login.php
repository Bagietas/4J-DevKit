<?php

require '../global.php';

/* Redirige si l'utilisateur est connecté */
$Controller->isConnected();
if (strpos($_SERVER["REQUEST_URI"], "register")){
    $_GET["page"] = "register";
}else if(strpos($_SERVER["REQUEST_URI"], "login")){
    $_GET["page"] = "login";
}
?>
<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.0//EN" "http://www.wapforum.org/DTD/xhtml-mobile10.dtd"><html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>
<?php if($_GET['page'] == 'login' OR $_GET['page'] == '')
 { echo 'Login'; } 
 elseif($_GET['page'] == 'register') 
 { echo 'Register'; } 
 elseif($_GET['page'] == 'forgot') 
 { echo 'Forgot Password'; } 
 elseif($_GET['page'] == 'confirmemail') 
 { echo 'Confirmation'; } ?>
  - <?= $Controller->Settings('name'); ?>
</title>
<link href=assets/images/favicon.ico rel=apple-touch-icon type=image/png sizes=144x144>
<link href=assets/images/favicon.ico rel=apple-touch-icon type=image/png sizes=114x114>
<link href=assets/images/favicon.ico rel=apple-touch-icon type=image/png sizes=72x72>
<link href=assets/images/favicon.ico rel=apple-touch-icon type=image/png>
<link href=assets/images/favicon.ico rel=icon type=image/png>
<link href=assets/images/favicon.ico rel="shortcut icon">
<link rel="shortcut icon" type="image/png" href="img/main/ico-2.png">
<link rel="icon" type="image/png" href="img/main/ico-2.png">
<link rel="stylesheet" href="LoginCSS/css/fonts.css">
<link rel="stylesheet" href="LoginCSS/style.css">

<meta name="description" content="
<?php if($_GET['page'] == 'login' OR $_GET['page'] == '')
 { echo 'Login'; } 
 elseif($_GET['page'] == 'register')
{ echo 'Register'; } 
elseif($_GET['page'] == 'forgot') 
{ echo 'Forgot Password'; } ?>">
<meta name="viewport" content="width=device-width, initial-scale=1.0, minimum-scale=1.0, maximum-scale=1.0, user-scalable=yes">
<meta charset="utf-8">
<script type="text/javascript" src="LoginCSS/libs/Jquery/jquery.js">
</script>
<script type="text/javascript" src="LoginCSS/js/functions.js">
</script> 
<script type="text/javascript" src="LoginCSS/libs/Form/form.js">
</script>
<script src='https://www.google.com/recaptcha/api.js'>
</script>
</head>
<body>
<div id="preloader">
<div id="status">&nbsp;</div>
</div>
<div class="container">
<div class="content-block">
<div class="services">
<div class="s-content">
<?php if($_GET['page'] != 'login' AND $_GET['page'] != '') { ?>
<a href="login">
<div class="item">Login</div>
</a><?php } ?><?php 
if($_GET['page'] != 'register') { ?><a href="register">
<div class="item">Register</div>
</a><?php } ?><?php 
if($_GET['page'] != 'forgot') { ?><a href="forgot">
<div class="item">Forgot Password</div>
<br>
</a><?php } ?></div>
</div><div class="table"><div class="content"><div class="icon-box"><div class="logo"></div>
</div>
<div class="login-box form-box">
<div id="error">
</div>
<?php 
if($_GET['page'] == 'login' OR $_GET['page'] == '') { ?>
<form method="post" id="login-form" action="../core/action/action.php?to=login">
<input type="email" placeholder="Email" name="email" id="email" class="item input">
<input type="password" placeholder="Password" name="password" id="password" class="item input">
<button class="item submit-button">Login</button>
<button class="item submit-button" onclick="window.location.href = 'https://downcraft.xyz/client/forgot';">Forgot Password</button>
<button class="item submit-button" onclick="window.location.href = 'https://downcraft.xyz/client/register';">Don't have any account yet ?</button>
<div id="login-res"></div>
<b>
<br>
<h2><center> DownCraft © 2018 - 2020 Made By Misaki Dev </h2></center>
</b>
</form>
<?php } 
elseif($_GET['page'] == 'register') { ?>
<form method="post" id="register-form" action="../core/action/action.php?to=register">
<input type="text" placeholder="Username" name="username" id="username" class="item input">
<input type="email" placeholder="Email" name="email" id="email" class="item input">
<input type="password" placeholder="Password" name="password" id="password" class="item input">
<div style="height:19px">
</div>
<center>
<div class="g-recaptcha" data-sitekey="6Lc9dOEZAAAAAKws5ufLrGLoICrrb54hvFUwnbRO"></div>
</center>
<button class="item submit-button">Register</button>
<div id="login-res"></div>
</form><?php } ?><?php if($_GET['page'] == 'forgot') { ?>
<form method="post" id="forgot-form" action="/core/action/action.php?to=forgot">
<input type="email" placeholder="Email" name="email" id="email" class="item input">
<div style="height:19px"></div>
<center>
<div class="g-recaptcha" data-sitekey="6Lc9dOEZAAAAAKws5ufLrGLoICrrb54hvFUwnbRO">
</div>
</center>
<button class="item submit-button">Reset Password</button>
<div id="login-res"></div
><b>
<br>
<center> Reset your password to a random password ! </center>
</b></form><?php } ?><?php if($_GET['page'] == 'confirmemail') { ?> <?= $StingCMS->ConfirmEmail(); unset($_SESSION['response']); ?>
<?php } ?>
</div>
</div>
</div>
</div>
</div>
<?php if($_GET['page'] == 'login' OR $_GET['page'] == '') { ?>
<script type="text/javascript" src="LoginCSS/js/login.js"></script>
 <?php } elseif($_GET['page'] == 'register') { ?>
 <script type="text/javascript" src="LoginCSS/js/register.js">
 </script> <?php } ?><?php if($_GET['page'] == 'forgot') { ?>
  <script type="text/javascript" src="LoginCSS/js/forgot.js"></script>
  <script src="snowfinish.js"></script>
  <?php } ?> <script>$(window).load(function(){$("#status").fadeOut(2000);$("#preloader").delay(2000).fadeOut("slow");$("body").delay(1500).css({overflow:"visible"})});</script>
  <?= $StingCMS->SuiviGoogle(); ?>
  </body>
  </html>