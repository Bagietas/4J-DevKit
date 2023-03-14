<?php

require '../../global.php';

if(isset($_SESSION['admin'])) {
	if($_SESSION['admin'] == 'active') {
		if($_SESSION['account']['rank'] >= 8) {
			
		} else {
			header('Location: index');
		}
		
	} else {
		header('Location: login');
	}
	
} else {
	header('Location: login');
}

$page = 'update';

?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
		
		<title>Update - <?= $Controller->Settings('name'); ?></title>

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
                    <h1><a href="index.html">Administration DownCraft</a></h1>
                </div>

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

            <?php require 'templates/navigator.tpl'; ?>

            <section class="content">

					<?php if($_GET['id']) { $_SESSION['getidu'] = $Controller->GetID('id'); ?>
					<?= $StingCMS->ADMUpdateUpdate(); ?>
					<?php } elseif($_GET['page']) { ?>
				<div class="row">
					
					<div class="col-md-12">
					<div class="card-demo">
                    <div class="card">

                        <div class="card-header">
                            <h2 class="card-title">Creating an update</h2>
                        </div><div class="card-block">
						<form method="post" id="update" action="/core/action/action?to=admcreateupdate">
						<div class="row">
						<div class="col-sm-12">
							<div class="form-group">
								<label>Title</label>
								<input name="title" id="title" class="form-control" placeholder="Titre">
								<i class="form-group__bar"></i>
							</div>	
						</div>
						<div class="col-sm-6">
							<div class="form-group">
								<label>Type of task</label>
                                <select name="type_tache" class="form-control">
									<option value="Maintenance">Maintenance</option>
									<option value="Incident">Incident</option>
									<option value="Amélioration">Improvement</option>
								</select>
                                <i class="form-group__bar"></i>
                            </div>
							<div class="form-group">
								<label>Severity</label>
                                <select name="severite" class="form-control">
									<option value="Très basse">Very low</option>
									<option value="Basse">Low</option>
									<option value="Moyenne">Average</option>
									<option value="Haute">High</option>
									<option value="Très haute">Very high</option>
									<option value="Critique">Critical</option>
								</select>
                                <i class="form-group__bar"></i>
                            </div>
							<div class="form-group">
								<label>Status</label>
                                <select name="etat" class="form-control">
									<option value="En cours">In progress</option>
									<option value="Terminé">Finished</option>
								</select>
                                <i class="form-group__bar"></i>
                            </div>
						</div>
						<div class="col-sm-6">
							<div class="form-group">
								<label>Category</label>
                                <select name="categorie" class="form-control">
									<option value="Site">Site</option>
									<option value="Web">Web</option>
									<option value="MySQL">MySQL</option>
									<option value="VPS">API</option>
									<option value="Serveur dédié">RTM</option>
									<option value="Plesk">Account</option>
								</select>
                                <i class="form-group__bar"></i>
                            </div>
							<div class="form-group">
								<label>Operating system</label>
                                <select name="exploitation" class="form-control">
									<option value="Linux">Linux</option>
									<option value="Plesk">Plesk</option>
									<option value="Windows">Windows</option>
									<option value="Proxmox">Proxmox</option>
								</select>
                                <i class="form-group__bar"></i>
                            </div>
							<div class="form-group">
								<label>Progression</label>
                                <input name="progression" id="progression" type="number" class="form-control" placeholder="Progression">
                                <i class="form-group__bar"></i>
                            </div>
						</div>
						<div class="col-md-12">
							<div class="form-group">
								<label>Explanation</label> 
                                <textarea class="form-control" rows="5" id="explication" name="explication" placeholder="Explique-ici"></textarea>
                                <i class="form-group__bar"></i>
                            </div>
						</div>
						<div class="col-md-12">
							<button class="btn btn-primary btn-block waves-effect">Validate the update</button>
						</div>
						</div>
						</form></div>
						
						</div></div></div></div>
					<?php } else { ?>
					<div class="col-md-12">
						<div class="card-demo">
							<div class="card">

								<div class="card-header">
									<h2 class="card-title">Updates</h2>
								</div>
								<a href="?page=create" class="btn btn-primary">Create an update</a>
								<div class="card-block">
									<table class="table table-bordered mb-0">
										<thead>
											<tr>
												<th>Type of task</th>
												<th>Category</th>
												<th>Opening date</th>
												<th>Summary</th>
												<th>Action</th>
											</tr>
										</thead>
										<tbody>
											<?= $StingCMS->ADMUpdatesList(); ?>
										</tbody>
									</table>
								</div>

							</div>
						</div>
						<ul class="pagination">
											<?php for($i=1;$i<=$_SESSION['tt'];$i++) {
													if($i == $_SESSION['PA']) {
															echo '<li class="page-item active"><a class="page-link" href="#">'.$i.'</a></li>';
													} else {
														echo '<li class="page-item"><a class="page-link" href="?d='.$i.'">'.$i.'</a></li>';
													}
											} ?>
                    </ul>
					</div>
					<?php } ?>

                <footer class="footer hidden-xs-down">
                    <p>© <?= date('Y'); ?> DownCraft. Developed by Misaki Dev. All rights reserved.
</p>
                </footer>
            </section>
        </main>

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
		<script src="js/adm/update.js"></script>
    </body>
</html>